#include "console_for_timetable.h"
#include <iostream>
#include <core_of_timetable.h>

using namespace std;

ConsoleForTimetable::ConsoleForTimetable()
{
    theDefinitionOfAdministrator();
    menu();
}

void ConsoleForTimetable::theDefinitionOfAdministrator()
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

void ConsoleForTimetable::seeTheTimetable(int number_of_the_train)
{
    cout << Core.timetableForTrain(number_of_the_train) << endl;
}

void ConsoleForTimetable::findTheRoute(string departure,string arrival,int time)
{
//    Реализация будет позже
}

void ConsoleForTimetable::toEditTheTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        throw InsufficientRights();
    }

}

void ConsoleForTimetable::menu()
{
    cout << "1. To see the timetable" << endl;
    if (Core.informationOfTheRights() == administrator)
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
