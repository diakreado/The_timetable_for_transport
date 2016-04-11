#include "app.h"
#include <iostream>
#include <core.h>

using namespace std;

ConsoleForTimetable::ConsoleForTimetable()
{
    menu();
}

void ConsoleForTimetable::theDefinitionOfAdministrator()
{
    char answer;
    cout << " Are you the administrator? Y/N" << endl << endl << "-->";
    cin >> answer;
    if (answer == 'Y' or answer == 'y')
    {
        Core.issuanceOfRights(administrator);
        cout << endl << " Obtained administrator privileges" << endl << endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        cout << endl << " Granted privileges a usual user" << endl << endl;
    }
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::convenientOutputInTheConsoleForRouteTable(const int choice_of_the_route)
{
    cout << endl;
    vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
    for(unsigned int i = 0; i < output_for_console.size(); i++)
    {
        cout << ' ' << i+1 << '.' << output_for_console[i] << endl;
    }
    cout << endl << endl;
}

void ConsoleForTimetable::getRoutelInformation()
{
    int choice_of_the_route;
    cout << " What route are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_route;
    try
    {
    convenientOutputInTheConsoleForRouteTable(choice_of_the_route);
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl;
    }
    cout << endl << " Press any key..." << endl;
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::findTheRoute()
{
    return;
}

void ConsoleForTimetable::whenBeginsAndEndsMovementOfTheTrain()
{
    string choice_of_the_station;
    cout << " What station are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_station;
    cout << endl;
    try
    {
        cout << endl << " Time of the work station:" << endl << endl << ' ' << choice_of_the_station << " : "
             << Core.getWhenStartMovementOnTheStation(choice_of_the_station) << endl;
    }
    catch(StationDoesNotExist)
    {
        cout << " The station does not exist";
    }
    cout << endl << endl << " Press any key..." << endl;
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::changeRouteTable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        menu();
    }
    cout << " Which route you want to change?" << endl << endl << "-->";
    int choice_route;
    cin >> choice_route;
    try
    {
        convenientOutputInTheConsoleForRouteTable(choice_route);
        cout << " What station to change?" << endl << endl << "-->";
        int choice_station;
        cin >> choice_station;
        cout << endl;
        cout << " What to put in replacements?" << endl << endl << "-->";
        string what_to_replace;
        cin.get();
        getline(cin,what_to_replace);
        cout << endl << endl;
        Core.changeRouteTable(choice_route,choice_station,what_to_replace);
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl;
    }
    cout << endl << endl << " Press any key..." << endl;
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::changeTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        menu();
    }
    cout << " 1.Remove a station and schedule" << endl << " 2.Add or change a station and schedule " << endl << endl << "-->";
    char choice_of_action;
    cin >> choice_of_action;
    switch(choice_of_action)
    {
    case '1':
    {
        string what_remove;
        cout << endl << " What remove?" << endl << endl << "-->";
        cin >> what_remove;
        Core.removeStationFromTimetalbe(what_remove);
        break;
    }
    case '2':
    {
        string when_begin;
        string when_end;
        string what_change;
        cout << endl << " Which station change?" << endl << endl << "-->";
        cin >> what_change;
        cout << endl << " When station begin work?" << endl << endl << "-->";
        cin >> when_begin;
        cout << endl << " When station end work?" << endl << endl << "-->";
        cin >> when_end;
        string what_add = when_begin + when_end;
        Core.changeTimetable(what_change,what_add);
        break;
    }
    default:
    {
        cout << " You have entered something incomprehensible" << endl;

    }
    }
    cout << endl << " Press any key..." << endl;
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::menu()
{
    //system("cls"); // Очень удобная команда, но работает только под Windows
    cout << " 1. To see the route table for trains" << endl
         << " 2. To see when begins and ends movement of the train" << endl
         << " 3. To get administrator rights" << endl;
    if (Core.informationOfTheRights() == administrator)
    {
        cout << " 4. Change route table for the train" << endl
             << " 5. Change timetable for the train" << endl;
    }
    cout << " 0. Exit" << endl << endl;
    char choice_in_menu;
    cout << "-->";
    cin >> choice_in_menu;
    cout << endl;
    switch(choice_in_menu)
    {
    case '1':
    {
        getRoutelInformation();
        break;
    }
    case '2':
    {
        whenBeginsAndEndsMovementOfTheTrain();
        break;
    }
    case '3':
    {
        theDefinitionOfAdministrator();
        break;
    }
    case '4':
    {
        changeRouteTable();
        break;
    }
    case '5':
    {
        changeTimetable();
        break;
    }
    case '0':
    {
        return;
    }
    default:
        menu();
        break;
    }
}

