#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "keyboardmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(16);

    player = new Worm(10,20,580, 61, 70, 0, this);
    enemy= new Worm(400, 60, 580, 61, 71, 1, this);

    player->addVeloX(10);

    manager.Add(player);
    manager.Add(enemy);

    setFocusPolicy(Qt::StrongFocus);
    manager.setMouse(0, 0);
    setMouseTracking(true);
}

void MainWindow::mouseMoveEvent(QMouseEvent * e) {
    manager.setMouse(e->x(), e->y());
}


void MainWindow::paintEvent(QPaintEvent * e) {
    manager.Draw(this);
}

void MainWindow::Update()
{
    this->update();
    manager.Update(1.0 / 60.0);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    KeyboardManager::KeyPress(e);

}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    KeyboardManager::KeyRelease(e);

}

void PlayerUpdate()
{
    // TODO
}

MainWindow::~MainWindow()
{
    delete ui;
}
