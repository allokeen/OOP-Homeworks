#include "Universe.h"
#include "TestIncludes.h"
#include "ObserverMock.h"
#include "SpaceMock.h"
#include "TimeMock.h"

class Interface {
public: virtual int test() = 0;
};

//---------------

class Implementation : public Interface {
public:
    int test() override{
        return 10;
    }
};

//----------------

class MyMock : public Interface {
public:
    MOCK_METHOD0(test, int());
};

//----------------

class Dummy {
    Interface &interface;
public:
    explicit Dummy(Interface &interface) : interface(interface) {}
    int execute() { return interface.test();}
};

/*TEST(Universe, Create)
{
    StrictMock<MyMock> myMock{};
    Dummy dummy{myMock};

    EXPECT_CALL(myMock, test()).WillOnce(Return(10));        //EXPECT CALL, PRZED wywolaniem funkcji
    EXPECT_EQ(10,dummy.execute());

    //===============
    //TimeMock time{};
    //SpaceMock space{};
    //ObserverMock observer{};
    //Universe universe(time, space, observer);

    //universe.create - nie da sie przetestowac w ten sposob;
    //universe.simulate(6'000'000);
}*/

TEST(Universe, Create)
{
    StrictMock<SpaceMock> mySpaceMock{};
    StrictMock<TimeMock> myTimeMock{};
    StrictMock<ObserverMock> myObserverMock{};

    Universe universe{myTimeMock, mySpaceMock, myObserverMock};
    EXPECT_CALL(myTimeMock, create(true)).WillOnce(Return());
    EXPECT_CALL(mySpaceMock, create(11)).WillOnce(Return());
    EXPECT_CALL(mySpaceMock, dimensions()).WillOnce(Return(0));
    EXPECT_CALL(myObserverMock, remember("How many dimensions there are?", "0")).WillOnce(Return());
    universe.create();
}

TEST(Universe, Simulate)
{
    StrictMock<SpaceMock> mySpaceMock{};
    StrictMock<TimeMock> myTimeMock{};
    StrictMock<ObserverMock> myObserverMock{};
    Universe universe{myTimeMock, mySpaceMock, myObserverMock};
    EXPECT_CALL(myTimeMock, create(true)).WillOnce(Return());
    EXPECT_CALL(mySpaceMock, create(11)).WillOnce(Return());
    EXPECT_CALL(mySpaceMock, dimensions()).WillOnce(Return(0));
    EXPECT_CALL(myObserverMock, remember("How many dimensions there are?", "0")).WillOnce(Return());

    universe.create();

    EXPECT_CALL(myTimeMock, now())
    //.Times(AtLeast(1))
    .WillOnce(Return(9300000000))
    .WillOnce(Return(9900000000))
    .WillOnce(Return(13800000000))
    .WillOnce(Return(13800000001));

    EXPECT_CALL(myTimeMock, flow()).Times(AtLeast(1));
    EXPECT_CALL(myObserverMock, remember("Is there planet Earth?", "Yes!")).WillOnce(Return());
    EXPECT_CALL(myObserverMock, remember("Does life exist?", "Yes!")).WillOnce(Return());
    EXPECT_CALL(myObserverMock, remember("Have People evolved?", "Yes!")).WillOnce(Return());

    universe.simulate(13800000001);
}