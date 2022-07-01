#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include<QIcon>
#include <QTimer>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

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

//�ػ�
repaint();

}





void Widget::paintEvent(QPaintEvent *event)

{
    QPainter painter(this);
   //���ñ���
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y1,this->width(),this->height(),m_map.m_map);
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y2,this->width(),this->height(),m_map.m_map);
}














Widget::~Widget()
{
    delete ui;
}

