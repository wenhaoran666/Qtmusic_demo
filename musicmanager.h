#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H
#include "global.h"
#include "httpmgr.h"
#include "musicinfo.h"
#include "musicitemwi.h"
#include "singleton.h"
#include <QObject>
#include"bannerinfo.h"
//继承单例,音乐管理类
//本地音乐解析保存在本地窗口和此单例类,网络歌曲因为较多故只保存在此单例类
//缓存功能,缓存最近搜索/点击过的网络音乐，最多100首,查看最近听过音乐时可以用
class MusicManager: public QObject, public Singleton<MusicManager>,
                     public std::enable_shared_from_this<MusicManager>
{
    Q_OBJECT
public:

    friend class Singleton<MusicManager>;
    void initm_favoriteSongs(QList<MusicInfo> l);         //从数据库中初始化喜欢音乐
    void init_hashinfos(QList<MusicInfo> l);              //缓存中也同样初始化
    bool isexistIcon(MusicInfo &item);//是否已存在音乐信息,存在就用已有的覆盖,不存在就返回false
    void addSongitem(MusicInfo &icon);//添加到最近缓存,找到就更新,没找到就添加信息
    void addLike(qint64 songId);//添加到喜欢
    void removeLike(qint64 songId);//从喜欢中移除
    void SetLike(qint64 songId,bool a);//设置是否喜欢
    void setUrl(qint64 songId,QUrl url);//网络url解析完毕,用于设置对应id的url
    MusicInfo getSongitem(qint64 id);
    QList<MusicInfo> getAllFavoriteSongs() const;//获取所有喜欢歌曲

        void addbanneritem(Bannerinfo &icon);//添加轮播图信息
        QList<Bannerinfo> getAllbanners() const;//获取轮播图信息
        bool isBannerImageCached(qint64 songId); //判断轮播图是否已下载

         void addsonglistitem(SongListInfo &icon);//添加歌单信息
        bool isSonglistImageCached(qint64 songId); //判断推荐歌单图是否已下载
        QList<SongListInfo> getAllsonglists() const;//获取歌单信息

signals:
void refreshListViewItem(qint64 songId);//通知搜索窗口根据id刷新图片
    void refreshLikeListViewItem(qint64 songId);//通知喜欢窗口根据id刷新图片
    void addLikesong(qint64 songId);//通知喜欢窗口根据id添加项
    void removeLikesong(qint64 songId);//通知喜欢窗口根据id去除项
    void refreshbanenrs();  //通知轮播图
private slots:
    void onImageDownloaded(ImageDownloadInfo info, const QPixmap& image, bool success);
private:
    MusicManager();//私有化构造
    // 缓存最近搜索/点击过的网络音乐，最多100首
    QMap<qint64, MusicInfo> _hashinfos;  //  songId 为 key
    QList<qint64> _recentSongIds;       // 记录访问顺序（最新的在末尾）
    static const int MAX_RECENT_COUNT = 100;  // 最大缓存数量


    //喜欢的歌曲容器（键为songId，值为完整音乐信息）
    QMap<qint64, MusicInfo> m_favoriteSongs;

    //轮播图信息容器
    QMap<qint64, Bannerinfo>m_banners;

    //推荐歌单信息容器
    QMap<qint64, SongListInfo>m_songlists;

};

#endif // MUSICMANAGER_H
