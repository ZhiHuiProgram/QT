#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QPainter>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mousePressEvent(QMouseEvent *event){
        startp = event->pos();
    }
    void mouseReleaseEvent(QMouseEvent *event){
        saveit = true;
        update();
    }

    void mouseMoveEvent(QMouseEvent *event){
        endp = event->pos();
        update();
    }
    void paintEvent(QPaintEvent *event){ //双缓冲绘图
         QPainter p(this);
         QPainter px(pix);
        if(saveit){                     //点击绘图在背
            px.drawLine(startp,endp); //景板上，松开绘图在图片上
            p.drawPixmap(0,0,*pix);
            saveit = false;
        }else{

        p.drawPixmap(0,0,*pix);
        px.drawLine(startp,endp);
        p.drawLine(startp,endp);
        }
    }

private:
    Ui::Widget *ui;
    QPoint startp;
    QPoint endp;
    QPixmap *pix;
    bool saveit;
};

#endif // WIDGET_H
