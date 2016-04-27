#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится основная бизнес-логика приложения
 */
class CoreOfTimetable : public API
{

public:
    CoreOfTimetable();

    void issuanceOfRights(const int what_rights);

    bool informationOfTheRights() const;

    vector<string> getRouteOfTrain(unsigned number_of_the_route);

    string getInformationAboutStation(const string &name_of_the_station);

    void changeRouteTable(unsigned choice_route, unsigned choice_station, string &what_to_replace);

    void deleteStationFromRouteTable(unsigned choice_route, unsigned choice_station);

    void addStationInRouteTable(unsigned choice_route, string &what_to_add);

    void addStationInTimetable(string &name_of_the_route, string &route_description);

    void removeStationFromTimetalbe(const string &what_remove);

    string findSuitableRoute(string &departure, string &arrival);

    vector<string> getAllItemFromTimetable();

    unsigned addRoute();

    void deleteRoute(unsigned choice_route);

    void saveChanges();

    unsigned howManyRoutes();

private:

    int right;

    FileRoute DataSetOfTheRoute;

    FileTimetable DataSetOfTimetable;
};


class ThereAreNoRoutes : public exception {};

class NotSuitableInquiry : public exception {};

#endif // CORE_OF_TIMETABLE_H
