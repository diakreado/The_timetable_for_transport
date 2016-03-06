#include "console_for_timetable.h"
#include <iostream>
#include <core_of_timetable.h>

using namespace std;

Console_for_timetable::Console_for_timetable()
{
    theDefinitionOfAdministrator();
}

void Console_for_timetable::theDefinitionOfAdministrator()
{
    char answer;
    cout << "Are you the administrator? Y/N" << endl;
    cin >> answer;
    if (answer == 'Y' or answer == 'y')
    {
        Core.issuanceOfTheRights();
        cout << "Obtained administrator privileges on the schedule" << endl;
    }
}

vector<string>* Console_for_timetable::seeTheTimetable(int number_of_the_train)
{

    return 0;
}
