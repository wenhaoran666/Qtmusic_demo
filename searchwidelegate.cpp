#include "searchwidelegate.h"
#include "basemusicmodel.h"
#include "qdebug.h"
#include "qevent.h"
#include "qpainterpath.h"
#include <QPixmap>
#include <QFontMetrics>
#include <QApplication>
#include <QPainter>
#include <QStyle>
// 播放按钮图片路径（替换为你的实际路径）
const QString PLAY_BTN_NORMAL_PATH = ":/res/viewswitch/Play2.2.png";
const QString PLAY_BTN_HOVER_PATH = ":/res/viewswitch/Play2.2.png";
// 爱心按钮图片路径（替换为实际资源）
const QString LIKE_NORMAL = ":/res/viewswitch/like1.png";         // 未选中+未悬浮
const QString LIKE_NORMAL_HOVER = ":/res/viewswitch/like2.png"; // 未选中+悬浮
const QString LIKE_SELECTED = ":/res/viewswitch/like3.png";     // 选中+未悬浮
const QString LIKE_SELECTED_HOVER = ":/res/viewswitch/like4.png"; // 选中+悬浮

SearchwiDelegate::SearchwiDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    // 预加载图片资源
    m_playBtnNormal.load(PLAY_BTN_NORMAL_PATH);
    m_playBtnHover.load(PLAY_BTN_HOVER_PATH);

    // 检查图片加载状态
    if (m_playBtnNormal.isNull()) {
        qWarning() << u8"播放按钮图片加载失败：" << PLAY_BTN_NORMAL_PATH;
    }
    if (m_playBtnHover.isNull()) {
        qWarning() << u8"悬停按钮图片加载失败：" << PLAY_BTN_HOVER_PATH;
    }
    // 加载四种爱心图片
    m_likeNormal.load(LIKE_NORMAL);
    m_likeNormalHover.load(LIKE_NORMAL_HOVER);
    m_likeSelected.load(LIKE_SELECTED);
    m_likeSelectedHover.load(LIKE_SELECTED_HOVER);

    // 检查图片加载状态
    if (m_likeNormal.isNull()) qWarning() << "未选中+未悬浮图片加载失败";
    if (m_likeNormalHover.isNull()) qWarning() << "未选中+悬浮图片加载失败";
    if (m_likeSelected.isNull()) qWarning() << "选中+未悬浮图片加载失败";
    if (m_likeSelectedHover.isNull()) qWarning() << "选中+悬浮图片加载失败";

}

QSize SearchwiDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    // 高度 = 内容高度 + 上下margin（m_margin*2）
    return QSize(0, m_itemHeight + m_margin * 2);
}

void SearchwiDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setRenderHint(QPainter::Antialiasing); // 新增：圆角抗锯齿

    // 1. 绘制背景（实现样式表效果）
    drawBackground(painter, option, index);

    // 2. 计算内容区域（扣除margin和padding）
    QRect contentRect = option.rect.adjusted(
        m_margin + m_padding,  // 左：margin + padding
        m_margin + m_padding,  // 上：margin + padding
        -(m_margin + m_padding), // 右：margin + padding
        -(m_margin + m_padding)  // 下：margin + padding
        );
    // 3. 绘制播放按钮（调用封装的函数）
    drawPlayButton(painter, option, contentRect);
    // 绘制爱心按钮（始终显示，根据状态切换图片）
    drawLikeButton(painter, option, contentRect, index);

    // 4. 绘制内容（使用调整后的contentRect，避免内容超出圆角范围）
    drawCover(painter, contentRect, index);
    drawTextInfo(painter, contentRect, index);
    drawDuration(painter, contentRect, index);

    painter->restore();
}

