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
 //��ը����
     Bomb m_bombs[BOMB_NUM];
\
 void mouseMoveEvent(QMouseEvent* event);
 //�л�����
     void enemyToScene();

     //�л�����
     EnemyPlane m_enemys[ENEMY_NUM];

     //�л����������¼
     int m_recorder;

private:
    Ui::Widget *ui;
    int map1_x,map1_y;
    void paintEvent(QPaintEvent *event);
    void timerout();

//��ײ
    void collisionDetection();



};

#endif // WIDGET_H
