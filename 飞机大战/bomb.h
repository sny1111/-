#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QPixmap>
#include <QVector>

class Bomb
{
public:
    Bomb();

    //������Ϣ������ͼƬ�±ꡢ���ż����
    void updateInfo();

public:

    //�ű�ը��Դ����
    QVector <QPixmap> m_pixArr;

//    QPixmap m_pixArr;
    //��ըλ��
    int m_X;
    int m_Y;

    //��ը״̬
    bool m_Free;

    //��ը��ͼ��ʱ����
    int m_Recoder;

    //��ըʱ���ص�ͼƬ�±�
    int m_index;
};

#endif // BOMB_H
