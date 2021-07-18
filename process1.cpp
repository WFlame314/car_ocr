#include "process1.h"
#include "ui_process1.h"

process1::process1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::process1)
{
    ui->setupUi(this);
    setWindowTitle("图片处理");
}

process1::~process1()
{
    delete ui;
}

void process1::setui(QPixmap a,int t)
{
    if(t==1)
    {
        ui->gray->setScaledContents(true);
        ui->gray->setPixmap(a);
    }
    else if(t==2)
    {
        ui->bin->setScaledContents(true);
        ui->bin->setPixmap(a);
    }
}
