#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QErrorMessage>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>
#include <QTextEdit>
#include <QDebug>
#include <QThread>

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
    void setcolor(){
        QColor c = QColorDialog::getColor();//改变对话框字体颜色
        qte->setTextColor(c);
    }
    void showerr(){
        QErrorMessage *msg = QErrorMessage::qtHandler();//点击显示提示框
        msg->showMessage("show error");
    }
    void getfile(){
        QString filename = QFileDialog::getOpenFileName();//点击选择文件目录结果输入文本框
        qDebug()<<filename;
        qte->setText(filename);
    }
    void setfont(){
        bool ok;
        QFont myfont = QFontDialog::getFont(&ok);//设置字体
        if(ok)
            qte->setFont(myfont);
    }
    void getstr(){
        QString str = QInputDialog::getText(this,"xxx","yyy");//输入对话框标题xxx，标签yyy。
        qte->setText(str);
    }
    void showmsg(){
        QMessageBox::information(this,"vvv","hello","abc");//点击会弹出信息框，标题vv，信息hello，按钮abc
    }
    void showprog(){
        QProgressDialog progress;//显示进度条
        progress.setValue(50);
        progress.exec();
    }

private:
    Ui::Widget *ui;
    QPushButton *qbtcolor;
    QPushButton *qbterror;
    QPushButton *qbtfile;
    QPushButton *qbtfont;
    QPushButton *qbtinput;
    QPushButton *qbtmsg;
    QPushButton *qbtprog;
    QPushButton *qbtwizard;
    QTextEdit *qte;

};

#endif // WIDGET_H
