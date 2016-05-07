#include <QString>
#include <QtTest>
#include <core.h>

/**
 * @brief Тесты для функциональностей предоставляемых ядром
 */
class Test_for_coreTest : public QObject
{                                                 /// Слабоватенькие тесты
    Q_OBJECT

public:
    Test_for_coreTest();
private:
    CoreOfTimetable start_test;
private Q_SLOTS:

    /// Функциональные

    void theTestForTheGrantOfRights();
    void checkAddAndRemoveRoutes();
    void verifyRouteChanges();
    void verifyTimetableChanges();

    // todo можно создать отдельный проект для модульных, а функциональые оставить здесь
    /// Модульные

    void checkFileRoute();
    void checkFileTimetable();
};

Test_for_coreTest::Test_for_coreTest()
{
}

void Test_for_coreTest::theTestForTheGrantOfRights()
{
    // todo сравнение bool с int
    QCOMPARE(start_test.informationOfTheRights(), false);
    start_test.issuanceOfRights(administrator);
    QCOMPARE(start_test.informationOfTheRights(), true);
}

// todo очень длинный тест. Может быть, разделить на checkAdd и checkRemove
void Test_for_coreTest::checkAddAndRemoveRoutes()
{
    QVERIFY_EXCEPTION_THROWN(start_test.howManyRoutes(),ThereAreNoRoutes);
    start_test.addRoute();

    // todo уточнить тип переменной. Не только здесь
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

    QCOMPARE(start_test.getItinerary(number_of_the_route),OneElement);
    QVERIFY_EXCEPTION_THROWN(start_test.getItinerary(4),RouteDoesNotExist);

    unsigned which_route_del = 2;

    start_test.deleteRoute(which_route_del);
    what_expected = 2;
    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.deleteRoute(which_route_del);

    QVERIFY_EXCEPTION_THROWN(start_test.deleteRoute(which_route_del),RouteDoesNotExist);

    what_expected = 1;
    which_route_del = 1;
    QCOMPARE(start_test.howManyRoutes(),what_expected);
    start_test.deleteRoute(which_route_del);
    what_expected = 1;
    QCOMPARE(start_test.howManyRoutes(),what_expected);

    number_of_the_route = 1;
    QCOMPARE(start_test.getItinerary(number_of_the_route),OneElement);

    number_of_the_route = 2;
    QVERIFY_EXCEPTION_THROWN(start_test.getItinerary(number_of_the_route),RouteDoesNotExist);
    number_of_the_route = 10;
    QVERIFY_EXCEPTION_THROWN(start_test.getItinerary(number_of_the_route),RouteDoesNotExist);

    int negative_number_of_the_route = -1;
    QVERIFY_EXCEPTION_THROWN(start_test.getItinerary(negative_number_of_the_route),RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.deleteRoute(negative_number_of_the_route),RouteDoesNotExist);

    negative_number_of_the_route = -256;
    QVERIFY_EXCEPTION_THROWN(start_test.getItinerary(negative_number_of_the_route),RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.deleteRoute(negative_number_of_the_route),RouteDoesNotExist);
}

void Test_for_coreTest::verifyRouteChanges()
{
    unsigned number_of_the_route = 1;
    string what_to_add = "Prospekt Prosveshenia";
    start_test.addStationInItinerary(number_of_the_route, what_to_add);

    vector<string> what_to_expected;
    what_to_expected.push_back("");
    what_to_expected.push_back("Prospekt Prosveshenia");

    QCOMPARE(start_test.getItinerary(number_of_the_route),what_to_expected);

    what_to_add = "Ozerki";

    start_test.addStationInItinerary(number_of_the_route,what_to_add);

    what_to_expected.push_back("Ozerki");

    QCOMPARE(start_test.getItinerary(number_of_the_route),what_to_expected);

    int number_of_the_station = 4;

    string what_to_replace = "Parnas";

    QVERIFY_EXCEPTION_THROWN(start_test.changeItinerary(number_of_the_route,number_of_the_station,what_to_replace),
                             StationDoesNotExist);

    number_of_the_station = -1;
    QVERIFY_EXCEPTION_THROWN(start_test.changeItinerary(number_of_the_route,number_of_the_station,what_to_replace),
                             StationDoesNotExist);

    number_of_the_station = -256;
    QVERIFY_EXCEPTION_THROWN(start_test.changeItinerary(number_of_the_route,number_of_the_station,what_to_replace),
                             StationDoesNotExist);

    number_of_the_station = 256;
    QVERIFY_EXCEPTION_THROWN(start_test.changeItinerary(number_of_the_route,number_of_the_station,what_to_replace),
                             StationDoesNotExist);


    number_of_the_station = 1;
    start_test.changeItinerary(number_of_the_route,number_of_the_station,what_to_replace);

    what_to_expected[0] = "Parnas";

    QCOMPARE(start_test.getItinerary(number_of_the_route),what_to_expected);

    number_of_the_station = 4;

    QVERIFY_EXCEPTION_THROWN(start_test.deleteStationFromItinerary(number_of_the_route,number_of_the_station),
                             StationDoesNotExist);

    number_of_the_station = 3;
    start_test.deleteStationFromItinerary(number_of_the_route,number_of_the_station);

    what_to_expected.erase(what_to_expected.begin() + 2);

    QCOMPARE(start_test.getItinerary(number_of_the_route),what_to_expected);
}

