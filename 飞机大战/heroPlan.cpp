#include "heroPlan.h"
#include<QApplication>
#include"config.h"
#include"bullet.h"
hero::hero()
{
    //1.���ñ���ͼƬ
    m_hero.load(HERO);

    //2.��������
      hero_x=GAME_WIDTH/2-m_hero.width()*0.5;
      hero_y= GAME_HEIGHT-m_hero.height();
      //��ʼ����������¼
       m_recorder = 0;


       //�ɻ��߿�
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
    //�ۼ�ʱ������¼����
    m_recorder++;
    //�ж������¼���� δ�ﵽ��������ֱ��return
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }
//    ���﷢��ʱ�䴦��
//    ���÷���ʱ������¼
    m_recorder = 0;

    //�����ӵ�
    for(int i = 0 ; i < BULLET_NUM;i++)
    {
        //����ǿ��е��ӵ����з���
        if(m_bullets[i].m_Free)
        {
            //�����ӵ�����״̬��Ϊ��
            m_bullets[i].m_Free = false;
            //���÷�����ӵ�����
            m_bullets[i].bullet_x = hero_x + m_Rect.width()*0.5 - 10;
            m_bullets[i].bullet_y = hero_y - m_Rect.height()*0.5 ;
            break;
        }
    }
}



