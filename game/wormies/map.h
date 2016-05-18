#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QImage>
#include <QWidget>
#include <QRect>
#include <QColor>

class Map
{
public:
    Map(QWidget *parent);

    bool IsPassible(int x, int y);
    bool IsPassible(QRect rect);

    bool ManageBulletCollision(QRect rect, double radius);

    bool ManageCollision(QRect rect, double * xvel, double * yvel, double * x, double * y, double prevX, double prevY);
private:
    QLabel *sprite;
    QImage layer;
    bool isBlack(int x, int y);
    QColor black = QColor(0,0,0);
    void Explode(int x, int y, double radius);
};

namespace MapSingleton
{
    extern Map *map;
    void Initialize(QWidget *parent);
}


#endif // MAP_H
