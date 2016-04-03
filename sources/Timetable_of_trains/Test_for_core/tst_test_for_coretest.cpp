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
    void setMaxNumberTest();
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
 * @brief Проверка правильности обработки файла(считывание полей и попытка вызвать исключение)
 */
void Test_for_coreTest::fileProcessingChecks()
{
    vector<string> buffer = start_test.getRouteOfTrain(3);

    QVERIFY2(buffer[0] == "Elbatemit","Error to get second string from file");

    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(-1), RouteDoesNotExist);
    QVERIFY_EXCEPTION_THROWN(start_test.getRouteOfTrain(50), RouteDoesNotExist);
}

/**
 * @brief Проверка правильности работы функциональности, выставления количества читаемых строк из файла
 */
void Test_for_coreTest::setMaxNumberTest()
{
    start_test.issuanceOfRights(administrator);

    int max_num = start_test.getMaxNumberStringInFile();

    start_test.setMaxNumberStringInFile(14);

    QCOMPARE(start_test.getMaxNumberStringInFile(),14);

    start_test.setMaxNumberStringInFile(max_num);

    start_test.issuanceOfRights(usual_user);

    QVERIFY_EXCEPTION_THROWN(start_test.setMaxNumberStringInFile(max_num), InsufficientRights);
}

QTEST_APPLESS_MAIN(Test_for_coreTest)

#include "tst_test_for_coretest.moc"

