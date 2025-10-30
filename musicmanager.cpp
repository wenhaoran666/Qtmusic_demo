#include "musicmanager.h"
#include"httpmgr.h"
#include"musicdbmanager.h"
MusicManager::MusicManager() {

    //图片加载完,触发绘图更新
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_image_download_finish,
            this, &MusicManager::onImageDownloaded);

    //数据库保存的初始化
    QList<MusicInfo>l=MusicDBManager::GetInstance()->getAllFavoriteSongs();
    initm_favoriteSongs(l);

}

void MusicManager::initm_favoriteSongs(QList<MusicInfo> l)
{
    // 1. 清空现有喜欢列表（初始化前先清空）
    m_favoriteSongs.clear();
    // 2. 遍历传入的列表，以 songId 为键存入 QMap（自动去重）
    for (const auto& info : l) {
        qint64 songId = info.getsongId();

        // 校验歌曲ID有效性
        if (songId <= 0) {
            qWarning() << u8"初始化喜欢列表：跳过无效歌曲（songId=" << songId << u8"）";
            continue;
        }
        // 若已存在相同 songId，会自动覆盖（保留最新的 info）
        if (m_favoriteSongs.contains(songId)) {
            qDebug() << u8"初始化喜欢列表：覆盖重复歌曲（songId=" << songId << u8"）";
        }
        //初始化时顺便加载图片
        QUrl picurl=info.getm_image_url();
        HttpMgr::GetInstance()->downloadImage(picurl, songId);

        m_favoriteSongs.insert(songId, info); // 以 songId 为键存储
    }
    // 3. 输出初始化结果日志
    qDebug() << u8"喜欢列表初始化完成：共存储" << m_favoriteSongs.size()
             << u8"首歌曲（原始列表共" << l.size() << u8"首）";

}

void MusicManager::init_hashinfos(QList<MusicInfo> l)
{
    // 1. 清空现有喜欢列表（初始化前先清空）
    _hashinfos.clear();
    // 2. 遍历传入的列表，以 songId 为键存入 QMap（自动去重）
    for (const auto& info : l) {
        qint64 songId = info.getsongId();

        // 校验歌曲ID有效性
        if (songId <= 0) {
            qWarning() << u8"初始化喜欢列表：跳过无效歌曲（songId=" << songId << u8"）";
            continue;
        }
        // 若已存在相同 songId，会自动覆盖（保留最新的 info）
        if (m_favoriteSongs.contains(songId)) {
            qDebug() << u8"初始化喜欢列表：覆盖重复歌曲（songId=" << songId << u8"）";
        }
        //初始化时顺便加载图片
        QUrl picurl=info.getm_image_url();
        HttpMgr::GetInstance()->downloadImage(picurl, songId);

        m_favoriteSongs.insert(songId, info); // 以 songId 为键存储
    }
    // 3. 输出初始化结果日志
    qDebug() << u8"喜欢列表初始化完成：共存储" << m_favoriteSongs.size()
             << u8"首歌曲（原始列表共" << l.size() << u8"首）";
}

bool MusicManager::isexistIcon(MusicInfo &item)
{
    if (_hashinfos.count(item.getsongId())){
        item = _hashinfos[item.getsongId()];
        qDebug() << "SongManager::isexistIcon : 找到了";
        return true;
    }
    else if(m_favoriteSongs.count(item.getsongId()))
    {
        item = m_favoriteSongs[item.getsongId()];
        qDebug() << "SongManager::isexistIcon : 找到了";
        return true;
    }
    qDebug() << u8"SongManager::isexistIcon :  没找到, 需添加"<<item.getsongId();
    return false;
}

