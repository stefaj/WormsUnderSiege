#include "turnmanager.h"
#include "keyboardmanager.h"

TurnManager::TurnManager()
{

}

void TurnManager::Draw()
{

}

void TurnManager::Update(float elapsedSeconds)
{
    for(int i = 0; i < worms.count(); i++)
        worms[i]->Update();

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

