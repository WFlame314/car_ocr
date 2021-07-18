#ifndef PROCESS2_H
#define PROCESS2_H

#include <QWidget>
#include <QPixmap>
#include <QVector>
#include <QLabel>

namespace Ui {
class process2;
}

class process2 : public QWidget
{
    Q_OBJECT

public:
    explicit process2(QWidget *parent = nullptr);
    ~process2();

    void creatla(QPixmap a,int n);

private:
    Ui::process2 *ui;
    int total=0;
    int tx=20;
};

#endif // PROCESS2_H
