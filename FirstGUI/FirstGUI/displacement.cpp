#include "displacement.h"
#include <QDebug>

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    value = v;
    emit changed(value);
}
