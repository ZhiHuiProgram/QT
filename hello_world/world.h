#ifndef WORLD_H
#define WORLD_H
#include <QThread>
#include <QDebug>
#include <QSemaphore>
#include <QMutex>
class world : public QThread
{
    Q_OBJECT
public:
    world(QMutex *m,int *i):mut(m),c(i){}
    void run(){
        while(1){
            mut->lock();
            qDebug() << "younger_brother !";
            *c = 4;
            mut->unlock();
        }
    }
private:
    QSemaphore *sem;
    QMutex *mut;
    int *c;
};

#endif // WORLD_H
