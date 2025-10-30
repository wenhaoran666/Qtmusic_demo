#include "mainwidget.h"
#include "httpmgr.h"
#include "qpainterpath.h"
#include "ui_mainwidget.h"
#include<QGraphicsDropShadowEffect>
#include<QAction>
#include <QSystemTrayIcon>
#include <QMenu>
#include<QEvent>
#include<QMouseEvent>
#include<QDebug>
#include<QProcess>
#include "MainWidget.h"
#include "SearchRecomwi.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include"MusicManager.h"
#include"MusicDBManager.h"
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
_playlistwi(new playlistwi(this)),
_playmode(new PlaylistModel()),//数据层在主窗口初始化,mode改变发出信号通知播放列表窗口数据变了
    recomWi(new SearchRecomwi(this)),
    ui(new Ui::MainWidget)
{

    ui->setupUi(this);
    initui();
    Musicplayerwi *playerWidget = ui->playbackControlPanel_wi;  // 获取播放窗口
    playerWidget->setMainWidget(this);  //给播放窗口传入主窗口指针(让其获取播放列表)


}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::initui()
{
    initmainwidget();//初始化主界面
    initheadui();//初始化头窗口ui
    inittray();//初始化托盘
    initsidebar();//初始化侧边栏按钮
    installEventFilter(this);//安装事件过滤器

    //信号槽连接
    //本地窗口传来的播放信号
    connect(ui->local_wi,&Localwi::localplay,this,&MainWidget::slotlocalplay);
    //本地窗口传来的更新列表信号
    connect(ui->local_wi,&Localwi::updatelist,this,&MainWidget::slotupdatelist);

    //播放器要显示列表
    connect(ui->playbackControlPanel_wi,&Musicplayerwi::showlist,this,&MainWidget::slotlistshow);

    //连接列表数据层与窗口信号槽
    connect(_playmode,&PlaylistModel::listchange,_playlistwi,&playlistwi::slot_listchange);
    connect(_playmode,&PlaylistModel::nowchange,_playlistwi,&playlistwi::slot_nowchange);
    //列表窗口传来的播放信号
     connect(_playlistwi,&playlistwi::listplay,this,&::MainWidget::slotlistlplay);
    //列表窗口传来的清空信号
    connect(_playlistwi,&playlistwi::listclear,this,&::MainWidget::slotlistclear);
     // 连接搜索视图的播放请求信号
     connect(ui->search_wi, &Searchwi::searchPlayRequested,
             this, &MainWidget::onSearchPlayRequested);
    connect(ui->like_wi, &::Likemusicwi::LikePlayRequested,
            this, &MainWidget::onLikePlayRequested);
     connect(ui->songlist_wi, &Songlistwi::SonglistPlayRequested,
             this, &MainWidget::onSonglistPlayRequested);

     //连接搜索模块http响应
     connect(HttpMgr::GetInstance().get(), &HttpMgr:: sig_music_search_finish,
             this, &MainWidget::slot_music_search_finish);
     //连接喜欢模块http响应
     connect(HttpMgr::GetInstance().get(), &HttpMgr:: sig_music_like_finish,
             this, &::MainWidget::slot_music_like_finish);
     //连接推荐模块http响应
     connect(HttpMgr::GetInstance().get(), &HttpMgr:: sig_music_recommend_finish,
             this, &::MainWidget::slot_music_recommend_finish);
     //连接搜索界面播发
     connect(recomWi,&SearchRecomwi::suggestionSelected,
             this, &MainWidget::slot_suggestionSelected);

     //连接歌单点击响应
     connect(ui->recommend_wi,&Recommendwi::songlistclick,
             this, &MainWidget::onsonglistclick);
}

void MainWidget::initmainwidget()
{
    QIcon appIcon(":/res/windowIcon.png");
    this->setWindowIcon(appIcon); // 设置窗口图标，任务栏图标也会随之改变
    setWindowFlags(Qt::FramelessWindowHint);
    // 设置背景颜色（便于观察效果）
    //setStyleSheet("background-color: lightgreen;");
    setAttribute(Qt::WA_TranslucentBackground); // 窗口背景透明
    //设置阴影
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(Qt::black);
    effect->setOffset(0, 0); // 0偏移。这个不设置会有点偏, 立体感?
    effect->setBlurRadius(6);
    setGraphicsEffect(effect);
 //初始为推荐音乐界面
    ui->recommend_btn->setChecked(true);
    qDebug()<< u8"推荐音乐";
    ClearLabelState(ui->recommend_btn);//把除了自己其他的按钮状态全部清除
    ui->pages_wi->setCurrentWidget(ui->recommend_wi);
}

void MainWidget::initheadui()
{
    ui->close_btn->setCursor(Qt::PointingHandCursor);
    ui->minimize_btn->setCursor(Qt::PointingHandCursor);
    ui->dress_btn->setCursor(Qt::PointingHandCursor);
    ui->setting_btn->setCursor(Qt::PointingHandCursor);
    ui->message_btn->setCursor(Qt::PointingHandCursor);
    ui->back_btn->setCursor(Qt::PointingHandCursor);
    ui->phone_btn->setCursor(Qt::PointingHandCursor);
    //搜索框
    ui->search_lin->setPlaceholderText(QStringLiteral("搜索"));
     QIcon searchIcon(":/res/btn_search_100.png");  //搜索图标
    //创建一个 搜索图标QAction，并设置图标
    QAction *searchAction = new QAction(searchIcon, "", ui->search_lin);
    ui->search_lin->addAction(searchAction, QLineEdit::LeadingPosition);

    //创建一个清除QAction
    QIcon clearIcon(":/res/close_transparent.png");
    QAction*clearAction =new QAction(clearIcon,"",ui->search_lin);
    ui->search_lin->addAction(clearAction,QLineEdit::TrailingPosition);

    //搜索建议框
    recomWi->setFixedWidth(1170);

    //只要文本改变，就显示clear
    //textChanged自带const QString &text
    connect(ui->search_lin,&QLineEdit::textChanged,this,[clearAction, this](const QString &text){
        recomWi->hide();
        if(!text.isEmpty())
            clearAction->setIcon(QIcon(":/res/close_search.png"));
        else {
            clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 文本为空时，切换回透明图标
        }
          HttpMgr::GetInstance()->searchrecomMusic(text);
    });

    //连接清除文本
    connect(clearAction,&QAction::triggered,this,[=](){
        ui->search_lin->clear();
        clearAction->setIcon(QIcon(":/res/close_transparent.png"));
        ui->search_lin->clearFocus();//放弃焦点
         recomWi->hide();
    });
    // 为搜索框安装事件过滤器，监听按键事件
    ui->search_lin->installEventFilter(this);
    //文本改变建议框出现
//     connect(ui->search_lin, &QLineEdit::textChanged, this, [=](const QString &text)
// {
            // if (text.trimmed().isEmpty())
            // {
            //     recomWi->setSuggestions({}); // 清空建议
            //     return;
            // }
// 模拟API调用
            // QTimer::singleShot(300, this, [=]() {
            //     // 假设从接口获取的建议数据（单曲信息）
            //     QStringList suggestions = {
            //         u8"七里香 - 周杰伦",
            //         u8"七里香 (Demo) - 周杰伦",
            //         u8"七里香 - 吉他版",
            //          u8"七里香 - 吉他版",
            //          u8"七里香 - 吉他版",
            //          u8"七里香 - 吉他版",
            //     };




//     });
 }

