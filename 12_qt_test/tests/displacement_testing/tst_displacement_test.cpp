#include <QtTest>

#include <QSignalSpy>
#include "displacement.h"

// add necessary includes here

class displacement_test : public QObject
{
    Q_OBJECT

private slots:
    void test_get(){

        Displacement displacement{};
        QCOMPARE(displacement.get(),1);
    }

    void test_set(){
        Displacement displacement{};

        displacement.set(1);
        QCOMPARE(displacement.get(),1);
    }

    void test_signal(){

        Displacement displacement{};

        QSignalSpy spy(&displacement, SIGNAL(changed(double)));
        displacement.set(5);

        QVERIFY(spy.count()==1);                    //wyemitowanie sygnalu
        QList<QVariant> argList = spy.takeFirst();  //wartosc przekazanego argumentu
        QVERIFY(argList.at(0) == 5);
    }

    void test_property(){
        Displacement displacement{};

        QVERIFY(displacement.property("value")==displacement.get());
        displacement.setProperty("value",10);
        QCOMPARE(displacement.get(), 10);
    }
};

QTEST_APPLESS_MAIN(displacement_test)
#include "tst_displacement_test.moc"
