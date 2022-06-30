#include "nemyplane.h"
#include"config.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    enemyplan_x = 0;
    enemyplan_y = 0;

    //敌机状态
    m_Free = true;

    //敌机速度
    m_Speed = ENEMY_SPEED;

    //敌机矩形
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(enemyplan_x,enemyplan_y);
}








void EnemyPlane::updatePosition()
{
    //空闲状态，不计算坐标
    if(m_Free)
    {
        return;
    }

    enemyplan_y += m_Speed;


    m_Rect.moveTo(enemyplan_x,enemyplan_y);

    if(enemyplan_y >= GAME_HEIGHT + m_Rect.height())
    {
        m_Free = true;
    }
}




//void EnemyPlane::shot()
//{
//     m++;
//     if(m<=DIJI_INTERVAL)
//     {

//         return;
//     }
//     m=0;
//     for(int i=0;i<DIJI_NUM;i++)
//         if(m_diji[i].panduan==1)
//         {

//             m_diji[i].panduan=0;


//             m_diji[i].dijibullet_x=enemyplan_x+m_Rect.width()*0.5-10;
//             m_diji[i].dijibullet_y=enemyplan_y+m_Rect.height()*0.5 ;
//         }


//}


