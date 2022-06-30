#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM--dd hh:mm:ss:zzz")

#define GAME_WIDTH 812//宽
#define GAME_HEIGHT 768//高
#define GAME_TITLE "Plane Fight v1.0"//名


#define GAME_RES_PATH "./plane.rcc" //rcc路线
#define GAME_ICON ":/res/app.ico"//图标


#define MAP_PATH ":/res/img_bg_level_1.jpg"//背景
#define HERO ":/res/hero2.png"
#define MAP_PAT ":/res/img_bg_level_2.jpg"//背景


/**********  子弹配置数据 **********/
#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 5 //子弹移动速度

#define BULLET_NUM 40  //弹匣中子弹总数
#define BULLET_INTERVAL 15 //发射子弹时间间隔

/************敌机子弹*********/
//#define DIJI_PATH "/res/bullet_4.png"
//#define DIJI_SPEED 5
//#define DIJI_NUM 40
//#define DIJI_INTERVAL 20


/**********  敌机配置数据 **********/
#define ENEMY_PATH  ":/res/img-plane_6.png"  //敌机资源图片
#define ENEMY_SPEED 5  //敌机移动速度
#define ENEMY_NUM   20  //敌机总数量
#define ENEMY_INTERVAL  30  //敌机出场时间间隔
//#define ENEMY_MAx  6 //敌机图片




#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  6      //爆炸图片最大索引
#define BOMB_INTERVAL 20  //爆炸切图时间间隔


#endif // CONFIG_H
