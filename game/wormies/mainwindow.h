#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <turnmanager.h>
#include <worm.h>
#include <QKeyEvent>
#include <QDebug>
#include <QMap>
#include "map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    TurnManager *manager;

private slots:
    void Update();
    void OnWormChange(Worm *worm);
    void OnPlayerChange(int playerId);

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
