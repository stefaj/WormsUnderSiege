#include "worm.h"

Worm::Worm(int x, int y, int maxY, int width, int height, int team, QWidget *parent)
{
    this->x = x;
    this->y = y;
    this->maxY = maxY;
    this->veloX = 0;
    this->veloY = 0;
    this->width = width;
    this->team = team;
    this->height = height;

    this->sprite = new QLabel(parent);
}

bool Worm::Collides(Worm *other)
{
    return this->boundingrect.intersects(other->boundingrect);
}

void Worm::Update()
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

    // Draw

    this->sprite->setGeometry(x,y,this->sprite->width(),this->sprite->height());
}

double Worm::addVeloX(double x)
{
    this->veloX += x;
}

double Worm::addVeloY(double y)
{
    this->veloY += y;
}


double Worm::getX()
{
    return this->x;
}


double Worm::getY()
{
    return this->y;
}


