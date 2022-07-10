#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include<QIcon>
#include <ctime>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    diji_time = 0;
    //���������
        srand((unsigned int)time(NULL));

    //ʱ��ۺ���
    QTimer *timer=new QTimer(this);

    connect(timer,&QTimer::timeout,this,&Widget::timeout);

    timer->start(10);




    //��С
        setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //��
        setWindowTitle(GAME_NAME);

     //����ͼ����Դ
        setWindowIcon(QIcon(GAME_APP));





}


void Widget::timeout()
{

    m_map.MAP_JISUAN();
    enemyToScene();
    for(int i = 0 ; i< diji_suliang;i++)
    {
        //�ǿ��ел� ��������
       if(m_diji[i].diji_free == false)
       {
          m_diji[i].updatePosition();
       }
    }


//�ػ�
repaint();

}





void Widget::paintEvent(QPaintEvent *event)

{int i=1;
    QPainter painter(this);
   //���ñ���
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y1,this->width(),this->height(),m_map.m_map);
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y2,this->width(),this->height(),m_map.m_map);

    //�������ɻ�
    painter.drawPixmap(m_hero.HERO_X,m_hero.HERO_Y,m_hero.HERO);

    //�л�
    for(int i=0;i<diji_suliang;i++)
    {


            if(m_diji[i].diji_free == false)
            {
                painter.drawPixmap(m_diji[i].diji_x,m_diji[i].diji_y,m_diji[i].dijiplan);

            }

     }



}



//�÷ɻ��������

void Widget::mouseMoveEvent(QMouseEvent *event)
{
   int x=event->x()-m_hero.HERO.width()*0.5;
   int y=event->y()-m_hero.HERO.height()*0.5;

   if(x<0)
   {x=0;}
   if(x>GAME_WIDTH-m_hero.HERO.width())
   {
     x=GAME_WIDTH-m_hero.HERO.width();

   }
    if(y<0)
    {y=0;}
    if(y>GAME_HEIGHT-m_hero.HERO.height())
    {
        y=GAME_HEIGHT-m_hero.HERO.height();
    }
    m_hero.set(x,y);
}




//�л�
void Widget::enemyToScene()
{
    diji_time++;

    if(diji_time<diji_jiange)
    {
        return;
    }
    diji_time=0;
    for(int i=0;i<diji_suliang;i++)
    {


        if(m_diji[i].diji_free)
        {
        m_diji[i].diji_free=false;

        m_diji[i].diji_x = rand()%(GAME_WIDTH - m_diji[i].m_Rect.width());
        m_diji[i].diji_y = -m_diji[i].m_Rect.height();
        break;
        }

    }


}







Widget::~Widget()
{
    delete ui;
}