bool SearchwiDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
        // 1. 计算内容区域（统一用于播放按钮和爱心按钮的区域判断）
        QRect contentRect = option.rect.adjusted(
            m_margin + m_padding,
            m_margin + m_padding,
            -(m_margin + m_padding),
            -(m_margin + m_padding)
            );

        // 2. 处理鼠标释放事件（点击交互的核心）
        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() != Qt::LeftButton) {
                return false; // 只响应左键点击
            }

            // 3. 判断是否点击播放按钮
            QRect playBtnRect = getPlayButtonRect(contentRect);
            if (playBtnRect.contains(mouseEvent->pos())) {
                qDebug()<<u8"点击播放按钮";
                emit playButtonClicked(index);
                return true; // 处理后返回，避免触发其他逻辑
            }

            // 4. 判断是否点击爱心按钮
            QRect likeBtnRect = getLikeButtonRect(contentRect);
            if (likeBtnRect.contains(mouseEvent->pos())) {

                // 切换收藏状态（取反）
                bool currentLiked = index.data(BaseMusicModel::IsLikedRole).toBool();
                bool newLiked = !currentLiked;
                if(newLiked)
                qDebug()<<u8"选中爱心";
                else
                    qDebug()<<u8"取消爱心";
                // 更新模型中的状态（触发视图重绘）
                if (BaseMusicModel *musicModel = static_cast<BaseMusicModel*>(model))
                {
                    //通过 setLikedState 函数将新状态写入模型
                    musicModel->setLikedState(index.row(), newLiked);
                }
                return true; // 处理后返回
            }
        }

        // 5. 其他事件（如鼠标移动、按下等）不处理
        return false;

}

// 封装：绘制播放按钮（使用图片）
void SearchwiDelegate::drawPlayButton(QPainter *painter, const QStyleOptionViewItem &option, const QRect &contentRect) const
{
    // 判断当前项是否被鼠标悬浮（核心逻辑）
    bool isHovered = option.state & QStyle::State_MouseOver;
    if (!isHovered) {
        return; // 未悬浮时直接返回，不绘制按钮
    }

    // 悬浮状态下才绘制按钮
    QRect playBtnRect = getPlayButtonRect(contentRect);
    const QPixmap &currentPixmap = m_playBtnNormal;

    if (currentPixmap.isNull()) {
        // 图片加载失败时的默认占位符（仅悬浮时显示）
        painter->fillRect(playBtnRect, QColor("#dddddd"));
        painter->setPen(QColor("#999999"));
        painter->drawText(playBtnRect, Qt::AlignCenter, u8"播");
    } else {
        painter->drawPixmap(playBtnRect, currentPixmap.scaled(
                                             playBtnRect.size(),
                                             Qt::KeepAspectRatio,
                                             Qt::SmoothTransformation
                                             ));
    }
}

// 封装：计算播放按钮区域（统一用于绘制和点击判断）
QRect SearchwiDelegate::getPlayButtonRect(const QRect &contentRect) const
{
    int btnX = contentRect.left() + PLAY_BTN_LEFT_OFFSET+20;
    int btnY = contentRect.top() + (contentRect.height() - PLAY_BTN_SIZE) / 2;
    return QRect(btnX, btnY, PLAY_BTN_SIZE, PLAY_BTN_SIZE);
}
// 新增：绘制爱心按钮
void SearchwiDelegate::drawLikeButton(QPainter *painter, const QStyleOptionViewItem &option,
                                      const QRect &contentRect, const QModelIndex &index) const
{
    // 1. 获取按钮区域
    QRect likeBtnRect = getLikeButtonRect(contentRect);

    // 2. 获取两个关键状态
    bool isLiked = index.data(BaseMusicModel::IsLikedRole).toBool(); // 选中状态（来自模型）
    bool isSelected = option.state & QStyle::State_Selected; // 项是否被选中（如鼠标点击选中）
    bool isHovered = option.state & QStyle::State_MouseOver; // 鼠标是否悬浮

    // 3. 核心判断：选中项 或 悬浮项，均使用悬浮样式
    bool useHoverStyle = isSelected || isHovered;
    // 3. 根据状态组合选择对应图片
    const QPixmap *currentPixmap = nullptr;
    if (useHoverStyle) {
        // 项选中或悬浮状态：区分喜欢/非喜欢
        currentPixmap = isLiked ? &m_likeSelectedHover : &m_likeNormalHover;
    } else {
        // 项未选中状态：区分喜欢/非喜欢
        currentPixmap = isLiked ? &m_likeSelected : &m_likeNormal;
    }

    // 4. 绘制图片（容错处理：图片加载失败时用文字替代）
    if (!currentPixmap || currentPixmap->isNull()) {
        // 文字替代方案（可选，确保界面不空白）
        painter->setPen(isLiked ? QColor("#ff4444") : QColor("#999999"));
        QString text = isLiked ? u8"♥" : u8"♡";
        // 悬浮时加粗区分
        // QFont font = painter->font();
        // font.setBold(useHoverStyle);
        // painter->setFont(font);
        // painter->drawText(likeBtnRect, Qt::AlignCenter, text);
    } else {
        // 绘制对应状态的图片
        painter->drawPixmap(likeBtnRect, currentPixmap->scaled(
                                             likeBtnRect.size(),
                                             Qt::KeepAspectRatio,
                                             Qt::SmoothTransformation
                                             ));
    }
}

