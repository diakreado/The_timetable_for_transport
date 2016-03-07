#include "core_of_timetable.h"
#include <iostream>

using namespace std;



Core_of_timetable::Core_of_timetable()
{
    right = usual_user;
}

void Core_of_timetable::issuanceOfTheRights()
{
    right = administrator;
}

int Core_of_timetable::informationOnTheRights()
{
    return right;
}
