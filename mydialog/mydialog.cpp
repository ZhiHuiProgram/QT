#include "mydialog.h"
#include <QVBoxLayout>
myQDialog::myQDialog()
{
    qle = new QLineEdit("abcd");
    qpb = new QPushButton("ok");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(qle);
    vbox->addWidget(qpb);

    setLayout(vbox);

    stat = false;
    connect(qpb,SIGNAL(clicked(bool)),this, SLOT(ok_push()));
}
