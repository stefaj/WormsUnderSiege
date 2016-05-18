#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QImage>
#include <QWidget>


class Map
{
public:
    Map(QWidget *parent);

    bool IsPassible(int x, int y);
private:
    QLabel *sprite;
    QImage layer;

};

namespace MapSingleton
{
    extern Map *map;
    void Initialize(QWidget *parent);
}


#endif // MAP_H
