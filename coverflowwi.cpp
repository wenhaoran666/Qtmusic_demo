#include"coverflowwi.h"
#include "qboxlayout.h"
#include "qpainterpath.h"
#include <QStyle>
#include <QResizeEvent>
#include <QtMath>
#include<QDebug>
#include <functional>

CoverFlowwi::CoverFlowwi(QWidget *parent)
    : QWidget(parent)
{
    BuildUI();               // 初始化UI
    InitAnim();              // 初始化动画
    //  //间隔一秒,确保图片加载完才初始化
    QTimer::singleShot(1000, [this]() {

        loadBannerFromManager(); // 替换原LoadSlide，从MusicManager加载
         next();
    });
    // 自动轮播：5秒切换一次
    timer_.setInterval(5000);
    timer_.start();
}

// 初始化UI布局
void CoverFlowwi::BuildUI()
{
    QVBoxLayout *root = new QVBoxLayout(this);
    root->setContentsMargins(0, 0, 0, 0);
    root->setSpacing(10);

    // 滚动窗口（图片显示区）
    scroll_ = new QWidget(this);
    scroll_->setMouseTracking(true);
    scroll_->setFixedWidth(1159);          // 宽度保持 900
    scroll_->setMinimumHeight(400);       // 高度 ≥ 500，用户可继续拉高
    scroll_->setObjectName("scroll");
    scroll_->setStyleSheet(R"(
        QWidget#scroll {
            border: 2px solid #F0F3F6;
            border-radius: 12px;
            background-color: transparent;
        }
    )");
    root->addWidget(scroll_, 1);

    // 左右按钮
    btnPrev_ = new QPushButton(scroll_);
    btnPrev_->setFixedSize(20, 20);
    btnPrev_->setIcon(style()->standardIcon(QStyle::SP_ArrowLeft));
    btnPrev_->setCursor(Qt::PointingHandCursor);
    btnPrev_->raise();
    btnPrev_->hide();

    btnNext_ = new QPushButton(scroll_);
    btnNext_->setFixedSize(20, 20);
    btnNext_->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));
    btnNext_->setCursor(Qt::PointingHandCursor);
    btnNext_->raise();
    btnNext_->hide();

    connect(btnPrev_, &QPushButton::clicked, this, &CoverFlowwi::prev);
    connect(btnNext_, &QPushButton::clicked, this, &CoverFlowwi::next);

    // 导航点容器
    dotBar_ = new QWidget(this);
    dotBar_->setFixedSize(200, 30);
    dotBar_->setMouseTracking(true);
    QHBoxLayout *dotLayout = new QHBoxLayout(dotBar_);
    dotLayout->setContentsMargins(0, 0, 0, 0);
    dotLayout->setSpacing(10);
    dotBar_->setStyleSheet(R"(
        QWidget {
            background-color: transparent;
            border-radius: 8px;
        }
    )");
    root->addWidget(dotBar_, 0, Qt::AlignHCenter);

    // 初始化布局位置
    dotBar_->updateGeometry();
    layout()->invalidate();
    layout()->activate();
    updateRects();
    btnPrev_->move(CalcuBtnPos(true));
    btnNext_->move(CalcuBtnPos(false));
}

// 初始化动画
void CoverFlowwi::InitAnim()
{
    anim_ = new QVariantAnimation(this);
    anim_->setDuration(320);
    anim_->setStartValue(0.0);
    anim_->setEndValue(1.0);

    connect(anim_, &QVariantAnimation::valueChanged, this, [this](const QVariant &v) {
        if (animState_ != AnimRunning) return;
        t_ = v.toReal();
        startAnimation();
        update();
    });

    connect(anim_, &QVariantAnimation::finished, this, [this] {
        if (animState_ != AnimRunning || bannerItems_.isEmpty()) return;

        // 更新导航点状态
        if (center_ < dots_.size()) {
            UpdateDotState(dots_[center_], false);
        }
        // 计算新中心索引
        center_ = (center_ + (dir_ > 0 ? 1 : -1) + bannerItems_.size()) % bannerItems_.size();
        t_ = 0.0;
        startAnimation();
        if (center_ < dots_.size()) {
            UpdateDotState(dots_[center_], true);
        }

        // 处理剩余步数
        remainingSteps_--;
        if (remainingSteps_ <= 0 || center_ == targetIdx_) {
            animState_ = AnimIdle;
            targetIdx_ = -1;
            remainingSteps_ = 0;
            return;
        }

        // 继续动画
        anim_->stop();
        anim_->setStartValue(0.0);
        anim_->setEndValue(1.0);
        anim_->start();
    });

    // 自动轮播
    connect(&timer_, &QTimer::timeout, this, [this] {
        if (animState_ == AnimIdle && !hovering_ && !bannerItems_.isEmpty()) {
            next();
        }
    });
}

