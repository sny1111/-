#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM--dd hh:mm:ss:zzz")

#define GAME_WIDTH 812//��
#define GAME_HEIGHT 768//��
#define GAME_TITLE "Plane Fight v1.0"//��


#define GAME_RES_PATH "./plane.rcc" //rcc·��
#define GAME_ICON ":/res/app.ico"//ͼ��


#define MAP_PATH ":/res/img_bg_level_1.jpg"//����
#define HERO ":/res/hero2.png"
#define MAP_PAT ":/res/img_bg_level_2.jpg"//����


/**********  �ӵ��������� **********/
#define BULLET_PATH ":/res/bullet_11.png"   //�ӵ�ͼƬ·��
#define BULLET_SPEED 5 //�ӵ��ƶ��ٶ�

#define BULLET_NUM 40  //��ϻ���ӵ�����
#define BULLET_INTERVAL 15 //�����ӵ�ʱ����

/************�л��ӵ�*********/
//#define DIJI_PATH "/res/bullet_4.png"
//#define DIJI_SPEED 5
//#define DIJI_NUM 40
//#define DIJI_INTERVAL 20


/**********  �л��������� **********/
#define ENEMY_PATH  ":/res/img-plane_6.png"  //�л���ԴͼƬ
#define ENEMY_SPEED 5  //�л��ƶ��ٶ�
#define ENEMY_NUM   20  //�л�������
#define ENEMY_INTERVAL  30  //�л�����ʱ����
//#define ENEMY_MAx  6 //�л�ͼƬ




#define BOMB_PATH  ":/res/bomb-%1.png"   //��ը��ԴͼƬ
#define BOMB_NUM  20     //��ը����
#define BOMB_MAX  6      //��ըͼƬ�������
#define BOMB_INTERVAL 20  //��ը��ͼʱ����


#endif // CONFIG_H
