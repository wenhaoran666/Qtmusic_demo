#include "mainwidget.h"
// #include"localwi.h"
#include <QApplication>
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include<QFile>
#include<QDir>
#include<QSettings>
#include"global.h"
#include"musicdbmanager.h"
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    //读取当前程序所在目录下的config.ini配置文件获取 GateServer的host port配置项拼接成一个 HTTP网址字符串gate_url_prefix。
    QString app_path = QCoreApplication::applicationDirPath();
    // 拼接文件名
    QString fileName = "config.ini";
    QString config_path = QDir::toNativeSeparators(app_path +
                                                   QDir::separator() + fileName);

    QSettings settings(config_path, QSettings::IniFormat);
    QString gate_host = settings.value("NeteaseCloudMusicApi/host").toString();
    QString gate_port = settings.value("NeteaseCloudMusicApi/port").toString();
    cloud_url_prefix = "http://"+gate_host+":"+gate_port;
    // 打印日志（包含原始配置和拼接后的URL前缀）
    qDebug() << u8"配置文件路径：" << app_path;  // 检查路径是否正确（如：./config.ini 或绝对路径）
    qDebug() << u8"[配置加载] NeteaseCloudMusicApi 主机地址：" << gate_host
             << u8"，端口：" << gate_port
             << u8"，拼接后的URL前缀：" << cloud_url_prefix;

    MainWidget w;
    //建议手动命令,qt中启动网易云API服务不好手动关服务
    // 启动网易云API服务
    //w.startNeteaseApiService();

    w.show();
    MusicDBManager::GetInstance();
    return a.exec();
}


