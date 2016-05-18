#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "keyboardmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // This first, low z order for bg
    MapSingleton::Initialize(this);

    manager = new TurnManager(this);
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(16);

    Worm *a1 = new Worm(10,20, 61, 70, 0, "John", this); manager->Add(a1);
    Worm *a2 = new Worm(110,20, 61, 70, 0, "Sansa", this); manager->Add(a2);
   // Worm *b1 = new Worm(400, 60, 620, 61, 71, 1, "Ned", this); manager->Add(b1);
  //  Worm *b2 = new Worm(500, 60, 620, 61, 71, 1, "Rob", this); manager->Add(b2);

    setFocusPolicy(Qt::StrongFocus);
    manager->setMouse(0, 0);
    setMouseTracking(true);

    connect(manager,SIGNAL(WormChange(Worm*)),this,SLOT(OnWormChange(Worm*)));
    connect(manager,SIGNAL(PlayerChange(int)),this,SLOT(OnPlayerChange(int)));

}

void MainWindow::mouseMoveEvent(QMouseEvent * e) {
    manager->setMouse(e->x(), e->y());
}


void MainWindow::paintEvent(QPaintEvent * e) {
    manager->Draw();
}

void MainWindow::Update()
{
    this->update();
    manager->Update(1.0 / 60.0);
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

 void MainWindow::OnWormChange(Worm *worm)
 {
    this->ui->lblWorm->setText(worm->getName());
 }


 void MainWindow::OnPlayerChange(int playerId)
 {
     this->ui->lblPlayer->setText(QString::number(playerId));
 }
