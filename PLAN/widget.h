#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"map.h"
#include"heroPlan.h"
#include"bullet.h"
#include"nemyplane.h"
#include"bomb.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
 map m_map;
 hero m_hero;
 //爆炸数组
     Bomb m_bombs[BOMB_NUM];
\
 void mouseMoveEvent(QMouseEvent* event);
 //敌机出场
     void enemyToScene();

     //敌机数组
     EnemyPlane m_enemys[ENEMY_NUM];

     //敌机出场间隔记录
     int m_recorder;

private:
    Ui::Widget *ui;
    int map1_x,map1_y;
    void paintEvent(QPaintEvent *event);
    void timerout();

//碰撞
    void collisionDetection();



};

#endif // WIDGET_H