void MainWidget::inittray()
{
    QSystemTrayIcon*tray=new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/res/windowIcon.png"));
    tray->setToolTip(u8"我的音乐播放器");//悬浮文字
    QMenu* menu = new QMenu(this);
    menu->addAction(u8"退出", this, &QCoreApplication::quit);
    tray->setContextMenu(menu); // 设置了菜单, 点击右键自动弹出
    tray->show();
    //ActivationReason代表因何种原因激活了图标
    connect(tray,&QSystemTrayIcon::activated,this,[=](QSystemTrayIcon::ActivationReason reason){
        if(reason==QSystemTrayIcon::Trigger)//单机
            this->show();
    });
}

void MainWidget::initsidebar()
{
    //将侧边栏现有的控件全部添加
     _lb_list.push_back(ui->explore_btn);
    _lb_list.push_back(ui->favorite_btn);
     _lb_list.push_back(ui->featured_btn);
    _lb_list.push_back(ui->follow_btn);
     _lb_list.push_back(ui->local_btn);
    _lb_list.push_back(ui->podcast_btn);
     _lb_list.push_back(ui->recent_btn);
    _lb_list.push_back(ui->recommend_btn);

     ui->explore_btn->setCursor(Qt::PointingHandCursor);
     ui->favorite_btn->setCursor(Qt::PointingHandCursor);
     ui->featured_btn->setCursor(Qt::PointingHandCursor);
     ui->recommend_btn->setCursor(Qt::PointingHandCursor);
     ui->recent_btn->setCursor(Qt::PointingHandCursor);
     ui->local_btn->setCursor(Qt::PointingHandCursor);
     ui->follow_btn->setCursor(Qt::PointingHandCursor);
     ui->podcast_btn->setCursor(Qt::PointingHandCursor);
}
bool MainWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (_playlistwi && _playlistwi->isVisible())
        {
            // 获取 _playlist 的全局屏幕位置
            QRect playlistRect = _playlistwi->geometry();
            QPoint playlistGlobalPos = _playlistwi->mapToGlobal(QPoint(0, 0));
            playlistRect.moveTo(playlistGlobalPos);

            // 获取鼠标点击的全局位置
            QPoint clickPos = mouseEvent->globalPos();

            // 如果点击位置不在 _playlist 区域内，则隐藏它
            if (!playlistRect.contains(clickPos))
            {
                _playlistwi->hide();
            }
        }
        if(recomWi&&recomWi->isVisible())
        {
            // 获取 _playlist 的全局屏幕位置
            QRect recomRect = recomWi->geometry();
            QPoint recomGlobalPos = recomWi->mapToGlobal(QPoint(0, 0));
            recomRect.moveTo(recomGlobalPos);

            // 获取鼠标点击的全局位置
            QPoint clickPos = mouseEvent->globalPos();

            // 如果点击位置不在 _playlist 区域内，则隐藏它
            if (!recomRect.contains(clickPos))
            {
                recomWi->hide();
            }
        }

    }

// 判断事件源是否为搜索框，且事件为按键释放
    if (watched == ui->search_lin && event->type() == QEvent::KeyRelease)
    {

    QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
    // 检测回车键（包括小键盘回车）
    if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
    {

        QString text=ui->search_lin->text();
        // 触发搜索逻辑
        if (text.isEmpty()) {
            return true; // 事件已处理
        }

        // 隐藏搜索建议窗口
        if (recomWi) {
            recomWi->hide();
        }

                //更新搜索窗口标题
            ui->search_wi->settitle(text);
            // 可以直接根据歌曲名和艺术家搜索详细信息
            HttpMgr::GetInstance()->searchMusic(text,20,1); // 搜索完整匹配项
        }

    }

    // qDebug() << u8"eventFilter 收到事件，类型:" << event->type()
    //          << u8"被监听对象:" << watched;
 return QWidget::eventFilter(watched, event);
}
PlaylistModel *MainWidget::getPlaylistModel()
{
    return _playmode;
}

void MainWidget::startNeteaseApiService() {
    QProcess *apiProcess = new QProcess(qApp);

    QString apiPath = "C:/Users/wenhaoran/AppData/Roaming/npm/NeteaseCloudMusicApi.cmd";
    QStringList arguments = {"-p", "52333"};

    apiProcess->setWorkingDirectory(QCoreApplication::applicationDirPath());
    //qDebug() << u8"正在启动API服务，命令：" << apiPath << arguments.join(" ");
    apiProcess->start(apiPath, arguments);

    // 等待启动，仅在成功后执行后续逻辑
    if (!apiProcess->waitForStarted(5000)) {
        qDebug() << u8"网易云API服务启动失败：" << apiProcess->errorString();
        apiProcess->deleteLater(); // 释放失败的进程对象
        return;
    }

    // 进程启动成功，记录有效PID
    qint64 apiPid = apiProcess->processId();
    qDebug() << u8"网易云API服务已启动，PID：" << apiPid;

    // 绑定输出日志
    connect(apiProcess, &QProcess::readyReadStandardOutput, [=]() {
        QByteArray output = apiProcess->readAllStandardOutput();
        qDebug() << u8"API服务输出：" << output;
    });
    connect(apiProcess, &QProcess::readyReadStandardError, [=]() {
        QByteArray error = apiProcess->readAllStandardError();
        qDebug() << u8"API服务错误：" << error;
    });

    // 绑定退出时的终止逻辑（只在启动成功后绑定）
    connect(qApp, &QCoreApplication::aboutToQuit, [=]() {
        // 方法1：通过QProcess对象终止（优先）
        if (apiProcess->state() == QProcess::Running) {
            qDebug() << u8"程序退出，正在关闭API服务...";
            apiProcess->terminate();
            if (!apiProcess->waitForFinished(2000)) {
                qDebug() << u8"API服务未响应，强制关闭...";
                apiProcess->kill();
            }
        }
        apiProcess->deleteLater();

        // 方法2：通过PID二次确认（防止QProcess对象失效）
        if (apiPid > 0) { // 确保PID有效
            killApiServiceByPid(apiPid);
        }
    });
}

void MainWidget::killApiServiceByPid(qint64 pid) {
    if (pid <= 0) return;
#ifdef Q_OS_WIN
    // 执行taskkill并检查结果
    int exitCode = QProcess::execute(QString("taskkill /PID %1 /F").arg(pid));
    if (exitCode == 0) {
        qDebug() << u8"已通过PID强制终止API服务（PID：" << pid << u8"）";
    } else {
        qDebug() << u8"通过PID终止API服务失败（PID：" << pid << u8"），可能已关闭";
    }
#endif
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // head_wi各个子窗口都有自己可拖动的区域
        if (((event->pos().y() < 120)&&ui->logo_wi->geometry().contains(event->pos()))||
            ((event->pos().y() < 35)&&ui->searchlist_wi->geometry().contains(event->pos()))||
            ((event->pos().y() < 120)&&ui->user_wi->geometry().contains(event->pos()))||
            ((event->pos().y() < 45)&&ui->headutils_wi->geometry().contains(event->pos())))
        {
            dragPosition = event->globalPos() - frameGeometry().topLeft();
            m_dragging=true;//使用后没有置为false才造成按钮也可移动(通过松开事件解决)
        }
        else
            m_dragging=false;
    }

    QWidget::mousePressEvent(event);

}


void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
//唱片旋转时拖动窗口会卡
    if (!m_dragging) {
        // 当前鼠标事件被禁用，直接忽略，不处理
        QWidget::mouseMoveEvent(event);
        return;
    }
    if (event->buttons() & Qt::LeftButton) {
        // 只有在窗口顶部 y < 50 的区域按住并移动，才执行拖动
       if (/*event->pos().y() < 10&&*/m_dragging==true) {
            move(event->globalPos() - dragPosition);
        }
    }

    QWidget::mouseMoveEvent(event);
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
     m_dragging=false;
    QWidget::mouseReleaseEvent(event);
}


