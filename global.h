#ifndef GLOBAL_H
#define GLOBAL_H
#include "qchar.h"
#include "qhashfunctions.h"
#include "qpixmap.h"
extern QString cloud_url_prefix;
enum ClickLbState//按钮状态
{
    Normal = 0,
    Selected = 1
};
QString truncateText(const QString &str, int maxLength);//截断函数

// 播放模式枚举
enum PlayMode {
    LoopNormal,    // 正序循环
    Loopcycle,     // 单曲循环
    LoopReverse,   // 倒序循环
    LoopShuffle    // 乱序循环
};

//定义ReqId枚举类型
enum ReqId{
    ID_SEARCHRECOM_MUSIC=1001,//搜索歌曲建议
    ID_SEARCH_MUSIC = 1002,    // 搜索歌曲
    ID_GET_BANNER = 1003, // 获取主页轮播图
    ID_GET_DETAIL = 1004,   // 获取歌曲详情
    ID_GET_SONGLIST = 1005,   // 获取推荐歌单信息
     ID_GET_LIST_INFO = 1006,   // 获取歌单中歌曲信息
     ID_GET_MUSIC_PLAYURL=1007,  // 获取播放URL
    ID_GET_ARTIST_INFO = 1008   // 获取歌手信息(没用)


};


// 定义模块枚举类型（结合项目功能模块划分）
enum Modules{
    MODULE_RECOMMEND,      //推荐界面
    MODULE_UI,           // UI交互模块（界面更新、状态切换等）(没用)
    MODULE_SEARCH,    // 搜索模块（歌曲搜索、结果处理等）
    MODULE_LIKE,     //喜欢音乐模块
    MODULE_LYRIC         // 歌词模块（歌词获取、同步显示等）(没用)
};

// 错误码枚举（补充网络请求相关错误）
enum ErrorCodes {
    ERROR_NONE = 0,           // 无错误
    ERROR_NETWORK = 100,      // 网络错误
    ERROR_PARSE = 101,        // 数据解析错误
    ERROR_API = 102,          // API返回错误（如404、500）
    ERROR_TIMEOUT = 103       // 超时错误
};
//下载图片枚举类型
enum IMAGEId
{
    SONG_IMAGE = 200,         //歌曲图片
    BANNER_IMAGE =201,        //轮播图图片
    SONGLIST_IMAGE =202,     //歌单图片

};
//图片下载信息
struct ImageDownloadInfo {
    qint64 id;           // 可以是 songId 或 bannerId
    IMAGEId imager;      //图片枚举
};

//歌单信息
struct SongListInfo{
    qint64 songlistid;       //歌单id
    QPixmap pic;       // 图片
    QString songlistname;  //歌单名
};

extern int nextSongId;  // 全局唯一ID起始值，可在适当作用域内定义（如音乐管理类中）

#endif // GLOBAL_H