// 从MusicManager加载Banner信息
void CoverFlowwi::loadBannerFromManager()
{
    // 清空原有数据
    qDeleteAll(labels_);
    qDeleteAll(dots_);
    bannerItems_.clear();
    labels_.clear();
    dots_.clear();

    // 获取Banner列表
    bannerItems_ = MusicManager::GetInstance()->getAllbanners();
    if (bannerItems_.isEmpty()) {
        qWarning() << u8"未获取到Banner数据";
        return;
    }

    // 创建标签和导航点
    QHBoxLayout *dotLayout = qobject_cast<QHBoxLayout*>(dotBar_->layout());
    for (int i = 0; i < bannerItems_.size(); ++i) {
        const Bannerinfo &banner = bannerItems_[i];

        // 创建图片标签
        FlowLabel *label = new FlowLabel(scroll_);
        label->setSongId(banner.songId);
        QPixmap initPic = banner.pic.isNull() ? QPixmap(":/res/head_2.jpg") : banner.pic;
        label->setPixmap(initPic);
        labels_.append(label);
        connect(label, &FlowLabel::clicked, this, &CoverFlowwi::onLabelClicked);

        // 创建导航点
        CircleDot *dot = new CircleDot(dotBar_);
        dots_.append(dot);
        dotLayout->addWidget(dot);
        connect(dot, &QPushButton::clicked, this, [=]() { onDotClicked(i); });
    }

    // 初始化状态
    center_ = 0;
    updateAllDotState();
    updateRects();
}

// 更新单个Banner图片
void CoverFlowwi::updateBannerPic(qint64 songId, const QPixmap &pic)
{
    if (bannerItems_.isEmpty() || labels_.isEmpty()) return;

    for (int i = 0; i < bannerItems_.size(); ++i) {
        if (bannerItems_[i].songId == songId) {
            bannerItems_[i].pic = pic;
            if (i < labels_.size()) {
                labels_[i]->setPixmap(pic);
            }
            break;
        }
    }
}

// 导航点点击事件
void CoverFlowwi::onDotClicked(int index)
{
    if (index < 0 || index >= bannerItems_.size() || animState_ == AnimRunning) {
        return;
    }

    int total = bannerItems_.size();
    int forwardStep = (index - center_ + total) % total;
    int backwardStep = (center_ - index + total) % total;
    remainingSteps_ = qMin(forwardStep, backwardStep);
    targetIdx_ = index;
    dir_ = forwardStep <= backwardStep ? 1 : -1;

    animState_ = AnimRunning;
    anim_->stop();
    anim_->setStartValue(0.0);
    anim_->setEndValue(1.0);
    anim_->start();

    timer_.stop();
    timer_.start();
}

// 图片标签点击事件
void CoverFlowwi::onLabelClicked(qint64 songId)
{
    emit bannerClicked(songId);
    qDebug() << u8"点击Banner：songId=" << songId;
}

// 更新所有导航点状态
void CoverFlowwi::updateAllDotState()
{
    if (bannerItems_.isEmpty() || dots_.isEmpty()) return;

    for (int i = 0; i < dots_.size(); ++i) {
        UpdateDotState(dots_[i], i == center_);
    }
}

// 获取指定偏移的Banner信息
Bannerinfo CoverFlowwi::getCurrentBanner(int offset)
{
    if (bannerItems_.isEmpty()) {
        return Bannerinfo();
    }

    int targetIdx = (center_ + offset + bannerItems_.size()) % bannerItems_.size();
    return bannerItems_[targetIdx];
}

