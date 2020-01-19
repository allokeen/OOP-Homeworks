#include <QtTest>
#include <QSignalSpy>
#include "speed.h"
#include "acceleration.h"
#include "displacement.h"

// add necessary includes here

class acceleration_testing : public QObject
{
    Q_OBJECT

private slots:
    void test_get(){
        Acceleration acceleration{};
        QCOMPARE(acceleration.get(),0);
    }

    void test_signal(){
        Speed speed{};
        Displacement displacement{};
        Acceleration acceleration{};

        QObject::connect(&displacement, SIGNAL(changed(double)),
                         &speed, SLOT(onChange(double)));
        QObject::connect(&speed, SIGNAL(changed(double)),
                         &acceleration, SLOT(onChange(double)));

        QSignalSpy spy(&acceleration, SIGNAL(changed(double)));
        displacement.set(7);

        QCOMPARE(spy.count(),1);                     //emisja sygnalu
        QList<QVariant> argList = spy.takeFirst();   //wartosc przekazanego argumentu
        QVERIFY(argList.at(0) == 7);
    }

    void test_property(){
        Acceleration acceleration{};

        QVERIFY(acceleration.property("value")==acceleration.get());  //wywołanie wlasciwosci get (READ)

        acceleration.setProperty("value",10);                         //brak wlasciwosci set (WRITE)
        QVERIFY(acceleration.get()!=10.0);
    }

};
QTEST_APPLESS_MAIN(acceleration_testing)

#include "tst_acceleration_testing.moc"
