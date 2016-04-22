#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include <file_route.h>
#include <file_timetable.h>
#include <algorithm>
#include <iostream>
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
    virtual vector<string> getRouteOfTrain(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода времени начала, окончания работы станции
     * @param name_of_the_station - название станции
     * @return Время начала движения в формате string
     */
    virtual string getWhenStartMovementOnTheStation(const string &name_of_the_station) = 0;

    /**
     * @brief Изменить маршрут поезда и печать изменённого в файл "Routetable.txt"
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     */
    virtual void changeRouteTable(unsigned choice_route,unsigned choice_station, string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута поезда "Routetable.txt"
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     */
    virtual void deleteStationFromRouteTable(unsigned choice_route,unsigned choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда (работа с информацией из файла "Routetable.txt")
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     */
    virtual void addStationInRouteTable(unsigned choice_route, string &what_to_add) = 0;

    /**
     * @brief Изменение станции и времени её открытия, закрытия (работа с информацией из файла "Schedule.txt")
     * @param what_change - название станции, которую нужно изменить или добавить
     * @param in_exchange - что поставить вместо (здесь также находится информация о закрытие и открыите)
     */
    virtual void changeTimetable(string &what_change, string &in_exchange) = 0;

    /**
     * @brief Удаление станции и информации о ней  из расписания (работа с информацией из файла "Schedule.txt")
     * @param what_remove - название станции, которую нужно удалить
     */
    virtual void removeStationFromTimetalbe(const string &what_remove)= 0;

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @return Возвращяет подходящий маршрут
     */
    virtual string findSuitableRoute(string &departure, string &arrival) = 0;

    virtual void addRoute() = 0;

    virtual void deleteRoute(unsigned choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файлах "Schedule.txt" и "Schedule.txt"
     */
    virtual void saveChanges() = 0;

    virtual ~API(){}
};

#endif // API_H