void MusicManager::addSongitem(MusicInfo &icon)
{
    qint64 songId = icon.getsongId();
    bool isExisting = _hashinfos.contains(songId); // 标记是否为已存在的歌曲

    if (isExisting) {
        // 已存在：仅更新为空的字段
        MusicInfo curSongItem = _hashinfos[songId];
        if (curSongItem.getsongId() == 0)
            curSongItem.setsongId(icon.getsongId());
        if (curSongItem.gettitle().isEmpty())
            curSongItem.setTitle(icon.gettitle());
        if (curSongItem.getalbum().isEmpty())
            curSongItem.setAlbum(icon.getalbum());
        if (curSongItem.getcomposer().isEmpty())
            curSongItem.setcomposer(icon.getcomposer());
        if (curSongItem.getm_image().isNull())
            curSongItem.setm_image(icon.getm_image());
        if (curSongItem.getm_image_url().isEmpty())
            curSongItem.setm_image_url(icon.getm_image_url());
        if (curSongItem.getduration() == 0)
            curSongItem.setDuration(icon.getduration());
        if (curSongItem.getwangyiyun_id() == 0)
            curSongItem.setwangyiyun_id(icon.getwangyiyun_id());
        if (curSongItem.geturl().isEmpty()) {
            curSongItem.setlocal_url(icon.geturl());
            curSongItem.setwangyiyun_url(icon.geturl());
        }
        _hashinfos[songId] = curSongItem;
        qDebug() << "SongManager: " << curSongItem.gettitle() << u8" -- 已存在, 更新成功";
    } else {
        // 不存在：直接新增
        _hashinfos[songId] = icon;
        QUrl url = icon.geturl();
        if (url.isEmpty()) {
            qDebug() << "SongManager: " << icon.gettitle() << u8" -- url未存在, 添加无url版本成功" << u8"id为" << songId;
        } else {
            qDebug() << "SongManager: " << icon.gettitle() << u8" -- url存在,添加有url版本成功" << u8"id为" << songId;
        }
    }

    //维护最近100首的缓存限制

    //更新访问顺序：已存在的歌曲移到列表末尾（标记为最新），新歌曲直接加在末尾
    if (isExisting) {
        _recentSongIds.removeOne(songId); // 移除旧位置
    }
    _recentSongIds.append(songId); // 无论是否存在，都加在末尾（最新访问）

    // 若超过最大容量（100首），删除最早访问的记录
    if (_recentSongIds.size() > MAX_RECENT_COUNT) {
        qint64 oldestId = _recentSongIds.takeFirst(); // 移除列表中最早的id
        _hashinfos.remove(oldestId); // 从缓存中删除最早的歌曲
        qDebug() << u8"SongManager: 缓存超过" << MAX_RECENT_COUNT << u8"首，删除最早记录(id:" << oldestId << ")";
    }
}

void MusicManager::addLike(qint64 songId)
{
    // 1. 先检查全局缓存中是否存在该歌曲（避免添加无效数据）
    if (!_hashinfos.contains(songId)) {
        qWarning() << u8"添加喜欢失败：歌曲ID" << songId << u8"不在全局缓存中";
        return;
    }
    // 2. 获取全局缓存中的完整歌曲信息
    MusicInfo info = _hashinfos[songId];
    // 3. 强制标记为喜欢（避免状态不一致）
    info.setLike(true);
    // 4. 加入喜欢容器（自动去重，若已存在则覆盖更新信息）
    m_favoriteSongs[songId] = info;
    qDebug() << u8"歌曲ID" << songId << u8"添加到喜欢列表成功";
    MusicDBManager::GetInstance()->addLikedSong(info);
    //检查网络URL是否有效
    //若为空
    if (info.geturl()==QUrl())
    {
        qDebug() << u8"歌曲ID" << songId << u8"URL不存在，尝试自动获取...";
        // 无URL（网络歌曲）→ 调用 HttpMgr 获取播放URL
        HttpMgr::GetInstance()->getMusicUrl(QString::number(info.getsongId()),Modules::MODULE_LIKE);
    }
}

void MusicManager::removeLike(qint64 songId)
{
    // 1. 检查是否在喜欢列表中
    if (!m_favoriteSongs.contains(songId)) {
        qWarning() << u8"移除喜欢失败：歌曲ID" << songId << u8"不在喜欢列表中";
        return;
    }

    // 2. 从喜欢容器中移除
    m_favoriteSongs.remove(songId);
    // 3.同步在数据库也删除
    MusicDBManager::GetInstance()->removeLikedSong(songId);
    // 4. 额外检查全局缓存，确保状态一致（若存在则取消喜欢标记）
    if (_hashinfos.contains(songId)) {
        _hashinfos[songId].setLike(false);
    }
    if ( m_favoriteSongs.contains(songId)) {
         m_favoriteSongs[songId].setLike(false);
    }
    qDebug() << u8"歌曲ID" << songId << u8"从喜欢列表移除成功";
}

