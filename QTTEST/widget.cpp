#include "widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pb = new QPushButton("OK",this);
    le = new QLineEdit(this);
    le1 = new QLineEdit(this);
  //  pb->setGeometry(100,100,50,50);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pb);
    vbox->addWidget(le);
    vbox->addWidget(le1);
    this->setLayout(vbox);
 //   connect(pb,SIGNAL(clicked(bool)),le,SLOT(clear()));
    connect(pb,SIGNAL(clicked(bool)),this,SLOT(movestr()));

}

Widget::~Widget()
{

}
