#ifndef RECOMMENDWI_H
#define RECOMMENDWI_H

#include "global.h"
#include <QWidget>

namespace Ui {
class Recommendwi;
}

class Recommendwi : public QWidget
{
    Q_OBJECT

public:
    explicit Recommendwi(QWidget *parent = nullptr);
    ~Recommendwi();
    //初始化歌单卡片
    void initsonglistcardwi();
signals:
    //接收子窗口点击信号,向主窗口传递
    void songlistclick(SongListInfo info);
private:
    Ui::Recommendwi *ui;
};

#endif // RECOMMENDWI_H
