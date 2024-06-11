#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
class tcpserver : public QObject
{
    Q_OBJECT
public:
    explicit tcpserver(QObject *parent = 0);

signals:

public slots:
    void newclient(){
        client = server->nextPendingConnection();
        qDebug()<<"connect";
        connect(client,SIGNAL(readyRead()),this,SLOT(readdate()));

    }
    void readdate(){
        QByteArray buf = client->readAll();
        qDebug()<<"recv"<<buf;
        client->write(buf);
    }

private:
    QTcpServer *server;
    QTcpSocket *client;
};

#endif // TCPSERVER_H
