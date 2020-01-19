#include <QtTest>
#include "demo.h"

// add necessary includes here

class demo_testing : public QObject
{
    Q_OBJECT

private slots:
    void test_case1(){
        demo Demo{};
        QCOMPARE(Demo.sum(1,2),3);
    }
};


QTEST_APPLESS_MAIN(demo_testing)

#include "tst_demo_testing.moc"
