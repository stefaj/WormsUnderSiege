#include "map.h"
#include <QRgb>
#include <QDebug>
#include <QColor>

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
    QColor black(0,0,0);
    qDebug() << black.rgba();
    qDebug() << this->layer.pixel(x,y);
    return this->layer.pixel(x,y) != black.rgba();
}

 bool Map::IsPassible(QRect rect)
 {

     for(int i = rect.left(); i < rect.right(); i++)
     {
     //    if(layer.pixel(i,rect.bottom()))
     }

     return false;
 }
