#ifndef WORMMANAGER_H
#define WORMMANAGER_H

#include <QList>
#include "worm.h"
#include <QKeyEvent>
#include <QDebug>
#include <QKeyEvent>

class TurnManager
{
public:
    TurnManager();
    void Draw();
    void Update(float elapsedSeconds);
    void Add(Worm *worm);

    void keyPressed(QKeyEvent *e);
    void keyRelease(QKeyEvent *e);

private:
    QList<Worm*> worms;
    int activePlayer;
    int activeWorm;

    float roundTimer;
    int rounds;
    const float STARTROUNDTIME = 40;

};

#endif // WORMMANAGER_H