// 新增：计算爱心按钮区域（固定在右侧）
QRect SearchwiDelegate::getLikeButtonRect(const QRect &contentRect) const
{
    // 固定在项右侧：右边界 - 偏移量 - 按钮大小
    int btnX = contentRect.right() - LIKE_BTN_RIGHT_OFFSET - LIKE_BTN_SIZE+800;
    int btnY = contentRect.top() + (contentRect.height() - LIKE_BTN_SIZE) / 2; // 垂直居中
    return QRect(btnX, btnY, LIKE_BTN_SIZE, LIKE_BTN_SIZE);
}


// 新增：绘制背景（实现圆角、边距、状态色）
void SearchwiDelegate::drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    // 背景区域：扣除margin（item之间的间隙）
    QRect bgRect = option.rect.adjusted(
        m_margin,
        m_margin,
        -m_margin,
        -m_margin
        );

    // 根据状态设置背景色
    QColor bgColor;
    if (option.state & QStyle::State_Selected) {
        bgColor = QColor("#ffffff"); // 选中状态
    } else if (option.state & QStyle::State_MouseOver) {
        bgColor = QColor("#ffffff"); // 悬停状态
    } else {
        bgColor = QColor("#f7f9fc"); // 默认状态
    }

    // 绘制圆角背景
    painter->setBrush(bgColor);
    painter->setPen(Qt::NoPen); // 无边框
    painter->drawRoundedRect(bgRect, m_borderRadius, m_borderRadius);
}

