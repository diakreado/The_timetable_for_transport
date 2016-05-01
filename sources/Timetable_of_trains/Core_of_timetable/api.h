#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include "route_information.h"
#include "station_information.h"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

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
    virtual void issuanceOfRights(const int what_rights) = 0;

    /**
     * @return Информация о правах
     */
    virtual bool informationOfTheRights() const = 0;

    /**
     * @brief Используется для более удобного вывода маршрута
     * @param number_of_the_route - номер маршрута
     * @return Маршрут поезда в формате vector<string>
     */
    virtual vector<string> getRouteOfTrain(unsigned number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции
     * @param name_of_the_station - название станции
     * @return Информация о станции в формате string
     */
    virtual string getInformationAboutStation(const string &name_of_the_station) = 0;

    /**
     * @brief Изменение маршрута поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     */
    virtual void changeRouteTable(unsigned choice_route,unsigned choice_station, string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     */
    virtual void deleteStationFromRouteTable(unsigned choice_route,unsigned choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param what_to_add - что нужно поставить взамен
     */
    virtual void addStationInRouteTable(unsigned choice_route, string &what_to_add) = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры
     * @param name_of_the_route - название маршрута
     * @param route_description - описание маршрута
     */
    virtual void addStationInTimetable(string &name_of_the_route, string &route_description) = 0;

    /**
     * @brief Удаление информации о станции из расписания
     * @param what_remove - название станции, которую нужно удалить
     */
    virtual void removeStationFromTimetalbe(const string &what_remove)= 0;

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @return Возвращяет подходящий маршрут
     */
    virtual string findSuitableRoute(string &departure, string &arrival) = 0;

    /**
     * @brief Добавить новый маршурт в таблицу
     * @return Номер добавленного маршрута
     */
    virtual unsigned addRoute() = 0;

    /**
     * @brief Удаление маршрута
     * @param choice_route - номер маршрута, который нужно удалить
     */
    virtual void deleteRoute(unsigned choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файлах "Schedule.txt" и "Schedule.txt"
     */
    virtual void saveChanges() = 0;

    /**
     * @return Возвращяет количество существующих маршрутов
     */
    virtual unsigned howManyRoutes() = 0;

    /**
     * @return Возвращяет все элементы из контейнера, свзяанного с описанием станций
     */
    virtual vector<string> getAllItemFromTimetable() = 0;

    virtual ~API(){}
};

#endif // API_H
