#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM--dd hh:mm:ss:zzz")

#define GAME_WIDTH 512//宽
#define GAME_HEIGHT 768//高
#define GAME_NAME "Plane Fight v1.0"//APP名
#define GAME_APP ":/plan/app.ico"//APP图标

#define GAME_MAP ":/plan/img_bg_level_2.jpg"//地图

///////////////////////////////////////

#define GAME_RES_PATH "./plane.rcc" //rcc路线

///////////////////////////////////

#define HERO_PLAN ":/plan/hero2.png"//主飞机图标

////////////////////////////////////

#define diji_plan ":/plan/img-plane_6.png"//敌机
#define diji_sudu 5 //敌机移动速度
#define diji_jiange 20  //出现间隔
#define  diji_suliang 30//敌机数量







#endif // CONFIG_H
