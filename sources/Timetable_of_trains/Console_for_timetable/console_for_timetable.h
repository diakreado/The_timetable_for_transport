#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core_of_timetable.h>
#include <string>
#include <exception>
#include <vector>

using namespace std;

/**
 * @brief Класс служащий для работы с ядром через консоль
 */
class ConsoleForTimetable
{
public:
    ConsoleForTimetable();

private:
    void menu();

    /**
     * @brief Определяет пользователя, как администратора
     */
    void theDefinitionOfAdministrator();

    /**
     * @brief Получить информацию о поезде
     */
    void getTrainTravelInformation();

    /**
     * @brief Печатает в консоль нужный маршрут
     *
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @param time - время (возможно я уберу этот параметр во время реализации функции)
     */
    void findTheRoute(string departure,string arrival,int time);

    /**
     * @brief Печатает в консоль время прибытия ближайшего поезда на станцию
     *
     * @param station - интересующая станция
     * @param time - интересующее время
     */
    void theNextTrainArrives(string station, int time);

    /// Методы для администратора:

    /// Режим редактирования расписания
    void toEditTheTimetable();

    /// Изменить максимально возможное количество строк в файле
    void changeMaxValueOfStringInTheFile();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
