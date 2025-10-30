#include "musicplayerwi.h"
#include "playerworker.h"
#include <QTimer>
#include <QSlider>
#include <QDebug>

Musicplayerwi::Musicplayerwi(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Musicplayerwi),
    m_playerThread(new QThread(this)),
    m_worker(new PlayerWorker()),
    _hideTimer(new QTimer(this)),
    mainwi(nullptr),
    _volumeTool(new VolumeToolwi()),
    _order(LoopNormal)
{
    if (!listmode) {
        qDebug() << "错误：获取到的播放列表模型是空指针！";
        return;
    }

    ui->setupUi(this);

    // 初始化播放线程
    m_worker->moveToThread(m_playerThread);
    m_playerThread->start();

    ui->pause_btn->setCheckable(false);//没有歌曲时不可点击暂停

    connect(this, &Musicplayerwi::playRequested, m_worker, &PlayerWorker::play);
    connect(this, &Musicplayerwi::pauseRequested, m_worker, &PlayerWorker::pause);
    connect(this, &Musicplayerwi::stopRequested, m_worker, &PlayerWorker::stop);
    connect(this, &Musicplayerwi::positionChanged, m_worker, &PlayerWorker::setPosition);
    connect(_volumeTool, &VolumeToolwi::volumesize, m_worker, &PlayerWorker::setVolume);
    connect(this,&Musicplayerwi::songstop,m_worker,&PlayerWorker::stop);

    connect(m_worker, &PlayerWorker::metadataReady, this, &Musicplayerwi::onMetadataReady);
    connect(m_worker, &PlayerWorker::positionChanged, this, &Musicplayerwi::onPositionChanged);
    connect(m_worker, &PlayerWorker::durationChanged, this, &Musicplayerwi::onDurationChanged);
    connect(m_worker, &PlayerWorker::stateChanged, this, &Musicplayerwi::onPlayerStateChanged);
    connect(m_worker, &PlayerWorker::errorOccurred, this, [=](QMediaPlayer::Error error, const QString &msg) {
        qDebug() << u8"播放错误：" << msg;
        // 可在此弹窗或设置错误状态
    });

    // 音量工具相关
    connect(_volumeTool, &VolumeToolwi::volumesize, this, [=](int a) {
        qDebug() << u8"调整的音量为" << a;
        emit setVolume(a); // 转发给 PlayerWorker
    });

    // 事件过滤器
    ui->volume_btn->installEventFilter(this);

    // 进度条控制
     ui->bar_sl->setRange(0, 100);
    connect(ui->bar_sl, &QSlider::sliderPressed, this, &Musicplayerwi::onSliderPressed);
    connect(ui->bar_sl, &QSlider::sliderReleased, this, &Musicplayerwi::onSliderReleased);

    // 音量窗口自动隐藏
    _hideTimer->setSingleShot(false);
    _hideTimer->setInterval(100);
    connect(_hideTimer, &QTimer::timeout, this, [this]() {
        if (!ui->volume_btn->underMouse() && !_volumeTool->underMouse()) {
            _volumeTool->hide();
            _hideTimer->stop();
        }
    });

    setnormalui(); // 设置默认 UI 状态
}

Musicplayerwi::~Musicplayerwi()
{
    delete ui;
    //  通知线程退出事件循环
    m_playerThread->quit();

    // 等待线程真正结束（必须！防止线程还在运行时析构）
    m_playerThread->wait();

}

void Musicplayerwi::playMusic(const QUrl &musicFilePath)
{
    // 不再直接操作 m_player，而是通过信号通知 PlayerWorker
    emit playRequested(musicFilePath);
}

void Musicplayerwi::setUi(const MusicInfo &info)
{
    ui->record_wi->swipic(info.getm_image());

    QString m_title = info.gettitle();
    QString m_composer = info.getcomposer();

    QString htmlText =
        "<div style='font-family: Arial; white-space: nowrap; display: inline-block;'>"
        "<span style='color: #283248; font-weight: normal; font-size: 24px;'>" + m_title + "</span>"
                    "<span style='color: #8b949e; font-weight: normal; font-size: 20px;'> - </span>"
                    "<span style='color: #8b949e; font-weight: normal; font-size: 21px;'>" + m_composer + "</span>"
                       "</div>";

    ui->songinfo_lb->setText(htmlText);
    ui->pause_btn->setCheckable(true);
    ui->pause_btn->SetSelected(true);
    ui->record_wi->resume();
    m_duration = info.getduration();
    ui->bar_sl->setMaximum(0); // 后续会被 durationChanged 覆盖
}

