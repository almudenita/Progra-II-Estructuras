#ifndef GAMETIMERTHREAD_H
#define GAMETIMERTHREAD_H
#include <QtCore>
#include <QTimer>
#include <QObject>


class GameTimerThread : public QThread
{
    Q_OBJECT
public:
    GameTimerThread();
    void run(); //sobrescribe la funcion de run de la clase QThread, para correr el timer
    //QTimer *timer;
    //QThread *timerThread;
    void timeBonus(QTimer *timer);


public slots:
    void timerSlot(QTimer *timer);
};

#endif // GAMETIMERTHREAD_H
