#ifndef GUN_H
#define GUN_H


class Gun
{
public:
    Gun(unsigned int bullets, double power, double range, double accuracy, double bullets_mass);
    unsigned int getBullets();
    double getDamage();
    double getRange();
    double getAccuracy();
    double getMass();
private:
    unsigned int bullets;
    double power;
    double range;
    double accuracy;
    double bullets_mass;
};

#endif // GUN_H
