#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    startTimer(1000); //开启定时器
}

Widget::~Widget()
{

}
