#include "core_of_timetable.h"
#include <iostream>

using namespace std;



Core_of_timetable::Core_of_timetable()
{
    right = usual_user;
}

void Core_of_timetable::issuanceOfAdministratorRights()
{
    right = administrator;
}

int Core_of_timetable::informationOfTheRights()
{
    return right;
}

vector<string>* Core_of_timetable::timetableForTrain(int number_of_the_train)
{
//    Скорее всего будет файл, из которого эта инфомрация будет добываться
    return 0;
}
