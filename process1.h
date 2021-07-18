#ifndef PROCESS1_H
#define PROCESS1_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class process1;
}

class process1 : public QWidget
{
    Q_OBJECT

public:
    explicit process1(QWidget *parent = nullptr);
    ~process1();

    void setui(QPixmap a,int t);

private:
    Ui::process1 *ui;
};

#endif // PROCESS1_H
