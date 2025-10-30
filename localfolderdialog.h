#ifndef LOCALFOLDERDIALOG_H
#define LOCALFOLDERDIALOG_H

#include "qboxlayout.h"
#include <QDialog>
//本地音乐点击添加文件夹出现的对话框
namespace Ui {
class LocalfolderDialog;
}

class LocalfolderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LocalfolderDialog(QWidget *parent = nullptr);
    ~LocalfolderDialog();
    void initPaths(const QStringList& paths);//初始化已有的路径
    QStringList getPaths() const;//获取路径
private slots:
    void on_pushButton_close_clicked();//关闭按钮
    void on_pushButton_selectFolder_clicked();//选择文件夹按钮
    void on_pushButton_accept_clicked();//确认按钮

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //用于拖动窗口
    QPoint dragPosition; // 用于记录鼠标拖动的位置
    bool m_dragging = true;  // 可选，标记是否正在拖动

     QVBoxLayout* _containerLayout;//存放路径项垂直布局
    QStringList _paths;//保存添加文件夹路径的列表
    Ui::LocalfolderDialog *ui;
};

#endif // LOCALFOLDERDIALOG_H
