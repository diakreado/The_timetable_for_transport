#include <QString>
#include <QtTest>
#include <core.h>

const std::string infoAboutRoute = "Devyatkino,Grazhdansky Prospekt/Parnas,Prospekt Prosvescheniya";
const std::string infoAboutStation = "Devyatkino~5.32-0.00/Grazhdansky Prospekt~5.30-0.44/Parnas~5.47-0.00/Prospekt Prosvescheniya~5.37-0.40";


/**
 * @brief Тесты для функциональностей предоставляемых ядром
 */
class Test_for_coreTest : public QObject
{                                                 /// Слабоватенькие тесты
    Q_OBJECT

public:

    Test_for_coreTest();

private Q_SLOTS:

    void putOfRights();



    void putInfoAbouteRoutes();

    void changeStationInRoute();

    void addStationInRoute();

    void deleteStationFromRoute();

    void addRoute();

    void deleteRoute();


    void testingException();


    void putInfoAbouteStations();

    void addInfoAboutStation();

    void removeInfoAboutStation();

    void getAllStation();
};

Test_for_coreTest::Test_for_coreTest()
{
}

void Test_for_coreTest::putOfRights()
{
    CoreOfInfoAboutMetro startTest;

    QCOMPARE(startTest.getInformationOfTheRights(), Rights_of_customers::user);
    startTest.putOfRights(Rights_of_customers::administrator);
    QCOMPARE(startTest.getInformationOfTheRights(), Rights_of_customers::administrator);
}

void Test_for_coreTest::putInfoAbouteRoutes()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::vector<std::string> route1;
    route1.push_back("Devyatkino");
    route1.push_back("Grazhdansky Prospekt");

    std::vector<std::string> route123 = startTest.getRoute(1);

    std::cout << route123[0] << std::endl;

    QCOMPARE(startTest.getRoute(1), route1);

    std::vector<std::string> route2;
    route2.push_back("Parnas");
    route2.push_back("Prospekt Prosvescheniya");

    QCOMPARE(startTest.getRoute(2), route2);
}

void Test_for_coreTest::changeStationInRoute()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::vector<std::string> route;
    route.push_back("Parnas");
    route.push_back("Prospekt Prosvescheniya");

    QCOMPARE(startTest.getRoute(2), route);

    std::string new_marking = "Avtovo";
    startTest.changeStationInRoute(2, 2, new_marking);

    route[1] = new_marking;

    QCOMPARE(startTest.getRoute(2), route);
}

void Test_for_coreTest::addStationInRoute()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::vector<std::string> route;
    route.push_back("Parnas");
    route.push_back("Prospekt Prosvescheniya");

    QCOMPARE(startTest.getRoute(2), route);

    std::string what_to_add = "Avtovo";
    startTest.addStationInRoute(2, what_to_add);

    route.push_back(what_to_add);

    QCOMPARE(startTest.getRoute(2), route);
}

void Test_for_coreTest::deleteStationFromRoute()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::vector<std::string> route;
    route.push_back("Parnas");
    route.push_back("Prospekt Prosvescheniya");

    QCOMPARE(startTest.getRoute(2), route);

    startTest.deleteStationFromRoute(2,1);

    route.erase(route.begin());

    QCOMPARE(startTest.getRoute(2), route);
}

void Test_for_coreTest::addRoute()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    QCOMPARE(startTest.howManyRoutes(), 2);

    startTest.addRoute();

    QCOMPARE(startTest.howManyRoutes(), 3);


    std::string what_to_add = "Why you read this?";
    startTest.addStationInRoute(3, what_to_add);

    std::vector<std::string> route;
    route.push_back(what_to_add);

    QCOMPARE(startTest.getRoute(3), route);
}

void Test_for_coreTest::deleteRoute()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    QCOMPARE(startTest.howManyRoutes(), 2);

    startTest.deleteRoute(1);

    QCOMPARE(startTest.howManyRoutes(), 1);

    std::vector<std::string> route;
    route.push_back("Parnas");
    route.push_back("Prospekt Prosvescheniya");

    QCOMPARE(startTest.getRoute(1), route);
}

void Test_for_coreTest::testingException()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::string name_first_file = "abraradabra";
    std::string name_second_file = "ba-ba-duk";
    QVERIFY_EXCEPTION_THROWN(startTest.loadInfoFromFile(name_first_file, name_second_file), MissingFile);

    QVERIFY_EXCEPTION_THROWN(startTest.getRoute(56), RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(startTest.getRoute(0), RouteDoesNotExist);

    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation("Pargolovo"), StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation(""), StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation(1, 124), StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation(3564, 124), RouteDoesNotExist);

    QVERIFY_EXCEPTION_THROWN(startTest.changeStationInRoute(45, 1, "Pararuram"), RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(startTest.changeStationInRoute(1, 2345, "Pararuram"), StationDoesNotExist);
}

void Test_for_coreTest::putInfoAbouteStations()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::string name_of_the_station = "Grazhdansky Prospekt";
    std::string info_about_station = "5.30-0.44";

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);

    name_of_the_station = "Parnas";
    info_about_station = "5.47-0.00";

    const int number_of_the_route = 2;
    const int number_of_the_station = 1;

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);
    QCOMPARE(startTest.getInfoAboutStation(number_of_the_route, number_of_the_station), info_about_station);

    name_of_the_station = "Prospekt Prosvescheniya";
    info_about_station = "5.37-0.40";

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);
}

void Test_for_coreTest::addInfoAboutStation()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::string name_of_the_station = "Avtovo";
    std::string info_about_station = "It is Avtovo";

    startTest.addInfoAboutStation(name_of_the_station, info_about_station);

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);


    name_of_the_station = "Parnas";
    const int number_of_the_route = 2;
    const int number_of_the_station = 1;

    info_about_station = "5.47-0.00";

    QCOMPARE(startTest.getInfoAboutStation(number_of_the_route, number_of_the_station), info_about_station);
    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);

    info_about_station = "It is Parnas";

    startTest.addInfoAboutStation(number_of_the_route, number_of_the_station, info_about_station);

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);
}

void Test_for_coreTest::removeInfoAboutStation()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    std::string name_of_the_station = "Parnas";
    std::string info_about_station = "5.47-0.00";

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);

    std::string what_station_to_remove = "Parnas";
    startTest.removeInfoAboutStation(what_station_to_remove);

    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation(what_station_to_remove), StationDoesNotExist);


    name_of_the_station = "Prospekt Prosvescheniya";
    info_about_station = "5.37-0.40";

    QCOMPARE(startTest.getInfoAboutStation(name_of_the_station), info_about_station);

    const int number_of_the_station = 4;

    startTest.removeInfoAboutStation(number_of_the_station);

    QVERIFY_EXCEPTION_THROWN(startTest.getInfoAboutStation(name_of_the_station), StationDoesNotExist);
}

void Test_for_coreTest::getAllStation()
{
    CoreOfInfoAboutMetro startTest;
    startTest.putInfoAboutMetro(infoAboutRoute, infoAboutStation);

    auto AllStation = startTest.getAllStationsWhichHaveDescription();

    std::string what_get = (AllStation[2]).first;
    std::string what_expect = "Parnas";

    QCOMPARE(what_get, what_expect);

    what_get = (AllStation[2]).second;
    what_expect = "5.47-0.00";

    QCOMPARE(what_get, what_expect);

    what_get = (AllStation[3]).first;
    what_expect = "Prospekt Prosvescheniya";

    QCOMPARE(what_get, what_expect);

    what_get = (AllStation[3]).second;
    what_expect = "5.37-0.40";

    QCOMPARE(what_get, what_expect);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

