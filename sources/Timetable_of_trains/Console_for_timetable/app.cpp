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
    if (answer == 'Y' or answer == 'y')
    {
        Core.issuanceOfRights(administrator);
        cout << endl << " You got administrator rights" << endl << endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        cout << endl << " You got rights as a usual user" << endl << endl;
    }
    cout << endl << " Press Enter..." << endl;
    cin.get();
}

void ConsoleForTimetable::convenientOutputInTheConsoleForRouteTable(const unsigned choice_of_the_route)
{
    cout << endl;
    vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
    for(unsigned i = 0; i < output_for_console.size(); i++)
    {
        cout << ' ' << i+1 << '.' << output_for_console[i] << endl;  /// Выводится в виде: 1.Parnas
    }                                                               ///                    2.Prospekt Prosvescheniya
    cout << endl;
}

void ConsoleForTimetable::routeInformation()
{
    unsigned how_many_routes = 0;
    try
    {
        unsigned choice_of_the_route;
        how_many_routes = Core.howManyRoutes();
        cout << " What route are you interested in?  (Enter number: 1-" << how_many_routes << ')' << endl << endl << "-->";
        cin >> choice_of_the_route;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        convenientOutputInTheConsoleForRouteTable(choice_of_the_route);
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl
             << endl << " At the moment there are 1-" << how_many_routes << " routes" << endl
             << endl << " Enter number of the route, for example: 1" << endl;
    }
    catch(ThereAreNoRoutes)
    {
        cout << endl << " At the moment there are no routes, contact the administrator for help" << endl;
    }
    cout << endl << " Press Enter..." << endl << endl;
    cin.get();
}

void ConsoleForTimetable::findTheRoute()            /// ToDo Реализовать
{
    return;
}

void ConsoleForTimetable::whenBeginsAndEndsMovementOfTheTrainAtTheStation()
{
    unsigned how_many_routes = 0;
    try
    {
        how_many_routes = Core.howManyRoutes();
        cout << " What route are you interested in?  (Enter number: 1-" << how_many_routes << ')' << endl << endl << "-->";
        unsigned choice_of_the_route;
        cin >> choice_of_the_route;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
        for(unsigned i = 0; i < output_for_console.size(); i++)
        {
            cout << ' ' << i+1 << '.' << output_for_console[i] << endl;  /// Выводится в виде: 1.Parnas
        }                                                               ///                    2.Prospekt Prosvescheniya
        cout << endl;
        cout << " What station are you interested in?" << endl << endl << "-->";
        unsigned choice_number_of_the_station;
        cin >> choice_number_of_the_station;
        choice_number_of_the_station--;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        string choice_name_of_the_station;
        if (choice_number_of_the_station >= 0 && choice_number_of_the_station < output_for_console.size())
        {
            choice_name_of_the_station = output_for_console[choice_number_of_the_station];
        }
        else
        {
            choice_name_of_the_station = " ";
        }
        try
        {
            cout << endl << " Working hours of the station:" << endl << endl << ' ' << choice_name_of_the_station << " : "
                 << Core.getWhenStartMovementOnTheStation(choice_name_of_the_station) << endl;
        }
        catch(StationDoesNotExist)
        {
            cout << " The station does not exist";
        }

    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl
             << endl << " At the moment there are 1-" << how_many_routes << " routes" << endl
             << endl << " Enter number of the route, for example: 1" << endl;
    }
    catch(ThereAreNoRoutes)
    {
        cout << endl << " At the moment there are no routes, contact the administrator for help" << endl;
    }
    cout << endl << endl << " Press Enter..." << endl;
    cin.get();
}