void MainWidget::on_close_btn_clicked()
{
    _playlistwi->hide();
    recomWi->hide();
    this->hide();//点击关闭只是最小化,使用托盘才完全关闭

}


void MainWidget::on_minimize_btn_clicked()
{
    _playlistwi->hide();
    recomWi->hide();
    this->showMinimized();

}

void MainWidget::ClearLabelState(StatePushbutton *lb)
{
    for(auto & ele: _lb_list){
        if(ele == lb){
            continue;
        }
        ele->ClearState();

    }
}


void MainWidget::on_local_btn_clicked()
{
    //禁止重复点击切换
    //这里有个问题,用的是qt初始setChecked,在按钮是已选中状态再次点击,一瞬间鼠标事件
    //会调用setChecked(!local_btn->isChecked()),而后才到下方ui->local_btn->setChecked(true)
    //故会有一瞬间变为样式表的未选中状态图片和背景造成"闪一下",可以自定义状态或点击后设置this->setCheckable(false)
    //等后面点击其他按钮再设置回来来解决,没什么大碍故不管

   //禁止重复点击切换
    if(!ui->local_btn->isChecked())
        ui->local_btn->setChecked(true);
    qDebug()<< u8"点击了本地音乐侧边栏按钮";
    ClearLabelState(ui->local_btn);//把除了自己其他的按钮状态全部清除
    ui->pages_wi->setCurrentWidget(ui->local_wi);
}


void MainWidget::on_recommend_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->recommend_btn->isChecked())
        ui->recommend_btn->setChecked(true);
    qDebug()<< u8"点击了推荐侧边栏按钮";
    ClearLabelState(ui->recommend_btn);//把除了自己其他的按钮状态全部清除
    ui->pages_wi->setCurrentWidget(ui->recommend_wi);
}


void MainWidget::on_featured_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->featured_btn->isChecked())
        ui->featured_btn->setChecked(true);
    qDebug()<< u8"点击了精选侧边栏按钮";
    ClearLabelState(ui->featured_btn);//把除了自己其他的按钮状态全部清除
}


void MainWidget::on_podcast_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->podcast_btn->isChecked())
        ui->podcast_btn->setChecked(true);
    qDebug()<< u8"点击了博客侧边栏按钮";
    ClearLabelState(ui->podcast_btn);//把除了自己其他的按钮状态全部清除
}


void MainWidget::on_explore_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->explore_btn->isChecked())
        ui->explore_btn->setChecked(true);
    qDebug()<< u8"点击了漫游侧边栏按钮";
    ClearLabelState(ui->explore_btn);//把除了自己其他的按钮状态全部清除
}


void MainWidget::on_follow_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->follow_btn->isChecked())
        ui->follow_btn->setChecked(true);
    qDebug()<< u8"点击了关注侧边栏按钮";
    ClearLabelState(ui->follow_btn);//把除了自己其他的按钮状态全部清除
}


void MainWidget::on_favorite_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->favorite_btn->isChecked())
        ui->favorite_btn->setChecked(true);
    qDebug()<< u8"点击了我喜欢的音乐侧边栏按钮";
    ClearLabelState(ui->favorite_btn);//把除了自己其他的按钮状态全部清除
    ui->pages_wi->setCurrentWidget(ui->like_wi);
}


void MainWidget::on_recent_btn_clicked()
{
    //禁止重复点击切换
    if(!ui->recent_btn->isChecked())
        ui->recent_btn->setChecked(true);
    qDebug()<< u8"点击了最近播放音乐侧边栏按钮";
    ClearLabelState(ui->recent_btn);//把除了自己其他的按钮状态全部清除
}

void MainWidget::slotupdatelist()
{
     qDebug()<<u8"更新新列表";
    // //更新新列表(数据层要在点击后才更新新列表)
    //  _playmode->setNewPlaylist(playlist);
    // //播放器设置
    //  ui->playbackControlPanel_wi->setnormalui();//设置默认状态
}

void MainWidget::slotlocalplay(const QList<MusicInfo> playlist,const MusicInfo message)
{
      //更新新列表
      _playmode->setNewPlaylist(playlist);
    //播放队列数据层设置
    _playmode->updateindex(message);

    //播放器设置
    ui->playbackControlPanel_wi->playMusic(message.geturl());
    ui->playbackControlPanel_wi->setUi(message);


}

void MainWidget::slotlistlplay(const MusicInfo message)
{
    //播放队列数据层设置
    _playmode->updateindex(message);

    //播放器设置
    ui->playbackControlPanel_wi->playMusic(message.geturl());
    ui->playbackControlPanel_wi->setUi(message);
}

void MainWidget::slotlistclear()
{
    _playmode->clear();
    ui->playbackControlPanel_wi->setnormalui();//设置默认状态
}

void MainWidget::slotlistshow()
{

    if (!_playlistwi) return;
    if(!_playlistwi->isVisible())
    {
    _playlistwi->adjustSize();  // 确保大小正确
    // 目标位置（紧贴主窗口右侧，Y可调整）
    int targetX = this->x() + this->width() - _playlistwi->width()-10;
    int targetY = this->y() +this->height()/2- _playlistwi->height()/2+5;

    QPoint targetPos(targetX, targetY);
    _playlistwi->move(targetPos);
    _playlistwi->show();  // 非模态显示
    }
    else
    {
        _playlistwi->hide();
    }

}


