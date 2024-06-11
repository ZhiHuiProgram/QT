#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QPixmap>
#include <QEvent>
#include <QKeyEvent>
class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void showpic(){
        index = 0;
        files = QFileDialog::getOpenFileNames();//打开多个文件
        QPixmap pix(files[0]);//文件0写入标签上
        ql->setPixmap(pix);
    }
    void showright(){
        if(index+1<files.length()){
            index++;
        }else{
            index=0;
        }
        QPixmap pix(files[index]);//文件i写入标签上
        ql->setPixmap(pix);
    }
    void showleft(){
        if(index-1>=0){
            index--;
        }else{
            index=files.length()-1;
        }
        QPixmap pix(files[index]);
        ql->setPixmap(pix);
    }
    bool eventFilter(QObject *watched, QEvent *event){
        ql->setFocus();//再次聚焦确保ql接收键盘事件
        if(watched == ql){
            if(event->type()==QEvent::KeyPress){
                QKeyEvent *keyevent=static_cast<QKeyEvent *>(event);
                if(keyevent->key() == Qt::Key_Left){
                    showleft();
                }
                if(keyevent->key() == Qt::Key_Right){
                    showright();
                }
                return true;
            }
        }
        return QWidget::eventFilter(watched,event);
    }

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel *ql;
    QPushButton *lqbt,*rqbt,*oqbt;
    QStringList files;
    int index;
};

#endif // WIDGET_H
