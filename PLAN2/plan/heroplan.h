#ifndef HEROPLAN_H
#define HEROPLAN_H
#include <QPixmap>

class heroplan
{
public:
    heroplan();
    //定义成员名
    QPixmap HERO;

    QRect m_Rect;

    int HERO_X;
    int HERO_Y;





    void  set(int x ,int y);









};

#endif // HEROPLAN_H
