#include "localwi.h"
#include "localfolderdialog.h"
#include "musicmanager.h"
#include "qdebug.h"
#include "qdir.h"
#include "ui_localwi.h"
#include<QMimeDatabase>
#include <QMediaPlayer>
#include<QMediaMetaData>
#include<QTimer>
Localwi::Localwi(QWidget *parent)
    : QWidget(parent)
    // ,m_play(new QMediaPlayer(this))
    , ui(new Ui::Localwi)
{
    ui->setupUi(this);
    setcontainerui();//设置音乐窗口布局

        //text
    _musiccount=0;//先定义为1,后期从数据库中获取
    MusicInfo*te=new MusicInfo;
    QString s=u8"生日快乐";
    te->setTitle(s);
    te->setcomposer(u8"文");
    te->setAlbum(u8"18岁");
    te->setDuration(0);
    te->setSize(u8"3.45mb");
    MusicInfo*te1=new MusicInfo;
    te1->setTitle(u8"生乐");
    te1->setcomposer(u8"吕");
    te1->setAlbum(u8"38岁");
    te1->setDuration(0);
    te1->setSize(u8"3.45mb");
    MusicItemwi*text=new MusicItemwi(*te);
    MusicItemwi*text1=new MusicItemwi(*te);
    MusicItemwi*text2=new MusicItemwi(*te);
    MusicItemwi*text3=new MusicItemwi(*te);
    MusicItemwi*text4=new MusicItemwi(*te);
    MusicItemwi*text5=new MusicItemwi(*te);
    MusicItemwi*text6=new MusicItemwi(*te);
    MusicItemwi*text7=new MusicItemwi(*te);
    MusicItemwi*text8=new MusicItemwi(*te);
    MusicItemwi*text9=new MusicItemwi(*te1);

    //addmusicitem(*text);
    // addmusicitem(*text1);
    // addmusicitem(*text2);
    // addmusicitem(*text3);
    // addmusicitem(*text4);
    // addmusicitem(*text5);
    // addmusicitem(*text6);
    // addmusicitem(*text7);
    // addmusicitem(*text8);
    //addmusicitem(*text9);
}

void Localwi::addmusicitem( MusicItemwi &musicitrm)
{
    _musicitems[_musiccount]=&musicitrm;
    musicitrm.setindex(++l);//乱设的
     _containerLayout->insertWidget(_musiccount, &musicitrm);  // 插入到索引 0，即最上方
     _musiccount++;
}

void Localwi::showitems()
{

    for(int i=0;i<_musicitems.size();i++)
    {
     _containerLayout->insertWidget(i, _musicitems[i]);  // 插入到索引 0，即最上方
    }
}

Localwi::~Localwi()
{
    delete ui;
}

void Localwi::setcontainerui()
{
    //container窗口设置垂直布局,下方设置弹簧一直顶着,有窗口弹簧就伸缩
    _containerLayout = new QVBoxLayout(ui->container_wi);
    _containerLayout->setSpacing(0);                      // 控件之间的间距为 10px
    _containerLayout->setContentsMargins(40, 0, 0, 0);  // 左、上、右、下边距
    QSpacerItem *spacer = new QSpacerItem(20, 638, QSizePolicy::Expanding,QSizePolicy::Expanding);
    _containerLayout->addSpacerItem(spacer);
}

bool Localwi::isMedia(const QString &path)
{
    QMimeDatabase db;//获取文件MIME类
    QMimeType type = db.mimeTypeForFile(path);//保存MIME类型类
    return type.name().startsWith("audio/");
}

void Localwi::on_content_btn_clicked()
{
    qDebug()<<u8"点击添加文件夹";
    LocalfolderDialog dialog(this);
    dialog.initPaths(_selectedPaths);//把已选过的初始化上
    if(dialog.exec() == QDialog::Accepted)//点击确认才添加到列表中
    {
        _selectedPaths = dialog.getPaths();
        ui->reload_btn->clicked();//直接调用重新加载的功能
    }
    qDebug() << u8"选择的文件夹为:";
    for(auto& path : _selectedPaths)
    {
        qDebug() << path;
    }
    qDebug() << "-------------";

}


