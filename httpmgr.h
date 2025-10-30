#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "global.h"
#include <memory>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QMap>
#include"global.h"
class HttpMgr : public QObject, public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT

public:
    ~HttpMgr() override;

    // 发送HTTP请求（支持Post/Get，基于网易云API特点扩展）
    void sendRequest(const QUrl& url,
                     ReqId req_id,
                     Modules mod,
                     QJsonObject json = QJsonObject(),
                     bool isPost = true);

    // // 网易云API专用：设置请求头（网易云 API需要特定请求头）
    //已经使用本地api无需设置
    // void setNeteaseHeaders(QNetworkRequest& req);


    // 搜索歌曲
    void searchMusic(const QString& keyword, int limit, int offset);
    //搜索建议
    void searchrecomMusic(const QString& keyword);
    //图片下载接口（将QUrl异步加载为QPix）
    void downloadImage(const QUrl& imageUrl, qint64 songId);
    //轮播图下载接口
    void downloadBannerImage(const QUrl& imageUrl, qint64 songId);
    //歌单图下载接口
    void downloadSonglistImage(const QUrl& imageUrl, qint64 songlistId);
    // 获取音乐播放URL（参数：音乐ID）
    void getMusicUrl(const QString& musicId, Modules m);
    //获取首页轮播图数据
    void getBanner();
    //通过music获取单个歌曲详情(针对单个歌曲,搜索窗口可以一次获取多个信息,故此现用在轮播图中获取音乐信息)
    void getMusicdetail(const QString& musicId, Modules m);
    //获取首页歌单信息
    void getsonglist();
    //获取歌单中歌曲信息
    void getlistinfo(QString &songlistId);
private:
    friend class Singleton<HttpMgr>;
    HttpMgr();

    QNetworkAccessManager _manager; // Qt 网络请求管理器
    // 存储图片下载请求与歌曲ID的映射（用于下载完成后关联）
    QMap<QNetworkReply*, ImageDownloadInfo> m_imageReplyMap;  // key:请求对象，value:歌曲ID

private slots:

    //接收sig_http_finish信号并做处理的槽函数
    void slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);

    // 处理图片下载完成
    void onImageDownloadFinished(QNetworkReply* reply);

signals:
    // 通用HTTP响应信号
    void sig_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);

    // 音乐相关模块信号（网易云核心功能）
    void sig_music_search_finish(ReqId id, QString res, ErrorCodes err);       // 歌曲搜索模块完成
    void sig_music_like_finish(ReqId id, QString res, ErrorCodes err);        //歌曲喜欢模块完成
    void sig_music_recommend_finish(ReqId id, QString res, ErrorCodes err);   //推荐界面模块完成



    // 图片下载完成信号
    void sig_image_download_finish(ImageDownloadInfo info, const QPixmap& image, bool success);
};

#endif // HTTPMGR_H
