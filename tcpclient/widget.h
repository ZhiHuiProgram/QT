#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QByteArray>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void clientRecv(){
        QByteArray buf = client->readAll();//接收
        //读到没有数据为止，读完会清除
        qte->append(buf);
    }
    void clientSend(){
        client->write(qle->text().toStdString().c_str());//发送数据的地址
    }

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTextEdit *qte;
    QLineEdit *qle;
    QPushButton *qpb;
    QTcpSocket *client;
};


#endif // WIDGET_H
