#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core.h>
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

    /**
     * @brief Показывает меню с предоставляемыми действиями
     */
    void menu();

    /**
     * @brief Показывает время начала и окончания движения
     */
    void whenBeginsAndEndsMovementOfTheTrain();

    /**
     * @brief Определяет пользователя, как администратора
     */
    void theDefinitionOfAdministrator();

    /**
     * @brief Получить информацию о маршруте
     */
    void getRoutelInformation();

    /**
     * @brief Удобный вывод маршрута в консоль
     * @param Номер маршрута
     */
    void convenientOutputInTheConsoleForRouteTable(int const choice_of_the_route);

    /**
     * @brief Печатает в консоль проложеный маршрут от одной станции до другой
     */
    void findTheRoute();

    /// Методы для администратора:

    /**
     * @brief Изменить маршруты поездов
     */
    void changeRouteTable();

    /**
     * @brief Изменить расписание
     */
    void changeTimetable();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
