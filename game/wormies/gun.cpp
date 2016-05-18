#include "gun.h"

Gun::Gun(unsigned int bullets, double power, double range, double accuracy, double bullets_mass)
{
  this->bullets = bullets;
  this->power = power;
  this->range = range;
  this->accuracy = accuracy;
  this->bullets_mass = bullets_mass;
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
