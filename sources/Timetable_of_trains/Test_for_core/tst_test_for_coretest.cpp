#include <QString>
#include <QtTest>
#include <core.h>

/**
 * @brief Тесты для функциональностей продоставляемых ядром
 */
class Test_for_coreTest : public QObject
{
    Q_OBJECT

public:
    Test_for_coreTest();
private:
    CoreOfTimetable start_test;
private Q_SLOTS:
    void theTestForTheGrantOfRights();
    void fileProcessingChecksForRouteTable();       /// Слабоватенькие тесты
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
   vector<string> Null;
   QCOMPARE(start_test.getRouteOfTrain(1),Null);
   QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(256),RouteDoesNotExist);
}

/**
 * @brief Проверка правильности обработки файла "Schedule.txt"
 */
void Test_for_coreTest::fileProcessingChecksForSchedule()
{
    QVERIFY_EXCEPTION_THROWN(start_test.getWhenStartMovementOnTheStation("Balalayka"),StationDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.removeStationFromTimetalbe("Balalayka"),StationDoesNotExist);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

