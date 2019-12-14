#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    qDebug() << "Displacement changed to: " << v;
    if(hasFirstValue == 0 )
    {
        firstValue = v;
        hasFirstValue = 1;
    }
    else if( hasFirstValue == 1 && hasSecondValue==0)        //pierwsze dwa pobrane przemieszczenia
    {
        secondValue=v;
        hasSecondValue=1;
        emit changed(secondValue-firstValue);
    }
    else if( hasFirstValue==1 && hasSecondValue==1)
    {
        firstValue=secondValue;
        secondValue=v;
        emit changed(secondValue-firstValue);
    }
}
