#ifndef SONGLISTCARDWI_H
#define SONGLISTCARDWI_H

#include "global.h"
#include <QWidget>


class SongListCardwi : public QWidget
{
    Q_OBJECT

public:
    explicit SongListCardwi(QWidget *parent = nullptr);
    ~SongListCardwi();

    //初始化
    void setinfo(SongListInfo &info);
    // 设置图片
    void setPixmap(const QPixmap &pixmap);
    // 设置显示文字
    void setText(const QString &text);
signals:
    //点击发送带歌单信息的信号
    void clicked( SongListInfo m_info);
private:
    // 重绘事件（核心：绘制图片和带模糊背景的文字）
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event)override;
    QPixmap m_pixmap;
    QString m_text;
    SongListInfo m_info;  //歌单信息
};

#endif // SONGLISTCARDWI_H
