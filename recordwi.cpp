#include "recordwi.h"
#include "qdebug.h"
#include "qpainterpath.h"
#include <QPainter>
#include <QApplication>

RecordWi::RecordWi(QWidget *parent)
    : QWidget(parent), rotationAngle(0), isPaused(true)
{
    timer = new QTimer(this);
    timer->stop();  // 停止定时器，不再触发旋转
    connect(timer, &QTimer::timeout, this, [this]() {
        if (!isPaused) {
            rotationAngle = (rotationAngle + 1) % 360;// 每次旋转5度
            update();
        }
    });


}
// 取消当前图片，重置状态
void RecordWi::clearPic()
{
    // 1. 清空图片
    recordTexture = QPixmap(); // 赋值为空 pixmap

    // 2. 停止旋转并重置角度
    pause(); // 调用已有的 pause 函数停止定时器
    rotationAngle = 0; // 重置旋转角度为 0

    // 3. 触发重绘（清除当前显示）
    update();

    qDebug() << u8"图片已取消，重置唱片状态";
}
void RecordWi::pause()
{
    isPaused = true;
     timer->stop();  // 停止定时器，不再触发旋转
}

void RecordWi::swipic(const QPixmap &pixmap)
{
    recordTexture = pixmap;
    update();  // 触发重绘，显示新图片
}

void RecordWi::resume()
{
    isPaused = false;
    timer->start(100);//每隔 100 毫秒触发一次
}

void RecordWi::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // 确保图片缩放平滑

    // 使用稍小的直径，使唱片不完全紧贴窗口边缘
    int diameter = qMin(width(), height()) - 10;
    int radius = diameter / 2;
    painter.translate(width() / 2, height() / 2); // 坐标原点移至中心
    painter.rotate(rotationAngle);

    // 1. 绘制黑胶唱片外圈（黑色背景）
    painter.setBrush(Qt::black);
    painter.drawEllipse(-radius, -radius, diameter, diameter);

    // 2. 绘制旋转的圆形图片（核心：添加圆形裁剪）
    if (!recordTexture.isNull()) {
        int textureSize = diameter * 0.75;  // 图片大小设为唱片直径的90%
        int texRadius = textureSize / 2;

        // 缩放图片（保持比例，平滑缩放）
        QPixmap scaledTex = recordTexture.scaled(textureSize, textureSize,
                                                 Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // 关键：设置圆形剪辑路径（只显示圆形区域内的图片）
        QPainterPath clipPath;
        clipPath.addEllipse(-texRadius, -texRadius, textureSize, textureSize); // 圆形路径
        painter.setClipPath(clipPath); // 应用剪辑

        // 绘制图片（超出圆形的部分会被裁剪）
        painter.drawPixmap(-texRadius, -texRadius, scaledTex);

        // 清除剪辑路径（避免影响后续绘图，可选）
        painter.setClipping(false);
    } else {
        isPaused = true;
    }

}