void MusicManager::SetLike(qint64 songId, bool a)
{
    // 先在全局缓存 _hashinfos 中更新喜欢状态（原有逻辑）
    for (MusicInfo& info : _hashinfos)
    {
        if (info.getsongId() == songId)
        {
            info.setLike(a); // 更新全局缓存中的喜欢状态
            qDebug() << u8"缓存容器歌曲ID" << songId << (a ? u8"已标记为喜欢" : u8"已取消喜欢");
            // 2. 同步维护“喜欢歌曲容器”_favoriteSongs
            if (a)
            {
                // 情况1：设置为喜欢 → 加入容器（去重）
                if (!m_favoriteSongs.contains(songId))
                {
                    addLike(songId);
                    //添加到喜欢窗口中
                    emit addLikesong(songId);
                    qDebug() << u8"歌曲ID" << songId << u8"已加入喜欢列表";
                }
                break;
            }
        }
    }
      if(!a)
    {

    //在爱心容器中,只处理删除情况
    for (MusicInfo& i : m_favoriteSongs)
    {
        if (i.getsongId() == songId)
        {
            i.setLike(a); // 更新喜欢容器中的喜欢状态
            qDebug() << u8"喜欢容器歌曲ID" << songId << (a ? u8"已标记为喜欢" : u8"已取消喜欢");

                // 情况2：取消喜欢 → 从容器移除
            if (m_favoriteSongs.contains(songId))
                {
                 emit removeLikesong(songId);
                    removeLike(songId);

                    qDebug() << u8"歌曲ID" << songId << u8"已从喜欢列表移除";
                }
               break;
        }
    }
    }
}

void MusicManager::setUrl(qint64 songId, QUrl url)
{
    bool isUpdated = false;

    // 1. 先更新全局缓存 _hashinfos 中的 URL
    for (MusicInfo& info : _hashinfos) {
        if (info.getsongId() == songId) {
            info.setwangyiyun_url(url); // 更新全局缓存的 URL
            qDebug() << u8"全局缓存中歌曲ID" << songId << u8"的URL已更新：" << url.toString();
            isUpdated = true;
            break;
        }
    }

    // 2. 若歌曲在爱心容器中，同步更新爱心容器的 URL
    if (m_favoriteSongs.contains(songId)) {
        MusicInfo& favoriteInfo = m_favoriteSongs[songId]; // 用引用直接修改
        favoriteInfo.setwangyiyun_url(url);
        qDebug() << u8"爱心容器中歌曲ID" << songId << u8"的URL已同步更新：" << url.toString();
        isUpdated = true;
    }

    // 3. 容错提示：若两处都没有该歌曲
    if (!isUpdated) {
        qWarning() << u8"更新URL失败：歌曲ID" << songId << u8"不在全局缓存或爱心容器中";
    }
}

MusicInfo MusicManager::getSongitem(qint64 id)
{

        // 1. 先从喜欢的网络音乐中查找
        for (const MusicInfo &info : m_favoriteSongs) {
            if (info.getsongId() == id) {  // 假设 MusicInfo 有 int id 成员
                return info;
            }
        }

        // 2. 再从 _hashinfos（所有音乐信息，以 URL 为 key）中查找
        for (const MusicInfo &info : _hashinfos.values()) {
            if (info.getsongId() == id) {
                return info;
            }
        }
        qDebug()<<u8"返回的是空";
        // 3. 如果都没找到，返回一个空的 MusicInfo 对象
        return MusicInfo();  // 默认构造，id 可能是 0 或未初始化，调用方可以判断

}

QList<MusicInfo> MusicManager::getAllFavoriteSongs() const
{
    // 直接通过 QMap 的 values() 方法获取所有值（自动转换为 QList）
    QList<MusicInfo> allSongs = m_favoriteSongs.values();
    qDebug() << u8"获取喜欢列表所有歌曲，共" << allSongs.size() << u8"首";
    return allSongs;
}

void MusicManager::addbanneritem(Bannerinfo &icon)
{
    qint64 songId = icon.songId;
    bool isExisting = m_banners.contains(songId); // 标记是否为已存在的歌曲

    if (isExisting) {
        qDebug() << u8"轮播图"<<icon.songId << u8" -- 已存在";
    } else {
        // 不存在：直接新增
        m_banners[songId] = icon;
         qDebug() <<u8"轮播图"<< icon.songId << u8" -- 已添加";
    }
}

QList<Bannerinfo> MusicManager::getAllbanners() const
{
    // 直接通过 QMap 的 values() 方法获取所有值（自动转换为 QList）
    QList<Bannerinfo> allbanners = m_banners.values();
    qDebug() << u8"获取喜欢列表所有歌曲，共" << allbanners.size() << u8"首";
    return allbanners;
}

bool MusicManager::isBannerImageCached(qint64 songId)
{
    // 1. 第一步：判断该songId对应的Banner是否存在于内存的m_banners中
    if (!m_banners.contains(songId)) {
        qDebug() << u8"songId" << songId << u8"对应的Banner不存在，无需检查缓存";
        return false;
    }

    // 2. 第二步：获取该Banner的信息，先检查内存缓存（图片是否已加载到QPixmap）
    Bannerinfo banner = m_banners.value(songId);
    // 检查Banner的图片是否有效（非空、尺寸合理，避免空图误判）
    if (!banner.pic.isNull() && banner.pic.width() > 0 && banner.pic.height() > 0) {
        qDebug() << u8"songId" << songId << u8"的Banner图片已存在内存缓存";
        return true;
    }
    // 4. 所有缓存场景均未命中
    qDebug() << u8"songId" << songId << u8"的Banner图片未缓存";
    return false;
}

