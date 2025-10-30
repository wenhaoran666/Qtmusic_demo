#include "listmusicitemwi.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "ui_listmusicitemwi.h"

Listmusicitemwi::Listmusicitemwi(const MusicInfo &musicInfo, QWidget *parent)
    : QWidget(parent),m_index(0), m_musicInfo(musicInfo)
    , ui(new Ui::Listmusicitemwi)
{
    ui->setupUi(this);
    ui->widgetMusicItem_wi->installEventFilter(this);//安装
    //显示信息
    ui->songname_lb->setText(musicInfo.gettitle());
    ui->composer_lb->setText(musicInfo.getcomposer());
    //  调用封装函数给 icon_lb 设置圆角图片
    setRoundedPixmap(ui->icon_lb, musicInfo.getm_image(), 8);


    qint64 durationMs=musicInfo.getduration();
    qint64 totalSeconds = durationMs / 1000;           // 转为总秒数

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    // 格式化为 "分:秒"，比如 "1:30" 或更整齐的 "01:30"（补零）
    QString timeStr = QString("%1:%2")
                          .arg(minutes)
                          .arg(seconds, 2, 10, QLatin1Char('0'));  // 秒数固定两位，不足补零
    ui->duration_lb->setText(timeStr);;
}

Listmusicitemwi::~Listmusicitemwi()
{
    delete ui;
}

void Listmusicitemwi::setindex(int index)
{
    ui->index_btn->setText(QString::number(index));
    m_index=index;
}

void Listmusicitemwi::setnowplay()
{
    ui->widgetMusicItem_wi->setStyleSheet(
   "#widgetMusicItem_wi {"
   "border-radius: 15px;"
   "background-color: #ffffff;"
   "border: 1px solid #cccccc;}"
        );
    ui->index_btn->show();                   // 确保按钮可见
    ui->index_btn->setEnabled(false);         // 不可点击
    ui->index_btn->setText("");
    ui->index_btn->setStyleSheet(
        "QPushButton {"
        "   background-color: #8b949e;"
        "background-image: url(:/res/viewswitch/nowplay1.png);"
        "background-repeat: no-repeat;"
        "background-position: center center;"
        "background-color: transparent;"
        "}"
        );

    ui->songname_lb->setStyleSheet(
    " color: #fc3b5b;"
    "font-size: 21px;"
    "font-family: \"Microsoft YaHei\";"
    "font-weight: normal;"
    "background-color: transparent;");
    ui->composer_lb->setStyleSheet(
        " color: #fc3b5b;"
        "font-size: 20px;"
        "font-family: \"Microsoft YaHei\";"
        "font-weight: normal;"
        "background-color: transparent;");


    ui->widgetMusicItem_wi->removeEventFilter(this);//取消事件过滤器
}

void Listmusicitemwi::setnormal()
{
    ui->widgetMusicItem_wi->setStyleSheet(
"#widgetMusicItem_wi {"
    "border-radius: 15px;}"
"#widgetMusicItem_wi:hover{"
"background-color: #ffffff;"
"border: 1px solid #cccccc;}"
  );
    ui->songname_lb->setStyleSheet(
        " color: #283248;"
        "font-size: 21px;"
        "font-family: \"Microsoft YaHei\";"
        "font-weight: normal;"
        "background-color: transparent;");
    ui->composer_lb->setStyleSheet(
        " color: #8b949e;"
        "font-size: 20px;"
        "font-family: \"Microsoft YaHei\";"
        "font-weight: normal;"
        "background-color: transparent;");
    ui->index_btn->setStyleSheet(
        "QPushButton {"
        "color: #8b949e;"
        "font-size: 20px;"
        "font-family: \"Microsoft YaHei\";"
        "font-weight: 500;"
        "background-color: transparent;"
        "}"
        );
     ui->index_btn->setText(QString::number(m_index));
    ui->widgetMusicItem_wi->installEventFilter(this);//安装
}

void Listmusicitemwi::setRoundedPixmap(QLabel *label, const QPixmap &sourcePix, int radius)
{
    if (!label || sourcePix.isNull()) {
        return; // 标签为空或图片无效，直接返回
    }

    // 1. 缩放图片：适应标签大小，保持比例
    QPixmap scaledPix = sourcePix.scaled(
        label->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );

    // 2. 创建透明画布（避免圆角外有底色）
    QPixmap roundedPix(label->size());
    roundedPix.fill(Qt::transparent);

    // 3. 绘制圆角图片
    QPainter painter(&roundedPix);
    painter.setRenderHint(QPainter::Antialiasing);       // 抗锯齿（圆角平滑）
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // 图片缩放平滑

    // 圆角裁剪路径（与标签大小一致）
    QPainterPath clipPath;
    clipPath.addRoundedRect(roundedPix.rect(), radius, radius);
    painter.setClipPath(clipPath); // 只显示圆角内的内容

    // 4. 居中绘制图片
    QPoint drawPos(
        (roundedPix.width() - scaledPix.width()) / 2,
        (roundedPix.height() - scaledPix.height()) / 2
        );
    painter.drawPixmap(drawPos, scaledPix);

    // 5. 设置到标签
    label->setPixmap(roundedPix);
}


void Listmusicitemwi::on_index_btn_clicked()
{
     emit Play(m_musicInfo);

}

bool Listmusicitemwi::eventFilter(QObject *watched, QEvent *event)
{
    //鼠标进入,索引按钮变为播放按钮,更多按钮可见
    if (watched == ui->widgetMusicItem_wi) {
        if (event->type() == QEvent::Enter)
        {
            // 鼠标进入：隐藏序号，显示为按钮，并设置样式
            ui->index_btn->show();                   // 确保按钮可见
            ui->index_btn->setEnabled(true);         // 确保可点击
            ui->index_btn->setText("");
            ui->index_btn->setStyleSheet(
                "QPushButton {"
                "   background-color: #8b949e;"
                "background-image: url(:/res/viewswitch/play1.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "background-color: transparent;"                // 鼠标悬停颜色
                "}"
                "QPushButton:hover {"
                "   background-color: #8b949e;"
                "background-image: url(:/res/viewswitch/play2.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "background-color: transparent;"                  // 鼠标悬停颜色
                "}"
                "QPushButton:pressed {"
                "   background-color: #8b949e;"
                "background-image: url(:/res/viewswitch/play1.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "background-color: transparent;"                  // 按下时颜色
                "}"
                );

        }
        else if (event->type() == QEvent::Leave)
        {
            // 鼠标离开：恢复显示序号样式（比如显示数字，去掉按钮样式）
            ui->index_btn->setText(QString::number(m_index));
            ui->index_btn->setStyleSheet("color: #8b949e; "
                                         "font-size: 20px; "
                                         "font-family: \"Microsoft YaHei\"; "
                                         "font-weight: normal; "
                                         "background-color: transparent;"
                                         );

        }
    }

    // 其他控件的事件过滤交给基类处理
    return QWidget::eventFilter(watched, event);
}
