#ifndef WORMMANAGER_H
#define WORMMANAGER_H

#include <QList>
#include <QWidget>
#include "worm.h"
#include <QKeyEvent>
#include <QDebug>
#include <QKeyEvent>
#include <QPicture>
#include <QPainter>
#include <QObject>

class TurnManager : public QObject
{
    Q_OBJECT

public:
    TurnManager(QWidget *parent);
    void Draw();
    void Update(float elapsedSeconds);
    void Add(Worm *worm);

    void setMouse(int x, int y);

signals:
    void WormChange(Worm *worm);
    void PlayerChange(int playerId);

private:
    QList<Worm*> worms;
    int activePlayer;
    int activeWorm;

    float roundTimer;
    int rounds;
    const float STARTROUNDTIME = 40;

    int mouse_x;
    int mouse_y;

};

#endif // WORMMANAGER_H
