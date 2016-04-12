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
     * @param Какие права нужно выдать
     */
    virtual void issuanceOfRights(int const what_rights) = 0;

    /**
     * @return Информация о правах
     */
    virtual bool informationOfTheRights() const = 0;

    /**
     * @brief Используется для более удобного вывода в консоль
     * @param Номер маршрута
     * @return Маршрут поезда в формате vector<string>
     */
    virtual vector<string> getRouteOfTrain(int const number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода в консоль
     * @param Название станции
     * @return Время начала движения в формате vector<string>
     */
    virtual string getWhenStartMovementOnTheStation(string const name_of_the_station) = 0;

    /**
     * @brief Изменить маршрут поезда
     * @param номер маршрута, который нужно изменить
     */
    virtual void changeRouteTable(unsigned int choice_route,unsigned int choice_station, string what_to_replace) = 0;

    /**
     * @brief Изменение станции в файле "Schedule.txt"
     * @param имя станции, которую нужно изменить или добавить
     * @param что поставить вместо
     */
    virtual void changeTimetable(string const what_change, string const in_exchange) = 0;

    /**
     * @brief Удаление станции из файла "Schedule.txt"
     * @param имя станции, которую нужно удалить
     */
    virtual void removeStationFromTimetalbe(string const what_remove) = 0;

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @param time - время (возможно я уберу этот параметр во время реализации функции)
     * @return Возвращяет подходящий маршрут
     */
    virtual string findSuitableRoute(string departure,string arrival) = 0;

    virtual ~API(){};
};

#endif // API_H
