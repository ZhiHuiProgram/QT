#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
signals:
    downloaded(int);
public:
    myThread();

    void run()
    {
        for(int i=0;i<100; i++)
        {
            //p1->setValue(i);
            emit downloaded(i);//每执行一次就会发射一次信号
            QThread::sleep(2);
        }
    }
};

#endif // MYTHREAD_H