void SearchwiDelegate::drawCover(QPainter *painter, const QRect &rect, const QModelIndex &index) const
{
    // 封面位置：基于内容区域（已扣除margin和padding）
    int x = rect.left() + 120; // 左侧额外留10px间距
    int y = rect.top() + (rect.height() - m_coverSize) / 2;
    QRect coverRect(x, y, m_coverSize, m_coverSize);

    QPixmap cover = index.data(BaseMusicModel::CoverRole).value<QPixmap>();
    if (cover.isNull()) {
        cover = QPixmap(":/res/head_2.jpg");
    }

    // 缩放封面至目标尺寸（保持比例和清晰度）
    QPixmap scaledCover = cover.scaled(
        coverRect.size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );

    // --------------------------
    // 绘制圆角封面核心逻辑
    // --------------------------
    painter->save();

    // 1. 创建圆角路径作为遮罩
    QPainterPath path;
    int radius = 8; // 圆角半径（可根据需要调整，如8px）
    path.addRoundedRect(coverRect, radius, radius);

    // 2. 将路径设为裁剪区域（超出路径的内容不显示）
    painter->setClipPath(path);

    // 3. 在裁剪区域内绘制封面（自动适配圆角）
    painter->drawPixmap(coverRect, scaledCover);

    // 4. 可选：绘制边框（增强圆角视觉效果）
    painter->setPen(QPen(QColor("#EEEEEE"), 1)); // 浅灰色边框，1px宽
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(coverRect, radius, radius);

    painter->restore();
}
void SearchwiDelegate::drawTextInfo(QPainter *painter, const QRect &rect, const QModelIndex &index) const
{
    // 文本起始X：封面右侧 + 15px间距
    int textLeft = rect.left() + m_coverSize + 140;
    // 获取当前项的总高度（用于垂直居中计算）
    int itemTotalHeight = rect.height();

    // --------------------------
    // 计算文本区域总高度（根据字体大小动态计算）
    // --------------------------
    // 标题字体（20pt，加粗）
    QFont titleFont = painter->font();
    titleFont.setBold(true);
    titleFont.setPointSize(12);
    QFontMetrics titleFm(titleFont);
    int titleHeight = titleFm.height(); // 标题实际高度（含上下间距）

    // 专辑字体（14pt，常规）
    QFont albumFont = painter->font();
    albumFont.setPointSize(12);
    QFontMetrics albumFm(albumFont);

    // 歌手字体（16pt，常规）
    QFont artistFont = painter->font();
    artistFont.setPointSize(11);
    QFontMetrics artistFm(artistFont);
    int artistHeight = artistFm.height(); // 歌手实际高度（含上下间距）

    // 文本区域总高度 = 标题高度 + 歌手高度 + 中间间距（10px）
    int textTotalHeight = titleHeight + artistHeight + 10;

    // 计算文本区域垂直居中的起始Y坐标
    int textStartY = rect.top() + (itemTotalHeight - textTotalHeight) / 2;


    // --------------------------
    // 1. 绘制标题（左侧，宽度写死）
    // --------------------------
    QString title = index.data(BaseMusicModel::TitleRole).toString();
    painter->setFont(titleFont);
    painter->setPen(QColor("#333333"));

    // 标题宽度写死为400px
    const int titleWidth = 400;
    QString elidedTitle = titleFm.elidedText(title, Qt::ElideRight, titleWidth);
    QRect titleRect(textLeft, textStartY, titleWidth, titleHeight);
    painter->drawText(titleRect, Qt::AlignLeft | Qt::AlignVCenter, elidedTitle);


    // --------------------------
    // 2. 绘制专辑（标题右侧，起始X和宽度写死）
    // --------------------------
    QString album = index.data(BaseMusicModel::AlbumRole).toString();
    if (!album.isEmpty()) {
        painter->setFont(albumFont);
        painter->setPen(QColor("#999999"));

        // 专辑起始X写死（标题左侧+标题宽度+固定间距）
        const int albumX = textLeft + titleWidth + 20; // 固定间距20px
        const int albumWidth = 300; // 专辑宽度写死200px
        QRect albumRect(albumX, textStartY, albumWidth, titleHeight);
        QString elidedAlbum = albumFm.elidedText(album, Qt::ElideRight, albumWidth);
        painter->drawText(albumRect, Qt::AlignLeft | Qt::AlignVCenter, elidedAlbum);
    }


    // --------------------------
    // 3. 绘制歌手（标题正下方，宽度写死）
    // --------------------------
    QString artist = index.data(BaseMusicModel::ArtistRole).toString();
    if (!artist.isEmpty()) {
        painter->setFont(artistFont);
        painter->setPen(QColor("#666666"));

        // 歌手Y坐标：标题起始Y + 标题高度 + 固定间距10px
        int artistY = textStartY + titleHeight + 10;
        const int artistWidth = 800; // 歌手宽度写死800px
        QRect artistRect(textLeft, artistY, artistWidth, artistHeight);
        QString elidedArtist = artistFm.elidedText(artist, Qt::ElideRight, artistWidth);
        painter->drawText(artistRect, Qt::AlignLeft | Qt::AlignVCenter, artist);
    }

}

void SearchwiDelegate::drawDuration(QPainter *painter, const QRect &rect, const QModelIndex &index) const
{

    // 1. 获取时长（DurationRole 为毫秒保留 /1000）
     qint64 durationSeconds = index.data(BaseMusicModel::DurationRole).toLongLong() / 1000;
    // 2. 格式化时长为 "mm:ss"（补零处理）
    int minutes = durationSeconds / 60;
    int seconds = durationSeconds % 60;
    QString timeStr = QString("%1:%2")
                          .arg(minutes, 2, 10, QLatin1Char('0'))  // 分钟补零（如 1→01）
                          .arg(seconds, 2, 10, QLatin1Char('0')); // 秒数补零

    // 3. 设置绘制样式
    painter->setPen(QColor("#999999"));
    painter->setFont(QFont("SimHei", 12)); // 可选：设置字体，避免中文乱码

    // 4. 计算绘制位置（基于item的rect，靠右显示，垂直居中）
    // 右侧留出 10px 边距，高度与item一致（垂直居中）
    QRect durationRect = rect.adjusted(0, 0, -60, 0); // 右边界缩进10px

    // 5. 绘制文本（靠右+垂直居中）
    painter->drawText(durationRect, Qt::AlignRight | Qt::AlignVCenter, timeStr);
}
