#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <stdio.h>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <QBitmap>
#include <QPainter>
#include <vector>
#include <QFile>
#include <QDebug>
#include <math.h>
#include "process1.h"
#include "process2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void imagecat();

    QImage * greySca(QImage *);

    QImage * BinSca(QImage *);

    int Otsu(QImage* img);

    QVector<int> Histogram(QImage* img);

    void Inintdata();

    void changesize(char* imdata,int n);

private slots:
    void on_Button_open_clicked();

    void on_Button_start_clicked();




private:

    Ui::MyWidget *ui;
    QString path;
    QImage *imagea;
    int threshold;
    int imagedata[458][140];
    int total;

    class  mypoint
    {
    public:
        mypoint()
        {
            x1=0;
            y1=20;
            x2=0;
            y2=120;
        }
        mypoint(int a,int b)
        {
            x1=a;
            y1=20;
            x2=b;
            y2=120;
        }
        void change_x1(int x)
        {
            x1=x;
        }
        void change_x2(int x)
        {
            x2=x;
        }
        void change_y1(int y)
        {
            y1=y;
        }
        void change_y2(int y)
        {
            y2=y;
        }
        int get_x1()
        {
            return x1;
        }
        int get_x2()
        {
            return x2;
        }
        int get_y1()
        {
            return y1;
        }
        int get_y2()
        {
            return y2;
        }
    private:
        int x1,y1,x2,y2;
    };
    class  basedata
    {
    public:
        basedata()
        {}
        basedata(int a,int b,char *c,int n)
        {
            ch='#';
            num=n;
            w=a;
            h=b;
            data=new char[a*b];
            strcpy(data,c);
            //data=c;
        }
        basedata(int a,int b,char *c,char n)
        {
            ch=n;
            num=-1;
            w=a;
            h=b;
            data=new char[a*b];
            strcpy(data,c);
        }
        void show()
        {
            if(ch!='#')
            {
                if(ch=='@')
                {
                    qDebug()<<"·"<<"->"<<w<<","<<h;
                }else
                {
                    qDebug()<<ch<<"->"<<w<<","<<h;
                }
            }else if(num!=-1)
            {
                qDebug()<<num<<"->"<<w<<","<<h;
            }
        }
        int pd(char* odata)
        {
            int out=0;
            for(int i=0;i<45*90;i++)
            {
                if(data[i]==odata[i])
                {
                    out++;
                }
            }
            return out;
        }
        void output()
        {
            for(int i=0;i<20;i++)
            {
                qDebug()<<data[i];
            }
        }
        int test()
        {
            return num;
        }

        QString getdata(QString a)
        {
            QString b;
            if(ch!='#')
            {
                if(ch=='@')
                {
                    b="·";
                }else
                {
                    b=ch;
                }
            }else if(num!=-1)
            {
                if(num<10)
                {
                    b=QString("%1").arg(num);
                }else
                {
                    switch (num)
                    {
                    case 11:
                        b="京";
                    break;
                    case 12:
                        b="津";
                    break;
                    case 13:
                        b="冀";
                    break;
                    case 14:
                        b="晋";
                    break;
                    case 15:
                        b="蒙";
                    break;
                    case 16:
                        b="黑";
                    break;
                    case 17:
                        b="吉";
                    break;
                    case 18:
                        b="辽";
                    break;
                    case 19:
                        b="沪";
                    break;
                    case 20:
                        b="苏";
                    break;
                    case 21:
                        b="浙";
                    break;
                    case 22:
                        b="皖";
                    break;
                    case 23:
                        b="赣";
                    break;
                    case 24:
                        b="闽";
                    break;
                    case 25:
                        b="鲁";
                    break;
                    case 26:
                        b="豫";
                    break;
                    case 27:
                        b="鄂";
                    break;
                    case 28:
                        b="湘";
                    break;
                    case 29:
                        b="粤";
                    break;
                    case 30:
                        b="桂";
                    break;
                    case 31:
                        b="云";
                    break;
                    case 32:
                        b="贵";
                    break;
                    case 33:
                        b="川";
                    break;
                    case 34:
                        b="渝";
                    break;
                    case 35:
                        b="藏";
                    break;
                    case 36:
                        b="陕";
                    break;
                    case 37:
                        b="甘";
                    break;
                    case 38:
                        b="宁";
                    break;
                    case 39:
                        b="青";
                    break;
                    case 40:
                        b="新";
                    break;
                    case 41:
                        b="港";
                    break;
                    case 42:
                        b="澳";
                    break;
                    case 43:
                        b="台";
                    break;
                    default:
                        b="?";
                    }
                }
            }
            return a+b;
        }
    private:
        int num;
        char ch;
        int w,h;
        char *data;
    };

    QVector<mypoint> p;
    QVector<basedata> trains;

    process1 pro1;
    process2 pro2;
};
#endif // MYWIDGET_H
