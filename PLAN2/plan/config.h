#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM--dd hh:mm:ss:zzz")

#define GAME_WIDTH 512//��
#define GAME_HEIGHT 768//��
#define GAME_NAME "Plane Fight v1.0"//APP��
#define GAME_APP ":/plan/app.ico"//APPͼ��

#define GAME_MAP ":/plan/img_bg_level_2.jpg"//��ͼ

#define GAME_RES_PATH "./plane.rcc" //rcc·��


#endif // CONFIG_H
