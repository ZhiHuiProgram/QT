#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void showfile(){
        QString files = QFileDialog::getOpenFileName();//获取文件属性
        QStringList arg = {files};//传参要qstringlist，转换一下
        qle->setText(arg[0]);

        QProcess qpro;
        qpro.execute("notepad",arg);//进程开启notepai传参arg
    }

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *qpb;
    QLineEdit *qle;
};

#endif // WIDGET_H
