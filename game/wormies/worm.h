#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QRect>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include "gun.h"
#include <QString>

class Worm
{
public:
    Worm(int x, int y, int width, int height, int team, QString name, QWidget *parent);
    double getX();
    double getY();
    double getAimX();
    double getAimY();
    int getWidth();
    int getHeight();
    void Update(float elapsedSeconds);
    void UpdateMain(float elapsedSeconds);
    void setAim(int x, int y);
    double addVeloX(double x);
    double addVeloY(double y);
    bool Collides(Worm *other);
    Gun getGun();
    void shoot();
    QString getName();

private:
       double x;
       double y;
       int width;
       int height;
       double veloX;
       double veloY;
       double aimX;
       double aimY;
       double dt;
       int team;
       bool facingLeft;
       int maxY;
       QString name;
       QRect boundingrect;
       QLabel *sprite;
       Gun * gun;
};

#endif // ENTITY_H
