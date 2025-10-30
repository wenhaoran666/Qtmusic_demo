#include "likemusicwi.h"
#include "qpainter.h"
#include "qscrollbar.h"
#include "ui_likemusicwi.h"
#include"musicdbmanager.h"
#include <QPainterPath>
#include <QPainter>
#include <QPixmap>
Likemusicwi:: Likemusicwi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Likemusicwi)
{
     ui->setupUi(this);
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
    ui->widget_4->hide();//默认不显示
    // 初始化模型和委托
    m_model = new BaseMusicModel(this);
    m_delegate = new Likewidelegate(this);
    m_listView->setModel(m_model);
    m_listView->setItemDelegate(m_delegate);
    //连接点击爱心触发添加项
    connect(MusicManager::GetInstance().get(),&MusicManager::addLikesong,this,&Likemusicwi::onaddLikesong);
    connect(MusicManager::GetInstance().get(),&MusicManager::removeLikesong,this,&Likemusicwi::onremoveLikesong);

    // 连接委托的 playButtonClicked 信号到自定义槽函数
    connect(m_delegate, &Likewidelegate::playButtonClicked,
            this, &Likemusicwi::onDelegatePlayClicked);

    // 连接信号槽
    connect(m_listView, &QListView::clicked, this, &Likemusicwi::onItemClicked);
    connect(m_listView, &QListView::doubleClicked, this, &Likemusicwi::onItemDoubleClicked);

    //连接图片加载
    connect(MusicManager::GetInstance().get(),&MusicManager::refreshLikeListViewItem,this,&Likemusicwi::onrefreshLikeListViewItem);
    //数据库保存的初始化

     QList<MusicInfo>l=MusicManager::GetInstance()->getAllFavoriteSongs();
     setLikeResults(l);
}

// 新增：处理委托的播放按钮点击（从模型提取 MusicInfo）
void Likemusicwi::onDelegatePlayClicked(const QModelIndex &index) {

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
    emit LikePlayRequested(currentMusic, allMusicList);
}


void Likemusicwi::setMaxVisibleItems(int count)
{
    m_maxVisibleItems = qMax(1, count);
}

void Likemusicwi::updateIcon()
{
    int itemCount = m_model->rowCount(QModelIndex());
    const int radius = 8; // 圆角半径，与你封面绘制逻辑保持一致

    if (itemCount > 0)
    {
        ui->widget_4->hide();
        qDebug() << u8"4隐藏";
        ui->scrollArea->show();

        QModelIndex firstIndex = m_model->index(0, 0, QModelIndex());
        if (firstIndex.isValid())
        {
            QVariant var = firstIndex.data(BaseMusicModel::CoverRole);
            QPixmap coverPixmap = var.value<QPixmap>();

            // 处理有效封面图
            if (!coverPixmap.isNull())
            {
                qDebug() << u8"封面图片存在";
                // 1. 缩放封面至 label 尺寸（保持比例）
                QPixmap scaledCover = coverPixmap.scaled(
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
                clipPath.addRoundedRect(roundedCover.rect(), radius, radius);
                painter.setClipPath(clipPath); // 应用裁剪，只显示圆角内内容

                // 4. 绘制缩放后的封面（居中显示）
                QPoint drawPoint((roundedCover.width() - scaledCover.width()) / 2,
                                 (roundedCover.height() - scaledCover.height()) / 2);
                painter.drawPixmap(drawPoint, scaledCover);

                // 5. 显示圆角封面
                ui->icon_lb->setPixmap(roundedCover);
                return;
            }
            // 处理无效封面图（显示占位图）
            else
            {
                qDebug() << u8" QUrl加载图片失败！";
                // 1. 加载占位图并缩放
                QPixmap placeholder(":/res/head_2.jpg");
                QPixmap scaledPlaceholder = placeholder.scaled(
                    ui->icon_lb->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    );

                // 2. 绘制占位图的圆角
                QPixmap roundedPlaceholder(ui->icon_lb->size());
                roundedPlaceholder.fill(Qt::transparent);

                QPainter painter(&roundedPlaceholder);
                painter.setRenderHint(QPainter::Antialiasing);
                painter.setRenderHint(QPainter::SmoothPixmapTransform);

                QPainterPath clipPath;
                clipPath.addRoundedRect(roundedPlaceholder.rect(), radius, radius);
                painter.setClipPath(clipPath);

                // 3. 居中绘制占位图
                QPoint drawPoint((roundedPlaceholder.width() - scaledPlaceholder.width()) / 2,
                                 (roundedPlaceholder.height() - scaledPlaceholder.height()) / 2);
                painter.drawPixmap(drawPoint, scaledPlaceholder);

                // 4. 显示圆角占位图
                ui->icon_lb->setPixmap(roundedPlaceholder);
            }
        }
    }
    // 无数据时显示占位图
    else
    {
        // 同样为占位图添加圆角（逻辑与上方一致）
        QPixmap placeholder(":/res/head_2.jpg");
        QPixmap scaledPlaceholder = placeholder.scaled(
            ui->icon_lb->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );

        QPixmap roundedPlaceholder(ui->icon_lb->size());
        roundedPlaceholder.fill(Qt::transparent);

        QPainter painter(&roundedPlaceholder);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        QPainterPath clipPath;
        clipPath.addRoundedRect(roundedPlaceholder.rect(), radius, radius);
        painter.setClipPath(clipPath);

        QPoint drawPoint((roundedPlaceholder.width() - scaledPlaceholder.width()) / 2,
                         (roundedPlaceholder.height() - scaledPlaceholder.height()) / 2);
        painter.drawPixmap(drawPoint, scaledPlaceholder);

        ui->icon_lb->setPixmap(roundedPlaceholder);
        showkong();
    }
}


void Likemusicwi::onremoveLikesong(qint64 songId)
{
    removeinfo(songId);
}

void Likemusicwi::onaddLikesong(qint64 songId)
{
    addInfo(songId);
}


void Likemusicwi::onItemClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit playRequested(m_model->getMusicInfo(index.row()));
    }
}

