#include "mywidget.h"
#include "ui_mywidget.h"

#include <QTextEdit>

#define cout qDebug()

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    imagea=new QImage();
    Inintdata();
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_Button_open_clicked()
{
    p.clear();
    path=QFileDialog::getOpenFileName(this,"打开识别图片",".","Images (*.png *.jpg);;全部文件 (*.*)");
    if(path!="")
    {
        ui->lineEdit_filepath->setText(path);
        imagea->load(path);
        ui->carimage->setScaledContents(true);
        ui->carimage->setPixmap(QPixmap::fromImage(*imagea));
        imagea=MyWidget::greySca(imagea);
        pro1.setui(QPixmap::fromImage(*imagea,Qt::AutoColor),1);
        pro1.show();
        imagea->save("./temp1.jpg");
        *imagea=imagea->scaled(440,140);//调整图片大小为440*140
        imagea->save("./temp3.jpg");
        imagea=MyWidget::BinSca(imagea);
        pro1.setui(QPixmap::fromImage(*imagea,Qt::AutoColor),2);
        imagea->save("./temp2.jpg");
        ui->carimage->setScaledContents(true);
    }
}

void MyWidget::on_Button_start_clicked()
{
    pro2.show();
    QString out="车牌号码为：";
    imagecat();
    QFile file;
    char *tempch;
    for(int i=0;i<=total;i++)
    {
        int max=0;

        QVector<basedata>::iterator pp,tp;
        file.setFileName(QString("./data/char%1.txt").arg(i));
        file.open(QIODevice::ReadOnly);
        tempch=file.readAll().data();
        file.close();
        for(pp=trains.begin();pp!=trains.end();pp++)
        {
            int out;
            out=pp->pd(tempch);
            //cout<<out;
            if(out>max)
            {
                max=out;
                tp=pp;
            }
        }
        out=tp->getdata(out);
    }
    ui->lineEdit->setText(out);
}

void MyWidget::imagecat()
{
    int i,j,tx;
    char* ctemp;
    QVector<mypoint>::iterator pp;
    int temp,times=0;
    for(i=3;i<imagea->width()-3;i++)
    {
        temp=0;
        for (j=20;j<imagea->height()-20;j++)
        {
            temp+=imagedata[i][j];
        }
        if(temp>5)
        {
            if(p.empty())
            {
                for(int k=i+1;k<imagea->width()-3;k++)
                {
                    temp=0;
                    for (j=10;j<imagea->height()-10;j++)
                    {
                        temp+=imagedata[k][j];
                    }
                    if(temp<5)
                    {
                        p.push_back(mypoint(i,k-1));
                        i=k;
                        k=imagea->width();
                    }else if(k-i>47)
                    {
                        p.push_back(mypoint(i,k-1));
                        i=k;
                        k=imagea->width();
                    }
                }
                tx=i;
            }else
            {
                if(i-tx>10)
                {
                    for(int k=i+1;k<imagea->width()-3;k++)
                    {
                        temp=0;
                        for (j=20;j<imagea->height()-20;j++)
                        {
                            temp+=imagedata[k][j];
                        }
                        if(temp<5)
                        {
                            p.push_back(mypoint(i,k-1));
                            i=k;
                            k=imagea->width();
                        }else if(k-i>47)
                        {
                            p.push_back(mypoint(i,k-1));
                            i=k;
                            k=imagea->width();
                        }
                    }
                    tx=i;
                }
            }
        }
    }
    for(pp=p.begin();pp!=p.end();pp++)
    {
        for(j=10;j<140;j++)
        {
            temp=0;
            for(i=pp->get_x1();i<pp->get_x2();i++)
            {
                temp+=imagedata[i][j];
            }
            if(temp>3)
            {
                pp->change_y1(j);
                for(j=j+85;j<140;j++)
                {
                    temp=0;
                    for(i=pp->get_x1();i<pp->get_x2();i++)
                    {
                        temp+=imagedata[i][j];
                    }
                    if(temp<3)
                    {
                        pp->change_y2(j);
                        j=140;
                    }
                }
            }
        }

    }
    QFile file;
    QTextStream out(&file);
    for(pp=p.begin();pp!=p.end();pp++)
    {
        total=times;
        file.setFileName(QString("./data/char%1.txt").arg(times));
        file.open(QFile::WriteOnly | QIODevice::Truncate);
        char aa,bb;
        aa=(char)pp->get_x2()-pp->get_x1();
        bb=(char)pp->get_y2()-pp->get_y1();
        out<<aa<<bb;
        for (int k=pp->get_y1();k<pp->get_y2();k++)
        {
            for(int kk=pp->get_x1();kk<pp->get_x2();kk++)
            {

                out<<(int)imagedata[kk][k];
            }
        }
        out<<'\0';
        file.close();
        file.setFileName(QString("./data/char%1.txt").arg(times));
        file.open(QIODevice::ReadOnly);
        ctemp=file.readAll().data();
        file.close();
        changesize(ctemp,times);
        times++;
    }
}

QImage * MyWidget::greySca(QImage * oimage)
{
    QImage * newImage = new QImage(oimage->width(), oimage->height(), QImage::Format_Grayscale8);
        for(int y = 0; y<newImage->height(); y++){
            //获取一行像素的首地址
            QRgb * line = (QRgb *)oimage->scanLine(y);

            for(int x = 0; x<newImage->width(); x++){
                //提取像素
                //灰度转换的一种方法（R G B 求平均值）
                int average = (qRed(line[x])*0.299 + qGreen(line[x])*0.587 + qBlue(line[x])*0.114);
                newImage->setPixel(x,y, qRgb(average, average, average));
            }
        }
        return newImage;

}

