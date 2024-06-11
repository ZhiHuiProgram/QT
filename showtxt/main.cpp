#include "widget.h"
#include <QApplication>
#include <QFileInfo>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir dir; //默认当前目录
    QFileInfoList list = dir.entryInfoList(); //获取文件属性
    std::cout << "filename bytes"<<std::endl;
    for(int i=0; i<list.size();++i){ //文件个数
        QFileInfo fileinfo = list.at(i); //遍历每个文件属性
        std::cout<< fileinfo.size()<<'\t'<< fileinfo.fileName().toStdString().c_str();
        std::cout <<std::endl;
    }

    return a.exec();
}
