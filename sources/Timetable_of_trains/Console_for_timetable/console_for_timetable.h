#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H
using namespace std;
#include <string>
#include <vector>

class Console_for_timetable
{
public:
    Console_for_timetable();
    void theDefinitionOfAdministrator(); /*Выдача прав на редактирование расписания*/
    void seeTheTimetable();  /*Выведет расписание в консоль*/
    vector<string>* seeTheRoutOfTheTrain(int number_of_the_train); /*Выведет маршрут заданого поезда в консоль*/
    vector<string>* findTheRoute(string departure,string arrival,int time); /*Поможет подобрать необходимый маршрут*/
};

#endif // CONSOLE_FOR_TIMETABLE_H
