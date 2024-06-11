#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qtw = new QTabWidget;
    qte[0] = new QTextEdit("11");
    qte[1] = new QTextEdit("22");
    qte[2] = new QTextEdit("33");

    qtw->addTab(qte[0],"aa");
    qtw->addTab(qte[1],"bb");
    qtw->addTab(qte[2],"cc");

    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addWidget(qtw);
    this->setLayout(mainbox);
}

Widget::~Widget()
{
    delete ui;
}
