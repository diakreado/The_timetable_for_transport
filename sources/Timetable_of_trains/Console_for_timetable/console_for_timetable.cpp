#include "console_for_timetable.h"
#include <iostream>
#include <core_of_timetable.h>
#include <algorithm>

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
        string string_for_the_output = Core.timetableForTrain(choice_of_the_train);
        for_each(string_for_the_output.begin(), string_for_the_output.end(),
                 [](char symbol_for_the_output)   /// Здесь описанно то, что должно выполниться для каждого элемента
        {
            cout << symbol_for_the_output;      /// Переводится строка если обнаружен пробел
            if (symbol_for_the_output == ' ')  /// Это делается для того, чтобы облегчить читаемость маршрута
            {
                cout << endl << ' ';
            }
        });                                /// Конец for_each

    }
    catch(FailedToOpen)
    {
        cout << " Error when opening file";
    }
    catch(BeyondTheArray)
    {
        cout << " Error output abroad";
    }
    cout << endl <<endl << ' ';
    system("pause");
    menu();
}

void ConsoleForTimetable::findTheRoute(string departure,string arrival,int time)
{
    //    Реализация будет позже
    return;
}

void ConsoleForTimetable::theNextTrainArrives(string station, int time)
{
    //    Реализация будет позже
    return;
}

void ConsoleForTimetable::toEditTheTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
       menu();
    }


    menu();
}

void ConsoleForTimetable::changeMaxValueOfStringInTheFile()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        menu();
    }
    int new_max_number;
/*    cout << " The maximum number of lines in the file is " << CoreOfTimetable::max_number << endl; */ ///  Переделать
    cout << " What value to set the maximum?" << endl << endl << "-->";
    cin >> new_max_number;
    cout << endl << ' ';
    try
    {
/*        Core.setMaxNumberOfStringInTheFile(new_max_number);*/ ///  Переделать
    }
    catch(InsufficientRights)
    {
        cout << " Insufficient rights to perform the action" << endl << endl;
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
        cout << " 3. To edit the timetable" << endl
        << " 4. To change the maximum number of lines in the file" << endl;
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
    case '4':
    {
        changeMaxValueOfStringInTheFile();
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
