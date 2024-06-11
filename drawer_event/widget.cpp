#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pix = new QPixmap(this->width(),this->height());
    pix->fill();
    saveit = false;
}

Widget::~Widget()
{
    delete ui;
}
