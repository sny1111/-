
#ifndef MAP_H
#define MAP_H

#include <QPixmap>


class map
{
public:
    map();

public:
    QPixmap m_map1;
    QPixmap m_map2;
    int map1_y;
    int map2_y;
    void mapPosition();
};

#endif // MAP_H

