#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void setpass(bool flag){
        if(flag)
            qle->setEchoMode(QLineEdit::Password); //框选打勾，密码屏蔽
        else
            qle->setEchoMode(QLineEdit::Normal); //框选取消，密码显示
    }

private:
    Ui::Widget *ui;
    QLineEdit *qle;
    QPushButton *qpb;
    QCheckBox *qcb; //框选
};

#endif // WIDGET_H
