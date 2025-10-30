#ifndef MUSICINFO_H
#define MUSICINFO_H
#include <QMetaType>  // 必须包含此头文件才能使用 Q_DECLARE_METATYPE
//音乐信息类
#include "qpixmap.h"
#include "qurl.h"
#include<QString>
//存信息若不设计复杂逻辑和继承还是建议设为结构体
//因为涉及异步加载网络图片资源,还是设计为类
class MusicInfo
{
 public:
    MusicInfo();
     // songId：歌曲唯一标识（推荐用于所有歌曲，本地/网络通用）
     qint64 getsongId() const;
     void setsongId(qint64 id);

    //const表示不修改成员变量
     qint64 getwangyiyun_id() const;
    void setwangyiyun_id( qint64 wangyiid);

    // QUrl getwangyiyun_url() const;
     void setwangyiyun_url( QUrl wangyiurl);

    void setlocal_url( QUrl local);

    QString gettitle() const;
    void setTitle( QString title);

    QString getcomposer() const;
    void setcomposer( QString composer);

    QString getalbum() const;
    void setAlbum( QString album);

    qint64 getduration() const;
    void setDuration( qint64 duration);

    QString getsize() const;
    void setSize(QString size);

    QPixmap getm_image() const;
    void setm_image( QPixmap image);

    QUrl getm_image_url() const;
    void setm_image_url(  QUrl image_url);

    QUrl geturl() const;//获取路径
    bool operator==(const MusicInfo& other) const;

    bool getisLiked()const;
    void setLike(bool a);

  private:
      qint64 songId = 0;                // 新增：歌曲唯一标识 ID（推荐用于全局唯一标识歌曲）

    qint64 wangyiyun_id = 0;//网易云歌曲唯一 ID(暂时与songid一致)
    QUrl wangyiyun_url;//网易云链接地址
    QUrl local_url;//本地地址
    QString m_title;//标题
    QString m_composer;//作者
    QString m_album;//专辑
    QPixmap m_image;//封面
    QUrl m_image_url;//封面路径
    qint64 m_duration = 0;//时长
    QString m_size;//大小
     bool isLiked = false; // 喜欢状态（默认未点击）
};


// 告诉 Qt 的元对象系统：这是一个可以被识别的自定义类型
Q_DECLARE_METATYPE(MusicInfo)
#endif // MUSICINFO_H