void MainWidget::slot_music_search_finish(ReqId id, QString res, ErrorCodes err)
{
    // 处理搜索建议请求
    if (id == ReqId::ID_SEARCHRECOM_MUSIC) {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索建议请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索建议";
                break;
            default:
                errMsg = u8"未知错误，搜索建议获取失败";
            }
            qWarning() << errMsg;
            // 清空搜索建议窗口（避免显示旧数据）
            if (recomWi) {
                recomWi->setSuggestions({});
            }
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"数据解析失败：" << parseErr.errorString();
            if (recomWi)
                recomWi->setSuggestions({});
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态（网易云API成功标识为code=200）
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"接口返回异常，code：" << rootObj["code"].toInt();
            if (recomWi) recomWi->setSuggestions({});
            return;
        }

        // 提取songs数组（单曲数据）
        QJsonObject resultObj = rootObj["result"].toObject();
        QJsonArray songsArr = resultObj["songs"].toArray();  // 重点：获取单曲数组
        QStringList suggestList;

        // 遍历单曲数组，提取歌曲名和艺术家列表
        for (const QJsonValue& songVal : songsArr) {
            if (!songVal.isObject()) continue;
            QJsonObject songObj = songVal.toObject();

            // 1. 提取歌曲名（songs.name）
            QString songName = songObj["name"].toString();
            if (songName.isEmpty()) continue;  // 跳过无效数据

            // 2. 提取艺术家列表（songs.artists[].name）
            QJsonArray artistsArr = songObj["artists"].toArray();
            QStringList artistNames;
            for (const QJsonValue& artistVal : artistsArr) {
                if (artistVal.isObject()) {
                    QString artistName = artistVal.toObject()["name"].toString();
                    if (!artistName.isEmpty()) {
                        artistNames << artistName;
                    }
                }
            }
            // 处理无艺术家信息的情况
            QString artistsStr = artistNames.join("/");  // 多艺术家以"/"分隔
            if (artistsStr.isEmpty()) {
                artistsStr = u8"未知艺术家";
            }

            // 组装建议项（格式：歌曲名 - 艺术家1/艺术家2）
            suggestList << QString("%1 - %2").arg(songName).arg(artistsStr);
        }
        // 提取搜索关键词（用于无结果时显示“搜索XXX”）
        QString keyword = ui->search_lin->text().trimmed();  // 从搜索框获取当前关键词
        // 如果没有搜索到结果，添加“搜索‘关键字’”选项
        if (suggestList.isEmpty() && !keyword.isEmpty()) {
            suggestList << QString(u8"搜索\"%1\"").arg(keyword);  // 格式：搜索"周杰伦"
        }

        // 更新搜索建议窗口
        if (recomWi) {
            recomWi->setSuggestions(suggestList);
            // 控制窗口显示位置（搜索框下方）
            if (recomWi->suggestionCount() > 0)
            {
                QRect pagesRect = ui->pages_wi->frameGeometry();
                QPoint pagesTopLeft = ui->pages_wi->mapToGlobal(QPoint(0, 0));
                int fixedY = ui->search_lin->mapToGlobal(QPoint(0, 0)).y() + ui->search_lin->height()+20;
                int pagesCenterX = pagesTopLeft.x() + ui->pages_wi->width() / 2;
                int recomHalfWidth = recomWi->width() / 2;
                int targetX = pagesCenterX - recomHalfWidth;
                QPoint targetPos(targetX, fixedY);
                recomWi->move(targetPos);
                recomWi->show();

            } else
            {
                recomWi->hide();
            }
        }
    }
    // 处理完整搜索结果请求
    else if (id == ReqId::ID_SEARCH_MUSIC) {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索结果";
                break;
            default:
                errMsg = u8"未知错误，搜索失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"搜索结果解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"搜索接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保证 JSON 格式不被添加额外引号干扰
        qDebug() << "=======================================";

        // 提取搜索结果中的歌曲列表（API中歌曲数组键是"songs"，嵌套在"result"下）
        QJsonObject resultObj = rootObj["result"].toObject();
        // 处理无搜索结果场景（result为空或songs数组为空）
        // --------------------------
        // 判断result是否为空（如 {"result":{},"code":200}）
        if (resultObj.isEmpty()) {
            QString noResultMsg = u8"未搜索到与关键词相关的歌曲";
            qDebug() << noResultMsg;
            // 通知UI显示无结果提示
            ui->search_wi->showkong();
            // 隐藏搜索建议窗口
            if (recomWi) recomWi->hide();
            return;
        }

        QJsonArray songsArr = resultObj["songs"].toArray();
        QList<MusicInfo> searchResults;

        // 遍历解析每首歌曲
        for (const QJsonValue& songVal : songsArr) {
            if (!songVal.isObject()) continue;
            QJsonObject songObj = songVal.toObject();

            MusicInfo info;
            // 1. 基础信息：歌曲ID、名称、网易云ID（API中"id"即歌曲唯一标识）
            qint64 songId = songObj["id"].toVariant().toLongLong();
            info.setsongId(songId);
            info.setwangyiyun_id(songId);  // 网易云ID与歌曲ID一致
            info.setTitle(songObj["name"].toString());
            qDebug()<<"id"<<songId;
            // 2. 艺术家信息（关键修复：API返回键是"ar"而非"artists"）
            QJsonArray artistsArr = songObj["ar"].toArray();  // 原代码"artists"改为"ar"
            QStringList artistNames;
            QList<qint64> artistIds;  // 可选：存储艺术家ID（如需后续获取歌手详情）
            for (const QJsonValue& artistVal : artistsArr) {
                if (artistVal.isObject()) {
                    QJsonObject artistObj = artistVal.toObject();
                    artistNames << artistObj["name"].toString();
                    artistIds << artistObj["id"].toVariant().toLongLong();  // 记录艺术家ID
                }
            }
            info.setcomposer(artistNames.join("/"));  // 多艺术家用"/"分隔（如"Beyond"）
            // 可选：将艺术家ID存入MusicInfo（需先在MusicInfo中添加setArtistIds方法）
            // info.setArtistIds(artistIds);

            // 3. 专辑信息（含专辑封面URL）
            if (songObj.contains("al") && songObj["al"].isObject()) {  // API中专辑键是"al"而非"album"
                QJsonObject albumObj = songObj["al"].toObject();
                info.setAlbum(albumObj["name"].toString());  // 专辑名称
                // 专辑封面URL（API中"picUrl"是完整链接，直接使用）
                if (albumObj.contains("picUrl")) {
                    QString picUrl = albumObj["picUrl"].toString();
                    // 补充：部分URL可能缺少"http:"协议头，需判断并补全
                    if (!picUrl.startsWith("http")) {
                        picUrl = "http:" + picUrl;
                    }
                    info.setm_image_url(QUrl(picUrl));
                    qDebug() << u8"歌曲" << info.gettitle() << u8"封面URL：" << picUrl;
                    // 调用HttpMgr下载图片（传入URL和当前歌曲ID）
                    // 检查缓存中是否已存在该歌曲且封面不为空
                    qint64 songId = info.getsongId();
                    MusicInfo cachedInfo = MusicManager::GetInstance()->getSongitem(songId);
                    if (cachedInfo.getsongId() == 0) {
                        // 缓存中不存在该歌曲，正常下载
                        HttpMgr::GetInstance()->downloadImage(picUrl, songId);
                    } else {
                        // 缓存中已存在该歌曲，判断封面是否有效
                        if (cachedInfo.getm_image().isNull()) {
                            // 封面为空，补充下载
                            HttpMgr::GetInstance()->downloadImage(picUrl, songId);
                            qDebug() << u8"歌曲ID" << songId << u8"缓存存在但封面为空，补充下载";
                        } else {
                            // 封面已存在，跳过下载
                            qDebug() << u8"歌曲ID" << songId << u8"封面已缓存，无需重复下载";
                        }
                    }
                }
                // 可选：专辑ID（如需后续获取专辑详情）
                qint64 albumId = albumObj["id"].toVariant().toLongLong();
                // info.setAlbumId(albumId);  // 需在MusicInfo中添加setAlbumId方法
            }

            // 4. 时长（API中"dt"是毫秒，转换为秒）
            qint64 durationMs = songObj["dt"].toVariant().toLongLong();  // 注意字段是"dt"而非"duration"
            info.setDuration(durationMs);  // 转换为秒级时长
            // 添加到结果列表
            searchResults << info;
        }

        // 将搜索结果加入音乐管理器缓存
        for (auto& info : searchResults) {
            MusicManager::GetInstance()->addSongitem(info);
        }

        // 打印搜索结果详情（调试用）
        qDebug() << u8"\n=== 搜索结果解析完成 ===";
        qDebug() << u8"共搜索到" << searchResults.size() << u8"首歌曲";
        for (int i = 0; i < searchResults.size(); ++i) {
            const MusicInfo& info = searchResults.at(i);
            qDebug() << u8"\n第" << (i + 1) << u8"首：";
            qDebug() << u8"歌曲名：" << info.gettitle();
            qDebug() << u8"艺术家：" << info.getcomposer();
            qDebug() << u8"专辑：" << info.getalbum();
            qDebug() << u8"时长：" << info.getduration() << u8"秒";
            qDebug() << u8"封面URL：" << info.getm_image_url().toString();
            //qDebug() << u8"是否VIP：" << (info.getIsVipSong() ? u8"是" : u8"否");  // 需添加getIsVipSong方法
        }

        // 更新UI展示搜索结果
        qDebug() << u8"\n搜索结果页面切换";
        ui->search_wi->setSearchResults(searchResults);
        ui->pages_wi->setCurrentWidget(ui->search_wi);
        recomWi->hide();

    }

    //点击播放网络歌曲触发获取URL
    else if(id == ReqId::ID_GET_MUSIC_PLAYURL)
    {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索结果";
                break;
            default:
                errMsg = u8"未知错误，搜索失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"搜索结果解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"搜索接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保证 JSON 格式不被添加额外引号干扰
        qDebug() << "=======================================";
        // 从 rootObj 中取出 "data" 数组
        QJsonValue dataVal = rootObj["data"];
        if (!dataVal.isArray()) {
            qWarning() << u8"JSON 数据格式错误：'data' 字段不是数组";
            return;
        }

        QJsonArray dataArray = dataVal.toArray();

        // 判断是否有数据
        if (dataArray.isEmpty()) {
            qWarning() << u8"没有搜索到任何歌曲";
            return;
        }

        // 取第一首歌（索引 0）
        QJsonValue firstSongVal = dataArray.at(0);
        if (!firstSongVal.isObject()) {
            qWarning() << u8"第一首歌曲数据格式错误，不是 JSON 对象";
            return;
        }

        QJsonObject firstSongObj = firstSongVal.toObject();

        qint64 songId = firstSongObj["id"].toVariant().toLongLong();  // 例如 347321
        QString urlStr = firstSongObj["url"].toString();              // 例如 http://...

        // 处理URL为空的情况（版权限制等）
        if (urlStr.isEmpty()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 无播放权限（版权限制）";
            qWarning() << errMsg;
            return;
        }

        // 补全URL协议头（防止API返回的URL缺少http/https）
        QUrl playUrl(urlStr);
        if (playUrl.scheme().isEmpty()) {
            playUrl.setScheme("http"); // 默认为http，若实际为https可调整
        }

        // 验证URL有效性
        if (!playUrl.isValid()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 播放URL无效：" + urlStr;
            qWarning() << errMsg;
            return;
        }

        // 解析成功，发送有效URL信号
        qDebug() << u8"歌曲ID " << songId << u8" 播放URL获取成功：" << playUrl.toString();
        MusicManager::GetInstance()->setUrl(songId,playUrl);
        MusicInfo info=MusicManager::GetInstance()->getSongitem(songId);
        QList<MusicInfo> validPlaylist ;
        validPlaylist<<info;

        // 步骤3：如果新列表为空，提示错误（避免播放队列无效）
        if (validPlaylist.isEmpty()) {
            qWarning() << u8"播放列表中无有效URL的歌曲，无法播放";
            return;
        }

        //更新新列表
        _playmode->setNewPlaylist(validPlaylist);
        //播放队列数据层设置(搜索的歌曲点击列表只有一个,可以不调用
        _playmode->updateindex(info);

        //播放器设置
        ui->playbackControlPanel_wi->playMusic(info.geturl());
        ui->playbackControlPanel_wi->setUi(info);


    }
}

