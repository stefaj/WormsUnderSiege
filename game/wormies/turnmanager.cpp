#include "turnmanager.h"

TurnManager::TurnManager()
{

}

void TurnManager::Draw(QWidget * parent)
{
  QPainter p(parent);
  for(int i = 0; i < worms.count(); i++) {

    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 12, Qt::DotLine, Qt::RoundCap));
    p.drawLine(static_cast<int>(worms[i]->getX()),
               static_cast<int>(worms[i]->getY()),
               static_cast<int>(worms[i]->getAimX()),
               static_cast<int>(worms[i]->getAimY()));

  }
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

    }

    // handle input of active worm
}


void TurnManager::Add(Worm *worm)
{
    this->worms.push_back(worm);
}

void TurnManager::keyPressed(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)
    {
        qDebug() << "Left";
        worms[activeWorm]->addVeloX(-1);
    }
    if(e->key() == Qt::Key_Right)
    {
        qDebug() << "Right";
        worms[activeWorm]->addVeloX(1);
    }
    if(e->key() == Qt::Key_Up)
    {
        worms[activeWorm]->addVeloY(-2);
    }
    if(e->key() == Qt::Key_Down)
    {
        worms[activeWorm]->addVeloY(1);
    }
}

void TurnManager::keyRelease(QKeyEvent *e)
{

}
