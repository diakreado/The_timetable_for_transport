#include <QString>
#include <QtTest>
#include <core.h>

/**
 * @brief Тесты для функциональностей продоставляемых ядром
 */
class Test_for_coreTest : public QObject
{                                                 /// Слабоватенькие тесты
    Q_OBJECT

public:
    Test_for_coreTest();
private:
    CoreOfTimetable start_test;
private Q_SLOTS:
    void theTestForTheGrantOfRights();
    void checkAddAndRemoveRoutes();
    void verifyRouteChanges();
    void verifyTimetableChanges();
};

Test_for_coreTest::Test_for_coreTest()
{
}

void Test_for_coreTest::theTestForTheGrantOfRights()
{
    QCOMPARE(start_test.informationOfTheRights(),0);
    start_test.issuanceOfRights(administrator);
    QCOMPARE(start_test.informationOfTheRights(),1);
}

void Test_for_coreTest::checkAddAndRemoveRoutes()
{
    QVERIFY_EXCEPTION_THROWN(start_test.howManyRoutes(),ThereAreNoRoutes);
    start_test.addRoute();

    unsigned what_expected = 1;

    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.addRoute();
    what_expected = 2;
    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.addRoute();
    what_expected = 3;
    QCOMPARE(start_test.howManyRoutes(),what_expected);

    vector<string> OneElement;
    OneElement.push_back("");

    unsigned number_of_the_route = 3;

    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),OneElement);
    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(4),RouteDoesNotExist);

    unsigned which_route_del = 2;

    start_test.deleteRoute(which_route_del);
    what_expected = 2;
    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.deleteRoute(which_route_del);
    what_expected = 1;
    which_route_del = 1;
    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.deleteRoute(which_route_del);
    what_expected = 1;
    QCOMPARE(start_test.howManyRoutes(),what_expected);

    number_of_the_route = 1;
    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),OneElement);

    number_of_the_route = 2;
    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(number_of_the_route),RouteDoesNotExist);
    number_of_the_route = 10;
    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(number_of_the_route),RouteDoesNotExist);
}

void Test_for_coreTest::verifyRouteChanges()
{
    unsigned number_of_the_route = 1;
    string what_to_add = "Prospekt Prosveshenia";
    start_test.addStationInRouteTable(number_of_the_route, what_to_add);

    vector<string> what_to_expected;
    what_to_expected.push_back("");
    what_to_expected.push_back("Prospekt Prosveshenia");

    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),what_to_expected);

    what_to_add = "Ozerki";

    start_test.addStationInRouteTable(number_of_the_route,what_to_add);

    what_to_expected.push_back("Ozerki");

    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),what_to_expected);

    unsigned number_of_the_station = 4;

    string what_to_replace = "Parnas";

    QVERIFY_EXCEPTION_THROWN(start_test.changeRouteTable(number_of_the_route,number_of_the_station,what_to_replace),
                             NotSuitableInquiry);

    number_of_the_station = 1;
    start_test.changeRouteTable(number_of_the_route,number_of_the_station,what_to_replace);

    what_to_expected[0] = "Parnas";

    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),what_to_expected);

    number_of_the_station = 4;

    QVERIFY_EXCEPTION_THROWN(start_test.deleteStationFromRouteTable(number_of_the_route,number_of_the_station),
                             NotSuitableInquiry);

    number_of_the_station = 3;
    start_test.deleteStationFromRouteTable(number_of_the_route,number_of_the_station);

    what_to_expected.erase(what_to_expected.begin() + 2);

    QCOMPARE(start_test.getRouteOfTrain(number_of_the_route),what_to_expected);
}

void Test_for_coreTest::verifyTimetableChanges()
{
    string name_of_the_station = "Parnas";
    string working_hours_of_the_station = "9.00-20.20";

    QVERIFY_EXCEPTION_THROWN(start_test.getWhenStartMovementOnTheStation(name_of_the_station),StationDoesNotExist);

    start_test.addStationInTimetable(name_of_the_station,working_hours_of_the_station);

    QCOMPARE(start_test.getWhenStartMovementOnTheStation(name_of_the_station),working_hours_of_the_station);

    start_test.removeStationFromTimetalbe(name_of_the_station);

    QVERIFY_EXCEPTION_THROWN(start_test.getWhenStartMovementOnTheStation(name_of_the_station),StationDoesNotExist);

    QVERIFY_EXCEPTION_THROWN(start_test.getWhenStartMovementOnTheStation("Balalayka"),StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.removeStationFromTimetalbe("Balalayka"),StationDoesNotExist);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

