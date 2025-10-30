#include "basemusicmodel.h"
#include "qdebug.h"
#include"MusicManager.h"
BaseMusicModel::BaseMusicModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int BaseMusicModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_musicList.size();
}

QVariant BaseMusicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_musicList.size())
        return QVariant();

    const MusicInfo &info = MusicManager::GetInstance()->getSongitem(m_musicList.at(index.row()));

    switch (role) {
    case TitleRole:
        return info.gettitle();
    case ArtistRole:
        return info.getcomposer();
    case AlbumRole:
        return info.getalbum();
    case DurationRole:
        return info.getduration();
    case CoverRole:
        return info.getm_image();
    case CoverurlRole:
        return info.getm_image_url();
    case OriginalInfoRole:
        return QVariant::fromValue(info); // 允许delegate 获取完整的 MusicInfo 对象
      case  IsLikedRole:
        return info.getisLiked();
    default:
        return QVariant();
    }
}

bool BaseMusicModel::removeRow(int row, const QModelIndex &parent)
{
    // 1. 校验索引有效性（父索引应为空，列表模型无层级）
    if (parent.isValid())
        return false;
    // 2. 校验行号范围
    if (row < 0 || row >= m_musicList.size()) {
        qWarning() << u8"BaseMusicModel::removeRow: 行号无效，row=" << row;
        return false;
    }
    // 3. 发送“开始删除”通知（关键：使用 beginRemoveRows）
    beginRemoveRows(parent, row, row); // 通知视图：从row开始删除1行
    // 4. 移除数据
    m_musicList.removeAt(row);
    // 5. 发送“删除完成”通知（与 beginRemoveRows 配对）
    endRemoveRows();
    return true;
}

void BaseMusicModel::refreshRow(int row)
{
    // 1. 校验行索引有效性
    if (row < 0 || row >= m_musicList.size()) {
        qWarning() << u8"刷新失败：无效行索引" << row;
        return;
    }

    // 2. 构造该行列的索引（列表模型列固定为0）
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, 0);

    // 3. 发送数据变更信号，通知视图重绘该行
    // 信号会触发视图调用委托的paint函数，更新UI
    emit dataChanged(topLeft, bottomRight);

    qDebug() << u8"模型已刷新行：" << row;
}



void BaseMusicModel::setMusicList(const QList<MusicInfo> &list)
{
    beginResetModel();
    m_musicList.clear();  //清空,视图关联了模型,清空列表自动触发清空QListViem
    for(auto l:list)
    {
     m_musicList<<l.getsongId();
    }
    endResetModel();
}

void BaseMusicModel::appendMusicInfo(qint64 songId)
{
    beginResetModel();
    m_musicList<<songId;
    endResetModel();
}

void BaseMusicModel::setLikedState(int row, bool isLiked)
{
    if (row < 0 || row >= m_musicList.size()) return;
    // 更新数据
    MusicManager::GetInstance()->SetLike(m_musicList[row],isLiked);
    // 精确通知视图：只有 row 行的数据变化了
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, 0);
    emit dataChanged(topLeft, bottomRight);
}

MusicInfo BaseMusicModel::getMusicInfo(int row) const
{
    if (row >= 0 && row < m_musicList.size())
        return MusicManager::GetInstance()->getSongitem(m_musicList.at(row));
    return MusicInfo(); // 返回空 MusicInfo 对象
}

void BaseMusicModel::onMusicInfoUpdated(int songId)
{
    // 可根据 songId 找到对应歌曲并更新数据，然后调用 dataChanged()
    // 暂时留空，按需实现
}
