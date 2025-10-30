#ifndef PLAYERWORKER_H
#define PLAYERWORKER_H
//播放线程类,将播放器ui显示与播放通过多线程分离
#include <QObject>
#include <QUrl>
#include <QMediaPlayer>
#include <mutex>
#include "musicinfo.h"
#include "singleton.h" // 单例模板

QT_FORWARD_DECLARE_CLASS(QMediaPlayer)

/**
 * @brief 播放工作线程类，运行在子线程，负责所有音频播放相关逻辑
 */
class PlayerWorker : public QObject
{
    Q_OBJECT

public:
    explicit PlayerWorker(QObject *parent = nullptr);
    ~PlayerWorker();

public slots:
    // 播放指定URL音频
    void play(const QUrl &url);
    // 暂停播放
    void pause(bool a);
    //继续播放
    void resume();
    // 停止播放
    void stop();
    // 设置播放位置（毫秒）
    void setPosition(qint64 pos);
    // 设置音量（0~100）
    void setVolume(int volume);

signals:
    // 通知UI切歌
    void playNextRequested();
    // 元数据解析完成，回传给UI
    void metadataReady(const MusicInfo &info);
    // 播放状态变化
    void stateChanged(QMediaPlayer::State state);
    // 播放位置变化
    void positionChanged(qint64 pos);
    // 音频总时长变化
    void durationChanged(qint64 duration);
    // 播放错误信息
    void errorOccurred(QMediaPlayer::Error error, const QString &msg);
    // 媒体状态变化（如播放完成）
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

private slots:
    // 处理播放器状态变化
    void onPlayerStateChanged(QMediaPlayer::State state);
    // 处理媒体状态（比如播放完成）
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    // 处理播放错误
    void onErrorOccurred(QMediaPlayer::Error error);

private:
    // 线程安全更新最近播放缓存（暂未实现，可后续扩展）
    // void updateRecentPlay(const MusicInfo &info);

    QMediaPlayer *m_player;           // 底层播放器
    mutable std::mutex m_mutex;       // 线程锁（更新最近播放缓存时使用）
};

#endif // PLAYERWORKER_H
