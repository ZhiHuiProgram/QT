#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QGroupBox *qgb;
    QRadioButton *qrb1 ,*qrb2,*qrb3;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
