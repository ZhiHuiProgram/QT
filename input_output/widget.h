#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox> //下拉列表
#include <QTimeEdit>  //时间
#include <QDial>    //
#include <QSlider>  //滑动条
#include <QScrollBar>  //滚动条
#include <QLabel>
#include <QLCDNumber>
#include <QProgressBar>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QLineEdit *qle;
    QTextEdit *qtext;
    QComboBox *qcb;
    QTimeEdit *qtime;
    QDial     *qd;
    QSlider   *qs;
    QScrollBar *qsb;
    QLabel     *ql;
    QLCDNumber *qlcd;
    QProgressBar *qpb;
};

#endif // WIDGET_H