QImage * MyWidget::BinSca(QImage * oimage)
{
    int width = oimage->width();
    int height = oimage->height();
    int bytePerLine = oimage->bytesPerLine();    // 每一行的字节数
    unsigned char *data = oimage->bits();
    unsigned char *binarydata = new unsigned char[bytePerLine * height];
    unsigned char g = 0;
    threshold=MyWidget::Otsu(oimage);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            g = *(data + i * bytePerLine + j);
            if(int(g) >= threshold)
            {
                binarydata[ i * bytePerLine + j] = 0xFF;
            }
            else
            {
                binarydata[ i * bytePerLine + j] = 0x00;
            }
        }
    }
    for (int k=0;k<440;k++)
    {
        for(int kk=0;kk<140;kk++)
        {
            imagedata[k][kk]=binarydata[k+kk*bytePerLine];
            if(imagedata[k][kk]==255)
            {
                imagedata[k][kk]=1;
            }
        }

    }
    QFile file(QString("./data/imagedata1.txt"));
    file.open(QFile::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    for (int k=0;k<440;k++)
    {
        for(int kk=0;kk<140;kk++)
        {
            out<<imagedata[k][kk];
        }
            out<<"\n";
    }
    file.close();
    QFile file2(QString("./data/imagedata2.txt"));
    file2.open(QFile::WriteOnly | QIODevice::Truncate);
    QTextStream out2(&file2);
    for (int k=0;k<140;k++)
    {
        for(int kk=0;kk<440;kk++)
        {
            out2<<imagedata[kk][k];
        }
            out2<<"\n";
    }
    file2.close();
    QImage *newImage = new QImage(binarydata, width, height, bytePerLine, QImage::Format_Grayscale8);
    return newImage;
}

int MyWidget::Otsu(QImage* img)
{
    if (NULL == img)
    {
        return -1;
    }
    QVector<int> histogram = Histogram(img);
    int total = 0;
    for (int i = 0; i != histogram.size(); ++i)
    {
        total += histogram[i];
    }

    double sum = 0.0;
    for (int i = 1; i < histogram.size(); ++i)
        sum += i * histogram[i];
    double sumB = 0.0;
    double wB = 0.0;
    double wF = 0.0;
    double mB = 0.0;
    double mF = 0.0;
    double max = 0.0;
    double between = 0.0;
    double threshold = 0.0;
    for (int i = 0; i != 256; ++i)
    {
        wB += histogram[i];
        if (wB == 0)
            continue;
        wF = total - wB;
        if (wF == 0)
            break;
        sumB += i * histogram[i];
        mB = sumB / wB;
        mF = (sum - sumB) / wF;
        between = wB * wF * (mB - mF) * (mB - mF);
        if ( between > max )
        {
            threshold = i;
            max = between;
        }
    }
    return threshold;
}

QVector<int> MyWidget::Histogram( QImage* img )
{
    unsigned char* graydata = img->bits();
    QVector<int> hist(256);    // 256色
    for (int i = 0; i != img->width(); ++i)
    {
        for (int j = 0; j != img->height(); ++j)
        {
            int index = int(*graydata);
            hist[index] += 1;
            graydata += 1;    //step
        }
    }
    graydata = NULL;
    return hist;
}

void MyWidget::Inintdata()
{
    int num=0;
    char ch='A';
    char *temp;
    QFile file;
    for(;num<10;num++)
    {
        file.setFileName(QString("./basedata/out-%1.txt").arg(num));
        file.open(QIODevice::ReadOnly);
        temp=file.readAll().data();
        trains.push_back(basedata(45,90,temp,num));
        file.close();
    }
    for(num=11;num<44;num++)
    {
        file.setFileName(QString("./basedata/out-%1.txt").arg(num));
        file.open(QIODevice::ReadOnly);
        temp=file.readAll().data();
        trains.push_back(basedata(45,90,temp,num));
        file.close();
    }
    for(;ch<='Z';ch++)
    {
        if(ch!='I'&&ch!='O')
        {
            file.setFileName(QString("./basedata/out-%1.txt").arg(ch));
            file.open(QIODevice::ReadOnly);
            temp=file.readAll().data();
            trains.push_back(basedata(45,90,temp,ch));
            file.close();
        }
    }
    file.setFileName("./basedata/out-@.txt");
    file.open(QIODevice::ReadOnly);
    temp=file.readAll().data();
    trains.push_back(basedata(45,90,temp,'@'));
    file.close();

}

void MyWidget::changesize(char *imdata,int n)
{
    int width = imdata[0];
    int height = imdata[1];
    int bytePerLine = imdata[0];
    unsigned char *binarydata = new unsigned char[bytePerLine * height];
    unsigned char *data;
    cout<<width<<height;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if(imdata[i * bytePerLine + j+2]=='1')
            {
                binarydata[ i * bytePerLine + j] = 0xFF;
            }
            else
            {
                binarydata[ i * bytePerLine + j] = 0x00;
            }
        }
    }
    QImage *newImage = new QImage(binarydata, width, height, bytePerLine, QImage::Format_Grayscale8);
    *newImage=newImage->scaled(45,90);
    pro2.creatla(QPixmap::fromImage(*newImage,Qt::AutoColor),n);
    newImage->save(QString("./data/char%1.jpg").arg(n));
    data=newImage->bits();
    int idata[90*45];
    for (int i = 0; i < 90*45; ++i)
    {
        if(data[i]==0xFF)
        {
            idata[i]=1;
        }
        else
        {
            idata[i]=0;
        }
    }
    QFile file(QString("./data/char%1.txt").arg(n));
    file.open(QFile::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    for (int i = 0; i < 90*45; ++i)
    {
        out<<idata[i];
    }
    out<<'\0';
    file.close();
}
