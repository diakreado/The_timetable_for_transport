#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include <string>
#include <vector>
#include "exception_of_core/exception_of_core.h"
#include <map>

enum class Part_of_buffer{name = 0, value = 1};

/**
 * @brief Класс отвечающий за работу с информацией свзяаной со станциями
 */
class StationsInfo
{
public:

    /**
     * @brief Получить информацию о станции
     * @param name_of_the_station - название станции, о которой хотят получить информацию
     * @return Информация о станции
     */
    std::string getInfoAboutStation(const std::string &name_of_the_station) noexcept;

    /**
     * @brief Добавляет информацию о станции, если станция уже существует, то старая информация удаляется
     * @param name_of_the_station - название станции, которую нужно добавить
     * @param station_description - информация о станции
     */
    void addInfoAboutStation(const std::string &name_of_the_station, const std::string &station_description) noexcept;

    /**
     * @brief Удаляет информацию о станции
     * @param what_station_to_remove - название станции, информацию, о которой нужно удалить
     */
    void removeInfoAboutStation(const std::string &what_station_to_remove) noexcept;

    /**
     * @return Возвраящет все станции, к которым присутствует описание
     * Этот метод используется, для вывода всех станци с описанием, чтобы потом выбрать определённую и удалить
     */
    std::vector<std::pair<std::string, std::string>> getAllStations() noexcept;

private:

    std::map<std::string,std::string> infoAboutStationsInMap;
};

#endif // FILESCHEDULE_H
