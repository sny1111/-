#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标 初始坐标可随意设置，后期会重置
    bullet_x = GAME_WIDTH*0.5 - m_Bullet.width()*0.5;
    bullet_y = GAME_HEIGHT;



//    子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框

        m_Rect.setWidth(m_Bullet.width());
        m_Rect.setHeight(m_Bullet.height());
        m_Rect.moveTo(bullet_x,bullet_y);



}




void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要坐标计算
    //玩家飞机可以控制子弹的空闲状态为false
    if(m_Free)
    {
        return;
    }

//    //子弹向上移动
    bullet_y  -= m_Speed;

    m_Rect.moveTo(bullet_x,bullet_y);

    if(bullet_y <= -m_Rect.height())
    {
        m_Free = true;
    }
}
