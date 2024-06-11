#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qpb =new QPushButton("showtxt");
    qle = new QLineEdit;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qpb);
    vbox->addWidget(qle);

    this->setLayout(vbox);
    connect(qpb,SIGNAL(clicked(bool)),this, SLOT(showfile()));
}

Widget::~Widget()
{
    delete ui;
}
