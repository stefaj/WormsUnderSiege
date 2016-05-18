#ifndef GUN_H
#define GUN_H
#include <QWidget>
#include <QLabel>
class Worm;

class Gun
{
public:
    Gun(unsigned int bullets, double power, double range, double accuracy, double bullets_mass, QWidget *parent);
    ~Gun();
    unsigned int getBullets();
    double getDamage();
    double getRange();
    double getAccuracy();
    double getMass();
    bool shoot(double time, Worm *worm);
private:
    unsigned int bullets;
    double power;
    double range;
    double radius;
    double accuracy;
    double bullets_mass;
    QLabel *bullet_sprite;
};

#endif // GUN_H
