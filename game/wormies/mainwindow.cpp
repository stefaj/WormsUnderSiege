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

    player = new Entity(ui->spritePlayer->x(), ui->spritePlayer->y(),580, ui->spritePlayer->width(), ui->spritePlayer->height());
    enemy= new Entity(ui->spriteEnemy->x(), ui->spriteEnemy->y(),580, ui->spriteEnemy->width(), ui->spriteEnemy->height());

    player->addVeloX(10);
}

void MainWindow::Update()
{
    player->Update();
    enemy->Update();

    ui->spriteEnemy->setGeometry((int)enemy->getX(),(int)enemy->getY(),ui->spriteEnemy->width(),ui->spriteEnemy->height());
    ui->spritePlayer->setGeometry((int)player->getX(),(int)player->getY(),ui->spritePlayer->width(),ui->spritePlayer->height());

}

void PlayerUpdate()
{
    // TODO
}

MainWindow::~MainWindow()
{
    delete ui;
}
