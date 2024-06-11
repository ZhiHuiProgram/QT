#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qle = new QLineEdit;
    qtext = new QTextEdit;
    qcb = new QComboBox;//下拉列表
    qcb->addItem("read");
    qcb->addItem("write");
    qtime = new QTimeEdit;
    qd = new QDial     ;//调节器
    qs = new QSlider   ;
    qs->setOrientation(Qt::Horizontal);//设置方向水平，vertical垂直
    qsb = new QScrollBar;
    qsb->setOrientation(Qt::Horizontal);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qle);
    vbox->addWidget(qtime);
    vbox->addWidget(qcb);
    vbox->addWidget(qtext);
    vbox->addWidget(qd);
    vbox->addWidget(qs);
    vbox->addWidget(qsb);

    ql = new QLabel();
    QPixmap pix("2.png");
    ql->setFixedSize(100,100);
    ql->setScaledContents(true);
    ql->setPixmap(pix);
    qlcd = new QLCDNumber ;
    qpb = new QProgressBar;
    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(ql);
    vbox1->addWidget(qlcd);
    vbox1->addWidget(qpb);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addLayout(vbox);
    hbox->addLayout(vbox1);
    this->setLayout(hbox);
    connect(qd,SIGNAL(valueChanged(int)),qlcd,SLOT(display(int)));
    connect(qd,SIGNAL(valueChanged(int)),qpb,SLOT(setValue(int)));
    connect(qs,SIGNAL(sliderMoved(int)),qpb,SLOT(setValue(int)));
    connect(qs,SIGNAL(valueChanged(int)),qlcd,SLOT(display(int)));

}

Widget::~Widget()
{
    delete ui;
}
