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
    layer = QImage(":/ims/map01.png");


    sprite = new QLabel(parent);
    QPixmap pixmap = QPixmap::fromImage(layer);
    this->sprite->setPixmap(pixmap);
    this->sprite->setGeometry(0,0,1024,768);
}

bool Map::IsPassible(int x, int y)
{
    qDebug() << black.rgba();
    qDebug() << this->layer.pixel(x,y);
    return this->layer.pixel(x,y) != black.rgba();
}

void Map::Explode(int x, int y, double radius)
{
    for(int i = x-radius;i<x+radius; i++)
    {
        for(int j = y-radius;j<y+radius;j++)
        {
            if( (i-x)*(i-x) + (j-y)*(j-y) < radius*radius)
            {
                QColor col = QColor(0,0,0,0);
                layer.setPixel(i,j,col.rgba());
            }
        }
    }

    QPixmap pixmap = QPixmap::fromImage(layer);
    this->sprite->setPixmap(pixmap);
}

bool Map::ManageBulletCollision(QRect rect, double radius)
{

    //bottom
    for(int x = rect.left(); x < rect.right(); x++)
    {
        if(isBlack(x,rect.bottom()))
        {
            Explode(x,rect.bottom(),radius);
            return false;
        }
    }
    //top
    for(int x = rect.left(); x < rect.right(); x++)
    {
        if(isBlack(x,rect.top()))
        {
            Explode(x,rect.top(),radius);
            return false;
        }
    }\
    //left
    for(int y = rect.top(); y < rect.bottom(); y++)
    {
        if(isBlack(rect.left(),y))
        {
            Explode(rect.left(),y,radius);
            return false;
        }
    }
    //right
    for(int y = rect.top(); y < rect.bottom(); y++)
    {
        if(isBlack(rect.right(),y))
        {
            Explode(rect.right(), y,radius);
            return false;
        }
    }

    return true;
}

bool Map::IsPassible(QRect rect)
{

     //bottom
     for(int x = rect.left(); x < rect.right(); x++)
     {
         if(isBlack(x,rect.bottom()))
             return false;
     }
     //top
     for(int x = rect.left(); x < rect.right(); x++)
     {
         if(isBlack(x,rect.top()))
             return false;
     }\
     //left
     for(int y = rect.top(); y < rect.bottom(); y++)
     {
         if(isBlack(rect.left(),y))
             return false;
     }
     //right
     for(int y = rect.top(); y < rect.bottom(); y++)
     {
         if(isBlack(rect.right(),y))
             return false;
     }

     return true;
}

bool Map::ManageCollision(QRect rect, double * xvel, double * yvel, double * x, double * y, double prevX, double prevY)
{
     bool notCollide = true;


     //bottom
     for(int x = rect.left()+2; x < rect.right()-2; x+=2)
     {

         if(isBlack(x,rect.bottom()))
         {
             if(*yvel > 0)
             {
                 *yvel = -0.1;
                 *y = prevY-0.1;
             }

             notCollide = false;
         }
     }

     //left
     for(int y = rect.top()+2; y < rect.bottom()-2; y+=2)
     {

         if(isBlack(rect.left(),y))
         {
             if(*xvel < 0)
             {
                 *xvel = 0;
                 *x = prevX+0.1;
             }
             notCollide = false;
         }
     }
     //right
     for(int y = rect.top()+2; y < rect.bottom()-2; y+=2)
     {

         if(isBlack(rect.right(),y))
         {
             if(*xvel > 0)
             {
                 *xvel = 0;
                 *x = prevX-0.1;
             }
            notCollide = false;
         }
     }



     //top
     for(int x = rect.left()+2; x < rect.right()-2; x+=2)
     {

         if(isBlack(x,rect.top()))
         {
             if(*yvel < 0)
             {
                 *yvel = 0.1;
                 *y = prevY+0.1;
             }
             return false;
             notCollide = false;
         }
     }\



     return notCollide;
}

bool Map::isBlack(int x, int y)
{

     return this->layer.pixel(x,y) == black.rgba();
}
