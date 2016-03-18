#include "core_of_timetable.h"
#include <iostream>

using namespace std;

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
}

void CoreOfTimetable::issuanceOfAdministratorRights()
{
    right = administrator;
}

int CoreOfTimetable::informationOfTheRights()
{
    return right;
}

string CoreOfTimetable::timetableForTrain(int number_of_the_train)
{

    return data_set.getFileData();
}
