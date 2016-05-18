#include "turnmanager.h"
#include "keyboardmanager.h"
#include <QObject>

TurnManager::TurnManager(QWidget *parent) : QObject(parent)
{
    activePlayer = 0;
    activeWorm = 0;
}

void TurnManager::Draw()
{
  QPainter p((QWidget*)this->parent());

  int i = activeWorm;

    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 12, Qt::DotLine, Qt::RoundCap));
    p.drawLine(static_cast<int>(worms[i]->getX() + worms[i]->getWidth() / 2),
               static_cast<int>(worms[i]->getY() + worms[i]->getHeight() / 2),
               static_cast<int>(worms[i]->getAimX()),
               static_cast<int>(worms[i]->getAimY()));


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

