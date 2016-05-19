#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include <string>
#include <vector>
#include "exception_of_core/exception_of_core.h"

/**
 * @brief Класс отвечающий за работу с информацией свзяаной с маршрутами
 */
class RoutesInfo
{
public:

    /**
     * @param number_of_the_route - номер запрашиваемого маршрута
     * @return Запрашиваемый маршрут
     */
    std::vector<std::string> getRoute(const int number_of_the_route) noexcept;

    /**
     * @return Возвращяет информацию, о том что сколько маршрутов существует на данный момент
     */
    int getHowManyRoutes() const noexcept;

    /**
     * @brief Изменяет название станции в маршруте
     * @param number_of_the_route - номер маршрута
     * @param number_of_the_station - номер станции
     * @param new_marking - новое название станции
     */
    void changeStationInRoute(const int number_of_the_route, const int number_of_the_station, const std::string &new_marking) noexcept;

    /**
     * @brief Добавляет новую станцию в маршрут
     * @param number_of_the_route - номер маршрута
     * @param what_add - название добавляемой станции
     */
    void addStationInRoute(const int number_of_the_route, const std::string &what_add) noexcept;

    /**
     * @brief Добавляет новый маршрут
     */
    void addRoute() noexcept;

    /**
     * @brief Удаляет станцию из маршрута
     * @param number_of_the_route - номер маршрута, из которого надо удалить станцию
     * @param number_of_the_station - номер станции, которую надо удалить
     */
    void deleteStationFromRoute(const int number_of_the_route, const int number_of_the_station) noexcept;

    /**
     * @brief Удаляет маршрут
     * @param number_of_the_route - номер маршрута, который нужно удалить
     */
    void deleteRoute(const int number_of_the_route) noexcept;

private:

    std::vector<std::vector<std::string>> many_routes;
};

#endif // FILETIMETABLE_H
