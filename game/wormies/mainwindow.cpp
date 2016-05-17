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

    player = new Worm(ui->spritePlayer->x(), ui->spritePlayer->y(),580, ui->spritePlayer->width(), ui->spritePlayer->height(), 0, this);
    enemy= new Worm(ui->spriteEnemy->x(), ui->spriteEnemy->y(),580, ui->spriteEnemy->width(), ui->spriteEnemy->height(), 1, this);

    player->addVeloX(10);

    manager.Add(player);
    manager.Add(enemy);
}

void MainWindow::Update()
{
    manager.Update(1.0/16.0);
    manager.Draw();
}

void PlayerUpdate()
{
    // TODO
}

MainWindow::~MainWindow()
{
    delete ui;
}
