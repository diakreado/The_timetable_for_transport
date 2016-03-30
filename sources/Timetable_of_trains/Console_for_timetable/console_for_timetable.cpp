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
        cout << endl << " Granted administrator privileges" << endl << endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        cout << endl << " Granted privileges a usual user" << endl << endl;
    }
    system("pause");
    menu();
}

void ConsoleForTimetable::getRoutelInformation()
{
    int choice_of_the_route;
    cout << " What route are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_route;
    cout << endl << ' ';
    try
    {
        string string_for_the_output = Core.timetableForTrain(choice_of_the_route);
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

void ConsoleForTimetable::findTheRoute()
{
    return;
}

void ConsoleForTimetable::theNextTrainArrives()
{
    return;
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
    system("pause");
    menu();
}

void ConsoleForTimetable::menu()
{
    system("cls");

    cout << " 1. To see the timetable" << endl
         << " 2. To get administrator rights" << endl;
    if (Core.informationOfTheRights() == administrator)
    {
        cout << " 3. To change the maximum number of lines in the file" << endl;
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
        theDefinitionOfAdministrator();
        break;
    }
    case '3':
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

