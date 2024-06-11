#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qte = new QTextEdit;
    qle = new QLineEdit;
    qpb = new QPushButton("send");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qte);
    vbox->addWidget(qle);
    vbox->addWidget(qpb);
    this->setLayout(vbox);

    client = new QTcpSocket ;//初始化tcpclient
    client->connectToHost(QHostAddress("192.168.31.158"),8888);//连接

    connect(qpb,SIGNAL(clicked(bool)),this,SLOT(clientSend()));//点击发送
    connect(client,SIGNAL(readyRead()),this,SLOT(clientRecv()));//接收
}

Widget::~Widget()
{
    delete ui;
}
