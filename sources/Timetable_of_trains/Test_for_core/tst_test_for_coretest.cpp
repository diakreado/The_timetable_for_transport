#include <QString>
#include <QtTest>
#include <core_of_timetable.h>

/// Тесты для ядра
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

/// Проверка выдачи прав
void Test_for_coreTest::theTestForTheGrantOfRights()
{
    QCOMPARE(start_test.informationOfTheRights(),0);
    start_test.issuanceOfRights(administrator);
    QCOMPARE(start_test.informationOfTheRights(),1);
}

/// Проверка обработки файла(считывание полей и попытка вызвать исключение)
void Test_for_coreTest::fileProcessingChecks()
{
    QVERIFY2(start_test.timetableForTrain(0) == "Timetable","Error to get first string from file");
    QVERIFY2(start_test.timetableForTrain(1) == "Elbatemit","Error to get second string from file");

    QVERIFY_EXCEPTION_THROWN(start_test.timetableForTrain(-1), BeyondTheArray);
    QVERIFY_EXCEPTION_THROWN(start_test.timetableForTrain(30), BeyondTheArray);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"
