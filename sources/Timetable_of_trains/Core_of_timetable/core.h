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

    void issuanceOfRights(int const what_rights);

    bool informationOfTheRights() const;

    vector<string> getRouteOfTrain(int number_of_the_route);

    string getWhenStartMovementOnTheStation(const string &name_of_the_station);

    void changeRouteTable(unsigned int choice_route, unsigned int choice_station, string &what_to_replace);

    void changeTimetable(string &what_change, string &in_exchange);

    void removeStationFromTimetalbe(string const &what_remove);

    string findSuitableRoute(string &departure, string &arrival);

private:

    int right;

    FileRoute DataSetOfTheRoute;

    FileTimetable DataSetOfTimetable;
};

#endif // CORE_OF_TIMETABLE_H
