#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QTimerEvent>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mousePressEvent(QMouseEvent *event){ //鼠标点击事件
        qDebug()<<"press  " << event->pos();
    }
    void mouseMoveEvent(QMouseEvent *event){ //鼠标移动
        qDebug()<<"moving"<<event->pos();
    }
    void keyPressEvent(QKeyEvent *event){ //键盘按下
        qDebug()<<"key"<<event->key();
    }
    void wheelEvent(QWheelEvent *event){ //鼠标滚轮
        qDebug()<<"wheel"<<event->delta();
    }
    void timerEvent(QTimerEvent *event){ //定时器事件
        qDebug()<<"timer";
    }
};

#endif // WIDGET_H
