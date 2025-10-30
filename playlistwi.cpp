#include "playlistwi.h"
#include "qdebug.h"
#include "ui_playlistwi.h"
#include<QRandomGenerator>
playlistwi::playlistwi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::playlistwi)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground); // 窗口背景透明
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    setcontainerui();//设置列表ui


}
void playlistwi::addmusicitem(Listmusicitemwi &items)
{

    listitems[_musiccount]=&items;//存放音乐项
    items.setindex(++l);//乱设的
    _containerLayout->insertWidget(_musiccount, &items);  // 插入到索引 0，即最上方
    _musiccount++;
}

void playlistwi::slot_listchange(const QList<MusicInfo> &newSongs)
{
    //将所有音乐项清空
    for(auto m:listitems)
    {
        m->hide();
        _containerLayout->removeWidget(m);
        m->deleteLater();                     // 安全地安排删除
    }
    //容器也清空
    listitems.clear();
    _musiccount=0;//数量也请零
    l=0;
    qDebug() << u8"列表窗口刷新:";
    for(int i=0;i<newSongs.size();i++)
    {
        Listmusicitemwi *items=new Listmusicitemwi(newSongs[i],this);
        connect(items,&Listmusicitemwi::Play,this,[=](const MusicInfo message){
            emit listplay(message);
        });//将点击的歌曲和播放列表传入
        addmusicitem(*items);
    }
}

void playlistwi::slot_nowchange(int index)
{
    if(m_currentIndex!=-1)
    {
    listitems[m_currentIndex]->setnormal();
    m_currentIndex=index;
    listitems[index]->setnowplay();
    }
}


playlistwi::~playlistwi()
{
    delete ui;
}

void playlistwi::setcontainerui()
{
    //container窗口设置垂直布局,下方设置弹簧一直顶着,有窗口弹簧就伸缩
    _containerLayout = new QVBoxLayout(ui->container_wi);
    _containerLayout->setSpacing(0);                      // 控件之间的间距为 10px
    _containerLayout->setContentsMargins(0, 0, 0, 0);  // 左、上、右、下边距
    QSpacerItem *spacer = new QSpacerItem(20, 758, QSizePolicy::Expanding,QSizePolicy::Expanding);
    _containerLayout->addSpacerItem(spacer);
}



void playlistwi::on_clear_btn_clicked()
{
    //将所有音乐项清空
    for(auto m:listitems)
    {
        m->hide();
        _containerLayout->removeWidget(m);
        m->deleteLater();                     // 安全地安排删除
    }
    //容器也清空
    listitems.clear();
    _musiccount=0;//数量也请零
    l=0;
    qDebug() << u8"列表窗口清空:";
    emit listclear();
}

