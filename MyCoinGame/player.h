#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include<QPainter>
#include<QPaintEvent>
#include"coin.h"
#include<QPropertyAnimation>

class Player : public QMainWindow
{
    Q_OBJECT
public:
//    explicit Player(QWidget *parent = nullptr);

    //重写构造函数
    Player(int levelnum);

    //重写绘画事件
    void paintEvent(QPaintEvent *event);

    //关卡数
    int m_Levelnum;

    //关卡数据维护
    int m_LevelType[4][4];

    //金币按钮的维护
    Coin * coinbtn[4][4];

    //判断是否胜利
    bool IsWin = true;

signals:
    void playexit();
};

#endif // PLAYER_H
