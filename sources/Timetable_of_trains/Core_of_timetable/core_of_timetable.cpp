#include "core_of_timetable.h"
#include <iostream>

using namespace std;



Core_of_timetable::Core_of_timetable()
{
    right = usual_user;
    cout << "123" << endl;

}

void Core_of_timetable::issuanceOfTheRights()
{
    right = administrator;
    cout << "321" << endl;
}