void MainWidget::slot_music_like_finish(ReqId id, QString res, ErrorCodes err)
{
    if(id == ReqId::ID_GET_MUSIC_PLAYURL)
    {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索结果";
                break;
            default:
                errMsg = u8"未知错误，搜索失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"搜索结果解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"搜索接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保证 JSON 格式不被添加额外引号干扰
        qDebug() << "=======================================";
        // 从 rootObj 中取出 "data" 数组
        QJsonValue dataVal = rootObj["data"];
        if (!dataVal.isArray()) {
            qWarning() << u8"JSON 数据格式错误：'data' 字段不是数组";
            return;
        }

        QJsonArray dataArray = dataVal.toArray();

        // 判断是否有数据
        if (dataArray.isEmpty()) {
            qWarning() << u8"没有搜索到任何歌曲";
            return;
        }

        // 取第一首歌（索引 0）
        QJsonValue firstSongVal = dataArray.at(0);
        if (!firstSongVal.isObject()) {
            qWarning() << u8"第一首歌曲数据格式错误，不是 JSON 对象";
            return;
        }

        QJsonObject firstSongObj = firstSongVal.toObject();

        qint64 songId = firstSongObj["id"].toVariant().toLongLong();  // 例如 347321
        QString urlStr = firstSongObj["url"].toString();              // 例如 http://...

        // 处理URL为空的情况（版权限制等）
        if (urlStr.isEmpty()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 无播放权限（版权限制）";
            qWarning() << errMsg;
            return;
        }

        // 补全URL协议头（防止API返回的URL缺少http/https）
        QUrl playUrl(urlStr);
        if (playUrl.scheme().isEmpty()) {
            playUrl.setScheme("http"); // 默认为http，若实际为https可调整
        }

        // 验证URL有效性
        if (!playUrl.isValid()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 播放URL无效：" + urlStr;
            qWarning() << errMsg;
            return;
        }

        // 解析成功，发送有效URL信号
        qDebug() << u8"歌曲ID " << songId << u8" 播放URL获取成功：" << playUrl.toString();
        MusicManager::GetInstance()->setUrl(songId,playUrl);
        MusicDBManager::GetInstance()->setUrl(songId,playUrl);
        //不播放,只获取
    }

}

