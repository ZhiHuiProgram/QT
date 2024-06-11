/*
#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

class mydialog : public QDialog
{
    Q_OBJECT//开启信号与槽机制
public:
    mydialog();

public slots:
    void ok_push(){
        stat = true;
        close();
    }
public:
    static int getstat(){
        mydialog a;
        a.exec();
        return a.stat;
    }

private:
    QLineEdit *qle;
    QPushButton *qpb;
    int stat;
};

#endif // MYDIALOG_H
*/
#ifndef MYQDIALOG_H
#define MYQDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class myQDialog : public QDialog
{
    Q_OBJECT
public:
    myQDialog();

public slots:
    void ok_pushed()
    {
        stat = true;
        close();
    }

public:
    static int getstat()
    {
        myQDialog a;
        a.exec();

        return a.stat;
     }

private:
    QLineEdit *qle;
    QPushButton *qpb;

    int stat;
};

#endif // MYQDIALOG_H
