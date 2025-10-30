#ifndef LISTMUSICITEMWI_H
#define LISTMUSICITEMWI_H

#include "musicinfo.h"
#include "qlabel.h"
#include <QWidget>

namespace Ui {
class Listmusicitemwi;
}

class Listmusicitemwi : public QWidget
{
    Q_OBJECT

public:
    explicit Listmusicitemwi(const MusicInfo &musicInfo,QWidget *parent = nullptr);
    ~Listmusicitemwi();
    void setindex(int index);//设置序号
    void setnowplay();//设置正在播放的状态
    void setnormal();//设置普通状态
    void  setRoundedPixmap(QLabel* label, const QPixmap& sourcePix, int radius);//设置圆角
signals:
    void Play(const MusicInfo message);

private slots:
    void on_index_btn_clicked();//点击播放
private:
    bool eventFilter(QObject *watched, QEvent *event);//事件过滤
    int m_index;//当前序号
     MusicInfo m_musicInfo;
    Ui::Listmusicitemwi *ui;
};

#endif // LISTMUSICITEMWI_H
