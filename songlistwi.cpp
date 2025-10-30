#include "songlistwi.h"
#include "qpainterpath.h"
#include "qscrollbar.h"
#include "ui_songlistwi.h"
#include"musicmanager.h"
Songlistwi::Songlistwi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Songlistwi)
{
    ui->setupUi(this);
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
    connect(MusicManager::GetInstance().get(),&MusicManager::refreshListViewItem,this,&::Songlistwi::onrefreshLikeListViewItem);

    // 关键：连接委托的 playButtonClicked 信号到自定义槽函数
    connect(m_delegate, &SearchwiDelegate::playButtonClicked,
            this, &Songlistwi::onDelegatePlayClicked);
    // 连接信号槽
    connect(m_listView, &QListView::clicked, this, &Songlistwi::onItemClicked);
    connect(m_listView, &QListView::doubleClicked, this, &Songlistwi::onItemDoubleClicked);
}

void Songlistwi::onDelegatePlayClicked(const QModelIndex &index) {

    if (!index.isValid()) return; // 校验索引有效性

    // 1. 获取当前点击项对应的 MusicInfo
    MusicInfo currentMusic = m_model->getMusicInfo(index.row());

    // 2. 遍历模型，提取所有数据到列表
    QList<MusicInfo> allMusicList;
    int rowCount = m_model->rowCount(); // 获取模型总数据量
    for (int i = 0; i < rowCount; ++i) {
        allMusicList.append(m_model->getMusicInfo(i)); // 逐个添加到列表
    }

    // 3. 转发信号（携带当前播放项 + 全部列表数据）
    emit SonglistPlayRequested(currentMusic, allMusicList);
}
void Songlistwi::setsonglistResults(const QList<MusicInfo> &results)
{
    // 通过模型更新视图数据（从MusicManager获取最新缓存）
    QList<MusicInfo> cachedResults;
    for ( auto info : results) {
        cachedResults << MusicManager::GetInstance()->getSongitem(info.getsongId());
    }
    m_model->setMusicList(cachedResults);
}



void Songlistwi::setMaxVisibleItems(int count)
{
    m_maxVisibleItems = qMax(1, count);
}


void Songlistwi::onItemClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit playRequested(m_model->getMusicInfo(index.row()));
    }
}

void Songlistwi::onItemDoubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit itemDoubleClicked(m_model->getMusicInfo(index.row()));
    }
}

void Songlistwi::onrefreshLikeListViewItem(qint64 songId)
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

Songlistwi::~Songlistwi()
{
    delete ui;
}

void Songlistwi::seticon(QPixmap pix)
{
    // 处理有效封面图
    if (!pix.isNull())
    {
        qDebug() << u8"封面图片存在";
        // 1. 缩放封面至 label 尺寸（保持比例）
        QPixmap scaledCover = pix.scaled(
            ui->icon_lb->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );

        // 2. 创建临时画布，用于绘制圆角
        QPixmap roundedCover(ui->icon_lb->size());
        roundedCover.fill(Qt::transparent); // 透明背景，避免圆角外有底色

        QPainter painter(&roundedCover);
        painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿，圆角更平滑
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        // 3. 圆角裁剪路径（与 label 大小一致）
        QPainterPath clipPath;
        clipPath.addRoundedRect(roundedCover.rect(), 15, 15);
        painter.setClipPath(clipPath); // 应用裁剪，只显示圆角内内容

        // 4. 绘制缩放后的封面（居中显示）
        QPoint drawPoint((roundedCover.width() - scaledCover.width()) / 2,
                         (roundedCover.height() - scaledCover.height()) / 2);
        painter.drawPixmap(drawPoint, scaledCover);

        // 5. 显示圆角封面
        ui->icon_lb->setPixmap(roundedCover);
        return;
    }
    else qDebug() << u8"封面图片不存在";
}

void Songlistwi::settext(QString s)
{
    ui->name_lb->setText(s);
}



