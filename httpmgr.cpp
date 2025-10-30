#include "httpmgr.h"
#include "qpixmap.h"
#include <QTimer>
#include<QUrlQuery>
HttpMgr::HttpMgr() {
    //连接http请求和完成信号，信号槽机制保证队列消费
    connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
    // 连接图片下载请求的完成信号（复用已有_manager）
    connect(&_manager, &QNetworkAccessManager::finished,
            this, &HttpMgr::onImageDownloadFinished);
}

HttpMgr::~HttpMgr() {
}

// void HttpMgr::setNeteaseHeaders(QNetworkRequest& req) {
//     req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
//     req.setRawHeader("Referer", "https://music.163.com");
//     req.setRawHeader("Cookie", "appver=2.0.2;"); // 根据实际需求补充Cookie
// }

void HttpMgr::sendRequest(const QUrl& url, ReqId req_id, Modules mod, QJsonObject json, bool isPost) {
    QNetworkRequest req;
    QNetworkReply* reply = nullptr;

    //如果是post情况,需要将json一并提交
    if (isPost)
    {
        // 网易云API常用form表单提交，需将JSON转换为键值对
        QByteArray postData;
        for (auto key : json.keys())
        {
            postData.append(key.toUtf8() + "=" + json[key].toString().toUtf8() + "&");
        }
        postData.chop(1); // 移除最后一个&
        reply = _manager.post(req, postData);
    }
    //大多为get,将json用QUrlQuery设置为 URL 中的查询字符串
    else
    {
        QUrl requestUrl = url;
        if (!json.isEmpty())
        {
            QUrlQuery query;
            for (auto key : json.keys())
            {
                // 获取当前键对应的 JSON 值
                QJsonValue val = json[key];
                QString valStr;
                // 根据 JSON 值的不同类型，将其转换为合适的字符串格式，以便作为 URL 参数值
                if (val.isString())
                    // 如果是字符串类型，直接使用其字符串表示
                    valStr = val.toString();
                else if (val.isDouble())
                    // 如果是双精度浮点数（比如数字），这里选择转为整数（比如用于页码等场景
                    valStr = QString::number(val.toInt()); // 或 toDouble()
                else if (val.isBool())
                    // 如果是布尔类型，转换为 "1"（true）或 "0"（false），这是很多接口常用的约定
                    valStr = val.toBool() ? "1" : "0";
                else
                    // 对于其他类型（如数组、对象、null等），暂不处理，直接跳过
                    continue;
                //addQueryItem()方法会自动对key和value进行URL编码（比如中文、空格、&、= 等特殊字符会被转义）
                query.addQueryItem(key, valStr);
            }
            requestUrl.setQuery(query);
        }
        req.setUrl(requestUrl); // 关键：把带参数的 URL 设置回去
        reply = _manager.get(req);
         qDebug()<<u8"URL为"<<requestUrl;
    }


    //要使用shared_from_this,类必须公开继承 std::enable_shared_from_this<HttpMgr>
    auto self = shared_from_this();

    connect(reply,&QNetworkReply::finished,[reply, self, req_id, mod](){
        //处理错误的情况
        if(reply->error() != QNetworkReply::NoError){
            qDebug() <<u8"接收错误"<<reply->errorString();
            //发送信号通知完成
            emit self->sig_http_finish(req_id, "", ErrorCodes::ERROR_NETWORK, mod);
            reply->deleteLater();//安全删除
            return;
        }
        //无错误则读回响应
        QString res = reply->readAll(); //储存响应信息
        //发送信号通知完成
        emit self->sig_http_finish(req_id, res, ErrorCodes::ERROR_NONE,mod);
        reply->deleteLater();//安全删除
        return;
    });
}

void HttpMgr::searchMusic(const QString &keyword, int limit, int offset)
{
    if (keyword.isEmpty()) {
        qWarning() << u8"搜索关键词为空";
        return;
    }
    // 基础URL
    QUrl baseUrl(cloud_url_prefix+"/cloudsearch");  // 本地API端口

    // 构造搜索参数
    QJsonObject params;
    params["keywords"] = keyword;    // 搜索关键词（必填）
    params["limit"] = limit;         // 返回结果数量（默认20）
    params["offset"] = offset;       // 分页偏移量（用于翻页，0开始）
    params["type"] = 1;              // 搜索类型：1=单曲（歌曲）

    // 3. 发送GET请求（搜索接口用GET）
    sendRequest(baseUrl, ReqId::ID_SEARCH_MUSIC, Modules::MODULE_SEARCH, params, false);
}

