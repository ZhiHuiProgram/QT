#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ql = new QLabel;
    ql->setMinimumSize(100,100);//最小标签大小
    ql->setScaledContents(true);//适配大小
    ql->setFocus();//让ql聚焦确保接收键盘事件
    ql->installEventFilter(this);//过滤器是this，ql的事件先触发eventfilter
    lqbt = new QPushButton("<");
    oqbt = new QPushButton("OPEN");
    rqbt = new QPushButton(">");
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch(1);  //按钮与边框互相的间隔分为
    hbox->addWidget(lqbt);//1：2：2：1
    hbox->addStretch(2);
    hbox->addWidget(oqbt);
    hbox->addStretch(2);
    hbox->addWidget(rqbt);
    hbox->addStretch(1);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(ql);
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(oqbt,SIGNAL(clicked(bool)),this,SLOT(showpic()));
    connect(lqbt,SIGNAL(clicked(bool)),this,SLOT(showleft()));
    connect(rqbt,SIGNAL(clicked(bool)),this,SLOT(showright()));
}

Widget::~Widget()
{

}
