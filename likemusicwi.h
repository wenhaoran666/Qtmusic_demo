#ifndef LIKEMUSICWI_H
#define LIKEMUSICWI_H

#include "basemusicmodel.h"
#include "likewidelegate.h"
#include "musicinfo.h"
#include "qlistview.h"
#include "musicmanager.h"
#include <QWidget>


namespace Ui {
class Likemusicwi;
}

class Likemusicwi : public QWidget
{
    Q_OBJECT

public:
    explicit Likemusicwi(QWidget *parent = nullptr);
    ~Likemusicwi();
    // 设置搜索结果窗口(数据)
    void setLikeResults(const QList<MusicInfo> &results);
    void addInfo(qint64 songId);//添加一个项
    void removeinfo(qint64 songId);//去除一个项
    void showkong();//显示未搜索到窗口
    // 设置最大可见项数（控制窗口高度）
    void setMaxVisibleItems(int count);
    int maxVisibleItems() const { return m_maxVisibleItems; }
    //根据模型项数量更新图标或显示空提示
    void updateIcon();

signals:
     //单击项时触发
    void playRequested(const MusicInfo &info);
    // 双击项时触发（可选）
    void itemDoubleClicked(const MusicInfo &info);
    // 转发委托的播放请求信号
    void LikePlayRequested(const MusicInfo& musicInfo,QList<MusicInfo> list);
private slots:
    void onremoveLikesong(qint64 songId);//接收管理类信号去除项
    void onaddLikesong(qint64 songId);//接收管理类信号添加项
    //转发委托的播放请求发送
    void onDelegatePlayClicked(const QModelIndex &index);
    // 处理列表项点击
    void onItemClicked(const QModelIndex &index);
    // 处理列表项双击
    void onItemDoubleClicked(const QModelIndex &index);
    //加载图片
    void onrefreshLikeListViewItem(qint64 songId);
private:
    QListView *m_listView;          // 界面拖出的列表视图
    BaseMusicModel *m_model;     // 数据模型
    Likewidelegate *m_delegate; // 样式委托
    int m_maxVisibleItems;          // 最大可见项数
    Ui::Likemusicwi *ui;
};

#endif // LIKEMUSICWI_H
