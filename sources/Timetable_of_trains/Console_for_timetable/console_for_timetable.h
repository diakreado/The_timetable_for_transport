#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core_of_timetable.h>
#include <string>
#include <exception>
#include <vector>

using namespace std;


/// Класс служащий для работы с ядром через консоль
class ConsoleForTimetable
{
public:
    ConsoleForTimetable();

private:
    void menu();

    /// Определяет пользователя, как администратора
    void theDefinitionOfAdministrator();

    /// Получить информацию о поезде
    void getTrainTravelInformation();

    /// Найти нужный маршрут по времени и месту отправки и прибывания
    void findTheRoute(string departure,string arrival,int time);

    /// Время прибытия ближайшего поезда на станцию
    void theNextTrainArrives(string station, int time);

    /// Режим редактирования расписания
    void toEditTheTimetable();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
