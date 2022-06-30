#include "nemyplane.h"
#include"config.h"

EnemyPlane::EnemyPlane()
{
    //�л���Դ����
    m_enemy.load(ENEMY_PATH);

    //�л�λ��
    enemyplan_x = 0;
    enemyplan_y = 0;

    //�л�״̬
    m_Free = true;

    //�л��ٶ�
    m_Speed = ENEMY_SPEED;

    //�л�����
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(enemyplan_x,enemyplan_y);
}








void EnemyPlane::updatePosition()
{
    //����״̬������������
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


