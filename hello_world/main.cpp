#include <QCoreApplication>
#include "hello.h"
#include "world.h"
#include <QDebug>
#include <QSemaphore>
#include <QMutex>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMutex mutex; //创建锁
    int i=4;
    hello eld(&mutex,&i); //线程hello
    world young(&mutex,&i);//线程world
    eld.start(); //线程启动
    young.start();
    qDebug()<<"hello";
    return a.exec();
}
