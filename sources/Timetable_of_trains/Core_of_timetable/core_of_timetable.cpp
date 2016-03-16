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

int Core_of_timetable::informationOnTheRights()
{
    return right;
}

vector<string>* Core_of_timetable::routOfTheTrain(int number_of_the_train)
{

}