void Musicplayerwi::setnormalui()
{
    QString m_title = u8"歌曲名";     // 假设有这个 getter
    QString m_composer = u8"作曲家"; // 假设有这个 getter

    //  拼接富文本，设置不同样式

    QString htmlText =
        "<div style='font-family: Arial; white-space: nowrap; display: inline-block;'>"
        "<span style='color: #283248; font-weight: normal; font-size: 24px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; display: inline-block; width: 220px; vertical-align: top;'>" + m_title + "</span>"
                    "<span style='color: #8b949e; font-weight: normal; font-size: 20px;'>" + " - " + "</span>"
                  "<span style='color: #8b949e; font-weight: normal; font-size: 21px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; display: inline-block; width: 160px; vertical-align: top;'>" + m_composer + "</span>"
                       "</div>";
    //超出可以添加省略
    //htmlText=truncateText(htmlText,30);
    ui->songinfo_lb->setText(htmlText);
    ui->pause_btn->SetSelected(false);
    ui->pause_btn->SetSelected(false);
    ui->bar_sl->setMaximum(0);
    ui->righttime_lb->setText("0:00");
    ui->record_wi->pause();
    ui->record_wi->clearPic();
    emit songstop();
}


void Musicplayerwi::onSliderReleased()
{
    qDebug()<<u8"进度条释放";
    int pos = ui->bar_sl->value();
    emit positionChanged(pos); // 通知 PlayerWorker 跳转进度
    m_isDragging = false;
}

void Musicplayerwi::onSliderPressed()
{
     qDebug()<<u8"进度条按下";
    m_isDragging = true;
}

void Musicplayerwi::onPositionChanged(qint64 position)
{
    if (!m_isDragging)
        ui->bar_sl->setValue(position);

    int sec = position / 1000;
    int min = sec / 60;
    sec %= 60;
    ui->lefttime_lb->setText(QString("%1:%2").arg(min, 1, 10, QChar('0')).arg(sec, 2, 10, QChar('0')));
    if (m_duration > 0 && position >= m_duration - 1000)
    {
        qDebug()<<u8"总时长"<<m_duration<<u8"现在时长"<<position;
        switchToNextSong();
    }

}

void Musicplayerwi::onDurationChanged(qint64 duration)
{
    qDebug()<<u8"时长改变";
    if (duration > 0) {
        m_duration = duration;
        ui->bar_sl->setMaximum(duration);
        int sec = duration / 1000;
        int min = sec / 60;
        sec %= 60;
        ui->righttime_lb->setText(QString("%1:%2").arg(min, 1, 10, QChar('0')).arg(sec, 2, 10, QChar('0')));
    }
}

// 点击“列表”按钮，显示歌曲列表窗口（可根据实际需求打开弹窗或切换页面）
void Musicplayerwi::on_list_btn_clicked()
{
    emit showlist(); // 假定你已定义该信号，用于通知主窗口或其他组件显示播放列表
}

// 音量被改变时调用（通常由音量滑动条或音量工具按钮触发）
void Musicplayerwi::onVolumeChanged(int vol)
{
    // 此函数如果是由 UI 控件直接调用，可以直接转发到 PlayerWorker
    // 但你已经通过 _volumeTool 的信号连接到了 m_worker->setVolume(vol)
    // 所以此处可以留空，或添加 UI 反馈，比如设置音量图标
    qDebug() << u8"音量被调整为：" << vol;
}

// 播放状态改变时调用，比如 Playing / Paused / Stopped
void Musicplayerwi::onPlayerStateChanged(QMediaPlayer::State state)
{
    // 根据不同的播放状态，更新 UI 上的按钮样式或提示
    if (state == QMediaPlayer::PlayingState) {
        ui->pause_btn->SetSelected(true); // 假设这是一个自定义方法，表示正在播放
    } else if (state == QMediaPlayer::PausedState) {
        ui->pause_btn->SetSelected(false); // 表示已暂停
    } else if (state == QMediaPlayer::StoppedState) {
        // 可选：停止状态的 UI 处理
    }
}


void Musicplayerwi::onMetadataReady(const MusicInfo &info)
{
    // 将元数据设置到 UI 界面上，比如专辑图、歌名、歌手
    setUi(info);
}

// 播放过程中发生错误时调用
void Musicplayerwi::onerrorOccurred(QMediaPlayer::Error error, const QString &msg)
{
    // 可以弹窗提示用户，或者更新状态栏/日志
    qDebug() << u8"播放出错[" << error << u8"]：" << msg;
    // 例如：QMessageBox::warning(this, u8"播放错误", msg);
}

// 收到“播放下一首”请求信号（比如当前歌曲播放完毕）
void Musicplayerwi::onPlayNextRequested()
{
    // 直接调用切歌到下一首
    switchToNextSong();
}

// 事件过滤器：用于音量按钮的悬浮提示与自动隐藏
bool Musicplayerwi::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->volume_btn && event->type() == QEvent::Enter) {
        if (_hideTimer->isActive()) {
            _hideTimer->stop();
        }

        QPoint tgt = ui->volume_btn->mapToGlobal(QPoint(0, 0));
        QRect geometry = _volumeTool->geometry();
        geometry.setX(tgt.x() - 20);
        geometry.setY(tgt.y() - 195);

        _volumeTool->setGeometry(geometry);
        _volumeTool->show();

        qDebug() << u8"888 - 音量窗口显示";
        return true;
    }

    if (watched == ui->volume_btn && event->type() == QEvent::Leave) {
        _hideTimer->start();
        qDebug() << u8"000 - 鼠标离开音量按钮，启动延时隐藏检测";
        return true;
    }

    return QWidget::eventFilter(watched, event);
}

