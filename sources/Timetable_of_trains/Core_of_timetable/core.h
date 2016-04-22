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

    string getWhenStartMovementOnTheStation(const string &name_of_the_station);

    void changeRouteTable(unsigned choice_route, unsigned choice_station, string &what_to_replace);

    void deleteStationFromRouteTable(unsigned choice_route, unsigned choice_station);

    void addStationInRouteTable(unsigned choice_route, string &what_to_add);

    void changeTimetable(string &what_change, string &in_exchange);

    void removeStationFromTimetalbe(const string &what_remove);

    string findSuitableRoute(string &departure, string &arrival);

    unsigned addRoute();

    void deleteRoute(unsigned choice_route);

    void saveChanges();

private:

    int right;

    FileRoute DataSetOfTheRoute;

    FileTimetable DataSetOfTimetable;
};

class NotSuitableInquiry
{
public:
    string getInformation(){return whatIsWrong;}
private:
    string whatIsWrong;
};

#endif // CORE_OF_TIMETABLE_H
