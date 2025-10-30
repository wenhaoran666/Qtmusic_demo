#ifndef STATEPUSHBUTTON_H
#define STATEPUSHBUTTON_H
//自定义带状态的按钮
#include "qlabel.h"
#include "qpushbutton.h"
#include"global.h"
class StatePushbutton:public QPushButton
{
    Q_OBJECT
public:
    StatePushbutton(QWidget*parent=nullptr);

    ClickLbState GetCurState();//获取按钮状态
    void ClearState();//清除状态

    void SetSelected(bool bselected);//设置选中

protected:
    // void paintEvent(QPaintEvent* event);
    // virtual void mousePressEvent(QMouseEvent *ev) override;
    // virtual void mouseReleaseEvent(QMouseEvent *ev) override;
    // virtual void enterEvent(QEvent* event) override;
    // virtual void leaveEvent(QEvent* event) override;
signals:

private:

    ClickLbState _curstate;//当前控件状态
signals:



public slots:
};

#endif // STATEPUSHBUTTON_H
