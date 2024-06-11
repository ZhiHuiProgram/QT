#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qtb = new QToolBox;
    qpb[0]= new QPushButton("aaa");
    qpb[1]= new QPushButton("bbb");
    qpb[2]= new QPushButton("ccc");

    qtb->addItem(qpb[0],"11");
    qtb->addItem(qpb[1],"22");
    qtb->addItem(qpb[2],"33");

    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addWidget(qtb);
    this->setLayout(mainbox);
}

Widget::~Widget()
{
    delete ui;
}
