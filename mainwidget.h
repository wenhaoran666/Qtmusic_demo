#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "musicinfo.h"
#include "playlistmodel.h"
#include "playlistwi.h"
#include "searchrecomwi.h"
#include "statepushbutton.h"
#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    bool eventFilter(QObject *watched, QEvent *event) override;
    PlaylistModel* getPlaylistModel();//让播放器窗口获取播放列表数据层
    // 在程序初始化时调用开启本地网易云api
    void startNeteaseApiService();
    qint64 getNodeChildPid(qint64 parentPid);
    void killApiServiceByPid(qint64 pid) ;

private slots:
    void on_close_btn_clicked();//关闭主界面

    void on_minimize_btn_clicked();//最小化窗口
 void ClearLabelState(StatePushbutton *lb);//除了lb，list中的其他控件全部回到初始状态
    void on_local_btn_clicked();//点击本地音乐按钮

 void on_recommend_btn_clicked();//点击推荐音乐界面

    void on_featured_btn_clicked();

 void on_podcast_btn_clicked();

    void on_explore_btn_clicked();

 void on_follow_btn_clicked();

    void on_favorite_btn_clicked();//点击喜欢音乐窗口

 void on_recent_btn_clicked();
   void on_back_btn_clicked();//后退按钮
    void slotlocalplay(const QList<MusicInfo> playlist, const MusicInfo message);//接收本地窗口歌曲项播放信号的槽
    void slotlistlplay(const MusicInfo message);//接收列表窗口歌曲项播放信号
    void slotlistclear();//清空列表
 void slotupdatelist();//接收本地窗口更新的槽
    void slotlistshow();//显示列表
    void  slot_music_search_finish(ReqId id, QString res, ErrorCodes err); //歌曲搜索模块完成
    void slot_music_like_finish(ReqId id, QString res, ErrorCodes err);//歌曲喜欢模块完成
    void slot_music_recommend_finish(ReqId id, QString res, ErrorCodes err);//歌曲推荐模块完成
    void slot_suggestionSelected(const QString &text);//点击搜索建议项触发搜索
    //搜索视图的项播放函数
    void  onSearchPlayRequested(const MusicInfo& musicInfo);
    //喜欢视图的项播放函数
    void  onLikePlayRequested(const MusicInfo& musicInfo, QList<MusicInfo> list);
    //歌单点击触发歌单窗口显示
    void onsonglistclick(SongListInfo info);
    //歌单视图的项播放函数
    void onSonglistPlayRequested(const MusicInfo& musicInfo, QList<MusicInfo> list);
private:
    void initui();
    void initmainwidget();//初始化主界面
    void initheadui();//初始化头窗口ui
    void inittray();//初始化托盘
    void initsidebar();//初始化侧边栏按钮

     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void mouseReleaseEvent(QMouseEvent *event) override;

    //用于拖动窗口
    QPoint dragPosition; // 用于记录鼠标拖动的位置
    bool m_dragging = false;  // 可选，标记是否正在拖动

    QList<StatePushbutton*> _lb_list;//存放侧边栏按钮
    playlistwi *_playlistwi;//播放列表窗口
    PlaylistModel*_playmode;//播放列表数据层

    SearchRecomwi *recomWi;//搜索建议窗
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
