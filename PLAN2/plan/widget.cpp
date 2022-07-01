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

    //时间槽函数
    QTimer *timer=new QTimer(this);

    connect(timer,&QTimer::timeout,this,&Widget::timeout);

    timer->start(10);




    //大小
        setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //名
        setWindowTitle(GAME_NAME);

     //设置图标资源
        setWindowIcon(QIcon(GAME_APP));





}


void Widget::timeout()
{

m_map.MAP_JISUAN();

//重绘
repaint();

}





void Widget::paintEvent(QPaintEvent *event)

{
    QPainter painter(this);
   //设置背景
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y1,this->width(),this->height(),m_map.m_map);
    painter.drawPixmap(m_map.MAP_X,m_map.MAP_Y2,this->width(),this->height(),m_map.m_map);
}














Widget::~Widget()
{
    delete ui;
}

