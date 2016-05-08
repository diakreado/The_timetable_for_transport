#ifndef CONSOLE_FOR_TIMETABLE_H
#define CONSOLE_FOR_TIMETABLE_H

#include <core.h>
#include <algorithm>

/**
 * @brief Класс служащий для работы с ядром через консоль
 */
class ConsoleForTimetable
{
public:
    /**
     * @brief Вывод в консоль меню с предоставляемыми возможностями
     */
    bool menu();

private:

    /**
     * @return Символ считаный из консоли
     */
    char getCharFromConsole();

    /**
     * @return Число считаное из консоли
     */
    int getIntFromConsole();

    /**
     * @brief В зависимости от запрашиваемой станции, печатает информацию о ней
     */
    void informationAboutStation();

    /**
     * @brief Выдача прав администратора или обычного пользователя
     */
    void definitionOfAdministrator();

    /**
     * @brief Предоставляет информацию о запрашиваемом маршруте
     */
    void routeInformation();

    /// Методы для администратора(доступны только в режиме администратора):

    /**
     * @brief Предоставляет пользователю возможность изменения маршрутов
     * Изменить маршрут, удалить маршрут, добавить маршрут
     */
    void changeItinerarys();

    /**
     * @brief Предоставляет пользователю возможность изменения информации о станции
     * Добавить информацию о станции, удалить её
     */
    void changeInfoAboutStation();

    /**
     * @brief Предоставляет пользователю возможность изменить конкретный маршрут
     * Добавить, удалить и переименовать станцию
     */
    void changeRoute();

    /**
     * @brief Добавляет новый маршрут(пустой) с номером, на один больше чем последний существующий
     */
    void addRoute();

    /**
     * @brief Удаляет маршрут с указаным номером, причём маршруты чей номер больше указаного сдвигаются вниз
     */
    void deleteRoute();

    /**
     * @brief Все изменения совершенные пользователем записываются в файл
     */
    void saveChanges();

    CoreOfTimetable Core;
};

#endif // CONSOLE_FOR_TIMETABLE_H