void MainWidget::slot_music_recommend_finish(ReqId id, QString res, ErrorCodes err)
{
    //处理获取主页轮播图情况
    if(id == ReqId::ID_GET_BANNER)
    {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索结果";
                break;
            default:
                errMsg = u8"未知错误，搜索失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"搜索结果解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"搜索接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保证 JSON 格式不被添加额外引号干扰
        qDebug() << "=======================================";

        QJsonValue bannersVal = rootObj["banners"];
        if (!bannersVal.isArray()) {
            qWarning() << u8"Banner数据格式错误：'banners'字段不是数组";
            return;
        }
        QJsonArray bannersArr = bannersVal.toArray();
        if (bannersArr.isEmpty()) {
            qDebug() << u8"未获取到任何Banner数据（无图片可下载）";
            return;
        }


        // 5. 遍历Banner数组，提取图片URL并触发下载
        for (const QJsonValue& bannerVal : bannersArr) {
            if (!bannerVal.isObject()) {
                qWarning() << u8"跳过无效Banner数据（非JSON对象）";
                continue;
            }
            QJsonObject bannerObj = bannerVal.toObject();

            // 5.1 提取Banner关键信息
            qint64 songId = bannerObj["targetId"].toVariant().toLongLong();
            QString typeTitle = bannerObj["typeTitle"].toString();  // 例如："新歌首发"、"热歌推荐"

            // 只处理 "新歌首发" 和 "热歌推荐"
            if (typeTitle != u8"新歌首发" && typeTitle != u8"热歌推荐") {
                qDebug() << u8"跳过非目标Banner类型：" << typeTitle;
                continue;
            }

            QString bigImageUrl = bannerObj["bigImageUrl"].toString();
            if (bigImageUrl.isEmpty()) {
                qWarning() << u8"Banner无大图URL，跳过下载";
                continue;
            }


            // 5.3 补全URL协议头（防止API返回URL缺少http/https，导致下载失败）
            QUrl imageUrl(bigImageUrl);
            if (imageUrl.scheme().isEmpty()) {
                imageUrl.setScheme("https");  // 网易云图片优先用https，兼容性更好
                qDebug() << u8"补全URL协议头：" << imageUrl.toString();
            }

            // 5.4 验证URL有效性（过滤非法链接）
            if (!imageUrl.isValid()) {
                qWarning() << u8"无效Banner图片URL：" << bigImageUrl;
                continue;
            }

            //5.5 判断是否重复下载（从缓存检查：避免已下载的图片再次请求）
            //注：需先在MusicManager中添加Banner图片缓存管理方法（或复用现有缓存逻辑）
            bool isImageCached = MusicManager::GetInstance()->isBannerImageCached(songId);
            if (isImageCached) {
                qDebug() << u8"Banner图片已缓存，跳过下载：" << songId;
                continue;
            }

            // 5.6 触发图片下载（调用现有HttpMgr的下载接口，传入URL和Banner唯一标识）
            qDebug() << u8"开始下载Banner图片：" << imageUrl.toString();
            HttpMgr::GetInstance()->downloadBannerImage(
                imageUrl.toString(),        // 图片URL
                songId                     //id
                );

            // 5.7 临时存储Banner信息到管理器（便于UI后续展示）
            Bannerinfo bannerInfo;
            bannerInfo.songId=songId;
            MusicManager::GetInstance()->addbanneritem(bannerInfo);
        }

        // 6. 解析完成：通知UI更新Banner展示（如需要）
        qDebug() << u8"\nBanner图片解析与下载触发完成，共处理" << bannersArr.size() << u8"个Banner";
    }//处理推荐窗口的获取url,直接播放
    else if(id == ReqId::ID_GET_MUSIC_PLAYURL)
    {
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"搜索请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取搜索结果";
                break;
            default:
                errMsg = u8"未知错误，搜索失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"搜索结果解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"搜索接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保证 JSON 格式不被添加额外引号干扰
        qDebug() << "=======================================";
        // 从 rootObj 中取出 "data" 数组
        QJsonValue dataVal = rootObj["data"];
        if (!dataVal.isArray()) {
            qWarning() << u8"JSON 数据格式错误：'data' 字段不是数组";
            return;
        }

        QJsonArray dataArray = dataVal.toArray();

        // 判断是否有数据
        if (dataArray.isEmpty()) {
            qWarning() << u8"没有搜索到任何歌曲";
            return;
        }

        // 取第一首歌（索引 0）
        QJsonValue firstSongVal = dataArray.at(0);
        if (!firstSongVal.isObject()) {
            qWarning() << u8"第一首歌曲数据格式错误，不是 JSON 对象";
            return;
        }

        QJsonObject firstSongObj = firstSongVal.toObject();

        qint64 songId = firstSongObj["id"].toVariant().toLongLong();  // 例如 347321
        QString urlStr = firstSongObj["url"].toString();              // 例如 http://...

        // 处理URL为空的情况（版权限制等）
        if (urlStr.isEmpty()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 无播放权限（版权限制）";
            qWarning() << errMsg;
            return;
        }

        // 补全URL协议头（防止API返回的URL缺少http/https）
        QUrl playUrl(urlStr);
        if (playUrl.scheme().isEmpty()) {
            playUrl.setScheme("http"); // 默认为http，若实际为https可调整
        }

        // 验证URL有效性
        if (!playUrl.isValid()) {
            QString errMsg = u8"歌曲ID " + QString::number(songId) + u8" 播放URL无效：" + urlStr;
            qWarning() << errMsg;
            return;
        }

        // 解析成功，更新MusicManager中的URL
        qDebug() << u8"歌曲ID " << songId << u8" 播放URL获取成功：" << playUrl.toString();
        // 1. 从缓存获取完整的MusicInfo（包含详情接口的数据）
        MusicInfo info = MusicManager::GetInstance()->getSongitem(songId);
        if (info.getsongId() == 0) {
            qWarning() << u8"播放失败：未找到歌曲详情，可能详情请求未完成";
            return;
        }
        // 2. 将播放URL设置到info中
        MusicManager::GetInstance()->setUrl(info.getsongId(),playUrl);  // 更新缓存
       info.setwangyiyun_url(playUrl);
         qDebug() << u8"设置后URL：" << info.geturl();
        // 3. 构建播放列表并播放
        QList<MusicInfo> validPlaylist;
        validPlaylist << info;

        if (validPlaylist.isEmpty()) {
            qWarning() << u8"播放列表中无有效URL的歌曲，无法播放";
            return;
        }

        // 更新播放列表并播放
        _playmode->setNewPlaylist(validPlaylist);
        _playmode->updateindex(info);

        // 4. 调用播放器播放（传入已包含URL的info）
        ui->playbackControlPanel_wi->playMusic(info.geturl());  // 确保geturl()能正确返回URL
        ui->playbackControlPanel_wi->setUi(info);  // 设置UI显示详情
    }//若为获取详情
    else if(id == ReqId::ID_GET_DETAIL)
    {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"获取歌曲详情超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取歌曲详情";
                break;
            default:
                errMsg = u8"未知错误，获取歌曲详情失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"歌曲详情解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"歌曲详情接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的歌曲详情原始 JSON 数据 =======";
        qDebug().noquote() << res;
        qDebug() << "===========================================";

        // 提取歌曲列表（详情接口中"songs"是数组，通常包含一首歌曲的完整信息）
        QJsonArray songsArr = rootObj["songs"].toArray();
        if (songsArr.isEmpty()) {
            qWarning() << u8"歌曲详情数据为空";
            return;
        }

        // 解析第一首歌曲（详情接口通常返回单个歌曲的完整信息）
        QJsonObject songObj = songsArr[0].toObject();
        MusicInfo detailInfo;

        // 1. 基础信息：歌曲ID、名称
        qint64 songId = songObj["id"].toVariant().toLongLong();
        detailInfo.setsongId(songId);
        detailInfo.setwangyiyun_id(songId);
        detailInfo.setTitle(songObj["name"].toString());
        qDebug() << u8"歌曲ID：" << songId << u8"，歌曲名：" << detailInfo.gettitle();

        // 2. 艺术家信息（"ar"数组）
        QJsonArray artistsArr = songObj["ar"].toArray();
        QStringList artistNames;
        QList<qint64> artistIds;
        for (const QJsonValue& artistVal : artistsArr) {
            if (artistVal.isObject()) {
                QJsonObject artistObj = artistVal.toObject();
                artistNames << artistObj["name"].toString();
                artistIds << artistObj["id"].toVariant().toLongLong();
            }
        }
        detailInfo.setcomposer(artistNames.join("/"));
        qDebug() << u8"艺术家：" << detailInfo.getcomposer();

        // 3. 专辑信息（"al"对象）
        if (songObj.contains("al") && songObj["al"].isObject()) {
            QJsonObject albumObj = songObj["al"].toObject();
            detailInfo.setAlbum(albumObj["name"].toString());

            // 专辑封面URL（补全协议头）
            // 在下载图片前处理URL
            QString picUrl = albumObj["picUrl"].toString();
            if (picUrl.startsWith("https")) {
                picUrl.replace("https", "http"); // 临时降级为HTTP
            }
            detailInfo.setm_image_url(QUrl(picUrl));
            qDebug() << u8"专辑：" << detailInfo.getalbum() << u8"，封面URL：" << picUrl;

            // 下载专辑封面（如果缓存中不存在）
            MusicInfo cachedInfo = MusicManager::GetInstance()->getSongitem(songId);
            if (cachedInfo.getsongId() == 0 || cachedInfo.getm_image().isNull()) {
                HttpMgr::GetInstance()->downloadImage(picUrl, songId);
                qDebug() << u8"开始下载专辑封面：" << picUrl;
            } else {
                qDebug() << u8"专辑封面已缓存，无需重复下载";
            }
        }


        // 4. 时长（API中"dt"是毫秒，转换为秒）
        qint64 durationMs = songObj["dt"].toVariant().toLongLong();  // 注意字段是"dt"而非"duration"
       detailInfo.setDuration(durationMs);  // 转换为秒级时长

        // 6. 存储到音乐管理器
        MusicManager::GetInstance()->addSongitem(detailInfo);  // 添加或更新缓存
        qDebug() << u8"歌曲详情解析完成，已更新至缓存";

       //无需发信号,等待获取url直接播放
        // 关键：详情获取后，立即请求播放URL（无需延时）
        HttpMgr::GetInstance()->getMusicUrl(QString::number(songId), Modules::MODULE_RECOMMEND);
    }//处理获取推荐歌单情况
    else if (id == ReqId::ID_GET_SONGLIST)
    {
        // 1. 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"推荐歌单请求超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取推荐歌单";
                break;
            default:
                errMsg = u8"未知错误，推荐歌单获取失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 2. 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"推荐歌单解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 3. 检查接口返回状态（code=200表示成功）
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"推荐歌单接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }

        // 打印原始数据（调试用）
        qDebug() << u8"======= 收到的推荐歌单完整原始 JSON 数据 =======";
        qDebug().noquote() << res;  // noquote() 保留JSON原始格式
        qDebug() << "===============================================";

        // 4. 解析核心歌单数组（关键：原代码误解析banners，实际歌单在result数组中）
        QJsonValue playlistsVal = rootObj["result"];
        if (!playlistsVal.isArray()) {
            qWarning() << u8"推荐歌单数据格式错误：'result'字段不是数组";
            return;
        }
        QJsonArray playlistsArr = playlistsVal.toArray();
        if (playlistsArr.isEmpty()) {
            qDebug() << u8"未获取到任何推荐歌单数据";
            return;
        }

        // 5. 遍历歌单数组，提取关键信息并处理（下载封面图、缓存歌单信息）
        for (const QJsonValue& playlistVal : playlistsArr) {
            if (!playlistVal.isObject()) {
                qWarning() << u8"跳过无效歌单数据（非JSON对象）";
                continue;
            }
            QJsonObject playlistObj = playlistVal.toObject();

            // 5.1 提取歌单核心信息（与JSON字段一一对应）
            qint64 playlistId = playlistObj["id"].toVariant().toLongLong();  // 歌单唯一ID
            QString playlistName = playlistObj["name"].toString();          // 歌单名称
            QString coverPicUrl = playlistObj["picUrl"].toString();         // 歌单封面图URL

            // 打印歌单基础信息（调试用）
            qDebug() << u8"\n=== 解析到歌单 ===";
            qDebug() << u8"歌单ID：" << playlistId;
            qDebug() << u8"歌单名称：" << playlistName;
            qDebug() << u8"封面URL：" << coverPicUrl;

            // 5.2 过滤无效数据（必须包含歌单ID和封面URL）
            if (playlistId <= 0 || coverPicUrl.isEmpty()) {
                qWarning() << u8"跳过无效歌单（ID为空或封面URL为空）：" << playlistName;
                continue;
            }

            // 5.3 补全封面URL协议头（防止API返回URL缺少http/https）
            QUrl picUrl(coverPicUrl);
            if (picUrl.scheme().isEmpty()) {
                picUrl.setScheme("https");  // 网易云图片优先用HTTPS，兼容性更好
                qDebug() << u8"补全封面URL协议头：" << picUrl.toString();
            }
            // 验证URL有效性
            if (!picUrl.isValid()) {
                qWarning() << u8"无效歌单封面URL：" << coverPicUrl;
                continue;
            }

            // 5.4 检查封面图是否已缓存（避免重复下载，需在MusicManager中实现缓存判断）
            bool isCoverCached = MusicManager::GetInstance()->isSonglistImageCached(playlistId);
            if (isCoverCached) {
                qDebug() << u8"歌单封面已缓存，跳过下载：" << playlistName;
                continue;
            }

            // 5.5 触发歌单封面图下载（调用HttpMgr的下载接口，需提前实现）
            qDebug() << u8"开始下载歌单封面：" << picUrl.toString();
            HttpMgr::GetInstance()->downloadSonglistImage(
                picUrl.toString(),  // 封面图URL
                playlistId          // 歌单ID（作为下载标识，便于后续关联）
                );

            // 5.6 构建歌单信息对象，存储到MusicManager（便于后续UI展示）
            SongListInfo songlistInfo;
            songlistInfo.songlistid=playlistId;
            songlistInfo.songlistname=playlistName;
            // 缓存歌单基础信息（封面图下载完成后再更新封面本地路径）
            MusicManager::GetInstance()->addsonglistitem(songlistInfo);

        }
        // 6. 解析完成：统计处理结果
        qDebug() << u8"\n推荐歌单解析与下载触发完成，共处理" << playlistsArr.size() << u8"个歌单，有效歌单";
        //间隔一秒,确保图片加载完才初始化
        QTimer::singleShot(500, [this]() {
           ui->recommend_wi->initsonglistcardwi();
        });
    }//处理获取歌单中歌曲
    else if (id == ReqId::ID_GET_LIST_INFO)
    {
        // 处理错误情况
        if (err != ErrorCodes::ERROR_NONE) {
            QString errMsg;
            switch (err) {
            case ErrorCodes::ERROR_TIMEOUT:
                errMsg = u8"获取歌单信息超时，请稍后重试";
                break;
            case ErrorCodes::ERROR_NETWORK:
                errMsg = u8"网络错误，无法获取歌单信息";
                break;
            default:
                errMsg = u8"未知错误，获取歌单信息失败";
            }
            qWarning() << errMsg;
            return;
        }

        // 解析JSON数据
        QJsonParseError parseErr;
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(), &parseErr);
        if (parseErr.error != QJsonParseError::NoError) {
            qWarning() << u8"歌单信息解析失败：" << parseErr.errorString();
            return;
        }

        QJsonObject rootObj = doc.object();
        // 检查接口返回状态
        if (rootObj["code"].toInt() != 200) {
            qWarning() << u8"歌单接口返回异常，code：" << rootObj["code"].toInt();
            return;
        }
        qDebug() << u8"======= 收到的歌单完整原始 JSON 数据 =======";
        qDebug().noquote() << res;
        qDebug() << "=======================================";

        // 提取歌单中的歌曲列表
        QJsonArray songsArr = rootObj["songs"].toArray();
        if (songsArr.isEmpty()) {
            qWarning() << u8"歌单中没有歌曲数据";
            return;
        }

        QList<MusicInfo> songList;
        // 解析权限信息（用于判断歌曲是否可播放）
        QJsonArray privilegesArr = rootObj["privileges"].toArray();
        QMap<qint64, QJsonObject> privilegeMap;
        for (const QJsonValue& privVal : privilegesArr) {
            if (privVal.isObject()) {
                QJsonObject privObj = privVal.toObject();
                qint64 songId = privObj["id"].toVariant().toLongLong();
                privilegeMap.insert(songId, privObj);
            }
        }

        // 遍历解析每首歌曲
        for (const QJsonValue& songVal : songsArr) {
            if (!songVal.isObject()) continue;
            QJsonObject songObj = songVal.toObject();

            MusicInfo info;
            // 1. 基础信息：歌曲ID、名称
            qint64 songId = songObj["id"].toVariant().toLongLong();
            info.setsongId(songId);
            info.setwangyiyun_id(songId);
            info.setTitle(songObj["name"].toString());

            // 2. 艺术家信息
            QJsonArray artistsArr = songObj["ar"].toArray();
            QStringList artistNames;
            for (const QJsonValue& artistVal : artistsArr) {
                if (artistVal.isObject()) {
                    artistNames << artistVal.toObject()["name"].toString();
                }
            }
            info.setcomposer(artistNames.join("/"));

            // 3. 专辑信息（含封面URL）
            if (songObj.contains("al") && songObj["al"].isObject()) {
                QJsonObject albumObj = songObj["al"].toObject();
                info.setAlbum(albumObj["name"].toString());

                QString picUrl = albumObj["picUrl"].toString();
                if (picUrl.startsWith("https://")) {
                    picUrl.replace("https://", "http://"); // 替换为 HTTP
                } else if (!picUrl.startsWith("http")) {
                    picUrl = "http:" + picUrl; // 补全为 HTTP 协议
                }
                info.setm_image_url(QUrl(picUrl));
                // 下载封面图片（如果缓存中没有）
                MusicInfo cachedInfo = MusicManager::GetInstance()->getSongitem(songId);
                if (cachedInfo.getsongId() == 0 || cachedInfo.getm_image().isNull()) {
                    HttpMgr::GetInstance()->downloadImage(picUrl, songId);
                }
            }

            // 4. 时长（毫秒转换为秒）
            qint64 durationMs = songObj["dt"].toVariant().toLongLong();
            info.setDuration(durationMs );
            qDebug()<<u8"时间"<<durationMs;
            songList << info;
        }

        // 将解析的歌曲添加到音乐管理器缓存
        for (auto& info : songList) {
            MusicManager::GetInstance()->addSongitem(info);
        }

        // 打印解析结果
        qDebug() << u8"\n=== 歌单解析完成 ===";
        qDebug() << u8"共解析到" << songList.size() << u8"首歌曲";
        for (int i = 0; i < songList.size(); ++i) {
            const MusicInfo& info = songList.at(i);
            qDebug() << u8"第" << (i + 1) << u8"首：" << info.gettitle();
        }

        // 更新UI展示搜索结果
        qDebug() << u8"歌单页面切换";
        ui->songlist_wi->setsonglistResults(songList);
        ui->pages_wi->setCurrentWidget(ui->songlist_wi);
    }
}
void MainWidget::slot_suggestionSelected(const QString &text)
{
    if (text.isEmpty()) {
        return;
    }

    // 隐藏搜索建议窗口
    if (recomWi) {
        recomWi->hide();
    }

    // 更新搜索框文本
    ui->search_lin->setText(text);

    // 处理特殊情况：当选择的是"搜索XXX"选项时，提取关键词并执行搜索
    static QString searchPrefix = u8"搜索\"";
    if (text.startsWith(searchPrefix) && text.endsWith("\""))
    {
        QString keyword = text.mid(searchPrefix.length(), text.length() - searchPrefix.length() - 1);
        if (!keyword.isEmpty()) {
            // 执行实际搜索操作（示例：调用搜索接口）
            qDebug() << u8"执行搜索：" << keyword;
            //更新搜索窗口标题
            ui->search_wi->settitle(keyword);
            HttpMgr::GetInstance()->searchMusic(keyword,20,1); // 假设存在该搜索接口

            return;
        }
    }

    // 处理常规歌曲建议项（格式：歌曲名 - 艺术家）
    int separatorIndex = text.lastIndexOf(" - ");
    if (separatorIndex > 0) {
        QString songName = text.left(separatorIndex);
        QString artist = text.mid(separatorIndex + 3);
        qDebug() << u8"选中歌曲：" << songName << u8" 艺术家：" << artist;
            //更新搜索窗口标题
        ui->search_wi->settitle(text);
        // 可以直接根据歌曲名和艺术家搜索详细信息
        HttpMgr::GetInstance()->searchMusic(text,20,1); // 搜索完整匹配项


    }
    // 或者如果需要立即播放，可先尝试从缓存中查找
    // QList<MusicInfo> cachedSongs = MusicManager::GetInstance()->searchCachedSongs(songName, artist);
    // if (!cachedSongs.isEmpty()) {
    //     ui->playbackControlPanel_wi->playMusic(cachedSongs.first().geturl());
    // }
}

