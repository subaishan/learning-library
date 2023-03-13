#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include<QPaintEvent>
#include<QPainter>
#include<QTimer>

class Coin : public QPushButton
{
    Q_OBJECT
public:
//    explicit Coin(QWidget *parent = nullptr);

    //重写构造函数
    Coin(QString filename);

    //维护金银币
    QString m_filename;

    //金币的属性
    int m_x;//x坐标
    int m_y;//y坐标
    bool flag = true;//金币的正反

    //金币的反转特效
    void changeflag();
    int min = 1;
    int max = 8;

    //定时器
    QTimer * time1;
    QTimer * time2;

    //动画标志
    bool IsAnimol = false;

    //胜利标志
    bool Iswin = false;

    //重写鼠标按下事件
    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // COIN_H
