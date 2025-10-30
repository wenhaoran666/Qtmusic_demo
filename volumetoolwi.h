#ifndef VOLUMETOOLWI_H
#define VOLUMETOOLWI_H

#include <QWidget>

namespace Ui {
class VolumeToolwi;
}

class VolumeToolwi : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeToolwi(QWidget *parent = nullptr);
    ~VolumeToolwi();
signals:
    void volumesize(int);//当前音量
private:
    Ui::VolumeToolwi *ui;
};

#endif // VOLUMETOOLWI_H