void Likemusicwi::onItemDoubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        emit itemDoubleClicked(m_model->getMusicInfo(index.row()));
    }
}

void Likemusicwi::onrefreshLikeListViewItem(qint64 songId)
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
     updateIcon();//更新
}



Likemusicwi::~Likemusicwi()
{
    delete ui;
}

void Likemusicwi::setLikeResults(const QList<MusicInfo> &results)
{
    // 通过模型更新视图数据（从MusicManager获取最新缓存）
    QList<MusicInfo> cachedResults;
    for ( auto info : results) {
        cachedResults << info;
    }
    m_model->setMusicList(cachedResults);
    updateIcon();//更新
}

void Likemusicwi::addInfo(qint64 songId)
{

    m_model->appendMusicInfo(songId);
     updateIcon();//更新
}

void Likemusicwi::removeinfo(qint64 songId)
{
    //数据层在musicmanager就删除了,此函数只进行窗口移除

    // 1. 先获取模型当前的总行数（避免遍历过程中数据变化导致索引偏差）
    int currentRowCount = m_model->rowCount(QModelIndex());
    qDebug()<<u8"取消前行数"<<currentRowCount;
    // 2. 遍历模型，找到匹配 songId 的行（从后往前遍历，避免删除后索引错位）
    for (int i = currentRowCount - 1; i >= 0; --i)
    {
        // 创建当前行的模型索引（父索引为空，因为是列表模型）
        QModelIndex index = m_model->index(i, 0, QModelIndex());
        if (!index.isValid()) {
            qWarning() << u8"喜欢列表：无效的模型索引，行号" << i;
            continue;
        }

        // 3. 从索引中提取 MusicInfo
        QVariant var = index.data(BaseMusicModel::OriginalInfoRole);
        if (!var.canConvert<MusicInfo>()) {
            qWarning() << u8"喜欢列表：模型数据无法转换为 MusicInfo，行号" << i;
            continue;
        }
        MusicInfo info = var.value<MusicInfo>();

        if (info.getsongId() == songId)
        {
            // 4. 调用模型的 removeRow 方法删除行（触发视图刷新的关键）
            bool removeSuccess = m_model->removeRow(i, QModelIndex());
            if (removeSuccess) {
                qDebug() << u8"喜欢列表界面：成功移除歌曲ID" << songId << u8",行号" << i;
            } else {
                qWarning() << u8"喜欢列表界面：删除行失败，行号" << i << u8"，歌曲ID" << songId;
            }
            break; // 找到目标行，删除后退出循环
        }
    }
     updateIcon();//更新
}

void Likemusicwi::showkong()
{
    ui->scrollArea->hide();
    ui->widget_4->show();
     qDebug() << u8"4显示";
}
