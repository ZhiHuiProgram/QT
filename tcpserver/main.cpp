#include <QCoreApplication>
#include "tcpserver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    tcpserver serverInstance;//构造函数已完成初始化
    return a.exec();
}
