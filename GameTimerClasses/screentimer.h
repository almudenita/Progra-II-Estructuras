#ifndef SCREENTIMER_H
#define SCREENTIMER_H
#include <QGraphicsTextItem>


class ScreenTimer : public QGraphicsTextItem
{
public:
    ScreenTimer(QGraphicsItem * parent  = 0);
    void decrease();
    int getScreenTimer();
    void bonusTimeIncrease();

private:
    int time;
};

#endif // SCREENTIMER_H
