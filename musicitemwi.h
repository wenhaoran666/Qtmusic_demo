#ifndef MUSICITEMWI_H
#define MUSICITEMWI_H

#include "musicinfo.h"
#include "qlabel.h"
#include <QWidget>

namespace Ui {
class MusicItemwi;
}

class MusicItemwi : public QWidget
{
    Q_OBJECT

public:
    explicit MusicItemwi(const MusicInfo &musicInfo, QWidget *parent = nullptr);
    // void setUi(const MusicInfo &musicInfo);//设置信息
    void setindex(int index);//设置序号
    // MusicInfo getmusicinfo();//获取音乐项的信息(暂时没用上)
    ~MusicItemwi();
signals:
    void Play(const MusicInfo message);

private slots:
    void on_index_btn_clicked();//点击播放

private:
    bool eventFilter(QObject *watched, QEvent *event);//事件过滤
    // void setupUi();
    // void updateUi();
    // QLabel *m_titleLabel;
    // QLabel *m_albumLabel;
    // QLabel *m_durationLabel;
    // QLabel *m_sizeLabel;
    int m_index;//当前序号
    MusicInfo m_musicInfo;
private:
    Ui::MusicItemwi *ui;
};

#endif // MUSICITEMWI_H
