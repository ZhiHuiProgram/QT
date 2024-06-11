#ifndef ELDER_BROTHER_H
#define ELDER_BROTHER_H
#include <QThread>
#include <QDebug>

class elder_brother : public QThread
{
    Q_OBJECT
public:
    elder_brother();
    void run(){
        while(1){
            qDebug() << "elder_brother !";
            sleep(1);
        }
    }
};

#endif // ELDER_BROTHER_H