void MainWidget::onSearchPlayRequested(const MusicInfo &musicInfo)
{

    // 检查 MusicInfo 是否已有有效URL（本地/网络）
    if (musicInfo.geturl().isValid() && !musicInfo.geturl().isEmpty()) {
        qDebug()<<u8"已缓存URL直接播放";
        QList<MusicInfo> validPlaylist ;
        validPlaylist<<musicInfo;
        // 情况1：已有URL（如本地歌曲或已缓存URL）→ 直接播放
        _playmode->setNewPlaylist(validPlaylist);
        //播放队列数据层设置
        _playmode->updateindex(musicInfo);

        //播放器设置
        ui->playbackControlPanel_wi->playMusic(musicInfo.geturl());
        ui->playbackControlPanel_wi->setUi(musicInfo);
    } else
    {
        // 情况2：无URL（网络歌曲）→ 调用 HttpMgr 获取播放URL
        HttpMgr::GetInstance()->getMusicUrl(QString::number(musicInfo.getsongId()),Modules::MODULE_SEARCH);
    }

}

void MainWidget::onLikePlayRequested(const MusicInfo &musicInfo,QList<MusicInfo> list)
{
    // 检查 MusicInfo 是否已有有效URL（本地/网络）
        qDebug()<<u8"已缓存URL直接播放";
        // 情况1：已有URL（如本地歌曲或已缓存URL）→ 直接播放
        _playmode->setNewPlaylist(list);
        //播放队列数据层设置
        _playmode->updateindex(musicInfo);

        //播放器设置
        ui->playbackControlPanel_wi->playMusic(musicInfo.geturl());
        ui->playbackControlPanel_wi->setUi(musicInfo);

}