void HttpMgr::searchrecomMusic(const QString &keyword)
{
    if (keyword.isEmpty()) {
        qWarning() << u8"搜索关键词为空";
        return;
    }

    // 基础URL
    QUrl baseUrl(cloud_url_prefix+"/search/suggest");  // 本地API端口
    // 构造搜索参数
    QJsonObject params;
    params["keywords"] = keyword;    // 搜索关键词
    // 3. 发送GET请求（搜索接口用GET）
    sendRequest(baseUrl, ReqId::ID_SEARCHRECOM_MUSIC, Modules::MODULE_SEARCH, params, false);
}

void HttpMgr::downloadImage(const QUrl& imageUrl, qint64 songId) {
    // 校验URL有效性
    if (!imageUrl.isValid()) {
        qWarning() << u8"图片URL无效：" << imageUrl.toString() << u8"，歌曲ID：" << songId;
        return;
    }

    // 补全URL协议头（防止缺少http:）
    QUrl url = imageUrl;
    if (url.scheme().isEmpty()) {
        url.setScheme("http"); // 若URL无协议，默认http（也可根据实际用https）
    }

    // 创建网络请求（可添加模拟浏览器的UA头，避免被拦截）
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader,
                      "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36");

    // 发送GET请求，并关联歌曲ID
    QNetworkReply* reply = _manager.get(request);
    ImageDownloadInfo info;
    info.id=songId;
    info.imager=IMAGEId::SONG_IMAGE ;//表示歌曲图片
    m_imageReplyMap.insert(reply, info); // 记录“请求-下载信息”映射
    qDebug() << u8"开始下载图片：" << url.toString() << u8"，歌曲ID：" << songId;

    // 歌曲图片下载时打印URL
    qDebug() << u8"歌曲封面请求URL：" << url.scheme() << url.toString();
}

void HttpMgr::downloadBannerImage(const QUrl &imageUrl, qint64 songId)
{
    // 校验URL有效性
    if (!imageUrl.isValid()) {
        qWarning() << u8"轮播图片URL无效：" << imageUrl.toString() << u8"，歌曲ID：" << songId;
        return;
    }

    // 轮播图URL补全逻辑（修改为HTTP）
    QUrl url = imageUrl;
    if (url.scheme().isEmpty()) {
        url.setScheme("http"); // 强制用HTTP，而非HTTPS
    } else if (url.scheme() == "https") {
        url.setScheme("http"); // 若原URL是HTTPS，也强制转为HTTP
    }

    // 创建网络请求（可添加模拟浏览器的UA头，避免被拦截）
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader,
                      "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36");

    // 发送GET请求，并关联歌曲ID
    QNetworkReply* reply = _manager.get(request);
    ImageDownloadInfo info;
    info.id=songId;
    info.imager=IMAGEId::BANNER_IMAGE;//表示轮播图图片
    m_imageReplyMap.insert(reply, info); // 记录“请求-下载信息”映射
    qDebug() << u8"开始下载图片：" << url.toString() << u8"，歌曲ID：" << songId;
    // 轮播图下载时打印URL
    qDebug() << u8"轮播图请求URL：" << url.scheme() << url.toString();
}

void HttpMgr::downloadSonglistImage(const QUrl &imageUrl, qint64 songlistId)
{
    // 校验URL有效性
    if (!imageUrl.isValid()) {
        qWarning() << u8"歌单图片URL无效：" << imageUrl.toString() << u8"，歌单ID：" << songlistId;
        return;
    }

    // 轮播图URL补全逻辑（修改为HTTP）
    QUrl url = imageUrl;
    if (url.scheme().isEmpty()) {
        url.setScheme("http"); // 强制用HTTP，而非HTTPS
    } else if (url.scheme() == "https") {
        url.setScheme("http"); // 若原URL是HTTPS，也强制转为HTTP
    }

    // 创建网络请求（可添加模拟浏览器的UA头，避免被拦截）
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader,
                      "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36");

    // 发送GET请求，并关联歌曲ID
    QNetworkReply* reply = _manager.get(request);
    ImageDownloadInfo info;
    info.id=songlistId;
    info.imager=IMAGEId::SONGLIST_IMAGE;//表示歌单图片
    m_imageReplyMap.insert(reply, info); // 记录“请求-下载信息”映射
    qDebug() << u8"开始下载图片：" << url.toString() << u8"，歌单ID：" << songlistId;
    // 歌单图下载时打印URL
    qDebug() << u8"歌单图片请求URL：" << url.scheme() << url.toString();
}

void HttpMgr::getMusicUrl(const QString &musicId,Modules m)
{
    if (musicId.isEmpty()) {  // 校验单个ID有效性
        qWarning() << u8"获取播放URL失败：无效歌曲ID";
        return;
    }

    // 1. 基础URL（与之前一致）
    QUrl baseUrl(cloud_url_prefix + "/song/url/v1");

    // 2. 构造参数（仅传递当前单个ID，格式为"[id]"）
    QJsonObject params;
    params["id"] = musicId;  // 单个ID仍需包裹在数组中（API要求）
    params["level"] = "standard";  // 音质参数
    sendRequest(baseUrl, ReqId::ID_GET_MUSIC_PLAYURL, m, params, false);
}

