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
    try
    {
        vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
        for(unsigned int i = 0; i < output_for_console.size(); i++)
        {
            cout << ' ' << i+1 << '.' << output_for_console[i] << endl;
        }
    }
    catch(FailedToOpen)
    {
        cout << " Error when opening file";
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist";
    }
    cout << endl << endl;
}

void ConsoleForTimetable::convenientOutputInTheConsoleForTimetable(string const choice_of_the_route)
{
    cout << endl;
    try
    {
        cout << Core.getWhenStartMovementOnTheStation(choice_of_the_route) << endl;
    }
    catch(FailedToOpen)
    {
        cout << " Error when opening file";
    }
    catch(RouteDoesNotExist)
    {
        cout << " The station does not exist";
    }
    cout << endl << endl;
}

void ConsoleForTimetable::getRoutelInformation()
{
    int choice_of_the_route;
    cout << " What route are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_route;
    convenientOutputInTheConsoleForRouteTable(choice_of_the_route);
    cout << endl << " Press any key..." << endl;
    cin.get();
    cin.get();
    menu();
}

void ConsoleForTimetable::findTheRoute()
{
    return;
}

void ConsoleForTimetable::theNextTrainArrives()
{
    return;
}

void ConsoleForTimetable::whenBeginsAndEndsMovementOfTheTrain()
{
    string choice_of_the_station;
    cout << " What station are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_station;
    convenientOutputInTheConsoleForTimetable(choice_of_the_station);
    cout << endl << " Press any key..." << endl;
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
    menu();
}

void ConsoleForTimetable::changeMaxValueOfStringInTheFile()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        menu();
    }
    int new_max_number;
    cout << " The maximum number of lines in the file is:      " << Core.getMaxNumberStringInFile() << endl << endl;
    cout << " What value to set the maximum?" << endl << endl << "-->";
    cin >> new_max_number;
    cout << endl;
    try
    {
        Core.setMaxNumberStringInFile(new_max_number);
    }
    catch(InsufficientRights)
    {
        cout << " Insufficient rights to perform the action" << endl << endl;
    }
    catch(RecommendedSettings)
    {
        cout << " Put the number more" << endl << endl;
    }
    menu();
}

void ConsoleForTimetable::menu()
{
//    system("cls"); // Очень удобная команда, но работает только под Windows
    cout << " 1. To see the route table for trains" << endl
         << " 2. To see when begins and ends movement of the train" << endl
         << " 3. To get administrator rights" << endl;
    if (Core.informationOfTheRights() == administrator)
    {
        cout << " 4. To change the maximum number of lines in the file" << endl
             << " 5. Change route table for the train" << endl;
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
        changeMaxValueOfStringInTheFile();
        break;
    }
    case '5':
    {
        changeRouteTable();
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