void MainWidget::onsonglistclick(SongListInfo info)
{
    QString songlistid=QString::number(info.songlistid);
    HttpMgr::GetInstance()->getlistinfo(songlistid);
    //初始化歌单界面
    ui->songlist_wi->seticon(info.pic);
    ui->songlist_wi->settext(info.songlistname);
}

void MainWidget::onSonglistPlayRequested(const MusicInfo &musicInfo, QList<MusicInfo> list)
{
    // 检查 MusicInfo 是否已有有效URL（本地/网络）
    if (musicInfo.geturl().isValid() && !musicInfo.geturl().isEmpty()) {
        qDebug()<<u8"已缓存URL直接播放";
        QList<MusicInfo> validPlaylist ;
        validPlaylist<<musicInfo;
        // 情况1：已有URL（如本地歌曲或已缓存URL）→ 直接播放
        _playmode->setNewPlaylist(validPlaylist);
        //播放队列数据层设置
        _playmode->updateindex(musicInfo);

        //播放器设置
        ui->playbackControlPanel_wi->playMusic(musicInfo.geturl());
        ui->playbackControlPanel_wi->setUi(musicInfo);
    } else
    {
        // 情况2：无URL（网络歌曲）→ 调用 HttpMgr 获取播放URL
        HttpMgr::GetInstance()->getMusicUrl(QString::number(musicInfo.getsongId()),Modules::MODULE_SEARCH);
    }


}


void MainWidget::on_back_btn_clicked()
{

        ui->recommend_btn->setChecked(true);
    qDebug()<< u8"退回本地音乐侧边栏按钮";
    ClearLabelState(ui->recommend_btn);//把除了自己其他的按钮状态全部清除
    ui->pages_wi->setCurrentWidget(ui->recommend_wi);
}

