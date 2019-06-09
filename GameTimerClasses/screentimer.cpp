#include "screentimer.h"
#include <QString>
#include <QDateTime>
#include <QFont>

ScreenTimer::ScreenTimer(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicializar el tiempo
    int time= 200;//cantidad de segundos que dura el juego, se puede cambiar para modificar la dificultad
                    //a la variable se le restara elapsedTime mientras corre el juego, hasta llegar a 0
                    //cuando llega a 0, termina el juego
    //mostrar el timer en pantalla
    QString timeString = QString::number(time);
    //setPlainText(QString("Tiempo: ")+QString(timeString)); //formato solo segundos
    setPlainText(QString("Tiempo: ")+QDateTime::fromTime_t(time).toUTC().toString("mm:ss")); //formato en minutos y segundos
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial", 16));
    //;
}
//disminuye el tiempo restante. Es controlado por el un slot de la clase GameTimerThread.
void ScreenTimer::decrease()
{
    time--;
}

int ScreenTimer::getScreenTimer()
{
    return time;
}
//funcion para aumentar el tiempo cuando el jugador realiza una accion especial
void ScreenTimer::bonusTimeIncrease()
{
    time += 5;//aumenta el tiempo en x segundos (5) cuando come una manzanita
}
