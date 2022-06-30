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
    //���������
        srand((unsigned int)time(NULL));  //ͷ�ļ�  #include <ctime>


//��ʱ
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerout);
     timer->start(10);

   /*     repaint������repaint����������ִ���ػ棬ĳЩ��������Ҫ�������ı��綯���ȡ�

        update���Ƽ�ʹ�øú�������ԭ���Ǹú�����������ִ���ػ棬���ǵȵ��߳����»ص���Ϣѭ��ʱ��ִ���ػ棬
                �����repaint�����ػ溯�����ԣ�����update����ʱ��������Qt�������Ż��ٶ��Լ���˸������*/






//��С
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
//��
    setWindowTitle(GAME_TITLE);

 //����ͼ����Դ
    setWindowIcon(QIcon(GAME_ICON));
//���ñ���
   setStyleSheet("border-image: url(:/res/img_bg_level_1.jpg);");

}


//ʱ��
void Widget::timerout()
{

      m_map.mapPosition();

//�л�����
        enemyToScene();


        //�л��������
            for(int i = 0 ; i< ENEMY_NUM;i++)
            {
                //�ǿ��ел� ��������
               if(m_enemys[i].m_Free == false)
               {
                  m_enemys[i].updatePosition();
               }
            }

//�����ӵ�
    m_hero.shoot();
    //�����ӵ�����
    for(int i = 0 ;i < BULLET_NUM;i++)
    {

            m_hero.m_bullets[i].updatePosition();

    }
    //��ײ
    collisionDetection();

    //���㱬ը���ŵ�ͼƬ
        for(int i = 0 ; i < BOMB_NUM;i++)
        {
            if(m_bombs[i].m_Free == false)
            {
               m_bombs[i].updateInfo();
            }
        }
//        m_enemys->shot();
//        //�����ӵ�����
//        for(int i = 0 ;i < BULLET_NUM;i++)
//        {

//                m_enemys[i].m_diji[i].aaaa();

//        }



repaint();


// �� update();



}
Widget::~Widget()
{
    delete ui;
}

//���ñ���
 void Widget:: paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);

     //��ͼ
     if(a>50)
     {

     painter.drawPixmap(map_x,m_map.map1_y,this->width(),this->height(),m_map.m_map2);
     painter.drawPixmap(map_x,m_map.map2_y,this->width(),this->height(),m_map.m_map2);

     }else
     {painter.drawPixmap(map_x,m_map.map1_y,this->width(),this->height(),m_map.m_map1);
     painter.drawPixmap(map_x,m_map.map2_y,this->width(),this->height(),m_map.m_map1);}
     //���÷ɻ�
     painter.drawPixmap(m_hero.hero_x,m_hero.hero_y,m_hero.m_hero);




     //�����ӵ�
         for(int i = 0 ;i < BULLET_NUM;i++)
         {
             //����ӵ�״̬Ϊ�ǿ��У����㷢��λ��
             if(!m_hero.m_bullets[i].m_Free)
             {
                 painter.drawPixmap(m_hero.m_bullets[i].bullet_x,m_hero.m_bullets[i].bullet_y,m_hero.m_bullets[i].m_Bullet);
            }
         }

         //���Ƶл�
             for(int i = 0 ; i< ENEMY_NUM;i++)
             {
                 if(m_enemys[i].m_Free == false)
                 {
                     painter.drawPixmap(m_enemys[i].enemyplan_x,m_enemys[i].enemyplan_y,m_enemys[i].m_enemy);
                 }
             }


             //���Ʊ�ըͼƬ
                 for(int i = 0 ; i < BOMB_NUM;i++)
                 {
                     if(m_bombs[i].m_Free == false)
                     {
                         painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
                      }
                  }

//                 //�л��ӵ�
//                 for(int i = 0 ;i < BULLET_NUM;i++)
//                 {
//                     //����ӵ�״̬Ϊ�ǿ��У����㷢��λ��
//                     if(m_enemys[i].m_diji[i].panduan==1)
//                     {
//                         painter.drawPixmap(m_enemys[i].m_diji[i].dijibullet_x,m_enemys[i].m_diji[i].dijibullet_y,m_enemys[i].m_diji[i].diji);
//                    }
//                 }

 }








//���ɻ�

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x()-m_hero.m_hero.width()*0.5;//���λ�� - �ɻ����ε�һ��
    int y=event->y()-m_hero.m_hero.height()*0.5;
    //�߽���
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




//�л�
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
            //�л�����״̬��Ϊfalse
            m_enemys[i].m_Free = false;
            //��������
            m_enemys[i].enemyplan_x = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].enemyplan_y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}






void Widget::collisionDetection()
{
    //�������зǿ��еĵл�
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //���зɻ� ��ת��һ��ѭ��
            continue;
        }

        //�������� �ǿ��е��ӵ�
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                //�����ӵ� ��ת��һ��ѭ��
                continue;
            }


            //����ӵ����ο�͵л����ο��ཻ��������ײ��ͬʱ��Ϊ����״̬����
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;

                    a++;
                //���ű�ըЧ��
                                for(int k = 0 ; k < BOMB_NUM;k++)
                                {
                                    if(m_bombs[k].m_Free)
                                    {
                                        //��ը״̬����Ϊ�ǿ���
                                        m_bombs[k].m_Free = false;
                                        //��������
                                        m_bombs[k].m_X = m_enemys[i].enemyplan_x;
                                        m_bombs[k].m_Y = m_enemys[i].enemyplan_y;
                                        break;
                                    }
                                }

            }
        }
    }
}
