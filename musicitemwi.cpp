#include "musicitemwi.h"
#include "ui_musicitemwi.h"


MusicItemwi::MusicItemwi(const MusicInfo &musicInfo, QWidget *parent): QWidget(parent)
    ,m_index(0), m_musicInfo(musicInfo)
    , ui(new Ui::MusicItemwi)
{
    ui->setupUi(this);
    ui->widgetMusicItem_wi->installEventFilter(this);//安装
    //显示信息
    ui->songname_lb->setText(musicInfo.gettitle());
    ui->composer_lb->setText(musicInfo.getcomposer());
    ui->album_lb->setText(musicInfo.getalbum());

    qint64 durationMs=musicInfo.getduration();
        qint64 totalSeconds = durationMs / 1000;           // 转为总秒数

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    // 格式化为 "分:秒"，比如 "1:30" 或更整齐的 "01:30"（补零）
    QString timeStr = QString("%1:%2")
                          .arg(minutes)
                          .arg(seconds, 2, 10, QLatin1Char('0'));  // 秒数固定两位，不足补零
    ui->duration_lb->setText(timeStr);
    ui->size_lb->setText(musicInfo.getsize());
}

// void MusicItemwi::setUi(const MusicInfo &musicInfo)
// {

// }

void MusicItemwi::setindex( int index)
{
    ui->index_btn->setText(QString::number(index));
    m_index=index;
}

// MusicInfo MusicItemwi::getmusicinfo()
// {
//     return m_musicInfo;
// }

MusicItemwi::~MusicItemwi()
{
    delete ui;
}

bool MusicItemwi::eventFilter(QObject *watched, QEvent *event)
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



 void MusicItemwi::on_index_btn_clicked()
{
     emit Play(m_musicInfo);

}

