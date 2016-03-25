#include "core_of_timetable.h"
#include <iostream>

using namespace std;

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
}

void CoreOfTimetable::issuanceOfRights(int const what_rights)
{
    if (what_rights == 1)
    {
        right = administrator;
    }
    else
    {
        right = usual_user;
    }
}

bool CoreOfTimetable::informationOfTheRights() const
{
    return right;
}

string CoreOfTimetable::timetableForTrain(int number_of_the_train) const
{
    number_of_the_train--; /// Уменьшение, для того чтобы при вызове 1 поезда выводился 0 элемент
    return data_set.getFileData(number_of_the_train);
}

string CoreOfTimetable::whenWillTheTrainsArrive(string station, int time)
{

    return 0;
}
