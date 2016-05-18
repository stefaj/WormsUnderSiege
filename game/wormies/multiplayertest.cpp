#include "multiplayertest.h"
#include "ui_multiplayertest.h"
#include <QDebug>
#include "keyboardmanager.h"

MultiplayerTest::MultiplayerTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiplayerTest)
{
    MapSingleton::Initialize(this);
    ui->setupUi(this);
    isInit = false;



    manager = new TurnManager(this);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(16);

    Worm *a1 = new Worm(10,80, 61, 70, 0, "John", this); manager->Add(a1);
    Worm *a2 = new Worm(110,80, 61, 70, 0, "Sansa", this); manager->Add(a2);
    Worm *b1 = new Worm(400, 100, 61, 71, 1, "Ned", this); manager->Add(b1);
    Worm *b2 = new Worm(500, 100, 61, 71, 1, "Rob", this); manager->Add(b2);

    connect(manager,SIGNAL(WormChange(Worm*)),this,SLOT(OnWormChange(Worm*)));
    connect(manager,SIGNAL(PlayerChange(int)),this,SLOT(OnPlayerChange(int)));
}

MultiplayerTest::~MultiplayerTest()
{
    delete ui;
}

void MultiplayerTest::on_pushButton_clicked()
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,8888);
    qDebug() << "Starting server on any device port:8888";

    connect(server,SIGNAL(newConnection()),this, SLOT(onClientConnect()));

}

void MultiplayerTest::onClientConnect()
{

    bool conAvailable = server->waitForNewConnection(100);
    peerSocket  = server->nextPendingConnection();
    peerConnection = new Connection(peerSocket);

    qDebug() << "Client connected " << peerSocket->peerAddress() << " " << peerSocket->peerPort();

    isServer = true;



    setFocusPolicy(Qt::StrongFocus);
    manager->setMouse(0, 0);
    setMouseTracking(true);
    isInit = true;

}

void MultiplayerTest::onConnected()
{
    qDebug() << "Local connection connecting to server";
    peerConnection = new Connection(peerSocket);

    qDebug() << "Connected";


    isServer = false;


    setFocusPolicy(Qt::StrongFocus);
    manager->setMouse(0, 0);
    setMouseTracking(true);
    isInit = true;

}

void MultiplayerTest::on_pushButton_2_clicked()
{
    peerSocket = new QTcpSocket(this);
    peerSocket->connectToHost(QHostAddress(ui->joinIPText->toPlainText()),8888);
    connect(peerSocket,SIGNAL(connected()), this, SLOT(onConnected()));
}



void MultiplayerTest::mouseMoveEvent(QMouseEvent * e) {
    if(!isInit)
        return;
    manager->setMouse(e->x(), e->y());
}


void MultiplayerTest::paintEvent(QPaintEvent * e) {
    if(!isInit)
        return;
    manager->Draw();
}

void MultiplayerTest::Update()
{
    if(!isInit)
        return;
    this->update();
    manager->Update(1.0 / 60.0);
}

void MultiplayerTest::keyPressEvent(QKeyEvent *e)
{
   KeyboardManager::KeyPress(e);
}

void MultiplayerTest::keyReleaseEvent(QKeyEvent *e)
{
   KeyboardManager::KeyRelease(e);
}


void MultiplayerTest::OnWormChange(Worm *worm)
{
}


void MultiplayerTest::OnPlayerChange(int playerId)
{
}
