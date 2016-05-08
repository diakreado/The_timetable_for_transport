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
     */
    virtual std::vector<std::string> getItinerary(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции
     * @param name_of_the_station - название станции
     * @return Информация о станции в формате string
     */
    //todo Здесь навзвание станции строкой, а ниже по номеру. Лучше все привести к одному виду.
    virtual std::string getInformationAboutStation(const std::string &name_of_the_station) = 0;

    /**
     * @brief Изменение маршрута поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     */
    //todo Здесь станция указывается номером, а выше строкой. Лучше все привести к одному виду.
    virtual void changeItinerary(int choice_route, int choice_station, std::string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     */
    //todo Здесь станция указывается номером, а выше строкой. Лучше все привести к одному виду.
    virtual void deleteStationFromItinerary(int choice_route, int choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param what_to_add - что нужно поставить взамен
     */
    virtual void addStationInItinerary(int choice_route, std::string &what_to_add) = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры
     * @param name_of_the_station - название маршрута
     * @param station_description - описание маршрута
     */
    //todo Все способы обращения к станции лучше привести к одному. Либо строкой, либо по номеру.
    virtual void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept = 0;

    /**
     * @brief Удаление информации о станции из расписания
     * @param what_station_to_remove - название станции, которую нужно удалить
     */
    //todo Все способы обращения к станции лучше привести к одному. Либо строкой, либо по номеру.
    virtual void removeInformationAboutStation(const std::string &what_station_to_remove)= 0;

    /**
     * @brief Добавить новый маршурт в таблицу
     * @return Номер добавленного маршрута
     */
    virtual int addRoute() noexcept = 0;

    /**
     * @brief Удаление маршрута
     * @param choice_route - номер маршрута, который нужно удалить
     */
    virtual void deleteRoute(int choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файле "metro_Saint-Petersburg"
     */
    virtual void saveChanges() noexcept = 0;

    /**
     * @return Возвращяет количество существующих маршрутов
     */
    virtual int howManyRoutes() = 0;

    /**
     * @return Возвращяет все элементы из контейнера, свзяанного с описанием станций
     */
    virtual std::vector<std::string> getAllItemWhichHaveDescription() noexcept = 0;

    virtual ~API(){}
};

#endif // API_H
