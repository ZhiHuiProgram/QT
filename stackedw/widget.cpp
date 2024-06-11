#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qsw = new QStackedWidget;
    qte[0] = new QTextEdit("qqq");
    qte[1] = new QTextEdit("ddd");
    qte[2] = new QTextEdit("ppp");

    qsw->addWidget(qte[0]);
    qsw->addWidget(qte[1]);
    qsw->addWidget(qte[2]);

    qcb = new QComboBox;
    qcb->addItem("111");
    qcb->addItem("222");
    qcb->addItem("333");

    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addWidget(qsw);
    mainbox->addWidget(qcb);
    this->setLayout(mainbox);

    connect(qcb,SIGNAL(activated(int)), qsw, SLOT(setCurrentIndex(int)));
}

Widget::~Widget()
{
    delete ui;
}
