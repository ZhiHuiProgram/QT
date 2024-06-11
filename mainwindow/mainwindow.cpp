#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QTextEdit>
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openfile = new QAction(QIcon("open.png"),"open",this);    //创建action
    openfile->setShortcut(QKeySequence(tr("Ctrl+O")));
    copyfile = new QAction(QIcon("copy.png"),"copy",this);
    pastefile = new QAction(QIcon("past.png"),"paste",this);
    setcolor = new QAction(QIcon("color.png"),"setcolor",this);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File")); //将action加入menu
    fileMenu->addAction(openfile);

    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(copyfile);
    editMenu->addAction(pastefile);

    QMenu *setMenu = menuBar()->addMenu(tr("&Set"));
    setMenu->addAction(setcolor);

    QToolBar *tfile  = addToolBar("file");  //将action加入toolbar
    tfile->addAction(openfile);
    QToolBar *tedit  = addToolBar("edit");
    tedit->addAction(copyfile);
    tedit->addAction(pastefile);
    QToolBar *tset  = addToolBar("set");
    tset->addAction(setcolor);

    qte = new QTextEdit;
    qte->setMinimumSize(640,480);
    setCentralWidget(qte);  //将文本框加入中央

    ql = new QLabel("1.txt");
    qpb = new QProgressBar();
    QStatusBar *qsb = statusBar();  //状态栏加入标签进度条
    qsb->addWidget(ql);
    qsb->addWidget(qpb);

    connect(openfile,SIGNAL(triggered(bool)),this, SLOT(openf())); //信号与槽相连
    connect(copyfile,SIGNAL(triggered(bool)),this, SLOT(copyf()));
    connect(pastefile,SIGNAL(triggered(bool)),this, SLOT(pastf()));
    connect(setcolor,SIGNAL(triggered(bool)),this, SLOT(setcf()));

}

MainWindow::~MainWindow()
{

}
