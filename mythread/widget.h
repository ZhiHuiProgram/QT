#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProgressBar>
#include "mythread.h"
#include "mythread1.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QProgressBar *p1, *p2;//用两个进度条观察线程

    myThread1 *t1;
    myThread *t2;
};

#endif // WIDGET_H
