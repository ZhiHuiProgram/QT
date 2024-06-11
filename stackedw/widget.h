#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QTextEdit>
#include <QComboBox>
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
    QStackedWidget *qsw;
    QTextEdit *qte[3];
    QComboBox *qcb;
};

#endif // WIDGET_H
