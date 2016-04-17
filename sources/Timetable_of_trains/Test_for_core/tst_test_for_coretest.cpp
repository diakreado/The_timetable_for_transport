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
    void fileProcessingChecksForRouteTable();
    void fileProcessingChecksForSchedule();
};

Test_for_coreTest::Test_for_coreTest()
{
}

/**
 * @brief Проверка правильности работы функиональности, отвечающей за выдачу прав
 */
void Test_for_coreTest::theTestForTheGrantOfRights()
{
    QCOMPARE(start_test.informationOfTheRights(),0);
    start_test.issuanceOfRights(administrator);
    QCOMPARE(start_test.informationOfTheRights(),1);
}

/**
 * @brief Проверка правильности обработки файла "Routetable.txt"
 */
void Test_for_coreTest::fileProcessingChecksForRouteTable()
{
    string Input = "Privet";
    start_test.changeRouteTable(1,1,Input);
    vector<string> VectorOfOutputWord = start_test.getRouteOfTrain(1);
    string OutputWord = VectorOfOutputWord[0];
    QVERIFY2(OutputWord == Input," 1 word 1 line not work initial input (Part of Test 1) ");

    string what_to_replace = "Hello";
    start_test.changeRouteTable(1,1,what_to_replace);
    VectorOfOutputWord = start_test.getRouteOfTrain(1);
    OutputWord = VectorOfOutputWord[0];
    QVERIFY2(OutputWord == what_to_replace," 1 word 1 line not accepted changes (Part of Test 2) ");

    what_to_replace = "ABCDEFG";
    start_test.changeRouteTable(1,2,what_to_replace);
    VectorOfOutputWord = start_test.getRouteOfTrain(1);
    OutputWord = VectorOfOutputWord[1];
    QVERIFY2(OutputWord == what_to_replace," 1 word 2 line not work initial input (Part of Test 3) ");

    what_to_replace = "ParaRuram";
    start_test.changeRouteTable(2,1,what_to_replace);
    VectorOfOutputWord = start_test.getRouteOfTrain(2);
    OutputWord = VectorOfOutputWord[0];
    QVERIFY2(OutputWord == what_to_replace," 2 word 1 line not work initial input (Part of Test 4) ");

    what_to_replace = "";
    start_test.changeRouteTable(2,1,what_to_replace);
    start_test.changeRouteTable(1,2,what_to_replace);
    start_test.changeRouteTable(1,1,what_to_replace);

    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(256),RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.changeRouteTable(256,1,what_to_replace),RouteDoesNotExist);
}

/**
 * @brief Проверка правильности обработки файла "Schedule.txt"
 */
void Test_for_coreTest::fileProcessingChecksForSchedule()
{
    ///  Пока трудо тестить, не появилась функциональность редактирование расписания
    QVERIFY_EXCEPTION_THROWN(start_test.getWhenStartMovementOnTheStation("Balalayka"),StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.removeStationFromTimetalbe("Balalayka"),StationDoesNotExist);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

