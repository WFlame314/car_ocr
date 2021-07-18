#include "process2.h"
#include "ui_process2.h"


process2::process2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::process2)
{
    ui->setupUi(this);
    setWindowTitle("车牌字符分割");
}

process2::~process2()
{
    delete ui;
}

void process2::creatla(QPixmap a, int n)
{
    QLabel *tl;
    tl=new QLabel(this);
    tl->setMinimumSize(67,135);
    tl->setPixmap(a);
    tl->setScaledContents(true);
    tl->move(tx+90*n,20);
    tl->show();
    setMinimumSize(tx+90*n+67+20,175);
}
