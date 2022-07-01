#include "map.h"
#include "config.h"
#include "qwidget.h"

MAP::MAP()
{
    m_map.load(GAME_MAP);
    MAP_X=0;
    MAP_Y1=0;
    MAP_Y2=-GAME_HEIGHT+1;



}


void MAP::MAP_JISUAN()
{
    MAP_Y1+=1;
    MAP_Y2+=1;
    if(MAP_Y1>GAME_HEIGHT)
      MAP_Y1=0;
    if(MAP_Y2>0)
        MAP_Y2=-GAME_HEIGHT+1;



}