void ConsoleForTimetable::changeRouteTable()
{
    if (Core.informationOfTheRights() == usual_user)  /// Пользователь не сможет вызвать метод, если он не админ
    {
        return;
    }
    unsigned how_many_routes = 0;
    int choice_action_with_route_table;
    cout << " What do you want to do with route table? ";
    try
    {
        how_many_routes = Core.howManyRoutes();
        cout << "(There are routes: 1-" << how_many_routes << ')' << endl;
    }
    catch(ThereAreNoRoutes)
    {
        cout << "(There are routes: 0)" << endl;
    }
    cout << " 1.Add route" << endl
         << " 2.Change route" << endl
         << " 3.Delete route" << endl << endl << "-->";
    cin >> choice_action_with_route_table;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(choice_action_with_route_table)
    {
    case 1:
    {
        addRoute();
        break;
    }
    case 2:
    {
        changeRoute();
        break;
    }
    case 3:
    {
        deleteRoute();
        break;
    }
    default:
    {
        cout << " You have entered something unclear" << endl;
        break;
    }
    }
    cout << endl << " Press Enter..." << endl << endl;
    cin.get();
}

void ConsoleForTimetable::addRoute()
{
    cout << endl << " Was created the route " << Core.addRoute() << endl;
}

void ConsoleForTimetable::deleteRoute()
{
    unsigned choice_route;
    cout << endl << " Which route you want to delete" << endl << endl << "-->";
    cin >> choice_route;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        Core.deleteRoute(choice_route);
        cout << endl << " The route " << choice_route << " was successfully deleted" << endl;
    }
    catch(RouteDoesNotExist)
    {
        cout << endl << " The route does not exist" << endl;
    }
    cout << endl;
}

void ConsoleForTimetable::changeRoute()
{
    bool how_successful_changes = 1;
    cout << endl << " Which do route you want to change?" << endl << endl << "-->";
    unsigned choice_route;
    cin >> choice_route;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        convenientOutputInTheConsoleForRouteTable(choice_route);
        cout << " What do you want?" << endl
             << " 1.Add station" << endl
             << " 2.Change station" << endl
             << " 3.Delete station" << endl
             << endl << "-->";
        int choice_action_with_rote;
        cin >> choice_action_with_rote;
        cout << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice_action_with_rote)
        {
        case 1:
        {
            cout << " What station do you want to add?" << endl
                 << "  (the station will be added to the end of the branch)" <<endl << endl << "-->";
            string what_to_add;
            getline(cin,what_to_add);
            cout << endl << endl;
            Core.addStationInRouteTable(choice_route,what_to_add);
            break;
        }
        case 2:
        {
            cout << " What station do you want to change?" << endl << endl << "-->";
            unsigned choice_station;
            cin >> choice_station;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << " What do you want to put in replacement?" << endl << endl << "-->";
            string what_to_replace;
            getline(cin,what_to_replace);
            cout << endl << endl;
            Core.changeRouteTable(choice_route,choice_station,what_to_replace);
            break;
        }
        case 3:
        {
            cout << " What station do you want to delete?" << endl << endl << "-->";
            unsigned choice_station;
            cin >> choice_station;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Core.deleteStationFromRouteTable(choice_route,choice_station);
            break;
        }
        default:
        {
            cout << endl << " You have entered something unclear" << endl;
            how_successful_changes = 0;
            break;
        }
        }
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl;
        how_successful_changes = 0;
    }
    catch(NotSuitableInquiry)
    {
        cout << endl << " Not the correct use of functions" << endl;
        how_successful_changes = 0;
    }
    if (how_successful_changes == 1)
    {
        cout << endl << " The changes have been well accepted" << endl;
    }
}

