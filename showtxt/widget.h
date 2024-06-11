#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void showfile(){
        QString filename = QFileDialog::getOpenFileName(); //获取文件目录
        qle->setText(filename);
#if 0
        QFile file(filename);//创建文件类
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd()) {
            QByteArray line = file.readLine(); //读
            qte->append(line); //追加写
        }
#endif
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file); //流式读写
        while (!in.atEnd()) {
            QString line = in.readLine();
            qte->append(line);
        }
    }

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QTextEdit *qte;
    QLineEdit *qle;
    QPushButton *qpb;
};

#endif // WIDGET_H
