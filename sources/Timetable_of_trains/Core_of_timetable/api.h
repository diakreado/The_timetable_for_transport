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
     * @brief Используется для более удобного вывода маршрута
     * @param Номер маршрута
     * @return Маршрут поезда в формате vector<string>
     */
    virtual vector<string> getRouteOfTrain(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода времени начала, окончания работы станции
     * @param Название станции
     * @return Время начала движения в формате string
     */
    virtual string getWhenStartMovementOnTheStation(string const &name_of_the_station) = 0;

    /**
     * @brief Изменить маршрут поезда и печать изменённого в файл "Routetable.txt"
     * @param номер маршрута, который нужно изменить
     * @param номер станции
     * @param что нужно поставить взамен
     */
    virtual void changeRouteTable(unsigned int choice_route,unsigned int choice_station, string &what_to_replace) = 0;

    /**
     * @brief Изменение станции и времени её открытия, закрытия  и печать в файл "Schedule.txt"
     * @param название станции, которую нужно изменить или добавить
     * @param что поставить вместо (здесь также находится информация о закрытие и открыите)
     */
    virtual void changeTimetable(string &what_change, string &in_exchange) = 0;

    /**
     * @brief Удаление станции  и печать новой версии в файл "Schedule.txt"
     * @param название станции, которую нужно удалить
     */
    virtual void removeStationFromTimetalbe(string const &what_remove) = 0;

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @param time - время (возможно я уберу этот параметр во время реализации функции)
     * @return Возвращяет подходящий маршрут
     */
    virtual string findSuitableRoute(string &departure, string &arrival) = 0;

    virtual ~API(){}
};

#endif // API_H
