#ifndef YOUNGERBROTHER_H
#define YOUNGERBROTHER_H
#include <QThread>
#include <QDebug>

class youngerbrother : public QThread
{
    Q_OBJECT
public:
    youngerbrother();
    void run(){
        while(1){
            qDebug() << "younger_brother !";
            sleep(1);
        }
    }
};

#endif // YOUNGERBROTHER_H
