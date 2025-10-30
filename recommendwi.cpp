#include "recommendwi.h"
#include "songlistcardwi.h"
#include "ui_recommendwi.h"
#include"httpmgr.h"
Recommendwi::Recommendwi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Recommendwi)
{
    ui->setupUi(this);
   ui->coverFlowwi->setStyleSheet(R"(
    #widget_2 {
        background-color: #f7f9fc; /* 淡灰蓝色背景 */
        border-radius: 12px;      /* 12px 圆角 */
        border: 1px solid black;  /* 1px 黑色边框 */
        margin: 10px;             /* 可选：与窗口边缘留10px空隙，避免边框贴边 */
    }
)");
    //初始轮播图
    HttpMgr::GetInstance()->getBanner();

    //初始推荐歌单(初始化完成后发送信息,回调会调用initsonglistcardwi)
    HttpMgr::GetInstance()->getsonglist();

}

Recommendwi::~Recommendwi()
{
    delete ui;
}

void Recommendwi::initsonglistcardwi()
{
    if (!ui->songwi) {
        qWarning() << u8"推荐歌单容器ui->songwi未初始化";
        return;
    }

    // 清除旧布局及控件
    QLayout *oldLayout = ui->songwi->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
        delete oldLayout;
    }

    QList<SongListInfo> songlists = MusicManager::GetInstance()->getAllsonglists();
    if (songlists.isEmpty()) {
        qDebug() << u8"未获取到任何歌单数据";
        return;
    }

    // 限制只显示5个歌单（如果数据超过5个）
    int showCount = qMin(5, songlists.size());
    qDebug() << u8"显示" << showCount << u8"个歌单卡片";

    // 创建水平布局
    QHBoxLayout *songListLayout = new QHBoxLayout(ui->songwi);
    // 设置左右边距为0，上下边距可根据需要调整（这里保持24）
    songListLayout->setContentsMargins(0, 24, 0, 24); // 左右边距0，上下边距24
    // 固定卡片之间的间距为24
    songListLayout->setSpacing(24);


    // 遍历创建歌单卡片
    for (int i = 0; i < showCount; ++i) {
        SongListInfo &currSongList = songlists[i];
        SongListCardwi *card = new SongListCardwi(ui->songwi);
        card->setFixedSize(210, 288); // 固定尺寸
        card->setinfo(currSongList);
        songListLayout->addWidget(card);
        qDebug() << u8"创建歌单卡片：" << currSongList.songlistname << u8"(索引：" << i << ")";
        card->setPixmap(currSongList.pic);
        //点击事件
        connect(card, &SongListCardwi::clicked, this,&Recommendwi::songlistclick);
    }
    // 确保布局占满窗口
    songListLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
