#include "displacement.h"

#include <QDebug>

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

double Displacement::get()
{
    return value;
}

void Displacement::set(double v)
{
    value = v;
    emit changed(value);
}
