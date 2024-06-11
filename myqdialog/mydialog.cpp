#include "mydialog.h"
#include <QVBoxLayout>
mydialog::mydialog()
{
    le = new QLineEdit("aaaaaa");
    pb = new QPushButton("OK");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(pb);

    setLayout(vbox);

    stat = false;
    connect(pb, SIGNAL(clicked(bool)), this, SLOT(ok_pushed()));
}
