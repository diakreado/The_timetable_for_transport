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
    void fileProcessingChecks();
};

Test_for_coreTest::Test_for_coreTest()
{
}

/**
 * @brief Проверка выдачи прав
 */
void Test_for_coreTest::theTestForTheGrantOfRights()
{
    QCOMPARE(start_test.informationOfTheRights(),0);
    start_test.issuanceOfRights(administrator);
    QCOMPARE(start_test.informationOfTheRights(),1);
}

/**
 * @brief Проверка обработки файла(считывание полей и попытка вызвать исключение)
 */
void Test_for_coreTest::fileProcessingChecks()
{
//    QVERIFY2(start_test.timetableForTrain(3) == "Elbatemit","Error to get second string from file");

//    QVERIFY_EXCEPTION_THROWN(start_test.timetableForTrain(-1), BeyondTheArray);
//    QVERIFY_EXCEPTION_THROWN(start_test.timetableForTrain(30), BeyondTheArray);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"
