#ifndef API_H
#define API_H

#include "route_information.h"
#include "station_information.h"
#include "exception_of_core.h"

enum class rights_of_customers{user = 0, administrator = 1};

/**
 * @brief Абстрактный класс, которым описывается функциональность предоставляемая ядром приложения
 */
class API
{
public:

    /**
     * @brief Выдача прав
     * @param what_rights - какие права нужно выдать
     */
    virtual void issuanceOfRights(const rights_of_customers rights) noexcept = 0;

    /**
     * @return Информация о правах
     */
    virtual rights_of_customers informationOfTheRights() const noexcept = 0;

    /**
     * @param number_of_the_route - номер маршрута
     * @return Маршрут поезда в формате vector<string> (массив названий станций)
     *
     * Может быть брошено исключение RouteDoesNotExist
     */
    virtual std::vector<std::string> getItinerary(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции
     * @param name_of_the_station - название станции
     * @return Информация о станции в формате string, здесь возвращяется только информация о станции,
     *  так как название станции заранее известно
     *
     * Может быть брошено исключение StationDoesNotExist
     */
    virtual std::string getInformationAboutStation(const std::string &name_of_the_station) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции, аналог предидущего
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @return Информация о станции в формате string, здесь кроме информации о станции возвращяется и название станции,
     *  т.е. string  в формате "Parnas : Info", сделанно потому что пользователь может не знать о станции
     *
     * Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual std::string getInformationAboutStation(int choice_route, int choice_station) = 0;

    /**
     * @brief Изменение маршрута поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     *
     * Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual void changeItinerary(int choice_route, int choice_station, std::string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     *
     * Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual void deleteStationFromItinerary(int choice_route, int choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param what_to_add - что нужно поставить взамен
     *
     * Может быть брошено исключение RouteDoesNotExist
     */
    virtual void addStationInItinerary(int choice_route, std::string &what_to_add) = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры
     * @param name_of_the_station - название маршрута
     * @param station_description - описание маршрута
     */
    virtual void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры, альтернативный путь, в котором название станции получаем
     * из информации о маршрутах
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param station_description - описание маршрута
     *
     * Может быть брошено исключение RouteDoesNotExist
     */
    virtual void addInformationAboutStation(int choice_route, int choice_station, std::string &station_description) = 0;


    /**
     * @brief Удаление информации о станции из расписания
     * @param what_station_to_remove - название станции, которую нужно удалить
     *
     * Может быть брошено исключение StationDoesNotExist
     */
    virtual void removeInformationAboutStation(const std::string &what_station_to_remove)= 0;

    /**
     * @brief Удаление информации о станции из расписания
     * @param choice_station - номер станции, только в данном случае номер маршрута берётся не из информации о маршрутах,
     * а из списка станций, о которых существует информация (список можно получить с помощью getAllStations...)
     *
     * Может быть брошено исключение StationDoesNotExist
     */
    virtual void removeInformationAboutStation(int choice_station)= 0;

    /**
     * @brief Добавить новый маршурт в таблицу
     * @return Номер добавленного маршрута
     */
    virtual int addRoute() noexcept = 0;

    /**
     * @brief Удаление маршрута
     * @param choice_route - номер маршрута, который нужно удалить
     *
     * Может быть брошено исключение RouteDoesNotExist
     */
    virtual void deleteRoute(int choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файле "metro_Saint-Petersburg"
     */
    virtual void saveChanges() noexcept = 0;

    /**
     * @return Возвращяет количество существующих маршрутов
     *
     * Может быть брошено исключение ThereAreNoRoutes
     */
    virtual int howManyRoutes() = 0;

    /**
     * @return Возвращяет все элементы из контейнера, свзяанного с описанием станций
     */
    virtual std::vector<std::string> getAllStationsWhichHaveDescription() noexcept = 0;

    virtual ~API(){}
};

#endif // API_H
