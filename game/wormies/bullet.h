#ifndef BULLET_H
#define BULLET_H
#include <QLabel>

class Bullet : public QLabel
{
public:
    Bullet();
    void setPosition(double x, double y);
private:
    double positionx;
    double positiony;

};

#endif // BULLET_H
