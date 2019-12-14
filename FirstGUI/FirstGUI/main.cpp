#include "mainwindow.h"
#include "acceleration.h"
#include "displacement.h"
#include "speed.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Displacement d{};
    Speed s{};
    Acceleration a{};

    QObject::connect(&d,
                     SIGNAL(changed(double)),
                     &s,
                     SLOT(onDisplacementChanged(double)));

    QObject::connect(&s,
                     SIGNAL(changed(double)),
                     &a,
                     SLOT(onSpeedChanged(double)));


    d.set(1);
    d.set(2);
    d.set(5);
    MainWindow w;
    w.show();
    return app.exec();
}
