#include "Searchwi.h"
#include <QHBoxLayout>
#include"musicmanager.h"
#include "ui_searchwi.h"
#include<QScrollBar>
Searchwi::Searchwi(QWidget *parent)
    : QWidget(parent)
    , m_maxVisibleItems(15)
, ui(new Ui::Searchwi)
{
    ui->setupUi(this);
    ui->widget_4->hide();//默认不显示
    // 窗口样式设置（无边框、透明背景）
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip | Qt::WindowDoesNotAcceptFocus);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    // 初始化QListView（可在UI设计器中拖出后关联）
    m_listView = ui->m_listView;
    m_listView->setMouseTracking(true); // 鼠标移动时立即触发状态更新
    m_listView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置该 QListView 不允许编辑。
    m_listView->setSelectionMode(QAbstractItemView::SingleSelection);//设置该 ListView 的 选择模式为：单选。
    m_listView->setFocusPolicy(Qt::NoFocus);
    m_listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);//设置 垂直滚动条的滚动模式为：按像素平滑滚动。
    m_listView->setSpacing(0);
    //设置样式(项的样式完全交由委托处理)
    m_listView->setStyleSheet(
        "QListView {"
        "   background-color: transparent;"           // 列表背景透明（可选）
        "   border: none;"                           // 列表无边框
        "   outline: none;"
        "}"
        );
    // 获取垂直滚动条
    QScrollBar *vScrollBar =  m_listView->verticalScrollBar();
    // 设置单步滚动距离（鼠标滚轮一次、点击箭头的滚动像素）
    vScrollBar->setSingleStep(20); // 默认通常是 10-15，值越大滚动越快

    // 设置页面滚动距离（点击滚动条空白处的滚动像素）
    vScrollBar->setPageStep(100); // 默认通常是视图高度的一半，值越大滚动越快
    // 初始化模型和委托
    m_model = new BaseMusicModel(this);
    m_delegate = new SearchwiDelegate(this);
    m_listView->setModel(m_model);
    m_listView->setItemDelegate(m_delegate);
    //图片加载触发刷新
    connect(MusicManager::GetInstance().get(),&MusicManager::refreshListViewItem,this,&Searchwi::onrefreshListViewItem);

    // 关键：连接委托的 playButtonClicked 信号到自定义槽函数
    connect(m_delegate, &SearchwiDelegate::playButtonClicked,
            this, &Searchwi::onDelegatePlayClicked);
    // 连接信号槽
    connect(m_listView, &QListView::clicked, this, &Searchwi::onItemClicked);
    connect(m_listView, &QListView::doubleClicked, this, &Searchwi::onItemDoubleClicked);
}
// 新增：处理委托的播放按钮点击（从模型提取 MusicInfo）
void Searchwi::onDelegatePlayClicked(const QModelIndex &index) {
    if (!index.isValid()) return; // 校验索引有效性

    // 从模型中获取当前索引对应的 MusicInfo（通过 BaseMusicModel 的接口）
    MusicInfo musicInfo = m_model->getMusicInfo(index.row());

    // 转发信号给主窗口（携带具体 MusicInfo，而非索引）
    emit searchPlayRequested(musicInfo);
}
void Searchwi::setSearchResults(const QList<MusicInfo> &results)
{
    // 通过模型更新视图数据（从MusicManager获取最新缓存）
    QList<MusicInfo> cachedResults;
    for ( auto info : results) {
        cachedResults << MusicManager::GetInstance()->getSongitem(info.getsongId());
    }
    m_model->setMusicList(cachedResults);

}

void Searchwi::showkong()
{
    ui->scrollArea->hide();
    ui->widget_4->show();
}

void Searchwi::setMaxVisibleItems(int count)
{
    m_maxVisibleItems = qMax(1, count);
}


void Searchwi::onItemClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit playRequested(m_model->getMusicInfo(index.row()));
    }
}

void Searchwi::onItemDoubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit itemDoubleClicked(m_model->getMusicInfo(index.row()));
    }
}

void Searchwi::onrefreshListViewItem(qint64 songId)
{
    // 遍历模型的歌曲列表，找到与 songId 匹配的行索引
    for (int row = 0; row < m_model->rowCount(); ++row)
    {

        MusicInfo info = m_model->getMusicInfo(row); // 调用模型接口获取歌曲信息
        if (info.getsongId() == songId)
            {
            m_model->refreshRow(row);
                qDebug() << u8"已刷新歌曲ID为" << songId << u8"的UI，行号：" << row;
            }
            break; // 找到后退出循环
        }
}

Searchwi::~Searchwi()
{
    delete ui;
}

void Searchwi::settitle(QString s)
{
    qDebug()<<"111111111111111111111111111";
    ui->label_searchText->setText(s);
    repaint();
}
