#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится бизнес-логика приложения
 */
class CoreOfTimetable : public API
{

public:
    CoreOfTimetable();

    void issuanceOfRights(int const what_rights);

    bool informationOfTheRights() const;

    vector<string> getRouteOfTrain(int const number_of_the_route);

    string getWhenStartMovementOnTheStation(string const name_of_the_station);

    int whenWillTheTrainsArrive(string station, int time);

    int getMaxNumberStringInFile();

    void changeRouteTable(int const  choice_route,int choice_station, string what_to_replace);

    void changeTimetable(string const what_change, string const in_exchange);

    void removeStationFromTimetalbe(string const what_remove);

    string findSuitableRoute(string departure,string arrival,int time);

private:

    int right;

    FileRoute DataSetOfTheRoute;

    FileTimetable DataSetOfTimetable;
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
