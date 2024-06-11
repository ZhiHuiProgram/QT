#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QByteArray>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void clientRecv(){//收消息
        QByteArray datagram;
        datagram.resize(client->pendingDatagramSize());//pending...返回下一个待读数据的大小
        //resize 的作用是确保 QByteArray 有足够的容
        QHostAddress sender; //量来完整地存储即将接收的 UDP 数据报，这是处理网络数据的重要步骤，以确保数据的完整性和正确性。
        quint16 senderPort;
        client->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
        qte->append(datagram);//追加写
    }
    void clientSend(){//发消息
        client->writeDatagram(qle->text().toStdString().c_str() ,QHostAddress("192.168.31.158"),8888);
    }

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTextEdit *qte;
    QLineEdit *qle;
    QPushButton *qpb;
    QUdpSocket *client;
};

#endif // WIDGET_H
