#ifndef PROGRESSBARWI_H
#define PROGRESSBARWI_H
#include <QWidget>

namespace Ui {
class Progressbarwi;
}

class Progressbarwi : public QWidget
{
    Q_OBJECT

public:
    explicit Progressbarwi(QWidget *parent = nullptr);
    ~Progressbarwi();

private:
    Ui::Progressbarwi *ui;
};

#endif // PROGRESSBARWI_H