// 更新图片位置矩形
void CoverFlowwi::updateRects()
{
    if (bannerItems_.isEmpty()) return;

    const int width = scroll_->width();
    const int height = scroll_->height();
    const int peek = qRound(width * 0.17);

    szCenter_ = QSizeF(width - 2 * peek, qMin(340, height - 2 * margin_));
    const qreal sideScale = 0.78;
    szSide_ = QSizeF(szCenter_.width() * sideScale, szCenter_.height() * sideScale);

    rcCenter_ = QRectF(
        (width - szCenter_.width()) / 2.0,
        (height - szCenter_.height()) / 2.0,
        szCenter_.width(),
        szCenter_.height()
        );

    rcLeft_ = QRectF(
        LEFT_MARGIN,
        (height - szSide_.height()) / 2.0,
        szSide_.width(),
        szSide_.height()
        );

    rcRight_ = QRectF(
        width - szSide_.width() - RIGHT_MARGIN,
        (height - szSide_.height()) / 2.0,
        szSide_.width(),
        szSide_.height()
        );
}

// 线性插值计算
QRectF CoverFlowwi::lerp(const QRectF &a, const QRectF &b, qreal t) const
{
    return QRectF(
        a.x() + (b.x() - a.x()) * t,
        a.y() + (b.y() - a.y()) * t,
        a.width() + (b.width() - a.width()) * t,
        a.height() + (b.height() - a.height()) * t
        );
}

// 绘制事件
void CoverFlowwi::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if (bannerItems_.isEmpty()) return;

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform, true);

    static bool isFirstPaint = true;
    if (isFirstPaint) {
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.fillRect(rect(), QColor(0xf5, 0xf7, 0xfa));
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        isFirstPaint = false;
    }

    const int n = bannerItems_.size();
    int idxC = center_;
    int idxL = (idxC - 1 + n) % n;
    int idxR = (idxC + 1) % n;

    QPixmap picC = bannerItems_[idxC].pic.isNull() ? QPixmap(":/res/head_2.jpg") : bannerItems_[idxC].pic;
    QPixmap picL = bannerItems_[idxL].pic.isNull() ? QPixmap(":/res/head_2.jpg") : bannerItems_[idxL].pic;
    QPixmap picR = bannerItems_[idxR].pic.isNull() ? QPixmap(":/res/head_2.jpg") : bannerItems_[idxR].pic;

    QRectF rcToSide, rcToCenter, rcStatic;
    QPixmap picToSide, picToCenter, picStatic;

    if (dir_ > 0) {
        rcToSide = lerp(rcCenter_, rcLeft_, t_);
        rcToCenter = lerp(rcRight_, rcCenter_, t_);
        rcStatic = rcLeft_;
        picToSide = picC;
        picToCenter = picR;
        picStatic = picL;
    } else {
        rcToSide = lerp(rcCenter_, rcRight_, t_);
        rcToCenter = lerp(rcLeft_, rcCenter_, t_);
        rcStatic = rcRight_;
        picToSide = picC;
        picToCenter = picL;
        picStatic = picR;
    }

    auto drawRoundedPic = [&](const QPixmap &pm, const QRectF &r) {
        QPainterPath path;
        path.addRoundedRect(r, radius_, radius_);
        painter.save();
        painter.setClipPath(path);
        painter.setClipping(true);

        QPixmap scaledPic = pm.scaled(
            r.size().toSize(),
            Qt::KeepAspectRatioByExpanding,
            Qt::SmoothTransformation
            );
        int x = r.x() + (r.width() - scaledPic.width()) / 2;
        int y = r.y() + (r.height() - scaledPic.height()) / 2;
        painter.drawPixmap(x, y, scaledPic);

        painter.restore();
    };

    if (anim_->state() == QAbstractAnimation::Running) {
        drawRoundedPic(picStatic, rcStatic);
        drawRoundedPic(picToSide, rcToSide);
        drawRoundedPic(picToCenter, rcToCenter);
    } else {
        drawRoundedPic(picL, rcLeft_);
        drawRoundedPic(picR, rcRight_);
        drawRoundedPic(picC, rcCenter_);
    }
}

