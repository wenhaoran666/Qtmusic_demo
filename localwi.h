#ifndef LOCALWI_H
#define LOCALWI_H

#include "musicitemwi.h"
#include "qboxlayout.h"
#include "qmediaplayer.h"
#include <QWidget>
#include<QMap>

namespace Ui {
class Localwi;
}

class Localwi : public QWidget
{
    Q_OBJECT

public:
    explicit Localwi(QWidget *parent = nullptr);
    void addmusicitem(MusicItemwi &musicitrm);//添加音乐项
    void showitems();
    ~Localwi();
signals:
    void localplay(const QList<MusicInfo>m_playlist,const MusicInfo message);//点击项的播放继续发送信号向主窗口传递
    void updatelist();//重置后触发的列表更新(暂时只做提醒)/*const QList<MusicInfo>playlist*/
private slots:
    void on_content_btn_clicked();//添加文件夹点击
    void on_reload_btn_clicked();//刷新点击

    void on_playall_btn_clicked();//播放全部按钮

private:
    void setcontainerui();//设置音乐窗口布局
    QMap<int, MusicItemwi*> _musicitems;//存放音乐项
    QList<MusicInfo>m_playlist;//存放此窗口播放列表
    int _musiccount;//音乐项数量
      QVBoxLayout* _containerLayout;
    QStringList _selectedPaths;//选择的文件夹路径集合

      bool isMedia(const QString& path);//判断是否为音频文件
    int processedFiles = 0;    //已经处理的
    QMediaPlayer *m_play;
      int l=0;
    Ui::Localwi *ui;
};

#endif // LOCALWI_H
