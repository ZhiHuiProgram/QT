#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *event){
        qDebug()<<"paint";

        QPainter p(this);
        p.translate(this->width()/2,this->height()/2);
        p.drawEllipse(QPoint(0,0),100,100);
        p.rotate(i++*10);
        p.drawLine(0,0,0,100);
    }
    void timerEvent(QTimerEvent *event){
        update();
    }

private:
    Ui::Widget *ui;
    int i;

};

#endif // WIDGET_H
