#ifndef DIJI_H
#define DIJI_H
#include"config.h"
#include <QPixmap>
class diji
{
public:
    diji();
    QPixmap dijiplan;
    QRect m_Rect;
    int diji_x;
    int diji_y;


    bool diji_free;//±êÖ¾Î»

    int diji_s;


    void updatePosition();



};

#endif // DIJI_H
