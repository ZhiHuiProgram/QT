#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qgb = new QGroupBox("choose");
    qrb1 = new QRadioButton("aaa");
    qrb2 = new QRadioButton("bbb");
    qrb3 = new QRadioButton("ccc");
    QVBoxLayout *vbox=new QVBoxLayout;
    vbox->addWidget(qrb1);
    vbox->addWidget(qrb2);
    vbox->addWidget(qrb3);
    qgb->setLayout(vbox);

    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addWidget(qgb);
    this->setLayout(mainbox);
}

Widget::~Widget()
{
    delete ui;
}
