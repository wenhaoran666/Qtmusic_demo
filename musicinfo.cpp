#include "musicinfo.h"
#include"httpmgr.h"
MusicInfo::MusicInfo()
{

}

qint64 MusicInfo::getsongId() const
{
    return songId;
}

void MusicInfo::setsongId(qint64 id)
{
    songId=id;
}

qint64 MusicInfo::getwangyiyun_id() const {
    return wangyiyun_id;
}

void MusicInfo::setwangyiyun_id(qint64 wangyiid) {
    wangyiyun_id = wangyiid;
}

// QUrl MusicInfo::getwangyiyun_url() const {
//     return wangyiyun_url;
// }

void MusicInfo::setwangyiyun_url(QUrl wangyiurl) {
    wangyiyun_url = wangyiurl;
}

void MusicInfo::setlocal_url(QUrl local)
{
    local_url=local;
}

QString MusicInfo::gettitle() const
{
    return m_title;
}

void MusicInfo::setTitle(QString title)
{
    m_title=title;
}

QString MusicInfo::getcomposer() const
{
    return m_composer;
}

void MusicInfo::setcomposer(QString composer)
{
    m_composer=composer;
}

QString MusicInfo::getalbum() const
{
    return m_album;
}

void MusicInfo::setAlbum(QString album)
{
    m_album=album;
}

qint64 MusicInfo::getduration() const
{
    return m_duration;
}

void MusicInfo::setDuration(qint64 duration)
{
    m_duration=duration;
}

QString MusicInfo::getsize() const
{
    return m_size;
}

void MusicInfo::setSize(QString size)
{
    m_size=size;
}

QPixmap MusicInfo::getm_image() const {
    return m_image;
}

void MusicInfo::setm_image(QPixmap image) {
    m_image = image;
}

QUrl MusicInfo::getm_image_url() const {
    return m_image_url;
}

void MusicInfo::setm_image_url(QUrl image_url) {
    m_image_url = image_url;
}

QUrl MusicInfo::geturl() const
{

     //优先返回本地路径（local_url），如果本地路径为空，则返回在线 URL（wangyiyun_url）
    if (local_url.isEmpty() == false) return local_url;
    if (wangyiyun_url.isEmpty() == false) return wangyiyun_url;
     return QUrl();
}
// 在 MusicInfo.cpp 中实现
bool MusicInfo::operator==(const MusicInfo& other) const
{
    return this->getsongId() == other.getsongId();
}

bool MusicInfo::getisLiked() const
{
    return isLiked;
}

void MusicInfo::setLike(bool a)
{
    isLiked=a;
}



