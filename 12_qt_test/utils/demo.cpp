#include "demo.h"

demo::demo(QObject *parent) : QObject(parent)
{

}

int demo::sum(int a, int b)
{
    return a+b;
}
