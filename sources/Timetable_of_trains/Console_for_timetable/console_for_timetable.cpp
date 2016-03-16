#include "console_for_timetable.h"
#include <iostream>
#include <core_of_timetable.h>

using namespace std;

Console_for_timetable::Console_for_timetable()
{
    theDefinitionOfAdministrator();
    menu();
}

void Console_for_timetable::theDefinitionOfAdministrator()
{
    char answer;
    cout << "Are you the administrator? Y/N" << endl;
    cin >> answer;
    if (answer == 'Y' or answer == 'y')
    {
        Core.issuanceOfAdministratorRights();
        cout << "Obtained administrator privileges on the schedule" << endl;
    }
}

void Console_for_timetable::seeTheTimetable(int number_of_the_train)
{
    Core.routOfTheTrain(number_of_the_train);
}

void Console_for_timetable::findTheRoute(string departure,string arrival,int time)
{

}

void Console_for_timetable::toEditTheTimetable()
{

}

void Console_for_timetable::menu()
{
    cout << "1. To see the timetable" << endl;
    if (Core.informationOnTheRights() == administrator)
    {
        cout << "2. To edit the timetable" << endl;
    }
    char choice_in_menu;
    cin >> choice_in_menu;
    switch(choice_in_menu)
    {
    case '1':
    {
        char choice_of_the_train;
        cout << "What train are you interested?" << endl;
        cin >> choice_of_the_train;
        seeTheTimetable(choice_of_the_train);
        break;
    }
    default:
        break;
    }
}
