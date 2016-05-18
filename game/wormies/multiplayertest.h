#ifndef MULTIPLAYERTEST_H
#define MULTIPLAYERTEST_H

#include <QMainWindow>
#include <connection.h>
#include <QTcpServer>
#include <QTcpSocket>

#include <QTimer>
#include <turnmanager.h>
#include <worm.h>
#include <QKeyEvent>
#include <QDebug>
#include <QMap>
#include "map.h"


namespace Ui {
class MultiplayerTest;
}

class MultiplayerTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiplayerTest(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    ~MultiplayerTest();

private slots:
    void on_pushButton_clicked();
    void onClientConnect();
    void onConnected();
    void on_pushButton_2_clicked();
    void Update();
    void OnWormChange(Worm *worm);
    void OnPlayerChange(int playerId);

private:
    Ui::MultiplayerTest *ui;
    QTcpServer *server;
    Connection *peerConnection;
    QTcpSocket *peerSocket;
    QTimer *timer;
    TurnManager *manager;

    bool isServer = false;
    bool isInit;

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // MULTIPLAYERTEST_H