void ConsoleForTimetable::changeTimetable()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        return;
    }
    unsigned how_many_routes = 0;
    try
    {
        cout << " 1.Add or change information about station" << endl
             << " 2.Remove information about station" << endl << endl << "-->";
        int choice_of_action;
        cin >> choice_of_action;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// Мешает считать кучу символов(ведь нам нужен один)
        cout << endl;
        switch(choice_of_action)
        {
        case 1:
        {
            how_many_routes = Core.howManyRoutes();
            cout << " What route are you interested in?  (Enter number: 1-"
                 << how_many_routes << ')' << endl << endl << "-->";
            unsigned choice_of_the_route;
            cin >> choice_of_the_route;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            vector<string> output_for_console = Core.getRouteOfTrain(choice_of_the_route);
            for(unsigned i = 0; i < output_for_console.size(); i++)
            {
                cout << ' ' << i+1 << '.' << output_for_console[i] << endl;
            }
            cout << endl;
            string when_begin;
            string when_end;
            string what_name;
            unsigned choice_number_of_the_station;
            cout << endl << " Which information about station do you want to change?" << endl << endl << "-->";
            cin >> choice_number_of_the_station;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice_number_of_the_station--;
            if (choice_number_of_the_station >= 0 && choice_number_of_the_station < output_for_console.size())
            {
                what_name = output_for_console[choice_number_of_the_station];
            }
            else
            {
                what_name = " ";
            }
            cout << endl << " When does the station open?" << endl << endl << "-->";
            cin >> when_begin;
            cout << endl << " When does the station close?" << endl << endl << "-->";
            cin >> when_end;
            string what_value = when_begin + '-' + when_end;

            Core.addStationInTimetable(what_name,what_value);
            break;

        }
        case 2:
        {
            vector<string> AllItemFromTimetable = Core.getAllItemFromTimetable();
            for(unsigned i = 0; i < AllItemFromTimetable.size(); i++)
            {
                cout << ' ' << i+1 << '.' << AllItemFromTimetable[i] << endl;
            }
            unsigned number_of_what_remove;
            string what_remove;
            cout << endl << " What do you want to remove?" << endl << endl << "-->";
            cin >> number_of_what_remove;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            number_of_what_remove--;
            if (number_of_what_remove >= 0 && number_of_what_remove < AllItemFromTimetable.size())
            {
                what_remove = AllItemFromTimetable[number_of_what_remove];
            }
            else
            {
                what_remove = " ";
            }
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
        default:
        {
            cout << " You have entered something unclear" << endl;
            break;
        }
        }
        cout << endl << " The changes have been well accepted" << endl;
    }
    catch(RouteDoesNotExist)
    {
        cout << " The route does not exist" << endl
             << endl << " At the moment there are 1-" << how_many_routes << " routes" << endl
             << endl << " Enter number of the route, for example: 1" << endl;
    }
    catch(ThereAreNoRoutes)
    {
        cout << endl << " At the moment there are no routes, contact the administrator for help" << endl;
    }
    cout << endl << endl << " Press Enter..." << endl << endl;
    cin.get();
    cin.get();
}

void ConsoleForTimetable::saveChanges()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        return;
    }
    cout << endl << " Do you want to save changes? (Y/N)" << endl << endl << "-->";
    char answer_about_save;
    cin >> answer_about_save;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (answer_about_save == 'Y' || answer_about_save == 'y')
    {
        Core.saveChanges();
        cout << endl << " The information was saved successfully" << endl << endl;
    }
    else
    {
         cout << endl << " You refused to save" << endl << endl;
    }
    cout << " Press Enter..." << endl;
    cin.get();
}

void ConsoleForTimetable::menu()
{
    cout << " 1. The route table for trains" << endl
         << " 2. Working hours of the train" << endl
         << " 3. Get administrator rights" << endl;
    if (Core.informationOfTheRights() == administrator)
    {
        cout << " 4. Change route table for the train" << endl
             << " 5. Change timetable for the train" << endl
             << " 6. Save Changes" << endl;
    }
    cout << " 0. Exit" << endl << endl;
    char choice_in_menu;
    cout << "-->";
    cin >> choice_in_menu;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  /// Мешает считать кучу символов(ведь нам нужен один)
    cout << endl;
    switch(choice_in_menu)
    {
    case '1':
    {
        routeInformation();
        break;
    }
    case '2':
    {
        whenBeginsAndEndsMovementOfTheTrainAtTheStation();
        break;
    }
    case '3':
    {
        definitionOfAdministrator();
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
    case '6':
    {
        saveChanges();
        break;
    }
    case '0':
    {
        saveChanges();
        return;
    }
    }
    menu();
}
