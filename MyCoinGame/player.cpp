#include "player.h"
#include "chooselevelscene.h"
#include<QMenuBar>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QDebug>
#include"coin.h"
#include"dataconfig.h"
#include<QPropertyAnimation>
#include<QSound>

//Player::Player(QWidget *parent)
//    : QMainWindow{parent}
//{

//}

Player::Player(int levelnum)
{
    //添加音效
    QSound * sound4 = new QSound(":/res/BackButtonSound.wav",this);
    QSound * sound5 = new QSound(":/res/ConFlipSound.wav",this);
    QSound * sound6 = new QSound(":/res/LevelWinSound.wav",this);

    //设置胜利图片
    QPixmap pb;
    pb.load(":/res/LevelCompletedDialogBg.png");
    pb = pb.scaled(420,170);
    QLabel * lab = new QLabel;
    lab->setParent(this);
    lab->setGeometry(0,0,pb.width(),pb.height());
    lab->setPixmap(pb);
    lab->move(50,-170);

    this->m_Levelnum = levelnum;

    //固定大小
    this->setFixedSize(520,788);

    //设置关卡界面的图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置关卡界面的标题
    this->setWindowTitle("关卡选择");

    //设置退出按钮
    myPushButton * exitbtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    exitbtn->setParent(this);
    exitbtn->move(this->width() - exitbtn->width(),this->height() - exitbtn->height());

    //设置退出按钮的功能
    connect(exitbtn,&myPushButton::clicked,[=](){
        //音效
        sound4->play();

        //延迟发送信号
        QTimer::singleShot(300,this,[=](){
            emit Player::playexit();
        });
    });

    //设置菜单栏
    QMenuBar * menu = new QMenuBar;
    setMenuBar(menu);
    QMenu * startmenu = menu->addMenu("开始");
    QAction* action= startmenu->addAction("退出");

    //设置退出功能
    connect(action,&QAction::triggered,[=](){
        this->close();
    });

    //获取关卡数据
    dataConfig config;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->m_LevelType[i][j] =config.mData[this->m_Levelnum][i][j];
        }
    }

    for(int i = 0; i < 16; i++)
    {
        //设置QLabel
        QLabel * BackLabel = new QLabel(this);
        BackLabel->setFixedSize(100,100);
        QPixmap pix(":/res/BoardNode(1).png");
        pix = pix.scaled(BackLabel->width(),BackLabel->height());
        BackLabel->setPixmap(pix);
        BackLabel->move(60 + i % 4 * 100,260 + i / 4 * 100);

        //设置场景
        QString scn;
        if(m_LevelType[i/4][i%4] == 1)
        {
           scn = ":/res/Coin0001.png";
        }
        else
        {
            scn = ":/res/Coin0008.png";
        }
        Coin * coin = new Coin(scn);
        coin->setParent(this);
        coin->move(QPoint(60 + i % 4 * 100,260 + i / 4 * 100));

        coin->m_x = i%4;
        coin->m_y = i/4;
        coin->flag = this->m_LevelType[i%4][i/4];

        coinbtn[i%4][i/4] = coin;

        connect(coin,&Coin::clicked,[=](){
            //设置音效
            sound5->play();

            coin->changeflag();
            this->m_LevelType[i%4][i/4] = this->m_LevelType[i/4][i%4] == 0 ? 1 : 0;

            //实现周围金币的延迟反转
            QTimer::singleShot(300,this,[=](){
                if(coin->m_x - 1 >= 0)
                {
                    this->coinbtn[coin->m_x - 1][coin->m_y]->changeflag();
                    this->m_LevelType[coin->m_x - 1][coin->m_y] = this->m_LevelType[coin->m_x - 1][coin->m_y] == 0 ? 1 : 0;
                }
                if(coin->m_x + 1 <=3)
                {
                    this->coinbtn[coin->m_x + 1][coin->m_y]->changeflag();
                    this->m_LevelType[coin->m_x + 1][coin->m_y] = this->m_LevelType[coin->m_x + 1][coin->m_y] == 0 ? 1 : 0;
                }
                if(coin->m_y + 1 <= 3)
                {
                    this->coinbtn[coin->m_x][coin->m_y + 1]->changeflag();
                    this->m_LevelType[coin->m_x][coin->m_y + 1] = this->m_LevelType[coin->m_x][coin->m_y + 1] == 0 ? 1 : 0;
                }
                if(coin->m_y - 1 >= 0)
                {
                    this->coinbtn[coin->m_x][coin->m_y - 1]->changeflag();
                    this->m_LevelType[coin->m_x][coin->m_y - 1] = this->m_LevelType[coin->m_x][coin->m_y - 1] == 0 ? 1 : 0;
                }


                this->IsWin =true;
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        if(coinbtn[i][j]->flag == false)
                        {
                            this->IsWin = false;
                            i = 5;
                            return;
                        }
                    }
                }

                if(this->IsWin == true)
                {
                    qDebug() << "胜利了";
                    for(int i = 0; i< 4; i++)
                    {
                        for(int j =0; j < 4; j++)
                        {
                            this->coinbtn[i][j]->Iswin = true;
                        }
                    }
                    //设置音效
                    sound6->play();

                    //设置动画
                    QPropertyAnimation * animation = new QPropertyAnimation(lab,"geometry");

                    //设置动画时间
                    animation->setDuration(1000);

                    //开始位置
                    animation->setStartValue(QRect(lab->x(),lab->y(),lab->width(),lab->height()));

                    //结束位置
                    animation->setEndValue(QRect(lab->x(),lab->y()+215,lab->width(),lab->height()));

                    //设置弹起特效
                    animation->setEasingCurve(QEasingCurve::OutBounce);

                    //动画开始
                    animation->start();
                }
            });

        });

    }

    //设置关卡数显示
    QLabel * label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(30);
    label->setFont(font);
    QString stn = QString("Level: %1").arg(this->m_Levelnum);
    label->setText(stn);
    label->setGeometry(10,this->height()-60,250,50);
}

void Player::paintEvent(QPaintEvent *event)
{

    //建立对象
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    //进行拉伸
    pix = pix.scaled(this->width(),this->height());
    painter.drawPixmap(0,0,pix);

    //设置背景上的装饰品
    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*0.8,pix.height()*0.8);

    painter.drawPixmap(0,40,pix);
}
