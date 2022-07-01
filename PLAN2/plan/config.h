#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM--dd hh:mm:ss:zzz")

#define GAME_WIDTH 512//宽
#define GAME_HEIGHT 768//高
#define GAME_NAME "Plane Fight v1.0"//APP名
#define GAME_APP ":/plan/app.ico"//APP图标

#define GAME_MAP ":/plan/img_bg_level_2.jpg"//地图

#define GAME_RES_PATH "./plane.rcc" //rcc路线


#endif // CONFIG_H
