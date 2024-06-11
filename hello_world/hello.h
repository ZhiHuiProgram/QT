#ifndef HELLO_H
#define HELLO_H
#include <QThread>
#include <QDebug>
#include <QSemaphore>
#include <QMutex>
class hello : public QThread
{
    Q_OBJECT
public:
    hello(QMutex *m,int *i):mut(m),c(i){}

    void run(){
        while(1){
            mut->lock();
            qDebug() << "elder_brother !";
            qDebug() << *c;
            *c = 8;
            sleep(1);
            mut->unlock();
        }
    }
private:
    QSemaphore *sem;
    QMutex *mut;
    int *c;
};

#endif // HELLO_H
