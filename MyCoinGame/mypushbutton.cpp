#include "mypushbutton.h"
#include<QPainter>
#include<QPaintEvent>
#include<QPropertyAnimation>

//myPushButton::myPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}

myPushButton::myPushButton(QString filename1,QString filename2)
{
    //接收文件路径
    this->m_Filename1 = filename1;
    this->m_Filename2 = filename2;

    //初始化图标
    QPixmap pix;
    pix.load(m_Filename1);

    //固定按钮大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图型
    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(QIcon(pix));

    //固定图标大小
    setIconSize(QSize(pix.width(),pix.height()));
}

void myPushButton::zoom1()
{
    //建立动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geomtry");

    //设置动画时间
    animation->setDuration(200);

    //开始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x()+15,this->y()+15,this->width(),this->height()));

    //设置弹起特效
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //动画开始
    animation->start();
}

void myPushButton::zoom2()
{
    //建立动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");

    //设置动画时间
    animation->setDuration(200);

    //开始位置
    animation->setStartValue(QRect(this->x()+15,this->y()+15,this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹起特效
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //动画开始
    animation->start();
}

void myPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->m_Filename2 != "")
    {
        //初始化图标
        QPixmap pix;
        pix.load(m_Filename2);

        //固定按钮大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图型
        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(QIcon(pix));

        //固定图标大小
        setIconSize(QSize(pix.width(),pix.height()));

    }

    return QPushButton::mousePressEvent(e);
}

void myPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->m_Filename2 != "")
    {
        //初始化图标
        QPixmap pix;
        pix.load(m_Filename1);

        //固定按钮大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图型
        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(QIcon(pix));

        //固定图标大小
        setIconSize(QSize(pix.width(),pix.height()));
    }

    return QPushButton::mouseReleaseEvent(e);
}
