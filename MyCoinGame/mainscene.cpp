#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPaintEvent>
#include<QDebug>
#include"mypushbutton.h"
#include<QTimer>
#include<QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //创建关卡界面
    chooselevescene = new ChooseLevelScene;

    //监听关卡界面发送的信号
    connect(chooselevescene,&ChooseLevelScene::exit,[=](){
        chooselevescene->hide();
        this->setGeometry(chooselevescene->geometry());
        this->show();
    });

    //添加音效
    QSound * sound1 = new QSound(":/res/TapButtonSound.wav",this);

    //固定主窗口大小
    setFixedSize(520,788);

    //设置窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置窗口名称
    setWindowTitle("金币游戏");

    //建立开始按钮
    myPushButton * pbn = new myPushButton(":/res/MenuSceneStartButton.png");
    pbn->setParent(this);

    //设置开始按钮的位置
    pbn->move(this->width() * 0.5 - pbn->width() * 0.5,this->height() * 0.6);

    connect(pbn,&myPushButton::clicked,[=](){
        //音效
        sound1->play();

        //设置开始按钮的特效
        pbn->zoom1();
        pbn->zoom2();

        QTimer::singleShot(400,this,[=](){
            //隐藏主界面
            this->hide();

            chooselevescene->setGeometry(this->geometry());

            //出现关卡选择界面
            chooselevescene->show();
        });
    });

    //退出功能
    connect(ui->actionexit,&QAction::triggered, this,&MainScene::close);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    //设置主窗口背景
    QPixmap pix;
    QPainter painter(this);
    pix.load(":/res/PlayLevelSceneBg.png");

    pix = pix.scaled(this->width(),this->height());
    painter.drawPixmap(0,0,pix);

    //设置主窗口上的背景
    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*0.8,pix.height()*0.8);

    painter.drawPixmap(0,40,pix);
}
