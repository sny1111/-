#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>


class Bullet
{
public:
    Bullet();

    //�����ӵ�����
    void updatePosition();

public:

    //�ӵ���Դ����
    QPixmap m_Bullet;
    //�ӵ�����
    int bullet_x;
    int bullet_y;
    //�ӵ��ƶ��ٶ�
    int m_Speed;
    //�ӵ��Ƿ�����
    bool m_Free;
    //�ӵ��ľ��α߿�������ײ��⣩
    QRect m_Rect;
};

#endif // BULLET_H

