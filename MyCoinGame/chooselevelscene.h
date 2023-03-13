#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include"player.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    Player * play = NULL;
signals:
    void exit();

};

#endif // CHOOSELEVELSCENE_H
