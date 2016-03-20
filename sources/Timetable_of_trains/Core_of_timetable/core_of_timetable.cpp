#include "core_of_timetable.h"
#include <iostream>

using namespace std;

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
}

void CoreOfTimetable::issuanceOfRights(int what_rights)
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

int CoreOfTimetable::informationOfTheRights()
{
    return right;
}

string CoreOfTimetable::timetableForTrain(int number_of_the_train)
{
    return data_set.getFileData(number_of_the_train);
}
