#include "heroplan.h"
#include "config.h"
heroplan::heroplan()
{
    HERO.load(HERO_PLAN);//ͼƬ
    //�ɻ���ʼλ��
    HERO_X=GAME_WIDTH/2-HERO.width()*0.5;
    HERO_Y=GAME_HEIGHT-HERO.height();


    //�ɻ��߿�
    m_Rect.setWidth(HERO.width());
     m_Rect.setHeight(HERO.height());
    m_Rect.moveTo(HERO_X,HERO_Y);



}


void heroplan:: set(int x ,int y)
{

    HERO_X=x;
    HERO_Y=y;


}
