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
     * @brief Удобный вывод времени начала/конца движения в консоль
     * @param Название станции
     */
    void convenientOutputInTheConsoleForTimetable(string const choice_of_the_station);

    /**
     * @brief Печатает в консоль проложеный маршрут от одной станции до другой
     */
    void findTheRoute();

    /**
     * @brief Печатает в консоль время прибытия ближайшего поезда на станцию
     */
    void theNextTrainArrives();

    /// Методы для администратора:

    /**
     * @brief Изменить максимально возможное количество строк в файле(реализовал метод и теперь сомневаюсь в его надобности)
     */
    void changeMaxValueOfStringInTheFile();

    /**
     * @brief Изменить маршруты поездов
     */
    void changeRouteTable();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
