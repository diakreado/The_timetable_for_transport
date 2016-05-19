#ifndef WORKWITHSTATIONS_H
#define WORKWITHSTATIONS_H

#include "work_with_info.h"

/**
 * @brief Класс, отвечающий за обработку запросов связаных со станциями, с помощью консоли
 */
class WorkWithStations : public WorkWithInfo
{
public:

    /**
     * @brief В зависимости от запрашиваемой станции, печатает информацию о ней
     */
    void informationAboutStation(CoreOfInfoAboutMetro &core);

/// Методы для администратора(доступны только в режиме администратора):

    /**
     * @brief Предоставляет пользователю возможность изменения информации о станции
     * Добавить информацию о станции, удалить её
     */
    void changeInfoAboutStation(CoreOfInfoAboutMetro &core);

    /**
     * @brief Добавить информацию о станции
     */
    void addOrChangeInformationAboutStation(CoreOfInfoAboutMetro &core);

    /**
     * @brief Удалить информацию о станции
     */
    void removeInformationAboutStation(CoreOfInfoAboutMetro &core);
};

#endif // WORKWITHSTATIONS_H
