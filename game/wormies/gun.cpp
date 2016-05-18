#include "gun.h"
#include "worm.h"
#include <QtMath>

Gun::Gun(unsigned int bullets, double power, double range, double accuracy, double bullets_mass, QWidget *parent)
{
  this->bullets = bullets;
  this->power = power;
  this->range = range;
  this->accuracy = accuracy;
  this->bullets_mass = bullets_mass;

  this->bullet_sprite = new QLabel(parent);
  this->bullet_sprite->setGeometry(50, 50, 50, 50);
  QPixmap pixmap = QPixmap(":/ims/wormjetpack.png");
  this->bullet_sprite->setPixmap(pixmap);
  this->bullet_sprite->setScaledContents(true);

}
double Gun::getDamage() {
  return this->power;
}

double Gun::getRange() {
  return this->range;
}

double Gun::getAccuracy() {
  return this->accuracy;
}

double Gun::getMass() {
  return this->bullets_mass;
}

void Gun::shoot(double time, Worm *worm) {
    double time_step = 1.0 / 2.0;
    double gravity = 9.8;
    double dx_init = worm->getX() + worm->getWidth() / 2.0;
    double dy_init = worm->getY() + worm->getHeight() / 2.0;
    double x_sq = pow(worm->getAimX() - dx_init, 2);
    double y_sq = pow(worm->getAimY() - dy_init, 2);
    double dist = pow(x_sq + y_sq, 0.5);
    double v_0 = (worm->getGun().getRange()) * dist / worm->getGun().getMass() / 25;
    double t = time;
    double x_0 = v_0 * (worm->getAimX() - dx_init) / dist;
    double x_n =  t * x_0 + dx_init;
    double y_0 = v_0 * (worm->getAimY() - dy_init) / dist;
    double y_n =  t * y_0 + 0.5 * gravity * t * t + dy_init;

    QPoint result = QPoint(static_cast<int>(x_n), static_cast<int>(y_n));


  this->bullet_sprite->setGeometry(result.x() -25, result.y() -25, 50, 50);
  this->bullet_sprite->show();
}

Gun::~Gun() {
}
