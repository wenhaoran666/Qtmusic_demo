#ifndef MUSICPLAYERWI_H
#define MUSICPLAYERWI_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QThread>
#include "playerworker.h"
#include "musicinfo.h"
#include "mainwidget.h"
#include "ui_musicplayerwi.h" // 假定你使用了 Qt Designer，根据实际情况调整
#include "volumetoolwi.h"

class Musicplayerwi : public QWidget
{
    Q_OBJECT

public:
    explicit Musicplayerwi(QWidget *parent = nullptr);
    ~Musicplayerwi();

    void playMusic(const QUrl &musicFilePath);   // 播放指定路径音乐
    void setUi(const MusicInfo &info);           // 根据音乐信息设置UI
    void setnormalui();                          // 普通无音乐状态UI
    void switchToNextSong();                     // 切歌到下一首
    void switchToLastSong();                     // 切歌到上一首
    void setMainWidget(MainWidget *mainWidget);

signals:
    void songstop();//重置播放器
    void showlist();
    // 发送给 PlayerWorker 的控制信号
    void playRequested(const QUrl &url);//要播放的歌url,交给worker解析(若可用,接收回调MetadataReady才初始ui)
    void pauseRequested(bool a);//暂停或继续
    void stopRequested();
    void positionChanged(qint64 pos);
    void setVolume(int volume);

private slots:
    void on_pause_btn_clicked();                    // 暂停按钮点击
    void on_retreat_btn_clicked();                  // 下一首按钮
    void on_forward_btn_clicked();                  // 上一首按钮
    void on_order_btn_clicked();                    // 播放顺序
    void onSliderPressed();                      // 进度条按下
    void onSliderReleased();                     // 进度条释放
    void onPositionChanged(qint64 position);     // 播放进度更新，用于UI
    void onDurationChanged(qint64 duration);     // 总时长，设置进度条最大值
    void on_list_btn_clicked();                  // 列表按钮
    void onVolumeChanged(int vol);               // 音量调节

    // 来自 PlayerWorker 的反馈
    void onPlayerStateChanged(QMediaPlayer::State state);
    void onMetadataReady(const MusicInfo &info);// 播放可用,初始ui
    void onerrorOccurred(QMediaPlayer::Error error, const QString &msg);
    void onPlayNextRequested();


protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Musicplayerwi *ui;
    QThread *m_playerThread;
    PlayerWorker *m_worker;
    QTimer *_hideTimer;  // 用于延迟隐藏音量窗口
    MainWidget* mainwi;
    bool m_isDragging = false;//当前是否在拖动
    qint64 m_duration = 0;
    VolumeToolwi* _volumeTool;
    PlayMode _order;//当前播放顺序
    PlaylistModel* listmode;
};

#endif // MUSICPLAYERWI_H