void HttpMgr::getBanner()
{
    // 1. 基础URL（与之前一致）
    QUrl baseUrl(cloud_url_prefix + "/banner");
    // 2. 构造参数（仅传递当前单个ID，格式为"[id]"）
    QJsonObject params;
    params["type"] = 0;  // 表示pc端


  sendRequest(baseUrl, ReqId::ID_GET_BANNER, Modules::MODULE_RECOMMEND, params, false);
}

void HttpMgr::getMusicdetail(const QString &musicId, Modules m)
{
    // 1. 基础URL（与之前一致）
    QUrl baseUrl(cloud_url_prefix + "/song/detail");
    // 2. 构造参数（仅传递当前单个ID，格式为"[id]"）
    QJsonObject params;
    params["ids"] = musicId;  // 搜索的id

    sendRequest(baseUrl, ReqId::ID_GET_DETAIL, m, params, false);
}

void HttpMgr::getsonglist()
{
    // 1. 基础URL（与之前一致）
    QUrl baseUrl(cloud_url_prefix + "/personalized");
    // 2. 构造参数（仅传递当前单个ID，格式为"[id]"）
    QJsonObject params;
    params["limit"] = 5;  // 表示获取5首歌单

    sendRequest(baseUrl, ReqId::ID_GET_SONGLIST, Modules::MODULE_RECOMMEND, params, false);
}

void HttpMgr::getlistinfo( QString &songlistId)
{
    // 1. 基础URL（与之前一致）
    QUrl baseUrl(cloud_url_prefix + "/playlist/track/all");
    // 2. 构造参数（仅传递当前单个ID，格式为"[id]"）

    QJsonObject params;
    params["id"] = songlistId;
    params["limit"] = 20;  // 获取50首
    sendRequest(baseUrl, ReqId::ID_GET_LIST_INFO, Modules::MODULE_RECOMMEND, params, false);
}



void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod)
{
     //搜索模块
    if(mod == Modules::MODULE_SEARCH)
    {
        //发送信号通知搜索模块http响应结束
        emit sig_music_search_finish(id, res, err);
    }//喜欢界面模块
    else if(mod == Modules::MODULE_LIKE)
    {
        emit sig_music_like_finish(id, res, err);
    }//推荐界面模块
    else if(mod == Modules::MODULE_RECOMMEND)
    {
        emit sig_music_recommend_finish(id, res, err);
    }

}

void HttpMgr::onImageDownloadFinished(QNetworkReply* reply) {
    // 从映射中获取对应的歌曲ID
    if (!m_imageReplyMap.contains(reply)) {
        reply->deleteLater();
        return;
    }
    ImageDownloadInfo info = m_imageReplyMap.take(reply); // 取出并移除映射
    // 处理下载结果
    QPixmap image;
    bool success = false;
    if (reply->error() == QNetworkReply::NoError) {
        // 下载成功：将二进制数据转为QPixmap
        QByteArray imageData = reply->readAll();
        if (image.loadFromData(imageData))
        {
            if(info.imager==IMAGEId::SONG_IMAGE)
            {
            QSize targetSize(100, 100); // 根据实际UI需求调整
            image = image.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            success = true;
            qDebug() << u8"图片下载成功，歌曲ID：" <<info.id << u8"，尺寸：" << image.size();
            }
            else  if(info.imager==IMAGEId::BANNER_IMAGE)
                {
                QSize targetSize(1100, 600); // 根据实际UI需求调整
                image = image.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                success = true;
                qDebug() << u8"图片下载成功，歌曲ID：" <<info.id << u8"，尺寸：" << image.size();
                }
            else if(info.imager==IMAGEId::SONGLIST_IMAGE)
            {

                    QSize targetSize(250, 290); // 根据实际UI需求调整
                    image = image.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    success = true;
                    qDebug() << u8"图片下载成功，歌曲ID：" <<info.id << u8"，尺寸：" << image.size();
            }
            else
            {
            qWarning() << u8"图片格式无效，歌曲ID：" << info.id;
            }
        }

    } else {
        // 下载失败：记录错误信息，使用默认图片（可选）
        qWarning() << u8"图片下载失败，歌曲ID：" <<info.id<< u8"，错误：" << reply->errorString();
        // 加载本地默认封面（需提前准备资源文件）
        image.load(":/res/head_2.jpg");
    }

    // 发送信号通知下载完成（外部可通过songId匹配到对应的MusicInfo）
    emit sig_image_download_finish(info, image, success);

    // 释放请求资源
    reply->deleteLater();
}


