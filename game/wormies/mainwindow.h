#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <turnmanager.h>
#include <worm.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Worm *player;
    Worm *enemy;
    TurnManager manager;

private slots:
    void Update();
};

#endif // MAINWINDOW_H
