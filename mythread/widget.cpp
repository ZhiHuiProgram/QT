#include "widget.h"
#include <QVBoxLayout>
#include <QThread>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    p1 = new QProgressBar;
    p2 = new QProgressBar;

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(p1);
    vbox->addWidget(p2);
    setLayout(vbox);

    t1 = new myThread1;
    t2 = new myThread;
    connect(t1, SIGNAL(downloaded(int)), p1, SLOT(setValue(int)));
    connect(t2, SIGNAL(downloaded(int)), p2, SLOT(setValue(int)));
    t1->start();
    t2->start();

#if 0
    for(int i=0;i<100; i++)
    {
        p1->setValue(i);
        QThread::sleep(1);
    }

    for(int i=0;i<100; i++)
    {
        p2->setValue(i);
        QThread::sleep(2);
    }
#endif
}

Widget::~Widget()
{

}
