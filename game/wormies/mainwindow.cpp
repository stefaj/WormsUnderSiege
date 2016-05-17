#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(16);

    player = new Worm(10,20,580, 61, 70, 0, this);
    enemy= new Worm(400, 60,580, 61, 71, 1, this);

    player->addVeloX(10);

    manager.Add(player);
    manager.Add(enemy);
}

void MainWindow::Update()
{
    manager.Update(1.0/16.0);
    manager.Draw();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    manager.keyPressed(e);
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{

    manager.keyRelease(e);
}

void PlayerUpdate()
{
    // TODO
}

MainWindow::~MainWindow()
{
    delete ui;
}
