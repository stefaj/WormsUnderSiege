#include "map.h"
#include <QRgb>


namespace MapSingleton
{
    Map *map;
    void Initialize(QWidget *parent)
    {
        map = new Map(parent);
    }
}


Map::Map(QWidget *parent)
{
    layer = QImage(":/ims/map01.bmp");


    sprite = new QLabel(parent);
    QPixmap pixmap = QPixmap::fromImage(layer);
    this->sprite->setPixmap(pixmap);
    this->sprite->setGeometry(0,0,1024,768);
}

bool Map::IsPassible(int x, int y)
{
    return this->layer.pixel(x,y) != 0;
}

