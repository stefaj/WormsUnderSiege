#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QRect>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include "gun.h"

class Worm
{
public:
    Worm(int x, int y, int maxY, int width, int height, int team, QWidget *parent);
    double getX();
    double getY();
    double getAimX();
    double getAimY();
    int getWidth();
    int getHeight();
    void Update();
    void setAim(int x, int y);
    double addVeloX(double x);
    double addVeloY(double y);
    bool Collides(Worm *other);
    Gun getGun();

private:
       double x;
       double y;
       int width;
       int height;
       double veloX;
       double veloY;
       double aimX;
       double aimY;
       int team;
       bool facingLeft;
       int maxY;
       QRect boundingrect;
       QLabel *sprite;
};

#endif // ENTITY_H
