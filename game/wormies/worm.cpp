#include "worm.h"
#include "map.h"

Worm::Worm(int x, int y, int width, int height, int team, QString name, QWidget *parent)
{
    this->x = x;
    this->y = y;
    this->veloX = 0;
    this->veloY = 0;
    this->dt = 0.0;
    this->width = width;
    this->team = team;
    this->height = height;
    this->gun = new Gun(10, 1, 3, 1.0, 0.5, parent);
    this->sprite = new QLabel(parent);
    this->sprite->setGeometry(x,y,width,height);
    QPixmap pixmap = QPixmap(":/ims/wormjetpack.png");
    if(team == 1)
        pixmap = QPixmap(":/ims/wormjetpackorange.png");

    this->sprite->setPixmap(pixmap);
    this->sprite->setScaledContents(true);

    this->name = name;
}
double Worm::getAimX() {
  return this->aimX;
}

double Worm::getAimY() {
  return this->aimY;
}

void Worm::shoot() {
  dt = 0;
}

Gun Worm::getGun() {
    return *gun;
}

bool Worm::Collides(Worm *other)
{
    return this->boundingrect.intersects(other->boundingrect);
}

void Worm::setAim(int x, int y) {
  this->aimX = static_cast<double>(x);
  this->aimY = static_cast<double>(y);
}

void Worm::Update()
{
    dt += 1.0 / 5.0;
    if(gun->shoot(dt, this))
    {
        dt = 0;
    }

    double xp = this->x; double yp = this->y;

    xp += this->veloX;
    yp += this->veloY;

    this->veloX *= 0.95;
    this->veloY *= 0.95;
    this->veloY += 0.4;

    boundingrect = QRect((int)xp,(int)yp,width,height);


    if(MapSingleton::map->ManageCollision(boundingrect,&veloX,&veloY,&xp,&yp,this->x,this->y))
    {

    }

    this->x = xp;
    this->y = yp;

//     if(MapSingleton::map->IsPassible(boundingrect))
//     {
//         this->x = xp;
//         this->y = yp;
//     }
//     else
//     {
//        //this->veloX = 0;
//        //this->veloY = 0;
//    }



    this->sprite->setGeometry(x, y, this->sprite->width(),this->sprite->height());


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

int Worm::getWidth()
{
    return width;
}

int Worm::getHeight()
{
    return height;
}

QString Worm::getName()
{
    return name;
}

