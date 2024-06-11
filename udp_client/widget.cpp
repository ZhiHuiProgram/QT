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

    client = new QUdpSocket; //新建并初始化udpclient
    connect(qpb,SIGNAL(clicked(bool)),this,SLOT(clientSend()));//点击发送
    connect(client,SIGNAL(readyRead()),this,SLOT(clientRecv()));//接受客户端的消息
}

Widget::~Widget()
{
    delete ui;
}
