#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    i=0;
    startTimer(100);


}

Widget::~Widget()
{
    delete ui;
}