bool MusicManager::isSonglistImageCached(qint64 songlistId)
{
    // 1. 第一步：判断该songId对应的songlist是否存在于内存的songlist中
    if (!m_songlists.contains(songlistId)) {
        qDebug() << u8"songlistId" << songlistId << u8"对应的songlist不存在，无需检查缓存";
        return false;
    }

    // 2. 第二步：获取该Banner的信息，先检查内存缓存（图片是否已加载到QPixmap）
    SongListInfo songlist = m_songlists.value(songlistId);
    // 检查Banner的图片是否有效（非空、尺寸合理，避免空图误判）
    if (!songlist.pic.isNull() && songlist.pic.width() > 0 && songlist.pic.height() > 0) {
        qDebug() << u8"songlistId" << songlistId << u8"的songlist图片已存在内存缓存";
        return true;
    }
    // 4. 所有缓存场景均未命中
    qDebug() << u8"songlistId" << songlistId << u8"的songlist图片未缓存";
    return false;
}

QList<SongListInfo> MusicManager::getAllsonglists() const
{
    // 直接通过 QMap 的 values() 方法获取所有值（自动转换为 QList）
    QList<SongListInfo> allsonglists = m_songlists.values();
    qDebug() << u8"获取喜欢列表所有歌曲，共" << allsonglists.size() << u8"首";
    return allsonglists;
}

void MusicManager::addsonglistitem(SongListInfo &icon)
{
    qint64 songlistId = icon.songlistid;
    bool isExisting = m_songlists.contains(songlistId); // 标记是否为已存在的歌曲

    if (isExisting) {
        qDebug() << u8"歌单图"<<icon.songlistid << u8" -- 已存在";
    } else {
        // 不存在：直接新增
        m_songlists[songlistId] = icon;
        qDebug() <<u8"歌单图"<< icon.songlistid << u8" -- 已添加";
    }
}

void MusicManager::onImageDownloaded(ImageDownloadInfo info, const QPixmap &image, bool success)
{
    Q_UNUSED(success);
    //若下载的图片为歌曲图
    if(info.imager==IMAGEId::SONG_IMAGE)
 {
        qint64 songId =info.id;
    // 1. 从搜索结果列表中找到对应songId的MusicInfo
    for (MusicInfo& info : _hashinfos) { // 注意：需用引用&修改原对象
        if (info.getsongId() == songId) {
            // 2. 调用setm_image更新封面
            info.setm_image(image);
            qDebug() << u8"歌曲" << info.gettitle() << u8"封面已更新";

            // 3. 通知UI刷新（搜索页面更新）
            emit refreshListViewItem(songId); // 自定义函数：刷新列表中该歌曲的显示
            break;
        }
    }
    //在更新一遍喜欢列表中的,防止遗漏
    for (MusicInfo& info :m_favoriteSongs)
    { // 注意：需用引用&修改原对象
        if (info.getsongId() == songId) {
            // 2. 调用setm_image更新封面
            info.setm_image(image);
            qDebug() << u8"喜欢列表中的歌曲" << info.gettitle() << u8"封面已更新";
          emit refreshLikeListViewItem(songId); // 自定义函数：刷新列表中该歌曲的显示
            break;
        }
    }

 }//下载的若为轮播图
    else if(info.imager==IMAGEId::BANNER_IMAGE)
    {
         qint64 songId =info.id;
     // 1. 从搜索结果列表中找到对应songId的MusicInfo
     for (Bannerinfo& info : m_banners) { // 注意：需用引用&修改原对象
         if (info.songId == songId) {
             // 2. 调用setm_image更新封面
             info.pic=image;
             qDebug() << u8"轮播封面已更新"<<info.songId;
             // 3. 通知UI刷新
             break;
         }
     }
    }
 //下载的若为歌单图
 else if(info.imager==IMAGEId::SONGLIST_IMAGE)
 {
     qint64 songlistId =info.id;
     // 1. 从搜索结果列表中找到对应songId的MusicInfo
     for (SongListInfo& info : m_songlists) { // 注意：需用引用&修改原对象
         if (info.songlistid == songlistId) {
             // 2. 调用setm_image更新封面
             info.pic=image;
             qDebug() << u8"歌单封面已更新"<<info.songlistid;
             // 3. 通知UI刷新

             break;
         }
     }
    }
}
