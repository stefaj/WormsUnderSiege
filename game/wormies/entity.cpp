#include "entity.h"

Entity::Entity(int x, int y, int maxY, int width, int height)
{
    this->x = x;
    this->y = y;
    this->maxY = maxY;
    this->veloX = 0;
    this->veloY = 0;
    this->width = width;
    this->height = height;
}

bool Entity::Collides(Entity *other)
{
    return this->boundingrect.intersects(other->boundingrect);
}

void Entity::Update()
{
    this->x += this->veloX;
    this->y += this->veloY;

    this->veloX *= 0.95;
    this->veloY *= 0.95;
    this->veloY += 0.4;

    if(this->y > maxY)
    {
        this->y = maxY;
        this->veloY = 0;
    }

    boundingrect = QRect((int)x,(int)y,width,height);
}

double Entity::addVeloX(double x)
{
    this->veloX += x;
}

double Entity::addVeloY(double y)
{
    this->veloY += y;
}


double Entity::getX()
{
    return this->x;
}


double Entity::getY()
{
    return this->y;
}


