#include <QtTest>
#include "speed.h"
#include "displacement.h"

// add necessary includes here

class speed_test : public QObject
{
    Q_OBJECT

private slots:

    void test_get(){
        Speed speed{};
        QCOMPARE(speed.get(),0);
    }

    void test_signal(){
        Speed speed{};
        Displacement displacement{};
        QObject::connect(&displacement, SIGNAL(changed(double)),
                         &speed, SLOT(onChange(double)));

        QSignalSpy spy(&speed, SIGNAL(changed(double)));
        displacement.set(5);

        QVERIFY(spy.count()==1);                     //emisja sygnalu
        QList<QVariant> argList = spy.takeFirst();   //wartosc przekazanego argumentu
        QVERIFY(argList.at(0) == 5);
    }

    void test_property(){
        Speed speed{};

        QVERIFY(speed.property("value")==speed.get());  //wywołanie wlasciwosci get (READ)

        speed.setProperty("value",10);                  //brak wlasciwosci set (WRITE) - wartosc nie zmieni się
        QVERIFY(speed.get()!=10.0);
    }

};

QTEST_APPLESS_MAIN(speed_test)

#include "tst_speed_test.moc"
