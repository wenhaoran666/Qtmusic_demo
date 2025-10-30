#include "playlistmodel.h"
#include "qdebug.h"
#include <random>

PlaylistModel::PlaylistModel(QObject *parent) : QObject(parent)
{

}    //  调用 QObject 构造函数 {}

void PlaylistModel::setNewPlaylist(const QList<MusicInfo> &newSongs)
{

    if(newSongs!=m_list)//若列表发生变化才替换
    {

    m_list = newSongs;            // 替换整个播放列表
         qDebug()<<u8"m_list替换";
    m_shuffleOrder.clear();           // 清空乱序索引
    m_currentIndex = 0;               // 重置当前播放索引
    /*m_playMode = LoopNormal;*/          // 默认恢复为正序模式（也可不重置，看需求）
    //发送信号通知列表窗口改变
    emit listchange(newSongs);
    }

}

void PlaylistModel::appendSongs(const QList<MusicInfo> &songs)
{
    if (songs.isEmpty())
        return;

    m_list.append(songs);         // 在原列表后追加新歌曲
    // 追加歌曲后，如果当前是乱序模式，且已经打乱过，通常不需要更新 m_shuffleOrder
    // 但如果你希望追加后重新打乱，可以在这里调用 shuffle()

}

void PlaylistModel::updateindex( MusicInfo message)
{

    for (int i = 0; i < m_list.size(); ++i) {
        // 假设通过id判断是否是同一首歌
        if (m_list[i].getsongId() == message.getsongId()) {
            m_currentIndex = i;

            //发送信号当前音乐改变
            emit nowchange(m_currentIndex);
            return;  // 找到了，设置索引并返回
        }
    }

 qDebug() << u8"未找到匹配的歌曲：" << message.gettitle();
}

void PlaylistModel::clear()
{
    m_list.clear();               // 清空歌曲列表
    m_shuffleOrder.clear();           // 清空乱序索引
    m_currentIndex = 0;               // 重置当前索引
    m_playMode = LoopNormal;          // 恢复默认播放模式（可选，根据需求）
}
MusicInfo PlaylistModel::nextSong() {


    if (m_list.isEmpty())
    {
        qDebug()<<u8"空列表";
        return MusicInfo();  // 空列表返回空
    }

    if (m_playMode == LoopShuffle && m_shuffleOrder.isEmpty()) {
        // 如果是乱序但没有打乱过，先打乱
        shuffle();
    }

    if (m_playMode == LoopNormal) {
        // 正序播放
        m_currentIndex++;
        if (m_currentIndex >= m_list.size()) {
            m_currentIndex = 0;  // 循环：回到第一首
        }
    }
    else if (m_playMode == LoopReverse) {
        // 倒序播放
        m_currentIndex--;
        if (m_currentIndex < 0) {
            m_currentIndex = m_list.size() - 1;  // 循环：回到最后一首
        }
    }
    else if (m_playMode == LoopShuffle) {

        if (m_shuffleOrder.isEmpty()) {
            shuffle();  // 确保已经打乱
        }

        if (m_shuffleIndex >= m_shuffleOrder.size()) {
            m_shuffleIndex = 0;  // 循环
        }

        int realIndex = m_shuffleOrder[m_shuffleIndex];
        m_shuffleIndex++;
        return m_list[realIndex];
    }
    emit nowchange(m_currentIndex);
    return m_list[m_currentIndex];
    //  return  MusicInfo();

}

MusicInfo PlaylistModel::previousSong()
{
    if (m_list.isEmpty())
        return MusicInfo();

    if (m_playMode == LoopNormal) {
        // 正序模式下的上一首
        m_currentIndex--;
        if (m_currentIndex < 0) {
            m_currentIndex = m_list.size() - 1;  // 循环到最后一首
        }
    }
    else if (m_playMode == LoopReverse) {
        // 倒序模式下的“上一首”其实是正序的下一首（逻辑视情况而定，这里简化处理）
        m_currentIndex++;
        if (m_currentIndex >= m_list.size()) {
            m_currentIndex = 0;  // 循环到第一首
        }
    }
    else if (m_playMode == LoopShuffle) {
        // 乱序模式下的上一首比较复杂，这里简化：仍使用 m_shuffleOrder 倒着取
        static int shuffleIndex = 0;
        if (m_shuffleOrder.isEmpty()) {
            shuffle();  // 确保已经打乱
        }

        // 简单处理：倒序播放乱序列表（你可以优化为记录上一次的位置）
        static int reverseShuffleIndex = m_shuffleOrder.size() - 1;
        if (reverseShuffleIndex < 0) {
            reverseShuffleIndex = m_shuffleOrder.size() - 1;  // 循环
        }

        int realIndex = m_shuffleOrder[reverseShuffleIndex];
        reverseShuffleIndex--;
        return m_list[realIndex];
    }
    emit nowchange(m_currentIndex);
    return m_list[m_currentIndex];
}


void PlaylistModel::shuffle()
{
    if (m_list.isEmpty())
        return;

    m_shuffleOrder.clear();
    for (int i = 0; i < m_list.size(); ++i) {
        m_shuffleOrder.append(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_shuffleOrder.begin(), m_shuffleOrder.end(), g);
}

void PlaylistModel::unshuffle()
{
    m_shuffleOrder.clear();     // 清空乱序索引列表
    m_playMode = LoopNormal;    // 恢复为正序循环模式
    m_currentIndex = 0;         // 回到第一首
}

void PlaylistModel::setPlayMode(PlayMode mode)
{
    m_playMode = mode;

    // if (mode != LoopShuffle) {
    //     // 如果不是乱序模式，不需要保留乱序索引（可选）
    //     // m_shuffleOrder.clear();  // 可选：清除乱序索引
    // }
}
