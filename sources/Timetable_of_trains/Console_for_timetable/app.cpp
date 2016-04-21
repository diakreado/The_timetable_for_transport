#include "app.h"
#include <iostream>
#include <core.h>

using namespace std;

ConsoleForTimetable::ConsoleForTimetable()
{
    menu();
}

void ConsoleForTimetable::definitionOfAdministrator()
{
    char answer;
    cout << " Are you the administrator? Y/N" << endl << endl << "-->";
    cin >> answer;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (answer == 'Y' or answer == 'y')         /// Вообще можно сделать, чтобы администратором становились только те,
    {                                            /// кто знает определённый пароль, но это не главная часть программы,
        Core.issuanceOfRights(administrator);      ///  поэтому мне кажется, так тоже норм
        cout << endl << " Obtained administrator privileges" << endl << endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        cout << endl << " Granted privileges a usual user" << endl << endl;
    }
    cin.get();
    menu();
}

void ConsoleForTimetable::convenientOutputInTheConsoleForRouteTable(const int choice_of_the_route)
{
    cout << endl;
    vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
    for(unsigned i = 0; i < output_for_console.size(); i++)
    {
        cout << ' ' << i+1 << '.' << output_for_console[i] << endl;  /// Выводится в виде: 1.Parnas
    }                                                               ///                    2.Prospekt Prosvescheniya
    cout << endl << endl;
}

void ConsoleForTimetable::routeInformation()
{
    try
    {
        int choice_of_the_route;
        cout << " What route are you interested?" << endl << endl << "-->";
        cin >> choice_of_the_route;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        convenientOutputInTheConsoleForRouteTable(choice_of_the_route);
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl;
    }
    cout << endl << " Press any key..." << endl << endl;
    cin.get();
    menu();
}

void ConsoleForTimetable::findTheRoute()            /// ToDo Реализовать
{
    return;
}

void ConsoleForTimetable::whenBeginsAndEndsMovementOfTheTrainAtTheStation()
{
    string choice_of_the_station;
    cout << " What station are you interested?" << endl << endl << "-->";
    cin >> choice_of_the_station;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    menu();
}

void ConsoleForTimetable::changeRouteTable()
{
    if (Core.informationOfTheRights() == usual_user)  /// Пользователь не сможет вызвать метод, если он не админ
    {
        menu();
        return;
    }
    cout << " Which route you want to change?" << endl << endl << "-->";
    int choice_route;
    cin >> choice_route;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    convenientOutputInTheConsoleForRouteTable(choice_route);
    cout << " What do you want?" << endl
         << " 1.Add station" << endl
         << " 2.Change station" << endl
         << " 3.Delete station" << endl
         << endl << "-->";
    int choice_action;
    cin >> choice_action;
    cout << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        switch (choice_action)
        {
        case 1:
        {
            cout << " What name of the station which you want to add?" <<endl << endl << "-->";
            string what_to_add;
            getline(cin,what_to_add);
            cout << endl << endl;
            Core.addStationInRouteTable(choice_route,what_to_add);
            break;
        }
        case 2:
        {
            cout << " What number of the station which should to change?" << endl << endl << "-->";
            int choice_station;
            cin >> choice_station;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << " What to put in replacements?" << endl << endl << "-->";
            string what_to_replace;
            getline(cin,what_to_replace);
            cout << endl << endl;
            Core.changeRouteTable(choice_route,choice_station,what_to_replace);
            break;
        }
        case 3:
        {
            cout << " What number of the station which should to delete?" << endl << endl << "-->";
            int choice_station;
            cin >> choice_station;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Core.deleteStationFromRouteTable(choice_route,choice_station);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl;
    }
    catch(NotSuitableInquiry)
    {
        cout << endl << " Not the correct use of functions" << endl;
    }
    cout << endl << endl << " Press any key..." << endl;
    cin.get();
    menu();
}

void ConsoleForTimetable::changeTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        menu();
        return;
    }
    cout << " 1.Remove a station and schedule" << endl
         << " 2.Add or change a station and schedule " << endl << endl << "-->";
    int choice_of_action;
    cin >> choice_of_action;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Мешает считать кучу символов(ведь нам нужен один)
    switch(choice_of_action)
    {
    case 1:
    {
        string what_remove;
        cout << endl << " What remove?" << endl << endl << "-->";
        cin >> what_remove;
        try
        {
            Core.removeStationFromTimetalbe(what_remove);
        }
        catch(StationDoesNotExist)
        {
            cout << endl << " The station does not exist" << endl;
        }
        break;
    }
    case 2:
    {
        string when_begin;
        string when_end;         /// Пока не уверен, что будет именно так, потому что метод ядра не реализован
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
    int choice_in_menu;
    cout << "-->";
    cin >> choice_in_menu;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  /// Мешает считать кучу символов(ведь нам нужен один)
    cout << endl;
    switch(choice_in_menu)
    {
    case 1:
    {
        routeInformation();
        break;
    }
    case 2:
    {
        whenBeginsAndEndsMovementOfTheTrainAtTheStation();
        break;
    }
    case 3:
    {
        definitionOfAdministrator();
        break;
    }
    case 4:
    {
        changeRouteTable();
        break;
    }
    case 5:
    {
        changeTimetable();
        break;
    }
    case 0:
    {
        return;
    }
    default:
        menu();
        break;
    }
}

