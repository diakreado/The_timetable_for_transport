#ifndef WORKWITHROUTES_H
#define WORKWITHROUTES_H

#include "work_with_info.h"

/**
 * @brief Класс, отвечающий за обработку запросов связаных с маршрутамии, с помощью консоли
 */
class WorkWithRoutes : public WorkWithInfo
{
public:

    /**
     * @brief Предоставляет информацию о запрашиваемом маршруте
     */
    void routeInformation(CoreOfTimetable &core);

/// Методы для администратора(доступны только в режиме администратора):

    /**
     * @brief Предоставляет пользователю возможность изменения маршрутов
     * Изменить маршрут, удалить маршрут, добавить маршрут
     */
    void changeItinerarys(CoreOfTimetable &core);

    /**
     * @brief Предоставляет пользователю возможность изменить конкретный маршрут
     * Добавить, удалить и переименовать станцию
     */
    void changeRoute(CoreOfTimetable &core);

    /**
     * @brief Добавляет новый маршрут(пустой) с номером, на один больше чем последний существующий
     */
    void addRoute(CoreOfTimetable &core);

    /**
     * @brief Удаляет маршрут с указаным номером, причём маршруты чей номер больше указаного сдвигаются вниз
     */
    void deleteRoute(CoreOfTimetable &core);
};

#endif // WORKWITHROUTES_H
