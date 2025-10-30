#include "playerworker.h"
#include "musicmanager.h"
#include <QMediaMetaData>
#include <QDebug>

// 与 MusicManager 保持一致的缓存大小
constexpr int MAX_CACHE_SIZE = 200;

PlayerWorker::PlayerWorker(QObject *parent)
    : QObject(parent), m_player(new QMediaPlayer(this))
{
    // 当播放到结尾时，自动通知切歌
    connect(m_player, &QMediaPlayer::mediaStatusChanged,
            this, [this](QMediaPlayer::MediaStatus status) {
                if (status == QMediaPlayer::EndOfMedia)
                    emit playNextRequested();
            });

    // 转发 QMediaPlayer 状态信号到 UI
    connect(m_player, &QMediaPlayer::stateChanged,
            this, &PlayerWorker::stateChanged);
    connect(m_player, &QMediaPlayer::positionChanged,
            this, &PlayerWorker::positionChanged);
    connect(m_player, &QMediaPlayer::durationChanged,
            this, &PlayerWorker::durationChanged);
    // 将原来的 errorOccurred 信号连接替换为 error 信号
    connect(m_player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
            this, &PlayerWorker::onErrorOccurred);
    connect(m_player, &QMediaPlayer::mediaStatusChanged,
            this, &PlayerWorker::mediaStatusChanged);
}

PlayerWorker::~PlayerWorker()
{
    // 自动析构，无需手动释放
}

void PlayerWorker::play(const QUrl &url)
{
    MusicInfo info;
    // 无论是否是同一URL，都强制重置媒体
    m_player->stop();
    m_player->setMedia(QMediaContent()); // 清空当前媒体，强制后续setMedia重新加载
    //播放
    m_player->setMedia(url);
    m_player->play();
    // 线程安全地更新最近播放（可后续实现）
    // updateRecentPlay(info);

}

void PlayerWorker::pause(bool a)
{
    if(a)
     m_player->pause();
    else
     m_player->play();
}


void PlayerWorker::resume()
{
    m_player->play();
}

void PlayerWorker::stop()
{
    m_player->stop();
}

void PlayerWorker::setPosition(qint64 pos)
{
    m_player->setPosition(pos);
}

void PlayerWorker::setVolume(int volume)
{
    m_player->setVolume(volume);
}

void PlayerWorker::onPlayerStateChanged(QMediaPlayer::State state)
{
    emit stateChanged(state);
}

void PlayerWorker::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    emit mediaStatusChanged(status);

    if (status == QMediaPlayer::EndOfMedia) {
        emit playNextRequested();
    }
}

void PlayerWorker::onErrorOccurred(QMediaPlayer::Error error)
{
    QString errorMsg = m_player->errorString();
    emit errorOccurred(error, errorMsg);
}



/**
 * @brief 线程安全地更新“最近播放”缓存
 * @param info 当前播放的音乐信息
 */
// void PlayerWorker::updateRecentPlay(const MusicInfo &info)
// {
//     auto& cache = MusicManager::GetInstance()->m_networkMusicCache;
//     std::lock_guard<std::mutex> lock(m_mutex); // 使用成员 mutex 保证线程安全

//     // 如果已存在，则先移除旧的
//     cache.removeOne(info);
//     // 添加到头部（表示最新播放）
//     cache.prepend(info);

//     // 如果超出最大缓存数量，删除最旧的
//     if (cache.size() > MAX_CACHE_SIZE) {
//         cache.removeLast();
//     }
// }
