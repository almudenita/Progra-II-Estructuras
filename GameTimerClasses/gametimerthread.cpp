#include "gametimerthread.h"
#include <QDebug>
#include "screentimer.h"

extern ScreenTimer *screenTimer;
GameTimerThread::GameTimerThread()
{

}

void GameTimerThread::run()
{
    //sobrescribo run, para inicializar el timer del thread
    qDebug()<<"help this poor thread";
    QThread* timerThread = new QThread(this);
    QTimer* timer = new QTimer(0);
    timer->setInterval(1000);//corre cada segundo
    timer->moveToThread(timerThread);//se asegura de que el timer este corriendo en el thread deseado
    /*connect(timer, SIGNAL(timeout()), this, &GameTimerThread::timerSlot);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot(QTimer *timer)));//conecta el timer inicializado a una accion*/
    timer->start();
    timerThread->start();
}

void GameTimerThread::timerSlot(QTimer *timer)
{
    //qDebug()<<"Executing";
    qDebug()<<"im trying";
    while(timer->isActive())
    {
        //disminuir el timer en un segundo, porque el intervalo del timer es de 1 segundo
        //esto se hace llamando a la funcion que disminuye el timer(decrease), de la clase ScreenTimer
        screenTimer->decrease();


        //el main tiene acceso al tiempo recorrido por ser una variable global
    }
}

void timeBonus(QTimer *timer)
{
    //aumentar el tiempo que queda en el timer si se come una manzanita
}
