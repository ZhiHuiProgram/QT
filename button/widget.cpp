#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qpb = new QPushButton("designed");

    qcb = new QCheckBox("show passwd");  //勾选框
    qle = new QLineEdit;


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qle);
    vbox->addWidget(qcb);
    vbox->addWidget(qpb);

    this->setLayout(vbox);
    connect(qpb,SIGNAL(clicked(bool)),qle,SLOT(clear()));
    connect(qcb,SIGNAL(clicked(bool)),this,SLOT(setpass(bool)));

}

Widget::~Widget()
{
    delete ui;
}
