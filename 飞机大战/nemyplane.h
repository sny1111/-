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

    //更新坐标
    void updatePosition();

public:
    //敌机资源对象
        QPixmap m_enemy;
    //     QVector<QPixmap> m_enemy;

    //位置
    int enemyplan_x;
    int enemyplan_y;

    //敌机的矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;
    int m_index;
//    void shot();
//    //子弹时间间隔
//    int m;
//    dijibullet m_diji[DIJI_NUM];
};

#endif // ENEMYPLANE_H