// 切歌到下一首（已实现）
void Musicplayerwi::switchToNextSong()
{
    if (!listmode) {
        qDebug() << u8"错误：播放列表模型为空！";
        return;
    }
    MusicInfo next = listmode->nextSong();
    listmode->updateindex(next);
    playMusic(next.geturl());
    setUi(next);
}

void Musicplayerwi::switchToLastSong()
{
    if (!listmode) {
        qDebug() << u8"错误：获取到的播放列表模型是空指针！";
        return;
    }

    MusicInfo last=listmode->previousSong();//获取上一首
    //播放队列数据层设置
    listmode->updateindex(last);
    //播放器设置
    playMusic(last.geturl());
    setUi(last);
}

void Musicplayerwi::setMainWidget(MainWidget * mainWidget)
{

        // 先检查传进来的主窗口指针是否有效
        if (!mainWidget) {
            qDebug() << u8"错误：setMainWidget() 传入的主窗口指针为空！";
            return;
        }

        // 如果已经设置过，避免重复设置
        if (mainwi) {
            qDebug() << u8"提示：setMainWidget() 已经设置过主窗口，本次忽略。";
            return;
        }

        // 设置主窗口指针
        mainwi = mainWidget;

        // 再通过主窗口获取播放列表模型
        listmode = mainwi->getPlaylistModel();
        if (!listmode) {
            qDebug() << u8"错误：setMainWidget() 获取到的播放列表模型为空！";
            return;
        }

        qDebug() << u8"成功：setMainWidget() 设置主窗口和播放列表模型成功。";
}

// 暂停按钮点击事件
void Musicplayerwi::on_pause_btn_clicked()
{
    //为暂停状态就设置继续
    if(ui->pause_btn->GetCurState()==ClickLbState::Normal)
    {
        ui->record_wi->resume();//唱片开始旋转
        ui->pause_btn->SetSelected(ui->pause_btn->isChecked());//设置状态
        emit pauseRequested(false); // 通知 PlayerWorker 继续播放
         qDebug()<<u8"继续";
    }
    //为继续状态设置暂停
    else if(ui->pause_btn->GetCurState()==ClickLbState::Selected)
    {
        ui->record_wi->pause();//唱片旋转暂停
        ui->pause_btn->SetSelected(ui->pause_btn->isChecked());//设置状态
        emit pauseRequested(true); // 通知 PlayerWorker 暂停播放
         qDebug()<<u8"暂停";
    }


}

// 下一首按钮点击事件
void Musicplayerwi::on_retreat_btn_clicked()
{
    switchToNextSong(); // 切歌到下一首
}


// 上一首按钮点击事件
void Musicplayerwi::on_forward_btn_clicked()
{

    switchToLastSong();
}


// 播放顺序按钮点击事件（循环模式切换）
void Musicplayerwi::on_order_btn_clicked()
{
    qDebug()<<u8"切换播放顺序";
    if(_order==LoopNormal)
    {
        qDebug()<<u8"切换到循环顺序";
        //设置按钮ui
        ui->order_btn->setStyleSheet("QPushButton{"
                                     "background-image: url(:/res/viewswitch/cycleorder1.png);"
                                     "background-position: center center;}"
                                     "QPushButton:hover {"
                                     "background-image: url(:/res/viewswitch/cycleorder2.png);"
                                     "background-position: center center;}"
                                     "QPushButton:pressed {"
                                     "background-image: url(:/res/viewswitch/cycleorder3.png);"
                                     "background-position: center center;}"
                                     );

        _order=Loopcycle;
        //播放列表数据层
        listmode->setPlayMode(Loopcycle);
    }
    else if(_order==Loopcycle)
    {
        qDebug()<<u8"切换到乱序顺序";
        ui->order_btn->setStyleSheet("QPushButton{"
                                     "background-image: url(:/res/viewswitch/disorder1.png);"
                                     "background-position: center center;}"
                                     "QPushButton:hover {"
                                     "background-image: url(:/res/viewswitch/disorder2.png);"
                                     "background-position: center center;}"
                                     "QPushButton:pressed {"
                                     "background-image: url(:/res/viewswitch/disorder3.png);"
                                     "background-position: center center;}"
                                     );
        _order=LoopShuffle;
        //播放列表数据层
        listmode->setPlayMode(LoopShuffle);
    }
    else if(_order==LoopShuffle)
    {
        qDebug()<<u8"切换到普通顺序";
        ui->order_btn->setStyleSheet("QPushButton{"
                                     "background-image: url(:/res/viewswitch/order1.png);"
                                     "background-position: center center;}"
                                     "QPushButton:hover {"
                                     "background-image: url(:/res/viewswitch/order2.png);"
                                     "background-position: center center;}"
                                     "QPushButton:pressed {"
                                     "background-image: url(:/res/viewswitch/order3.png);"
                                     "background-position: center center;}"
                                     );

        _order=LoopNormal;
        //播放列表数据层
        listmode->setPlayMode(LoopNormal);
    }
}



