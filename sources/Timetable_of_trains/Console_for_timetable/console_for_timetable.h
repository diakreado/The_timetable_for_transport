#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core_of_timetable.h>
#include <string>
#include <vector>

using namespace std;

class Console_for_timetable
{
public:
    Console_for_timetable();

private:
    void theDefinitionOfAdministrator(); /*Выдача прав на редактирование расписания*/
    vector<string>* seeTheTimetable(int number_of_the_train);  /*Выведет расписание поезда в консоль*/
    vector<string>* findTheRoute(string departure,string arrival,int time); /*Поможет подобрать необходимый маршрут*/

    Core_of_timetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