// 启动动画
void CoverFlowwi::startAnimation()
{
    if (bannerItems_.size() < 3) return;

    const int n = bannerItems_.size();
    int idxC = center_;
    int idxL = (idxC - 1 + n) % n;
    int idxR = (idxC + 1) % n;

    QRectF rcToSide, rcToCenter, rcStatic;
    int idxToSide = idxC;
    int idxToCenter = (dir_ > 0 ? idxR : idxL);
    int idxStatic = (dir_ > 0 ? idxL : idxR);

    if (dir_ > 0) {
        rcToSide = lerp(rcCenter_, rcLeft_, t_);
        rcToCenter = lerp(rcRight_, rcCenter_, t_);
        rcStatic = rcLeft_;
    } else {
        rcToSide = lerp(rcCenter_, rcRight_, t_);
        rcToCenter = lerp(rcLeft_, rcCenter_, t_);
        rcStatic = rcRight_;
    }

    QList<int> needShowIdx;
    if (anim_->state() == QAbstractAnimation::Running) {
        needShowIdx = {idxStatic, idxToSide, idxToCenter};
    } else {
        needShowIdx = {idxL, idxR, idxC};
    }

    // 隐藏不需要的标签
    for (int i = 0; i < labels_.size(); ++i) {
        if (!needShowIdx.contains(i)) {
            labels_[i]->hide();
        }
    }

    // 绘制需要显示的标签
    auto drawRoundedLabel = [&](int idx, const QRectF &r) {
        if (idx >= labels_.size() || idx >= bannerItems_.size()) return;
        FlowLabel *label = labels_[idx];

        if (label->geometry() != r.toRect()) {
            label->setFixedSize(r.size().toSize());
            label->setGeometry(r.toRect());
        }

        QPixmap currentPic = bannerItems_[idx].pic.isNull() ? QPixmap(":/res/head_2.jpg") : bannerItems_[idx].pic;
        if (label->pixmap().cacheKey() != currentPic.cacheKey()) {
            QPixmap scaledPix = currentPic.scaled(
                r.size().toSize(),
                Qt::KeepAspectRatioByExpanding,
                Qt::SmoothTransformation
                );
            label->setPixmap(scaledPix);
        }

        if (label->styleSheet() != QString("border-radius: %1px;").arg(radius_)) {
            label->setStyleSheet(QString("border-radius: %1px;").arg(radius_));
        }
        label->show();
        label->raise();
    };

    for (int idx : needShowIdx) {
        QRectF r;
        if (idx == idxStatic) r = rcStatic;
        else if (idx == idxToSide) r = rcToSide;
        else if (idx == idxToCenter) r = rcToCenter;
        else if (idx == idxL) r = rcLeft_;
        else if (idx == idxR) r = rcRight_;
        else if (idx == idxC) r = rcCenter_;
        drawRoundedLabel(idx, r);
    }
}

// 计算按钮位置
QPoint CoverFlowwi::CalcuBtnPos(bool isLeft)
{
    const int btnSize = 20;
    if (isLeft) {
        return QPoint(LEFT_MARGIN, (scroll_->height() - btnSize) / 2);
    } else {
        return QPoint(scroll_->width() - RIGHT_MARGIN - btnSize, (scroll_->height() - btnSize) / 2);
    }
}

// 更新导航点状态
void CoverFlowwi::UpdateDotState(QPushButton *dot, bool isSelected)
{
    if (!dot) return;
    dot->setProperty("selected", isSelected);

    dot->setStyleSheet(R"(
        QPushButton {
            background-color: black;
            border-radius: 5px;
            border: 1px solid #ddd;
            border-style: solid;
            min-width: 10px;
            min-height: 10px;
            max-width: 10px;
            max-height: 10px;
        }
        QPushButton[selected=true] {
            background-color: red;
            border-color: red;
        }
    )");

    dot->setAttribute(Qt::WA_TranslucentBackground, false);
    dot->style()->unpolish(dot);
    dot->style()->polish(dot);
    dot->update();
}

// 上一张
void CoverFlowwi::prev()
{
    if (bannerItems_.size() <= 1 || animState_ != AnimIdle) return;
    animState_ = AnimRunning;
    targetIdx_ = (center_ - 1 + bannerItems_.size()) % bannerItems_.size();
    remainingSteps_ = 1;
    dir_ = -1;

    anim_->stop();
    anim_->setStartValue(0.0);
    anim_->setEndValue(1.0);
    anim_->start();

    timer_.stop();
    timer_.start();
}

// 下一张
void CoverFlowwi::next()
{
    if (bannerItems_.size() <= 1 || animState_ != AnimIdle) return;
    animState_ = AnimRunning;
    targetIdx_ = (center_ + 1) % bannerItems_.size();
    remainingSteps_ = 1;
    dir_ = 1;

    anim_->stop();
    anim_->setStartValue(0.0);
    anim_->setEndValue(1.0);
    anim_->start();

    timer_.stop();
    timer_.start();
}

// 窗口缩放事件
void CoverFlowwi::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    updateRects();
    btnPrev_->move(CalcuBtnPos(true));
    btnNext_->move(CalcuBtnPos(false));
    startAnimation();
    update();
}
