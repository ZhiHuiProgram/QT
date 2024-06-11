#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qbtcolor = new QPushButton("setcolor");
    qbterror = new QPushButton("errmsg");
    qbtfile  = new QPushButton("setfile");
    qbtfont  = new QPushButton("setfont");
    qbtinput = new QPushButton("getmsg");
    qbtmsg   = new QPushButton("msg");
    qbtprog  = new QPushButton("progress");
    qbtwizard= new QPushButton("");

    qte = new QTextEdit;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qbtcolor);
    vbox->addWidget(qbterror);
    vbox->addWidget(qbtfile);
    vbox->addWidget(qbtfont);
    vbox->addWidget(qbtinput);
    vbox->addWidget(qbtmsg);
    vbox->addWidget(qbtprog);

    QHBoxLayout *mainbox = new QHBoxLayout;
    mainbox->addLayout(vbox);
    mainbox->addWidget(qte);
    this->setLayout(mainbox);

    connect(qbtcolor,SIGNAL(clicked(bool)),this,SLOT(setcolor()));
    connect(qbterror,SIGNAL(clicked(bool)),this,SLOT(showerr()));
    connect(qbtfile, SIGNAL(clicked(bool)),this,SLOT(getfile()));
    connect(qbtfont, SIGNAL(clicked(bool)),this,SLOT(setfont()));
    connect(qbtinput, SIGNAL(clicked(bool)),this,SLOT(getstr()));
    connect(qbtmsg, SIGNAL(clicked(bool)),this,SLOT(showmsg()));
    connect(qbtprog, SIGNAL(clicked(bool)),this,SLOT(showprog()));
}

Widget::~Widget()
{
    delete ui;
}