void Test_for_coreTest::verifyTimetableChanges()
{
    string name_of_the_station_1 = "Parnas";
    string working_hours_of_the_station_1 = "9.00-20.20";

    string name_of_the_station_2 = "Devyatkino";
    string working_hours_of_the_station_2 = "6.35 - 23.34";

    string name_of_the_station_3 = "Avtovo";
    string working_hours_of_the_station_3 = "7:55-20:83";


    QVERIFY_EXCEPTION_THROWN(start_test.getInformationAboutStation(name_of_the_station_1),StationDoesNotExist);

    start_test.addInformationAboutStation(name_of_the_station_1,working_hours_of_the_station_1);
    start_test.addInformationAboutStation(name_of_the_station_2,working_hours_of_the_station_2);
    start_test.addInformationAboutStation(name_of_the_station_3,working_hours_of_the_station_3);

    // todo AllItem --> Stations (например). AllItem - сложно прочитать
    vector<string> AllItem;
    AllItem.push_back("Parnas~9.00-20.20");
    AllItem.push_back("Devyatkino~6.35 - 23.34");
    AllItem.push_back("Avtovo~7:55-20:83");

    QCOMPARE(start_test.getAllItemWhichHaveDescription(),AllItem);

    QCOMPARE(start_test.getInformationAboutStation(name_of_the_station_1),working_hours_of_the_station_1);
    QCOMPARE(start_test.getInformationAboutStation(name_of_the_station_2),working_hours_of_the_station_2);
    QCOMPARE(start_test.getInformationAboutStation(name_of_the_station_3),working_hours_of_the_station_3);

    start_test.removeInformationAboutStation(name_of_the_station_1);
    start_test.removeInformationAboutStation(name_of_the_station_3);

    AllItem.erase(AllItem.begin());
    AllItem.erase(AllItem.begin()+2);

    QCOMPARE(start_test.getAllItemWhichHaveDescription(),AllItem);

    QVERIFY_EXCEPTION_THROWN(start_test.getInformationAboutStation(name_of_the_station_1),StationDoesNotExist);
    QCOMPARE(start_test.getInformationAboutStation(name_of_the_station_2),working_hours_of_the_station_2);
    QVERIFY_EXCEPTION_THROWN(start_test.getInformationAboutStation(name_of_the_station_3),StationDoesNotExist);

    QVERIFY_EXCEPTION_THROWN(start_test.getInformationAboutStation("Balalayka"),StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.removeInformationAboutStation("Balalayka"),StationDoesNotExist);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Test_for_coreTest::checkFileRoute()
{
    FileRouteInformation start_file_test;

    unsigned how_many_parts_of_line = 0;
    QCOMPARE(start_file_test.getNumberOfBlocksInTheLine(), how_many_parts_of_line);

    start_file_test.addNewBlock();
    string input_word = "Avtovo,Grazhdansky Prospekt";
    start_file_test.changeBlockFromLine(0, input_word);

    QCOMPARE(start_file_test.getFileData(0), input_word);

    start_file_test.addNewBlock();
    input_word = "Komendantskiy Prospekt,Lesnaya";
    start_file_test.changeBlockFromLine(1, input_word);

    QCOMPARE(start_file_test.getFileData(1), input_word);

    start_file_test.addNewBlock();
    input_word = "Politekhnicheskaya,Prospekt Veteranov";
    start_file_test.changeBlockFromLine(2, input_word);

    QCOMPARE(start_file_test.getFileData(2), input_word);

    how_many_parts_of_line = 3;
    QCOMPARE(start_file_test.getNumberOfBlocksInTheLine(), how_many_parts_of_line);

    start_file_test.deleteBlockFromLine(1);

    how_many_parts_of_line = 2;
    QCOMPARE(start_file_test.getNumberOfBlocksInTheLine(), how_many_parts_of_line);

    start_file_test.deleteBlockFromLine(1);

    how_many_parts_of_line = 1;
    QCOMPARE(start_file_test.getNumberOfBlocksInTheLine(), how_many_parts_of_line);

    start_file_test.deleteBlockFromLine(0);

    how_many_parts_of_line = 1;
    QCOMPARE(start_file_test.getNumberOfBlocksInTheLine(), how_many_parts_of_line);

    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData(3), ItemDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData(-1), ItemDoesNotExist);
}

void Test_for_coreTest::checkFileTimetable()
{
    FileStationInformation start_file_test;

    vector<string> Null_vector;
    QCOMPARE(start_file_test.getAllItem(), Null_vector);

    string what_add = "Peremenka 2";
    string what_value = "14.00-14.30";
    start_file_test.addNewBlockOrChangeExisting(what_add, what_value);

    what_add = "Peremenka 1";
    what_value = "12.00-12.30";
    start_file_test.addNewBlockOrChangeExisting(what_add, what_value);

    what_add = "Peremenka 3";
    what_value = "15.00-15.30";
    start_file_test.addNewBlockOrChangeExisting(what_add, what_value);

    string input_data = "Peremenka 2";
    string what_expected = "14.00-14.30";
    QCOMPARE(start_file_test.getFileData(input_data), what_expected);

    input_data = "Peremenka 1";
    what_expected = "12.00-12.30";
    QCOMPARE(start_file_test.getFileData(input_data), what_expected);

    input_data = "Peremenka 3";
    what_expected = "15.00-15.30";
    QCOMPARE(start_file_test.getFileData(input_data), what_expected);

    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData("Perepodgotovka"), ItemDoesNotExist);

    input_data = "Peremenka 1";
    start_file_test.deleteBlockFromeLine(input_data);

    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData(input_data), ItemDoesNotExist);

    input_data = "Peremenka 2";
    start_file_test.deleteBlockFromeLine(input_data);

    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData(input_data), ItemDoesNotExist);

    input_data = "Peremenka 3";
    start_file_test.deleteBlockFromeLine(input_data);

    QVERIFY_EXCEPTION_THROWN(start_file_test.getFileData(input_data), ItemDoesNotExist);
}


QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

