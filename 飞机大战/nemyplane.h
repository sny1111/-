#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include<QVector>
//#include"dijibullet.h"
#include"config.h"


class EnemyPlane
{
public:
    EnemyPlane();

    //��������
    void updatePosition();

public:
    //�л���Դ����
        QPixmap m_enemy;
    //     QVector<QPixmap> m_enemy;

    //λ��
    int enemyplan_x;
    int enemyplan_y;

    //�л��ľ��α߿���ײ��⣩
    QRect m_Rect;

    //״̬
    bool m_Free;

    //�ٶ�
    int m_Speed;
    int m_index;
//    void shot();
//    //�ӵ�ʱ����
//    int m;
//    dijibullet m_diji[DIJI_NUM];
};

#endif // ENEMYPLANE_H
