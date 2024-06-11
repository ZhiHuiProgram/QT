#include "tcpserver.h"
#include "QHostAddress"
tcpserver::tcpserver(QObject *parent) : QObject(parent)
{
    server = new QTcpServer;//初始化
    server->listen(QHostAddress("192.168.31.158"),8888);//绑定加监听
    if (server->isListening()) {//如果有东西
        qDebug() << "Server is listening on port 8888";
    } else {
        qDebug() << "Server failed to listen on port 8888";
    }
    connect(server,SIGNAL(newConnection()),this, SLOT(newclient()));
   // server->waitForNewConnection();
}
