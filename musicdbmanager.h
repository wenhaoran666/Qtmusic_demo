#ifndef MUSICDBMANAGER_H
#define MUSICDBMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QObject>
#include <QSqlDatabase>
#include <QList>
#include "musicinfo.h"
#include "singleton.h"
class MusicDBManager :public QObject, public Singleton<MusicDBManager>,
    public std::enable_shared_from_this<MusicDBManager>
{
    Q_OBJECT
    friend class Singleton<MusicDBManager>;
public:
    bool addLikedSong(const MusicInfo& info);       // 添加喜欢的歌曲
    bool removeLikedSong(qint64 songId);            // 移除喜欢的歌曲
    QList<MusicInfo> getAllFavoriteSongs();        //从列表加载所有喜欢音乐
    void setUrl(qint64 songId, QUrl url);          //url加载后补全url
private:
    MusicDBManager();//私有化构造
    QSqlDatabase m_db;    // 数据库连接对象
    QString m_dbPath;     // 数据库文件路径
};

#endif // MUSICDBMANAGER_H
