#ifndef SEARCHWI_H
#define SEARCHWI_H

#include "musicinfo.h"
#include <QWidget>
#include <QListView>
#include <QVBoxLayout>
 #include "basemusicmodel.h"
 #include "searchwidelegate.h"
namespace Ui {
class Searchwi;
}
class Searchwi : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int maxVisibleItems READ maxVisibleItems WRITE setMaxVisibleItems)

public:
    explicit Searchwi(QWidget *parent = nullptr);
    ~Searchwi();
    //设置搜索结果窗口标题
    void settitle(QString s);
    // 设置搜索结果窗口(数据)
    void setSearchResults(const QList<MusicInfo> &results);
    void showkong();//显示未搜索到窗口
    // 设置最大可见项数（控制窗口高度）
    void setMaxVisibleItems(int count);
    int maxVisibleItems() const { return m_maxVisibleItems; }

signals:
    // 单击项时触发
    void playRequested(const MusicInfo &info);
    // 双击项时触发（可选）
    void itemDoubleClicked(const MusicInfo &info);
    // 转发委托的播放请求信号
    void searchPlayRequested(const MusicInfo& musicInfo);
private slots:
    //转发委托的播放请求发送
    void onDelegatePlayClicked(const QModelIndex &index);
    // 处理列表项点击
    void onItemClicked(const QModelIndex &index);
    // 处理列表项双击
    void onItemDoubleClicked(const QModelIndex &index);
    //处理音乐管理类传来的图片更新
    void onrefreshListViewItem(qint64 songId);
private:
    QListView *m_listView;          // 界面拖出的列表视图
     BaseMusicModel *m_model;     // 数据模型
    SearchwiDelegate *m_delegate; // 样式委托
    int m_maxVisibleItems;          // 最大可见项数

private:
    Ui::Searchwi *ui;
};

#endif // SEARCHWI_H
