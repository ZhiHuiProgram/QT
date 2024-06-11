#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ql = new QLabel(this);
    QPixmap pix("2.png");
    ql->setPixmap(pix);

    qsa = new QScrollArea(this);
    qsa->setWidget(ql);

    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addWidget(qsa);
    this->setLayout(mainbox);
}

Widget::~Widget()
{
    delete ui;
}
