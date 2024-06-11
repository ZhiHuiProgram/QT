#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QLabel>
#include <QProgressBar>
#include <QFileDialog>
#include <QColorDialog>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openf(){
        QString filename = QFileDialog::getOpenFileName();//点击选择文件目录结果输入文本框
        qte->setText(filename);
    }
    void copyf(){
        qte->copy();
    }
    void pastf(){
        qte->paste();
    }
    void setcf(){
        QColor color = QColorDialog::getColor();
        qte->setTextColor(color);
    }

private:
    QAction *openfile;
    QAction *copyfile,*pastefile;
    QAction *setcolor;
    QTextEdit *qte;
    QLabel *ql;
    QProgressBar *qpb;
};

#endif // MAINWINDOW_H
