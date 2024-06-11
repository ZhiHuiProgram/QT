#include <QCoreApplication>
#include "elder_brother.h"
#include "youngerbrother.h"
#include <QDebug>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    elder_brother eld;
    youngerbrother young;
    eld.start();
    young.start();
    qDebug()<<"hello";
    return a.exec();
}
