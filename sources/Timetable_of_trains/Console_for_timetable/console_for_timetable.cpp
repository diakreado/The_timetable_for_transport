#include "console_for_timetable.h"
#include <iostream>
#include <core_of_timetable.h>

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
        cout << " Granted administrator privileges" << endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        cout << " Granted privileges a usual user" << endl;
    }
    menu();
}

void ConsoleForTimetable::getTrainTravelInformation()
{
    int choice_of_the_train;
    cout << " What train are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_train;
    cout << endl << ' ';
    try
    {
        cout << Core.timetableForTrain(choice_of_the_train) << endl;
    }
    catch(FailedToOpen)
    {
        cout << " Error when opening file" << endl;
    }
    catch(BeyondTheArray)
    {
        cout << " Error output abroad" << endl;
    }
    cout << endl << ' ';
    system("pause");
    menu();
}

void ConsoleForTimetable::findTheRoute(string departure,string arrival,int time)
{
    //    Реализация будет позже
}

void ConsoleForTimetable::toEditTheTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
       cout << " Insufficient rights" << endl << endl << ' '; /*Недостаточно прав*/
       system("pause");
    }


    menu();
}

void ConsoleForTimetable::menu()
{
    system("cls");

    cout << " 1. To see the timetable" << endl
         << " 2. To get administrator rights" << endl;
    if (Core.informationOfTheRights() == administrator)
    {
        cout << " 3. To edit the timetable" << endl;
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
        getTrainTravelInformation();
        break;
    }
    case '2':
    {
        theDefinitionOfAdministrator();
        break;
    }
    case '3':
    {
        toEditTheTimetable();
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
