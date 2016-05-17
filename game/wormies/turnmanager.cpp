#include "turnmanager.h"

TurnManager::TurnManager()
{

}

void TurnManager::Draw()
{

}

void TurnManager::Update(float elapsedSeconds)
{
    for(int i = 0; i < worms.size(); i++)
        worms[i]->Update();

    roundTimer -= elapsedSeconds;

    if(roundTimer < 0)
    {
        rounds++;
        roundTimer = STARTROUNDTIME;
        activeWorm++ % worms.size();

    }
    // handle input of active worm
}


void TurnManager::Add(Worm *worm)
{
    this->worms.push_back(worm);
}
