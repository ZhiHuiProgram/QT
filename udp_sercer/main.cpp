#include <QCoreApplication>
#include <udpserver.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Main function started";
    udpserver server;
    qDebug() << "udpserver object created";
    server.init();
    qDebug() << "init method called";
    return a.exec();
}
