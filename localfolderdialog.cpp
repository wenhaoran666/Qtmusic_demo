#include "localfolderdialog.h"
#include "qdebug.h"
#include "qevent.h"
#include "qgraphicseffect.h"
#include "ui_localfolderdialog.h"
#include<QFileDialog>
#include<QCheckBox>
LocalfolderDialog::LocalfolderDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LocalfolderDialog)
{
    ui->setupUi(this);
    // 设置阴影:
     ui->widget_2->setAttribute(Qt::WA_TranslucentBackground); // 窗口背景透明
     setWindowFlag(Qt::FramelessWindowHint);
     setAttribute(Qt::WA_TranslucentBackground);
     //这里用阴影出现显示bug,暂时不设置阴影
    //QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
     // effect->setColor(QColor(0, 0, 0, 66));
     // effect->setOffset(0, 0);
     // effect->setBlurRadius(10);
     // setGraphicsEffect(effect);

    //container窗口设置垂直布局,下方设置弹簧一直顶着,有窗口弹簧就伸缩
    _containerLayout = new QVBoxLayout(ui->container);
    _containerLayout->setSpacing(0);                      // 控件之间的间距为 10px
    _containerLayout->setContentsMargins(25, 0, 0, 0);  // 左、上、右、下边距
    QSpacerItem *spacer = new QSpacerItem(20, 441, QSizePolicy::Expanding,QSizePolicy::Expanding);
     _containerLayout->addSpacerItem(spacer);


}
void LocalfolderDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // head_wi各个子窗口都有自己可拖动的区域
        if (event->pos().y() < 150)
        {
            dragPosition = event->globalPos() - frameGeometry().topLeft();
            m_dragging=true;
        }
        else
            m_dragging=false;
    }
    QWidget::mousePressEvent(event);
}

void LocalfolderDialog::mouseMoveEvent(QMouseEvent *event)
{

    if (!m_dragging) {
        // 当前鼠标事件被禁用，直接忽略，不处理
        QWidget::mouseMoveEvent(event);
        return;
    }
    if (event->buttons() & Qt::LeftButton) {
        if (m_dragging==true) {
            move(event->globalPos() - dragPosition);
        }
    }
    QWidget::mouseMoveEvent(event);
}
LocalfolderDialog::~LocalfolderDialog()
{
    delete ui;
}

void LocalfolderDialog::initPaths(const QStringList &paths)
{
    _paths = paths;
    for(const auto& path : _paths){
        qDebug() << path;
        auto btn = new QCheckBox(path, ui->body);
        btn->setMinimumSize(QSize(500, 55));
        btn->setMaximumSize(QSize(500, 55));
        btn->setStyleSheet ("QCheckBox {font-size:20px;}"
                           "QCheckBox::indicator { width:20px; height:20px;}"
                           "QCheckBox::indicator:checked { background-color: red; border: 2px solid red; border-radius: 5px;} "
                           "QCheckBox::indicator:unchecked { border: 2px solid #787F8D; border-radius: 5px;}"
                           "QCheckBox::indicator:unchecked:hover { border: 2px solid #000000; border-radius: 5px;}");
        btn->setChecked(true);
        _containerLayout->insertWidget(0, btn);
    }
}

void LocalfolderDialog::on_pushButton_close_clicked()
{
    this->reject();//拒绝的方式关闭,exec()的返回值会是QDialog::Rejected
}


void LocalfolderDialog::on_pushButton_selectFolder_clicked()
{
    //调用getExistingDirectory弹出文件夹窗口,点击哪个文件,path即为路径
    QString path = QFileDialog::getExistingDirectory(this, u8"请选择文件夹", QDir::homePath());
   qDebug() << u8"选择了文件夹" << path;
    if (path.size()){
        if (_paths.contains(path)){
            qDebug()<<u8"选过了";
        } else {
            _paths.push_back(path);
            auto btn = new QCheckBox(path, ui->body);
            btn->setMinimumSize(QSize(500, 55));
            btn->setMaximumSize(QSize(500, 55));
            btn->setStyleSheet ("QCheckBox {font-size:20px;}"
                               "QCheckBox::indicator { width:20px; height:20px;}"
                               "QCheckBox::indicator:checked { background-color: red; border: 2px solid red; border-radius: 5px;} "
                               "QCheckBox::indicator:unchecked { border: 2px solid #787F8D; border-radius: 5px;}"
                               "QCheckBox::indicator:unchecked:hover { border: 2px solid #000000; border-radius: 5px;}");
            btn->setChecked(true);
            _containerLayout->insertWidget(0, btn);
            //_containerLayout->addWidget(btn);
        }
    }

}


void LocalfolderDialog::on_pushButton_accept_clicked()
{
    this->accept();//以接受方式关闭,exec()的返回值是QDialog::Accepted
}

QStringList LocalfolderDialog::getPaths() const
{
    QStringList ret;
    QList<QCheckBox*> list = findChildren<QCheckBox*>();
    for(auto btn : list){
        if (btn->isChecked()){
            ret += btn->text();
        }
    }
    return ret;
}

