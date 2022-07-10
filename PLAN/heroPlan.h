#ifndef HEROPLAN_H
#define HEROPLAN_H


#include"bullet.h"

#include <QPixmap>

#include<QMoveEvent>

class hero
{
public:
    hero();

    int hero_x;
    int hero_y;

    QPixmap m_hero;

    QRect m_Rect;
    //µ¯Ï»


    Bullet m_bullets[BULLET_NUM];

    //·¢Éä¼ä¸ô¼ÇÂ¼
    int m_recorder;


    void shoot();
    void mouseMoveEvent(QMouseEvent *event);




void setPosition(int ,int);

};

#endif // HEROPLAN_H
