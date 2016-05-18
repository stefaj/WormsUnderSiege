#include "connection.h"
#include "iostream"
#include <QDebug>

const int magic_num = 9;
Connection::Connection()
{
}

Connection::Connection(QTcpSocket *s)
{
    this->sock = s;
    connect(sock, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
    sock->blockSignals(false);
}

void Connection::Send(WormStruct h)
{
    sock->waitForConnected();

    int packet_type = PACKETTYPES::WormSync;
    QByteArray data = (QString::number(magic_num) + ":" + QString::number(packet_type)
            + ":" + QString::number(h.id) + ":" + QString::number(h.x)
            + ":" + QString::number(h.y) +  ":" + QString::number(h.veloX)+  ":" + QString::number(h.veloY) + ":@:").toUtf8();
    sock->write(data);
    sock->flush();

    qDebug() << data;
}

void Connection::on_readyRead()
{
    qDebug() << "ONREAD";

    QByteArray buffer;
    qint64 n = sock->bytesAvailable();
    buffer = sock->read(n);

    QList<QByteArray> elements = buffer.split(':');

    bool isData = true;
    int i =0;
    while(isData)
    {
        int magic = IntFromQByteArr(elements[0+i]);

        if(magic != magic_num)
        {
            //Some error
        }

        int packet_type = IntFromQByteArr(elements[1+i]);

        if(packet_type == PACKETTYPES::WormSync)
        {
            WormStruct worm;
            worm.id = IntFromQByteArr(elements[2+i]);
            worm.x = IntFromQByteArr(elements[3+i]);
            worm.y = IntFromQByteArr(elements[4+i]);
            worm.veloX = IntFromQByteArr(elements[5+i]);
            worm.veloY = IntFromQByteArr(elements[6+i]);

            qDebug() << "New Tower (" + QString::number(worm.id) + ","
                        +QString::number(worm.x) + ","
                        + QString::number(worm.y) + ","
                        + QString::number(worm.veloX) + ","
                        + QString::number(worm.veloY) + ")";

            emit OnWormReceived(worm);
            i+=7;
        }


        i++;
        isData = (elements[i].toInt() == magic_num);

    }

}

const int Connection::IntFromQByteArr(QByteArray a)
{
    return a.toInt();
}

const float Connection::FloatFromQByteArr(QByteArray a)
{
    return a.toFloat();
}
