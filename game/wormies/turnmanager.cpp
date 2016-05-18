#include "turnmanager.h"
#include "keyboardmanager.h"
#include <QtMath>
#include <QObject>

TurnManager::TurnManager(QWidget *parent) : QObject(parent)
{
    activePlayer = 0;
    activeWorm = 0;
}
QVector<QPoint> TurnManager::calcBulletDest(int steps) {
  int i = activeWorm;
  double time_step = 1.0 / 2.0;
  double gravity = 9.8;
  double dx_init = worms[i]->getX() + worms[i]->getWidth() / 2.0;
  double dy_init = worms[i]->getY() + worms[i]->getHeight() / 2.0;
  double x_sq = pow(worms[i]->getAimX() - dx_init, 2);
  double y_sq = pow(worms[i]->getAimY() - dy_init, 2);
  double dist = pow(x_sq + y_sq, 0.5);
  double v_0 = (worms[i]->getGun().getRange()) * dist / worms[i]->getGun().getMass() / 25;
  QVector<QPoint> current;
  for (int z = 0; z < steps; z++) {
      double t = z * time_step;

      double x_0 = v_0 * (worms[i]->getAimX() - dx_init) / dist;
      double x_n =  t * x_0 + dx_init;
      double y_0 = v_0 * (worms[i]->getAimY() - dy_init) / dist;
      double y_n =  t * y_0 + 0.5 * gravity * t * t + dy_init;
      current.push_back(QPoint(static_cast<int>(x_n), static_cast<int>(y_n)));
  }
  return current;
}

void TurnManager::Draw()
{
  QPainter p((QWidget*)this->parent());

  int i = activeWorm;
   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 12, Qt::DotLine, Qt::RoundCap));
   QVector<QPoint> bullets = calcBulletDest(500);
   for (int g = 0; g < bullets.count(); g++)
   p.drawPoint(bullets.value(g));
   p.end();

}

void TurnManager::setMouse(int x, int y) {
    this->mouse_x = x;
    this->mouse_y = y;
}

void TurnManager::Update(float elapsedSeconds)
{
    for(int i = 0; i < worms.count(); i++) {
        worms[i]->setAim(this->mouse_x, this->mouse_y);
        worms[i]->Update();
    }

    roundTimer -= elapsedSeconds;

    if(roundTimer < 0)
    {
        rounds++;
        roundTimer = STARTROUNDTIME;

        qDebug() << "Old active " << activeWorm;

        activeWorm++;
        if (activeWorm >= worms.count())
            activeWorm = 0;
        qDebug() << "New active " << activeWorm;
        qDebug() << "count " << worms.count();

        activePlayer = 1 - activePlayer;

        emit PlayerChange(activePlayer);
        emit WormChange(worms[activeWorm]);

    }

    //qDebug() << "Key left down " <<  KeyboardManager::IsKeyDown(Qt::Key_Left);
   // qDebug() << "Key up down " << KeyboardManager::keys[Qt::Key_Up];

    if( KeyboardManager::IsKeyDown(Qt::Key_Left))
    {
        qDebug() << "Left";
        worms[activeWorm]->addVeloX(-1);
    }
    if( KeyboardManager::IsKeyDown(Qt::Key_Right))
    {
        qDebug() << "Right";
        worms[activeWorm]->addVeloX(1);
    }
    if( KeyboardManager::IsKeyDown(Qt::Key_Up))
    {
        worms[activeWorm]->addVeloY(-2);
    }
    if( KeyboardManager::IsKeyDown(Qt::Key_Down))
    {
        worms[activeWorm]->addVeloY(1);
    }

    // handle input of active worm
}


void TurnManager::Add(Worm *worm)
{
    this->worms.push_back(worm);
}

