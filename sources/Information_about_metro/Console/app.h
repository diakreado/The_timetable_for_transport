#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include "workwithinfo/work_with_routes.h"
#include "workwithinfo/work_with_stations.h"

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
     * @return Возвращяет "fals", когда пользователь хочет выйти из приложения
     */
    bool menu();

    /**
     * @brief Выдача прав администратора или обычного пользователя
     */
    void definitionOfAdministrator();

    /**
     * @return Символ считаный из консоли
     */
    char getCharFromConsole();


/// Методы для администратора(доступны только в режиме администратора):

    /**
     * @brief Все изменения совершенные пользователем записываются в файл
     */
    void saveChanges();

    void loadFromFile();

    CoreOfInfoAboutMetro core;

    WorkWithRoutes route_info;

    WorkWithStations stations_info;
};

#endif // CONSOLE_FOR_TIMETABLE_H
