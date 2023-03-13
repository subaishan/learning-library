#include "coin.h"
#include<QDebug>

//Coin::Coin(QWidget *parent)
//    : QPushButton{parent}
//{

//}

Coin::Coin(QString filename)
{
    this->m_filename = filename;

    QPixmap pix;
    pix.load(this->m_filename);
    pix = pix.scaled(100,100);

    this->setFixedSize(100,100);

    //设置不规则图型
    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(QIcon(pix));
    this->setIconSize(QSize(this->width(),this->height()));

    //初始化定时器
    time1 = new QTimer(this);
    time2 = new QTimer(this);

    connect(time1,&QTimer::timeout,[=](){
        QPixmap pix1;
        QString snn = QString(":/res/Coin000%1.png").arg(min++);
        pix1.load(snn);
        pix1 = pix1.scaled(100,100);
        //设置不规则图型
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(QIcon(pix1));
        this->setIconSize(QSize(100,100));

        if(this->min == this->max+1)
        {
            min = 1;
            time1->stop();
            this->IsAnimol = false;
        }
    });

    connect(time2,&QTimer::timeout,[=](){
        QPixmap pix2;
        QString sqn = QString(":/res/Coin000%1.png").arg(max--);
        pix2.load(sqn);
        pix2 = pix2.scaled(100,100);
        //设置不规则图型
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(QIcon(pix2));
        this->setIconSize(QSize(100,100));

        if(this->min - 1 == this->max)
        {
            max = 8;
            time2->stop();
            this->IsAnimol = false;
        }
    });
}

void Coin::changeflag()
{
    if(this->flag == true)
    {
        this->flag = false;
        time1->start(30);
        this->IsAnimol = true;
    }
    else
    {
        this->flag = true;
        time2->start(30);
        this->IsAnimol = true;
    }

}

void Coin::mousePressEvent(QMouseEvent *e)
{
    if(this->IsAnimol == true || this->Iswin == true)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
