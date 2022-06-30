#include "map.h"
#include"config.h"
#include<QDebug>


map::map()
{
//1.调用背景图片
m_map1.load(MAP_PATH);
m_map2.load(MAP_PAT);
//2.设置地图坐标
   map1_y=0;
   map2_y=-GAME_HEIGHT+1;
}




void map::mapPosition()
{
    map1_y+=1;
    if(map1_y>768)
        map1_y=0;
    map2_y+=1;
    if(map2_y>0)
       map2_y=-GAME_HEIGHT+1;

}
