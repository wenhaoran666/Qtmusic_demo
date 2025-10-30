#ifndef BASEMUSICMODEL_H
#define BASEMUSICMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "musicinfo.h"


class BaseMusicModel : public QAbstractListModel
{
    Q_OBJECT

public:
    // 自定义角色，用于在视图中展示歌曲信息
    enum MusicRoles {
        TitleRole = Qt::UserRole + 1,      // 歌曲名称
        ArtistRole,                        // 歌手
        AlbumRole,                         // 专辑
        DurationRole,                      // 时长（如 "03:45"）
        CoverRole,                         // 封面图片
        CoverurlRole,                      //封面图片url
        OriginalInfoRole,                    // 原始 MusicInfo 对象
        IsLikedRole  // 喜欢状态
    };

    explicit BaseMusicModel(QObject *parent = nullptr);//构造

    // QAbstractListModel 接口
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;//返回行数
    //返回指定索引数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //移除指定项
     bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    void refreshRow(int row);//刷新指定行的数据
    // 设置要展示的音乐列表
    void setMusicList(const QList<MusicInfo> &list);
    //列表中添加一个
    void appendMusicInfo(qint64 songId);
    // 设置收藏状态
    void setLikedState(int row, bool isLiked);
    // 获取指定行的 MusicInfo 对象
    MusicInfo getMusicInfo(int row) const;

private slots:
    // 可用于响应某首歌曲信息被更新（比如从网络或本地数据库）
    void onMusicInfoUpdated(int songId);
private:
    QList<qint64> m_musicList;  // 当前模型维护的歌曲列表
};

#endif // BASEMUSICMODEL_H
