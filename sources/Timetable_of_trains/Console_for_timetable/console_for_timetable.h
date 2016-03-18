#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core_of_timetable.h>
#include <string>
#include <exception>
#include <vector>

using namespace std;

/**
* Класс служащий для работы с ядром через консоль
*/
class ConsoleForTimetable
{
public:
    ConsoleForTimetable();

private:
    void theDefinitionOfAdministrator(); /*Выдача прав администратору*/

    void seeTheTimetable(); /*Посмотерть расписание*/

    void findTheRoute(string departure,string arrival,int time); /*Найти нужный маршрут*/

    void toEditTheTimetable(); /*Добавить расписание*/

    void menu(); /*Вызов меню*/

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H

class InsufficientRights : public exception {}; /*Недостаточно прав*/

