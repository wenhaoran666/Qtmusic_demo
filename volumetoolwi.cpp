#include "volumetoolwi.h"
#include "qgraphicseffect.h"
#include "ui_volumetoolwi.h"

VolumeToolwi::VolumeToolwi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeToolwi)
{
    ui->setupUi(this);
    //表示它是一个工具窗口
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
setAttribute(Qt::WA_TranslucentBackground); // 窗口背景透明
    //设置阴影
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(Qt::black);
    effect->setOffset(0, 0); // 0偏移。这个不设置会有点偏, 立体感?
    effect->setBlurRadius(3);
    setGraphicsEffect(effect);

    //设置范围
    ui->slider->setRange(0, 100);
    ui->slider->setValue(50);      // 默认音量 50%

     //监听实时滑动条的值变化
    connect(ui->slider, &QSlider::valueChanged, this, [this](int pos) {
        // 设置标签显示当前音量，格式为 "50%"
        ui->volum_lb->setText(QString::number(pos) + "%");
         emit volumesize(pos);  // 发送当前音量值（0~100）
    });

}

VolumeToolwi::~VolumeToolwi()
{
    delete ui;
}
