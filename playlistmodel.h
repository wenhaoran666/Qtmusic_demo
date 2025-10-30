#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "global.h"
#include "musicinfo.h"
#include <QAbstractListModel>

class PlaylistModel: public QObject  // 或者其他 QObject
{
     Q_OBJECT
public:
    explicit PlaylistModel(QObject *parent = nullptr);  //


    // 添加一批歌曲，同时清空旧队列
    void setNewPlaylist(const QList<MusicInfo> &newSongs);

    // 添加歌曲到列表末尾
    void appendSongs(const QList<MusicInfo> &songs);

    //根据传来的歌曲更新当前的索引
    void updateindex(MusicInfo message);

    // 清空播放列表
    void clear();
    // MusicInfo currentSong() const;
    MusicInfo nextSong();           // 获取下一首（根据模式）
    MusicInfo previousSong();       // 上一首（可选）
    void shuffle();                // 打乱顺序（乱序模式）
    void unshuffle();              // 恢复正序
    void setPlayMode(PlayMode mode);// 设置播放模式：正序/倒序/乱序/循环

signals:
    void listchange(const QList<MusicInfo> &newSongs);//通知窗口改变

    void nowchange(int m_currentIndex);//发送信号当前音乐改变
private:
     QList<MusicInfo> m_list;//播放列表
    QList<int> m_shuffleOrder;              // 乱序时使用的索引顺序（打乱后的索引列表）
    int m_currentIndex = 0;        // 当前播放歌曲在列表中的索引
    int m_shuffleIndex = 0;          // 用于记录乱序播放的当前索引
    PlayMode m_playMode = LoopNormal;       // 当前播放模式
};

#endif // PLAYLISTMODEL_H
