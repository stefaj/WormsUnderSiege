#ifndef CONNECTION_H
#define CONNECTION_H
#include "wormstruct.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include <QList>


enum PACKETTYPES{WormSync=0, NewProjectile=1};
class Connection : public QObject
{
    Q_OBJECT
public:
    Connection();
    Connection(QTcpSocket *s);
    void Send(WormStruct h);
signals:
    void OnWormReceived(WormStruct t);
private:
    QTcpSocket *sock;
    const int IntFromQByteArr(QByteArray a);
    const float FloatFromQByteArr(QByteArray a);

private slots:
    void on_readyRead();

    //Packet loader
    //m_number:type;data:@:
    //eg tower
    //9:0:type:owner:damage:x:y:@:

    //types
    //0 - new tower

};

#endif // CONNECTION_H
