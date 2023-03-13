#include "chooselevelscene.h"
#include<QMenuBar>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QDebug>
#include"player.h"
#include<QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(520,788);

    //添加音效
    QSound * sound2 = new QSound(":/res/TapButtonSound.wav",this);
    QSound * sound3 = new QSound(":/res/BackButtonSound.wav");
    //设置关卡界面的图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置关卡界面的标题
    this->setWindowTitle("关卡选择");

    //设置菜单栏
    QMenuBar * menu = new QMenuBar;
    setMenuBar(menu);
    QMenu * startmenu = menu->addMenu("开始");
    QAction* action= startmenu->addAction("退出");

    //设置按钮
    myPushButton * exitbtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    exitbtn->setParent(this);
    exitbtn->move(this->width() - exitbtn->width(),this->height() - exitbtn->height());

    //设置按钮的功能
    connect(exitbtn,&myPushButton::clicked,[=](){
        sound3->play();

        QTimer::singleShot(300,this,[=](){
            emit ChooseLevelScene::exit();
        });
    });

    //设置关卡接口
    for(int i = 0; i < 20; i++)
    {
        myPushButton * levelbtn = new myPushButton(":/res/LevelIcon.png");
        levelbtn->setParent(this);
        levelbtn->move(90 + i % 4 * 100,200 + i / 4 * 100);

        //设置图标上的文字
       QLabel * txet = new QLabel(levelbtn);
       txet->resize(QSize(levelbtn->width(),levelbtn->height()));
       txet->setText(QString::number(i+1));
       txet->move(24,0);

       connect(levelbtn,&myPushButton::clicked,[=](){
           //音效
           sound2->play();

           //制作一个点击特效
           levelbtn->zoom1();
           levelbtn->zoom2();

           //制作延迟效果
           QTimer::singleShot(500,this,[=](){
               this->hide();

               //进入新的游戏界面
               play = new Player(i+1);

               play->setGeometry(this->geometry());
               play->show();

               //与游戏界面进行链接
               connect(play,&Player::playexit,[=](){
                   this->setGeometry(play->geometry());
                   this->show();
                   delete play;
                   play = NULL;
               });
           });
       });
    }

    //设置退出功能
    connect(action,&QAction::triggered,[=](){
        this->close();
    });
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    //设置背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    //背景拉伸
    pix = pix.scaled(this->width(),this->height());
    painter.drawPixmap(0,0,pix);

    //设置背景上的装饰
    pix.load(":/res/Title.png");
    pix = pix.scaled(this->width()* 0.8,this->height() * 0.2);

    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.5,30,pix);
}
