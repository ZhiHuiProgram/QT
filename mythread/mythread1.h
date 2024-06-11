#ifndef MYTHREAD1_H
#define MYTHREAD1_H

#include <QThread>

class myThread1 : public QThread
{
    Q_OBJECT
signals:
    downloaded(int);
public:
    myThread1();

    void run()
    {
        for(int i=0;i<100; i++)
        {
            //p1->setValue(i);
            emit downloaded(i);
            QThread::sleep(1);
        }
    }
};

#endif // MYTHREAD1_H
