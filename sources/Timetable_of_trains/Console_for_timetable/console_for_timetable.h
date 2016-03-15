#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core_of_timetable.h>
#include <string>
#include <vector>

using namespace std;

/**
* Класс служащий для работы с "Core_of_timetable" через консоль
*/
class Console_for_timetable
{
public:
    Console_for_timetable();

private:
    void theDefinitionOfAdministrator();

    vector<string>* seeTheTimetable(int number_of_the_train);

    vector<string>* findTheRoute(string departure,string arrival,int time);

    vector<string>* toEditTheTimetable();

    void menu();

    Core_of_timetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
