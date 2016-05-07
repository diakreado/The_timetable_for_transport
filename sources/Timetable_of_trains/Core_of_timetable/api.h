#ifndef API_H
#define API_H

#include "route_information.h"
#include "station_information.h"

/**
 * @brief Абстрактный класс, которым описывается функциональность предоставляемая ядром приложения
 */
// todo дописать noexcept для методов, не генерирующих исключения
class API
{
public:

    /**
     * @brief Выдача прав
     * @param what_rights - какие права нужно выдать
     */
    //todo enum можно использовать как тип
    //virtual void issuanceOfRights(const what_rights rights) = 0;
    virtual void issuanceOfRights(const int what_rights) = 0;

    /**
     * @return Информация о правах
     * todo что значит false, а что true? Распишите поподробнее.
     */
    virtual bool informationOfTheRights() const = 0;

    /**
     * @param number_of_the_route - номер маршрута
     * @return Маршрут поезда в формате vector<string> (массив названий станций)
     */
    virtual vector<string> getItinerary(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции
     * @param name_of_the_station - название станции
     * @return Информация о станции в формате string
     */
    //todo Здесь навзвание станции строкой, а ниже по номеру. Лучше все привести к одному виду.
    virtual string getInformationAboutStation(const string &name_of_the_station) = 0;

    /**
     * @brief Изменение маршрута поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     */
    //todo Здесь станция указывается номером, а выше строкой. Лучше все привести к одному виду.
    //todo Обычно просто unsigned не используется.
    virtual void changeItinerary(unsigned choice_route,unsigned choice_station, string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     */
    //todo Здесь станция указывается номером, а выше строкой. Лучше все привести к одному виду.
    //todo Обычно просто unsigned не используется.
    virtual void deleteStationFromItinerary(unsigned choice_route,unsigned choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param what_to_add - что нужно поставить взамен
     */
    virtual void addStationInItinerary(unsigned choice_route, string &what_to_add) = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры
     * @param name_of_the_station - название маршрута
     * @param station_description - описание маршрута
     */
    //todo Все способы обращения к станции лучше привести к одному. Либо строкой, либо по номеру.
    virtual void addInformationAboutStation(string &name_of_the_station, string &station_description) = 0;

    /**
     * @brief Удаление информации о станции из расписания
     * @param what_station_to_remove - название станции, которую нужно удалить
     */
    //todo Все способы обращения к станции лучше привести к одному. Либо строкой, либо по номеру.
    virtual void removeInformationAboutStation(const string &what_station_to_remove)= 0;

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @return Возвращяет подходящий маршрут
     */
    //todo Все способы обращения к станции лучше привести к одному. Либо строкой, либо по номеру.
    virtual string findSuitableRoute(string &departure, string &arrival) = 0;

    /**
     * @brief Добавить новый маршурт в таблицу
     * @return Номер добавленного маршрута
     */
    //todo Обычно просто unsigned не используется.
    virtual unsigned addRoute() = 0;

    /**
     * @brief Удаление маршрута
     * @param choice_route - номер маршрута, который нужно удалить
     */
    virtual void deleteRoute(unsigned choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файле "metro_Saint-Petersburg"
     */
    virtual void saveChanges() = 0;

    /**
     * @return Возвращяет количество существующих маршрутов
     */
    //todo Обычно просто unsigned не используется.
    virtual unsigned howManyRoutes() = 0;

    /**
     * @return Возвращяет все элементы из контейнера, свзяанного с описанием станций
     */
    virtual vector<string> getAllItemWhichHaveDescription() = 0;

    virtual ~API(){}
};

#endif // API_H
