#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit myPushButton(QWidget *parent = nullptr);

    myPushButton(QString filename1,QString filename2 = "");

    //设置按钮特效
    void zoom1();
    void zoom2();

    //设置文件路径
    QString m_Filename1;
    QString m_Filename2;

    //重新鼠标事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
