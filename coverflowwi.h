#ifndef CoverFlowwi_H
#define CoverFlowwi_H
#include "qpainterpath.h"
#include<QTimer>
#include"musicmanager.h"
#include <QVariantAnimation>
#include<QPushButton>
#include<QPainter>
#include"bannerinfo.h"
QT_BEGIN_NAMESPACE

// 自定义标签类：新增点击信号，传递songId（用于后续播放）
class FlowLabel : public QWidget
{
    Q_OBJECT
public:
    explicit FlowLabel(QWidget *parent = nullptr) : QWidget(parent), m_songId(0) {}

    void setPixmap(const QPixmap &pix) { m_pixmap = pix; update(); }
    QPixmap pixmap() const { return m_pixmap; }
    // 新增：设置当前标签对应的songId
    void setSongId(qint64 songId) { m_songId = songId; }
    qint64 songId() const { return m_songId; }

signals:
    // 新增：点击标签时发送songId信号
    void clicked(qint64 songId);

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        if (m_pixmap.isNull()) return;

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

        // 绘制圆角裁剪
        QPainterPath path;
        path.addRoundedRect(rect(), 10, 10);
        painter.setClipPath(path);

        // 绘制图片（保持宽高比）
        painter.drawPixmap(rect(), m_pixmap.scaled(
                                       rect().size(),
                                       Qt::KeepAspectRatioByExpanding,
                                       Qt::SmoothTransformation
                                       ));
    }
    // 新增：鼠标点击事件，触发clicked信号
    void mousePressEvent(QMouseEvent *event) override {
        Q_UNUSED(event);
        //存在时间问题
        // 只请求详情，URL请求在详情回调中触发
        HttpMgr::GetInstance()->getMusicdetail(QString::number(m_songId), Modules::MODULE_RECOMMEND);

    }

private:
    QPixmap m_pixmap;
    qint64 m_songId; // 新增：关联Bannerinfo的songId
};

// 自定义圆形按钮类：无修改
class CircleDot : public QPushButton {
    Q_OBJECT
public:
    explicit CircleDot(QWidget *parent = nullptr) : QPushButton(parent) {
        setFixedSize(10, 10);
        setCursor(Qt::PointingHandCursor);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        bool selected = property("selected").toBool();
        painter.setBrush(selected ? QColor("red") : QColor("black"));
        painter.setPen(QPen(selected ? QColor("red") : QColor("#ddd"), 1));

        painter.drawEllipse(rect().adjusted(1, 1, -1, -1));
    }
};
namespace Ui {
class CoverFlowwi;
}
QT_END_NAMESPACE

class CoverFlowwi : public QWidget
{
    Q_OBJECT

public:
    CoverFlowwi(QWidget *parent = nullptr);
    // 新增：从MusicManager加载Bannerinfo列表（核心接口）
    void loadBannerFromManager();
    // 新增：更新单个Banner的图片（图片下载完成后调用）
    void updateBannerPic(qint64 songId, const QPixmap &pic);
     void UpdateDotState(QPushButton *dot, bool isSelected); // 更新导航点状态
signals:
    // 新增：Banner点击信号，传递songId给MainWidget播放
    void bannerClicked(qint64 songId);

private slots:
    void prev();
    void next();
    void startAnimation();
    // 新增：导航点点击，切换到对应Banner
    void onDotClicked(int index);
    // 新增：处理FlowLabel点击，转发songId信号
    void onLabelClicked(qint64 songId);

private:
    void BuildUI();
    void InitAnim();
    void updateRects();//调整中心图片大小
    QPoint CalcuBtnPos(bool isLeft);
    QRectF lerp(const QRectF &a, const QRectF &b, qreal t) const;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    // 新增：根据当前中心索引更新导航点状态
    void updateAllDotState();
    // 新增：获取当前索引对应的Bannerinfo（处理循环）
    Bannerinfo getCurrentBanner(int offset = 0);

private:
    enum AnimState { AnimIdle, AnimRunning };
    AnimState animState_ = AnimIdle;
    int remainingSteps_ = 0;
    int targetIdx_ = -1;

    // UI组件：无修改
    QWidget *scroll_;
    QWidget *dotBar_;
    QPushButton *btnPrev_;
    QPushButton *btnNext_;

    // 数据与状态：替换slides_为bannerItems_，删除冗余测试列表
    QList<Bannerinfo> bannerItems_; // 存储从MusicManager获取的Bannerinfo
    QList<FlowLabel*> labels_;      // 每个标签对应一个Bannerinfo
    QList<QPushButton*> dots_;      // 每个导航点对应一个Bannerinfo

    // 布局参数：无修改
    QRectF rcCenter_;
    QRectF rcLeft_;
    QRectF rcRight_;
    QSizeF szCenter_;
    QSizeF szSide_;
    const int margin_ = 20;
    const int LEFT_MARGIN = 50;
    const int RIGHT_MARGIN = 50;
    const int radius_ = 20;

    // 动画参数：无修改
    QVariantAnimation *anim_;
    QTimer timer_;
    qreal t_ = 0.0;
    int center_ = 0; // 当前中心Banner的索引（对应bannerItems_）
    int dir_ = 1;
    bool hovering_ = false;
};

#endif // CoverFlowwi_H
