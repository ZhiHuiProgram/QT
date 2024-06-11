#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
class udpserver : public QObject
{
    Q_OBJECT
public:
    explicit udpserver(QObject *parent = 0);
    void init(){
        qDebug()<<"init...";
        server = new QUdpSocket; //初始化
        server->bind(QHostAddress("192.168.31.158") , 8888);//绑定
        connect(server, SIGNAL(readyRead()),
                      this, SLOT(readPendingDatagrams()));//接受消息处理
        qDebug()<<"init...";
    }
signals:

public slots:
    void readPendingDatagrams()
      {
          while (server->hasPendingDatagrams()) {//是否有消息
              QByteArray datagram;
              datagram.resize(server->pendingDatagramSize());//resize根据数据消息大小确定size
              QHostAddress sender;
              quint16 senderPort;

              server->readDatagram(datagram.data(), datagram.size(),
                                      &sender, &senderPort);//接收消息
              qDebug()<<"recv"<<datagram;
              server->writeDatagram(datagram.data(), datagram.size(),
                                      sender, senderPort);//根据收到的客户端身份返回数据
          }
      }
private:
    QUdpSocket *server;
};

#endif // UDPSERVER_H
