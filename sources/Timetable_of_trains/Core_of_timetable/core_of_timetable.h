#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include <string>
#include <vector>
#include "filetimetable.h"
#include <algorithm>

using namespace std;

enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится бизнес-логика приложения
 */
class CoreOfTimetable
{

public:
    CoreOfTimetable();

    /**
     * @brief Выдача прав
     *
     * @param Какие права нужно выдать
     */
    void issuanceOfRights(int const what_rights);

    /**
     * @return Информация о правах
     */
    bool informationOfTheRights() const;

    /**
     * @param Номер маршрута
     *
     * @return Маршрут поезда в формате string
     */
    vector<string> timetableForTrain(int const number_of_the_route);

    /**
     * @param station - станция
     * @param time - время относительно которого делается вывод
     *
     * @return время до прибытия следующего поезда
     */
    int whenWillTheTrainsArrive(string station, int time);

    /**
     * @brief Выставить максимально возможное количество строк в файле
     */
    void setMaxNumberStringInFile(int const new_max_quantity);

    /**
     * @brief Узнать максимально возможное количество строк в файле
     */
    int getMaxNumberStringInFile();

    /**
     * @brief Изменить маршрут поезда
     *
     * @param номер маршрута, который нужно изменить
     */
    void changeRouteTable(int choice_route);

    /**
     * @param departure - станция отправления
     * @param arrival  - станция назначения
     * @param time - время (возможно я уберу этот параметр во время реализации функции)
     *
     * @return Возвращяет подходящий маршрут
     */
    string findSuitableRoute(string departure,string arrival,int time);

private:
    int right;

    FileTimetable data_set;
};

/**
 * @brief Недостаточно прав
 */
class InsufficientRights : public exception {};

/**
 * @brief Рекомендованые параметры функции
 */
class RecommendedSettings : public exception {};

#endif // CORE_OF_TIMETABLE_H
