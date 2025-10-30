#ifndef RECORDWI_H
#define RECORDWI_H

#include <QWidget>
#include <QTimer>

class RecordWi : public QWidget
{
    Q_OBJECT

public:
    explicit RecordWi(QWidget *parent = nullptr);

    // 暂停旋转动画
    void pause();
    void swipic(const QPixmap &pixmap);//切换唱片图片
    // 继续旋转动画
    void resume();
    //重置图片
    void clearPic();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    int rotationAngle;
    bool isPaused;
    QPixmap recordTexture;  // 新增：用于旋转的图片
};

#endif // RECORDWI_H
