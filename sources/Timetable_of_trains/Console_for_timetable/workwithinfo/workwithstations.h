#ifndef WORKWITHSTATIONS_H
#define WORKWITHSTATIONS_H

#include "workwithinfo.h"

/**
 * @brief Класс, отвечающий за обработку запросов связаных со станциями, с помощью консоли
 */
class WorkWithStations : public WorkWithInfo
{
public:

    /**
     * @brief В зависимости от запрашиваемой станции, печатает информацию о ней
     */
    void informationAboutStation(CoreOfTimetable &core);

/// Методы для администратора(доступны только в режиме администратора):

    /**
     * @brief Предоставляет пользователю возможность изменения информации о станции
     * Добавить информацию о станции, удалить её
     */
    void changeInfoAboutStation(CoreOfTimetable &core);

    /**
     * @brief Добавить информацию о станции
     */
    void addOrChangeInformationAboutStation(CoreOfTimetable &core);

    /**
     * @brief Удалить информацию о станции
     */
    void removeInformationAboutStation(CoreOfTimetable &core);
};

#endif // WORKWITHSTATIONS_H
