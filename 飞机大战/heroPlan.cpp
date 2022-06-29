#include "heroPlan.h"
#include<QApplication>
#include"config.h"
#include"bullet.h"
hero::hero()
{
    //1.调用背景图片
    m_hero.load(HERO);

    //2.设置坐标
      hero_x=GAME_WIDTH/2-m_hero.width()*0.5;
      hero_y= GAME_HEIGHT-m_hero.height();
      //初始化发射间隔记录
       m_recorder = 0;


       //飞机边框
       m_Rect.setWidth(m_hero.width());
       m_Rect.setHeight(m_hero.height());
       m_Rect.moveTo(hero_x,hero_y);

}

void hero::setPosition(int x,int y)
{
    hero_x=x;
    hero_y=y;
//    m_Rect.moveTo(hero_x,hero_y);

}




void hero::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }
//    到达发射时间处理
//    重置发射时间间隔记录
    m_recorder = 0;

    //发射子弹
    for(int i = 0 ; i < BULLET_NUM;i++)
    {
        //如果是空闲的子弹进行发射
        if(m_bullets[i].m_Free)
        {
            //将改子弹空闲状态改为假
            m_bullets[i].m_Free = false;
            //设置发射的子弹坐标
            m_bullets[i].bullet_x = hero_x + m_Rect.width()*0.5 - 10;
            m_bullets[i].bullet_y = hero_y - m_Rect.height()*0.5 ;
            break;
        }
    }
}



