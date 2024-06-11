#include "widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qte = new QTextEdit;
    qte->setMinimumSize(640,480);
    qle = new QLineEdit;
    qpb = new QPushButton("showtext");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qte);
    vbox->addWidget(qle);
    vbox->addWidget(qpb);

    this->setLayout(vbox);
    connect(qpb,SIGNAL(clicked(bool)),this,SLOT(showfile()));
}

Widget::~Widget()
{

}
