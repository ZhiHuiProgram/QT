#include "widget.h"
#include <QWidget>
#include <QDialog>
#include "mydialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
#if 0
    myQDialog a;
    a.setFixedSize(100, 100);
    a.exec();

    if(!a.stat)
        exit(0);

#endif

    int s = mydialog::getstat();

    if(!s)
          exit(0);
}

Widget::~Widget()
{

}
