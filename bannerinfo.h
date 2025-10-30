//轻量
#ifndef BANNERINFO_H
#define BANNERINFO_H
#include "qpixmap.h"
#include "qurl.h"
struct Bannerinfo {
    QPixmap pic;       // 轮播图片（供FlowLabel显示）
    qint64 songId;     // 关联的歌曲ID（点击后使用）
    QUrl picUrl;       // 图片URL（用于下载）
};
#endif // GLOBAL_H
