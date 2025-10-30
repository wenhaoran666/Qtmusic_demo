#ifndef LOCALFOLDER_H
#define LOCALFOLDER_H

#include <QWidget>

namespace Ui {
class Localfolder;
}

class Localfolder : public QWidget
{
    Q_OBJECT

public:
    explicit Localfolder(QWidget *parent = nullptr);
    ~Localfolder();

private:
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //用于拖动窗口
    QPoint dragPosition; // 用于记录鼠标拖动的位置
    bool m_dragging = true;  // 可选，标记是否正在拖动
    Ui::Localfolder *ui;
};

#endif // LOCALFOLDER_H
