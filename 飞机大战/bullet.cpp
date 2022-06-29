#include "bullet.h"

Bullet::Bullet()
{
    //�����ӵ���Դ
    m_Bullet.load(BULLET_PATH);

    //�ӵ����� ��ʼ������������ã����ڻ�����
    bullet_x = GAME_WIDTH*0.5 - m_Bullet.width()*0.5;
    bullet_y = GAME_HEIGHT;



//    �ӵ��ٶ�
    m_Speed = BULLET_SPEED;

    //�ӵ��߿�

        m_Rect.setWidth(m_Bullet.width());
        m_Rect.setHeight(m_Bullet.height());
        m_Rect.moveTo(bullet_x,bullet_y);



}




void Bullet::updatePosition()
{
    //����ӵ��ǿ���״̬������Ҫ�������
    //��ҷɻ����Կ����ӵ��Ŀ���״̬Ϊfalse
    if(m_Free)
    {
        return;
    }

//    //�ӵ������ƶ�
    bullet_y  -= m_Speed;

    m_Rect.moveTo(bullet_x,bullet_y);

    if(bullet_y <= -m_Rect.height())
    {
        m_Free = true;
    }
}