void Localwi::on_reload_btn_clicked()
{
    //  清空播放列表数据
    m_playlist.clear();  // 保持数据与界面一致
    //将所有音乐项清空
    for(auto m:_musicitems)
    {
         m->hide();
        _containerLayout->removeWidget(m);
         m->deleteLater();                     // 安全地安排删除
    }
    //容器也清空
    _musicitems.clear();
    _musiccount=0;//数量也请零
    l=0;
     qDebug() << u8"刷新:";
    //将每个文件夹路径转为QDir保存在QVector
     //QDir文件目录类
      QVector<QDir> dirs(_selectedPaths.begin(), _selectedPaths.end());
      processedFiles = 0;    //已经处理的
     int totalAudioFiles = 0;
     for (QDir d : dirs) {
         QStringList paths = d.entryList(); // 获取所有文件名
         for (auto &path : paths) {
             if (isMedia(path)) {
                 totalAudioFiles++;  // 统计所有音频文件数量
             }
         }
     }
     qDebug() << u8"总共要处理的音频文件数：" << totalAudioFiles;
     if(totalAudioFiles)
{
         for(QDir d:dirs)
    {
        QStringList paths = d.entryList();//获取文件夹中所有文件路径
         qDebug() <<u8"这是"<< paths<<u8"文件夹:";
         for(auto& path : paths)
        {
             //qDebug() << path;
             if (isMedia(path))
            {
                 qDebug() <<u8"找到音频文件: "<<path;       
                 QString fileName = path;  // 假设 path 是从 entryList() 得到的文件名
                 QString fullPath = d.filePath(fileName);  // 拼接为完整路径，如 F:/musictext1/xxx.mp3
                 QUrl fileUrl = QUrl::fromLocalFile(fullPath);  //用完整路径构造 QUrl
                 QFileInfo fileInfo(fileUrl.toLocalFile());   // 检查文件是否存在
                 MusicInfo m_song;
                  m_song.setlocal_url(QUrl::fromLocalFile(fullPath));  //存本地url

                 //存文件大小
                  if (fileInfo.exists() && fileInfo.isFile()) {
                      qint64 fileSizeBytes = fileInfo.size();
                      qDebug() << u8"文件大小（字节）：" << fileSizeBytes;
                      QString sizeStr;
                      if (fileSizeBytes < 1024) {
                          // 小于1KB，按字节显示（可选，如果不需要可以不显示或显示为 0.X KB）
                          sizeStr = QString::number(fileSizeBytes) + u8"B";
                          qDebug() << u8"约 " << sizeStr;
                      } else if (fileSizeBytes < 1024 * 1024) {
                          // 1KB ~ 1MB 之间，转换为 KB，保留两位小数
                          double sizeKB = fileSizeBytes / 1024.0;
                          sizeStr = QString::number(sizeKB, 'f', 2) + u8"KB";
                          qDebug() << u8"约 " << sizeStr;
                      } else {
                          // 大于等于 1MB，转换为 MB，保留两位小数
                          double sizeMB = fileSizeBytes / (1024.0 * 1024.0);
                          sizeStr = QString::number(sizeMB, 'f', 1) + u8"M";
                          qDebug() << u8"约 " << sizeStr;
                      }
                      // 最终将带单位的字符串传入 setSize
                      m_song.setSize(sizeStr);

                 } else {
                     qDebug() << u8"该文件路径无效或文件不存在";
                 }

                 //判断若不存在信息
                 if (!MusicManager::GetInstance()->isexistIcon(m_song))
                {
                     QUrl playUrl = m_song.geturl();
                     qDebug() << u8"准备加载音频文件，播放器使用的路径是:" << playUrl.toString();
                    QMediaPlayer *m_play=new QMediaPlayer(this);//播放器用于解析元数据
                     m_play->setMedia(playUrl);
                     m_play->setMedia(m_song.geturl());//给播放器设置路径

                // 连接 mediaStatusChanged 信号每当媒体加载状态发生变化时（比如开始加载、加载中、加载完成、加载失败等）
            //该信号就会被触发，并带回当前的加载状态 status
    connect(m_play, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) mutable
{//这里m_song一直报错,早知道用结构体了
    if (status == QMediaPlayer::LoadedMedia || status == QMediaPlayer::BufferedMedia)
    {
        // 此时媒体已加载，元数据通常已经可用
        qDebug() << u8"媒体已加载，元数据应该可用";
        // 你可以安全地获取元数据了，比如：
                             // 获取元数据
                             QVariant titleVariant = m_play->metaData(QMediaMetaData::Title);//标题
                             QVariant albumVariant = m_play->metaData(QMediaMetaData::AlbumTitle);//专辑
                             // QVariant composerVariant = m_play->metaData(QMediaMetaData::Author);
                             //作者
                                 // 1. 尝试 AlbumArtist（专辑艺术家）
                                 QVariant composerVariant = m_play->metaData(QMediaMetaData::AlbumArtist);
                                 if (composerVariant.isValid() && !composerVariant.toString().isEmpty()) {
                                     qDebug() << u8"专辑艺术家（AlbumArtist）：" << composerVariant.toString();
                                 } else
                                 {
                                     // 2. 尝试 Author（作者）
                                     composerVariant = m_play->metaData(QMediaMetaData::Author);
                                     if (composerVariant.isValid() && !composerVariant.toString().isEmpty()) {
                                         qDebug() << u8"作者（Author）：" << composerVariant.toString();
                                     } else
                                     {
                                         qDebug() << u8"未能获取到作者/演唱者信息";
                                     }
                                 }

                             //时长
                             QVariant durationVariant = m_play->metaData(QMediaMetaData::Duration);
                             //图片
                             QImage thumbnailImage = m_play->metaData(QMediaMetaData::ThumbnailImage).value<QImage>();

                             //设置songid
                             m_song.setsongId(nextSongId++);
                             // 设置歌曲标题
                             if (titleVariant.isValid() && !titleVariant.toString().isEmpty()) {
                                 m_song.setTitle(titleVariant.toString());
                                 qDebug() << u8"歌曲标题：" << titleVariant.toString();
                             } else {
                                 qDebug() << u8"未能获取到歌曲标题元数据";
                             }

                             // 设置专辑
                             if (albumVariant.isValid() && !albumVariant.toString().isEmpty()) {
                                 m_song.setAlbum(albumVariant.toString());
                                 qDebug() << u8"专辑：" << albumVariant.toString();
                             } else {
                                 qDebug() << u8"未能获取到专辑元数据";
                             }

                             // 设置作者
                             if (composerVariant.isValid() && !composerVariant.toString().isEmpty()) {
                                 m_song.setcomposer(composerVariant.toString());
                                 qDebug() << u8"作者：" << composerVariant.toString();
                             } else {
                                 m_song.setcomposer(u8"未获得");
                                 qDebug() << u8"未能获取到作者元数据";
                             }

                             // 设置时长
                             if (durationVariant.isValid()) {
                                 qint64 durationMs = durationVariant.toLongLong();  // 毫秒
                                 // qint64 totalSeconds = durationMs / 1000;           // 转为总秒数

                                 // int minutes = totalSeconds / 60;
                                 // int seconds = totalSeconds % 60;

                                 // // 格式化为 "分:秒"，比如 "1:30" 或更整齐的 "01:30"（补零）
                                 // QString timeStr = QString("%1:%2")
                                 //                       .arg(minutes)
                                 //                       .arg(seconds, 2, 10, QLatin1Char('0'));  // 秒数固定两位，不足补零
                                 m_song.setDuration(durationMs);  // 设置为格式化后的时间字符串，如 "1:30" 或 "01:30"
                                 qDebug() << u8"时长：" << durationMs;
                             } else {
                                 qDebug() << u8"未能获取到时长元数据";
                                 m_song.setDuration(0);  // 或者你可以设置为 "" 或其他默认值
                             }

                             //设置图片
                             if (!thumbnailImage.isNull())
                             {
                                 m_song.setm_image(QPixmap::fromImage(thumbnailImage)) ;
                             }
                             else
                             {
                                // 如果没有缩略图，再尝试获取封面图
                                QByteArray imageData = m_play->metaData(QMediaMetaData::CoverArtImage).toByteArray();
                                    if (!imageData.isEmpty())
                                {
                                    QPixmap p;
                                    bool success = p.loadFromData(imageData); // 调用成员函数加载图片数据
                                    if (success) {
                                        // 加载成功，可以使用 p
                                        m_song.setm_image(p);
                                        qDebug() << u8"封面图片加载成功";
                                    } else {
                                        // 加载失败
                                        qDebug() << u8"封面图片加载失败";
                                    }

                                }
                                    else
                                     {
                                         qDebug() << u8"No cover art available";
                                     }

                             }
                             // 添加
                             MusicManager::GetInstance()->addSongitem(m_song);
                             //初始化音乐项
                             MusicItemwi*songwi=new MusicItemwi(m_song,this);
                             //连接槽

                             //连接播放槽
                             connect(songwi,&MusicItemwi::Play,this,[=](const MusicInfo message){
                                 emit localplay(m_playlist,message);
                             });//将点击的歌曲和播放列表传入
                             QTimer::singleShot(0, this, [=]{
                                 addmusicitem(*songwi);
                            m_playlist.append(m_song);// 将该歌曲加入当前窗口的播放列表
                                 processedFiles++;  // 当前文件处理完成

                                 // 如果是最后一个文件，则发射信号
                                 if (processedFiles == totalAudioFiles) {
                                     qDebug() << u8"所有音频文件处理完毕，发送播放列表更新信号";
                                     emit updatelist();  // 通知外部播放列表已完整更新
                                 }

                             });

                         }
                     });

                 }
                 else{
                 //信息存在也重新添加
                 MusicItemwi*songwi=new MusicItemwi(m_song,this);
                 //连接槽

                 //连接播放槽
                 connect(songwi,&MusicItemwi::Play,this,[=](const MusicInfo message){
                     emit localplay(m_playlist,message);
                 });//将点击的歌曲和播放列表传入
                 addmusicitem(*songwi);
                 m_playlist.append(m_song);  // 将该歌曲加入当前窗口的播放列表
                  processedFiles++;  // 当前文件处理完成
                 if (processedFiles == totalAudioFiles) {
                     qDebug() << u8"所有音频文件处理完毕，发送播放列表更新信号";
                     emit updatelist();  // 通知外部播放列表已完整更新
                 }
                 }

            }

     }
   }
}
     else
     {
         emit updatelist();  // 通知外部播放列表已完整更新
     }
}




void Localwi::on_playall_btn_clicked()
{
    emit localplay(m_playlist,m_playlist[0]);
}

