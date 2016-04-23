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
     * @brief Вывод в консоль меню с предоставляемыми возможностями
     */
    void menu();

    /**
     * @brief В зависимости от запрашиваемой станции, печатает время начала и окончания её работы
     */
    void whenBeginsAndEndsMovementOfTheTrainAtTheStation();

    /**
     * @brief Выдача прав или администратора, или обычного юзера
     */
    void definitionOfAdministrator();

    /**
     * @brief Предоставляет информация о запрашиваемом маршруте
     */
    void routeInformation();

    /**
     * @brief Удобный вывод маршрута в консоль
     * @param Номер маршрута
     * @return Количество существующих маршрутов
     */
    void convenientOutputInTheConsoleForRouteTable(const unsigned choice_of_the_route);

    /**
     * @brief Печатает в консоль проложеный маршрут от одной станции до другой
     * Метод будет реализован при наличие свободного времени
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

    /**
     * @brief Изменяет конкретный маршрут
     */
    void changeRoute();

    /**
     * @brief Добавляет новый маршрут(пустой) с номером, на один больше чем последний существующий
     */
    void addRoute();

    /**
     * @brief Удаляет маршрут с указаным номером, причём маршруты чей номер больше указаного сдвигаються вниз
     */
    void deleteRoute();

    /**
     * @brief Все изменения записываются в файл
     */
    void saveChanges();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
