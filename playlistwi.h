#ifndef PLAYLISTWI_H
#define PLAYLISTWI_H

#include "listmusicitemwi.h"
#include "musicinfo.h"
#include "qboxlayout.h"
#include <QDialog>
#include<QMap>
//使用 QScrollArea + QVBoxLayout,将一个个Listmusicitemwi窗口显示实现类似列表效果
//若需处理大量数据项要使用Model/View 架构
 // 最近播放 / 用户自定义歌单列表（推荐使用Model/View 架构）
//播放列表窗口,收到不同窗口发送的播放信号,自动清空队列,将发送信号的窗口歌曲队列添加上去
namespace Ui {
class playlistwi;
}

class playlistwi : public QDialog
{
    Q_OBJECT

public:
    explicit playlistwi(QWidget *parent = nullptr);
    ~playlistwi();

    void addmusicitem(Listmusicitemwi &items);//添加音乐项
    void setallwidget();
signals:
    void listplay(const MusicInfo message);//点击列表歌曲触发的播放
     void listclear();//列表清空
public slots:
    //与数据层通信的槽,在主窗口连接
    void slot_listchange(const QList<MusicInfo> &newSongs);//窗口更新槽
    void slot_nowchange(int index);

private slots:
    void on_clear_btn_clicked();

private:
    QVBoxLayout* _containerLayout;
    void setcontainerui();//
    QMap<int, Listmusicitemwi*> listitems;   //存放音乐项
    QList<int> m_shuffleOrder;              // 乱序时使用的索引顺序（打乱后的索引列表）
    int m_currentIndex = -1;                 // 当前播放歌曲在列表中的索引
    int _musiccount=0;//项数量
    int l=0;
    Ui::playlistwi *ui;
};

#endif // PLAYLISTWI_H
