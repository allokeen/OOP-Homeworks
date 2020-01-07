#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onSpeedChanged(double v)
{
    if(hasFirstValue == 0 )
    {
        firstValue = v;
        hasFirstValue = 1;
    }
    else if( hasFirstValue == 1 && hasSecondValue==0)       //pierwsze dwie pobrane prędkości
    {
        secondValue=v;
        hasSecondValue=1;
        qDebug() << "[Acceleration] value: " << secondValue-firstValue;
        emit changed(secondValue - firstValue);
    }
    else if( hasFirstValue==1 && hasSecondValue==1)
    {
        firstValue=secondValue;
        secondValue=v;
        qDebug() << "[Acceleration] value: " << secondValue-firstValue;
        emit changed(secondValue - firstValue);
    }
}

