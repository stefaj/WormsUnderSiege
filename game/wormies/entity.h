#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QRect>

class Entity
{
public:
    Entity(int x, int y, int maxY, int width, int height);
    double getX();
    double getY();
    void Update();
    double addVeloX(double x);
    double addVeloY(double y);
    bool Collides(Entity *other);

private:
       double x;
       double y;
       int width;
       int height;
       double veloX;
       double veloY;
       bool facingLeft;
       int maxY;
       QRect boundingrect;
};

#endif // ENTITY_H
