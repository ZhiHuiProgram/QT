#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout> //纵向布局
#include <QHBoxLayout> //横向布局
#include <QGridLayout> //平面布局
#include <QFormLayout> //表格布局
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qb = new QPushButton("ok",this);
    qle = new QLineEdit(this);
    qle1 = new QLineEdit(this);
    QFormLayout *fbox = new QFormLayout;
    fbox->addRow(qb);
    fbox->addRow("input",qle);
    fbox->addRow("output",qle1);
    this->setLayout(fbox);
    /*
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qb);
    vbox->addWidget(qle);
    vbox->addWidget(qle1);
    this->setLayout(vbox);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(qb);
    hbox->addWidget(qle);
    hbox->addWidget(qle1);
    this->setLayout(hbox);

    QGridLayout *gbox = new QGridLayout;
    gbox->addWidget(qb,1,1);
    gbox->addWidget(qle,0,1);
    gbox->addWidget(qle1,1,0);
    this->setLayout(gbox);
    */
}

Widget::~Widget()
{
    delete ui;
}
