#include "songlistcardwi.h"
#include "qdebug.h"
#include "qevent.h"
#include "qgraphicseffect.h"
#include "qpainter.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

SongListCardwi::SongListCardwi(QWidget *parent)
    : QWidget(parent)
{
    // 1. 基础设置（固定尺寸+透明背景）
    setFixedSize(210, 288); // 固定尺寸210x288
    setStyleSheet("background: transparent;"); // 窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground); // 启用透明背景属性
    // 设置鼠标指针为手型，提示可点击
    setCursor(Qt::PointingHandCursor);
}
void SongListCardwi::setinfo(SongListInfo &info)
{
    m_info=info;
    setText(m_info.songlistname);
    update();
}
void SongListCardwi::setPixmap(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
    update();
}

void SongListCardwi::setText(const QString &text)
{
    m_text = text;
    update();
}

void SongListCardwi::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true); // 图片平滑缩放

    // 3. 绘制圆角窗口（核心：裁剪为圆角）
    QPainterPath path;
    // 设置圆角矩形路径（左上角x, 左上角y, 宽度, 高度, 圆角x半径, 圆角y半径）
    path.addRoundedRect(rect(), 12, 12); // 12px圆角，可根据需要调整
    painter.setClipPath(path); // 按圆角路径裁剪，超出部分不显示

    // 4. 绘制图片（填满圆角窗口，无空白）
    if (!m_pixmap.isNull()) {
        // 按比例放大图片，确保填满窗口（超出部分被圆角裁剪）
        QPixmap scaledPix = m_pixmap.scaled(
            size(),
            Qt::KeepAspectRatioByExpanding, // 按比例放大到至少填满窗口
            Qt::SmoothTransformation
            );
        // 居中裁剪图片（保留中间区域，消除空白）
        int x = (scaledPix.width() - width()) / 2;
        int y = (scaledPix.height() - height()) / 2;
        painter.drawPixmap(0, 0, scaledPix, x, y, width(), height());
    }

    // 5. 绘制带模糊背景的文字（在圆角区域内）
    if (!m_text.isEmpty()) {
        int textAreaHeight = 70;
        int textAreaY = height() - textAreaHeight;

        // 绘制半透明黑色背景（带圆角）
        QImage tempImg(size(), QImage::Format_ARGB32);
        tempImg.fill(Qt::transparent);
        QPainter tempPainter(&tempImg);
        tempPainter.setRenderHint(QPainter::Antialiasing, true);
        QRect textRect(0, textAreaY, width(), textAreaHeight);
        QPainterPath textPath;
        textPath.addRoundedRect(textRect, 8, 8); // 文字区域圆角
        tempPainter.fillPath(textPath, QColor(0, 0, 0, 150)); // 半透明黑色

        // 应用模糊效果
        QPixmap tempPix = QPixmap::fromImage(tempImg);
        QGraphicsScene scene;
        QGraphicsPixmapItem item(tempPix);
        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(6);
        item.setGraphicsEffect(blur);
        scene.addItem(&item);

        // 渲染模糊背景
        QPixmap blurredPix(width(), height());
        blurredPix.fill(Qt::transparent);
        QPainter blurredPainter(&blurredPix);
        scene.render(&blurredPainter);
        painter.drawPixmap(0, 0, blurredPix);

        // 绘制文字
        // 绘制文字（设置指定字体样式）
        QFont font("Microsoft YaHei", 10, QFont::Normal); // 字体家族、大小、正常粗细
        painter.setFont(font);
        painter.setPen(Qt::white);
        painter.drawText(
            textRect.adjusted(5, 5, -5, -5),
            Qt::AlignCenter | Qt::TextWordWrap,
            m_text
            );

        delete blur;
    }
}
// 鼠标点击事件实现
void SongListCardwi::mousePressEvent(QMouseEvent *event)
{
    // 只处理左键点击
    if (event->button() == Qt::LeftButton) {
        emit clicked(m_info); // 发射点击信号，携带歌单ID
        qDebug() << u8"歌单卡片被点击，ID：" << m_info.songlistid;
    }
    // 传递事件给父类处理（确保正常的事件传递）
    QWidget::mousePressEvent(event);
}
SongListCardwi::~SongListCardwi()
{
}


