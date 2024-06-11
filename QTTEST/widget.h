#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void movestr(){
        QString tem = le->text();
        le1->setText(tem);
    }

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *pb;
    QLineEdit *le,*le1;
};

#endif // WIDGET_H
