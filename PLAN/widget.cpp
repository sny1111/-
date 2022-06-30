#include "widget.h"
#include "ui_widget.h"
#include"config.h"
#include"map.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include<QMouseEvent>
#include <ctime>

#include"heroPlan.h"
#include"bomb.h"


int map_x,a=0;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    map_x=0;
    m_recorder = 0;
    //随机数种子
        srand((unsigned int)time(NULL));  //头文件  #include <ctime>


//定时
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerout);
     timer->start(10);

   /*     repaint：调用repaint函数会立刻执行重绘，某些场景是需要这样做的比如动画等。

        update：推荐使用该函数，其原因是该函数不会立即执行重绘，而是等到线程重新回到消息循环时再执行重绘，
                相比于repaint立即重绘函数而言，调用update函数时，会允许Qt尽量的优化速度以及闪烁的问题*/






//大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
//名
    setWindowTitle(GAME_TITLE);

 //设置图标资源
    setWindowIcon(QIcon(GAME_ICON));
//设置背景
   setStyleSheet("border-image: url(:/res/img_bg_level_1.jpg);");

}


//时间
void Widget::timerout()
{

      m_map.mapPosition();

//敌机出场
        enemyToScene();


        //敌机坐标计算
            for(int i = 0 ; i< ENEMY_NUM;i++)
            {
                //非空闲敌机 更新坐标
               if(m_enemys[i].m_Free == false)
               {
                  m_enemys[i].updatePosition();
               }
            }

//发射子弹
    m_hero.shoot();
    //计算子弹坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {

            m_hero.m_bullets[i].updatePosition();

    }
    //碰撞
    collisionDetection();

    //计算爆炸播放的图片
        for(int i = 0 ; i < BOMB_NUM;i++)
        {
            if(m_bombs[i].m_Free == false)
            {
               m_bombs[i].updateInfo();
            }
        }
//        m_enemys->shot();
//        //计算子弹坐标
//        for(int i = 0 ;i < BULLET_NUM;i++)
//        {

//                m_enemys[i].m_diji[i].aaaa();

//        }



repaint();


// 或 update();



}
Widget::~Widget()
{
    delete ui;
}

//设置背景
 void Widget:: paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);

     //地图
     if(a>50)
     {

     painter.drawPixmap(map_x,m_map.map1_y,this->width(),this->height(),m_map.m_map2);
     painter.drawPixmap(map_x,m_map.map2_y,this->width(),this->height(),m_map.m_map2);

     }else
     {painter.drawPixmap(map_x,m_map.map1_y,this->width(),this->height(),m_map.m_map1);
     painter.drawPixmap(map_x,m_map.map2_y,this->width(),this->height(),m_map.m_map1);}
     //设置飞机
     painter.drawPixmap(m_hero.hero_x,m_hero.hero_y,m_hero.m_hero);




     //绘制子弹
         for(int i = 0 ;i < BULLET_NUM;i++)
         {
             //如果子弹状态为非空闲，计算发射位置
             if(!m_hero.m_bullets[i].m_Free)
             {
                 painter.drawPixmap(m_hero.m_bullets[i].bullet_x,m_hero.m_bullets[i].bullet_y,m_hero.m_bullets[i].m_Bullet);
            }
         }

         //绘制敌机
             for(int i = 0 ; i< ENEMY_NUM;i++)
             {
                 if(m_enemys[i].m_Free == false)
                 {
                     painter.drawPixmap(m_enemys[i].enemyplan_x,m_enemys[i].enemyplan_y,m_enemys[i].m_enemy);
                 }
             }


             //绘制爆炸图片
                 for(int i = 0 ; i < BOMB_NUM;i++)
                 {
                     if(m_bombs[i].m_Free == false)
                     {
                         painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
                      }
                  }

//                 //敌机子弹
//                 for(int i = 0 ;i < BULLET_NUM;i++)
//                 {
//                     //如果子弹状态为非空闲，计算发射位置
//                     if(m_enemys[i].m_diji[i].panduan==1)
//                     {
//                         painter.drawPixmap(m_enemys[i].m_diji[i].dijibullet_x,m_enemys[i].m_diji[i].dijibullet_y,m_enemys[i].m_diji[i].diji);
//                    }
//                 }

 }








//主飞机

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x()-m_hero.m_hero.width()*0.5;//鼠标位置 - 飞机矩形的一半
    int y=event->y()-m_hero.m_hero.height()*0.5;
    //边界检测
    if(x<=0)
    {x=0;}
    if(x>=GAME_WIDTH-m_hero.m_hero.width())
    {
        x=GAME_WIDTH-m_hero.m_hero.width();
    }
    if(y<=0)
    {y=0;}
    if(y>=GAME_HEIGHT-m_hero.m_hero.height())
    {y=GAME_HEIGHT-m_hero.m_hero.height();}
      m_hero.setPosition(x,y);
}




//敌机
void Widget::enemyToScene()
{
    m_recorder++;

    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //敌机空闲状态改为false
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].enemyplan_x = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].enemyplan_y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}






void Widget::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }


            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;

                    a++;
                //播放爆炸效果
                                for(int k = 0 ; k < BOMB_NUM;k++)
                                {
                                    if(m_bombs[k].m_Free)
                                    {
                                        //爆炸状态设置为非空闲
                                        m_bombs[k].m_Free = false;
                                        //更新坐标
                                        m_bombs[k].m_X = m_enemys[i].enemyplan_x;
                                        m_bombs[k].m_Y = m_enemys[i].enemyplan_y;
                                        break;
                                    }
                                }

            }
        }
    }
}
