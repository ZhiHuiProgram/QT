#ifndef MYQDIALOG_H
#define MYQDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class mydialog : public QDialog
{
    Q_OBJECT
public:
    mydialog();

public slots:
    void ok_pushed()
    {
        stat = true;
        close();
    }

public:
    static int getstat()
    {
        mydialog a;
        a.exec();

        return a.stat;
     }

private:
    QLineEdit *le;
    QPushButton *pb;

    int stat;
};

#endif // MYQDIALOG_H
