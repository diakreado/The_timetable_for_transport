#include "app.h"

ConsoleForTimetable::ConsoleForTimetable()
{
    try
    {
        while(menu()) {}
    }
    catch(std::exception &Error)
    {
        std::cout << " Exception :  " << Error.what() << std::endl << std::endl;
    }
    catch(...)
    {
        std::cout << " Unspecified error" << std::endl << std::endl;
    }

    std::cout << "  Come back soon!" << std::endl;
}

char ConsoleForTimetable::getCharFromConsole()
{
    char symbol;

    std::cin >> symbol;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  /// Мешает считать кучу символов(ведь нам нужен один)

    return symbol;
}

int ConsoleForTimetable::getIntFromConsole()
{
    int number;

    std::cin >> number;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  /// Мешает считать кучу символов(ведь нам нужен один)

    return number;
}

void ConsoleForTimetable::displayRoute(std::vector<std::string> &output_for_console)
{
    for(unsigned i = 0; i < output_for_console.size(); i++)
    {
        std::cout << ' ' << i+1 << '.' << output_for_console[i] << std::endl;  /// Выводится в виде: 1.Parnas
    }                                                               ///                    2.Prospekt Prosvescheniya
    std::cout << std::endl;
}

void ConsoleForTimetable::definitionOfAdministrator()
{
    std::cout << " Are you the administrator? Y/N" << std::endl << std::endl << "-->";
    char answer_about_rights = getCharFromConsole();

    if (answer_about_rights == 'Y' or answer_about_rights == 'y')
    {
        Core.issuanceOfRights(administrator);
        std::cout << std::endl << " You got administrator rights" << std::endl << std::endl;
    }
    else
    {
        Core.issuanceOfRights(usual_user);
        std::cout << std::endl << " You got rights as a usual user" << std::endl << std::endl;
    }

    std::cout << std::endl << " Press Enter..." << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::routeInformation()
{
    unsigned how_many_routes;
    try
    {
        how_many_routes = Core.howManyRoutes();

        std::cout << " What route are you interested in?  (Enter number: 1-" << how_many_routes << ')' << std::endl << std::endl << "-->";
        int choice_of_the_route =  getIntFromConsole();
        std::cout << std::endl;

        std::vector<std::string> output_for_console = Core.getItinerary(choice_of_the_route);

        displayRoute(output_for_console);
    }
    catch(RouteDoesNotExist&)
    {
        std::cout << " The route does not exist" << std::endl
             << std::endl << " At the moment there are 1-" << how_many_routes << " routes" << std::endl
             << std::endl << " Enter number of the route, for example: 1" << std::endl;
    }
    catch(ThereAreNoRoutes&)
    {
        std::cout << std::endl << " At the moment there are no routes, contact the administrator for help" << std::endl;
    }

    std::cout << std::endl << " Press Enter..." << std::endl << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::informationAboutStation()
{
    unsigned how_many_routes = 0;
    try
    {
        how_many_routes = Core.howManyRoutes();

        std::cout << " What route are you interested in?  (Enter number: 1-" << how_many_routes << ')' << std::endl << std::endl << "-->";
        int choice_of_the_route = getIntFromConsole();
        std::cout << std::endl;

        std::vector<std::string> output_for_console = Core.getItinerary(choice_of_the_route);

        displayRoute(output_for_console);

        std::cout << " What station are you interested in?" << std::endl << std::endl << "-->";
        int choice_number_of_the_station = getIntFromConsole();
        std::cout << std::endl;

        choice_number_of_the_station--;
        std::string choice_name_of_the_station;
        int size_of_vector = output_for_console.size();  /// Сделано, потому что иначе компилятор ругается на приведение типов

        if (choice_number_of_the_station >= 0 && choice_number_of_the_station < size_of_vector)
        {
            choice_name_of_the_station = output_for_console[choice_number_of_the_station];
        }
        else
        {
            choice_name_of_the_station = " ";
        }
        try
        {
            std::cout << std::endl << " Information about the station:" << std::endl << std::endl << ' ' << choice_name_of_the_station << " : "
                 << Core.getInformationAboutStation(choice_name_of_the_station) << std::endl;
        }
        catch(StationDoesNotExist&)
        {
            std::cout << " The station does not exist";
        }

    }
    catch(RouteDoesNotExist&)
    {
        std::cout << " The route does not exist" << std::endl
             << std::endl << " At the moment there are 1-" << how_many_routes << " routes" << std::endl
             << std::endl << " Enter number of the route, for example: 1" << std::endl;
    }
    catch(ThereAreNoRoutes&)
    {
        std::cout << std::endl << " At the moment there are no routes, contact the administrator for help" << std::endl;
    }
    std::cout << std::endl << std::endl << " Press Enter..." << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::changeItinerarys()
{
    if (Core.informationOfTheRights() == usual_user)  /// Пользователь не сможет вызвать метод, если он не админ
    {
        return;
    }

    std::cout << " What do you want to do with route table? ";
    try
    {
        unsigned how_many_routes = 0;
        how_many_routes = Core.howManyRoutes();
        std::cout << "(There are routes: 1-" << how_many_routes << ')' << std::endl;
    }
    catch(ThereAreNoRoutes&)
    {
        std::cout << "(There are routes: 0)" << std::endl;
    }
    std::cout << " 1.Add route" << std::endl
              << " 2.Change route" << std::endl
              << " 3.Delete route" << std::endl << std::endl << "-->";

    int choice_action_with_route_table = getIntFromConsole();

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
        std::cout << std::endl << " You have entered something unclear" << std::endl;
        break;
    }
    }
    std::cout << std::endl << " Press Enter..." << std::endl << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::addRoute()
{
    std::cout << std::endl << " Was created the route " << Core.addRoute() << std::endl;
}

void ConsoleForTimetable::deleteRoute()
{
    std::cout << std::endl << " Which route you want to delete" << std::endl << std::endl << "-->";
    int choice_route = getIntFromConsole();

    try
    {
        Core.deleteRoute(choice_route);
        std::cout << std::endl << " The route " << choice_route << " was successfully deleted" << std::endl;
    }
    catch(RouteDoesNotExist&)
    {
        std::cout << std::endl << " The route does not exist" << std::endl;
    }
    std::cout << std::endl;
}

void ConsoleForTimetable::changeRoute()
{
    bool how_successful_changes = 1;
    std::cout << std::endl << " Which do route you want to change?" << std::endl << std::endl << "-->";
    int choice_route = getIntFromConsole();
    std::cout << std::endl;

    try
    {
        std::vector<std::string> output_for_console = Core.getItinerary(choice_route);

        displayRoute(output_for_console);

        std::cout << " What do you want?" << std::endl
             << " 1.Add station" << std::endl
             << " 2.Change station" << std::endl
             << " 3.Delete station" << std::endl
             << std::endl << "-->";
        int choice_action_with_rote = getIntFromConsole();

        switch (choice_action_with_rote)
        {
        case 1:
        {
            std::cout << " What station do you want to add?" << std::endl
                 << "  (the station will be added to the end of the branch)" << std::endl << std::endl << "-->";

            std::string what_to_add;
            std::getline(std::cin,what_to_add);
            std::cout << std::endl << std::endl;

            Core.addStationInItinerary(choice_route,what_to_add);
            break;
        }
        case 2:
        {
            std::cout << " What station do you want to change?" << std::endl << std::endl << "-->";
            int choice_station = getIntFromConsole();

            std::cout << std::endl << " What do you want to put in replacement?" << std::endl << std::endl << "-->";
            std::string what_to_replace;
            std::getline(std::cin,what_to_replace);
            std::cout << std::endl << std::endl;

            Core.changeItinerary(choice_route,choice_station,what_to_replace);
            break;
        }
        case 3:
        {
            std::cout << " What station do you want to delete?" << std::endl << std::endl << "-->";
            int choice_station = getIntFromConsole();

            Core.deleteStationFromItinerary(choice_route,choice_station);
            break;
        }
        default:
        {
            std::cout << std::endl << " You have entered something unclear" << std::endl;
            how_successful_changes = 0;
            break;
        }
        }
    }
    catch(RouteDoesNotExist&)
    {
        std::cout << " The route does not exist" << std::endl;
        how_successful_changes = 0;
    }
    catch(StationDoesNotExist&)
    {
        std::cout << std::endl << " The station does not exist" << std::endl;
        how_successful_changes = 0;
    }
    if (how_successful_changes == 1)
    {
        std::cout << std::endl << " The changes have been well accepted" << std::endl;
    }
}

void ConsoleForTimetable::changeInfoAboutStation()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        return;
    }
    try
    {
        std::cout << " 1.Add or change information about station" << std::endl
             << " 2.Remove information about station" << std::endl << std::endl << "-->";

        int choice_of_action = getIntFromConsole();

        std::cout << std::endl;

        switch(choice_of_action)
        {
        case 1:
        {
            addOrChangeInformationAboutStation();
            break;

        }
        case 2:
        {
            removeInformationAboutStation();
            break;
        }
        default:
        {
            std::cout << " You have entered something unclear" << std::endl;
            break;
        }
        }
        std::cout << std::endl << " The changes have been well accepted" << std::endl;
    }
    catch(RouteDoesNotExist&)
    {
        std::cout << " The route does not exist" << std::endl
             << std::endl << " At the moment there are 1-" << Core.howManyRoutes() << " routes" << std::endl
             << std::endl << " Enter number of the route, for example: 1" << std::endl;
    }
    catch(ThereAreNoRoutes&)
    {
        std::cout << std::endl << " At the moment there are no routes, contact the administrator for help" << std::endl;
    }
    std::cout << std::endl << std::endl << " Press Enter..." << std::endl << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::addOrChangeInformationAboutStation()
{
    std::cout << " What route are you interested in?  (Enter number: 1-"
         << Core.howManyRoutes() << ')' << std::endl << std::endl << "-->";

    int choice_of_the_route = getIntFromConsole();

    std::cout << std::endl;

    std::vector<std::string> output_for_console = Core.getItinerary(choice_of_the_route);

    displayRoute(output_for_console);

    std::string name_of_the_route;

    std::cout << std::endl << " Which information about station do you want to change?" << std::endl << std::endl << "-->";

    int choice_number_of_the_station = getIntFromConsole();

    choice_number_of_the_station--;

    int size_of_vector = output_for_console.size();

    if (choice_number_of_the_station >= 0 && choice_number_of_the_station < size_of_vector)
    {
        name_of_the_route = output_for_console[choice_number_of_the_station];
    }
    else
    {
        name_of_the_route = " ";
    }

    std::cout << std::endl << " What is known about the station?" << std::endl << std::endl << "-->";
    std::string station_description;
    std::getline(std::cin, station_description);

    Core.addInformationAboutStation(name_of_the_route, station_description);
}

void ConsoleForTimetable::removeInformationAboutStation()
{
    std::vector<std::string> AllItemFromTimetable = Core.getAllItemWhichHaveDescription();
    for(unsigned i = 0; i < AllItemFromTimetable.size(); i++)
    {
        std::cout << ' ' << i+1 << '.' << AllItemFromTimetable[i] << std::endl;
    }

    std::string what_remove;
    std::cout << std::endl << " What do you want to remove?" << std::endl << std::endl << "-->";

    int number_of_what_remove = getIntFromConsole();

    number_of_what_remove--;

    int size_of_vector = AllItemFromTimetable.size();

    if (number_of_what_remove >= 0 && number_of_what_remove < size_of_vector)
    {
        what_remove = AllItemFromTimetable[number_of_what_remove];
    }
    else
    {
        what_remove = " ";
    }
    try
    {
        Core.removeInformationAboutStation(what_remove);
    }
    catch(StationDoesNotExist&)
    {
        std::cout << std::endl << " The station does not exist" << std::endl;
    }
}

void ConsoleForTimetable::saveChanges()
{
    if (Core.informationOfTheRights() == usual_user)
    {
        return;
    }
    std::cout << std::endl << " Do you want to save changes? (Y/N)" << std::endl << std::endl << "-->";

    char answer_about_save = getCharFromConsole();

    if (answer_about_save == 'Y' || answer_about_save == 'y')
    {
        Core.saveChanges();
        std::cout << std::endl << " The information was saved successfully" << std::endl << std::endl;
    }
    else
    {
         std::cout << std::endl << " You refused to save" << std::endl << std::endl;
    }
    std::cout << " Press Enter..." << std::endl;
    std::cin.get();
}

bool ConsoleForTimetable::menu()
{
    std::cout << " 1. The route table for trains" << std::endl
         << " 2. Information about station" << std::endl
         << " 3. Get administrator rights" << std::endl;

    if (Core.informationOfTheRights() == administrator)
    {
        std::cout << " 4. Change route table for the train" << std::endl
             << " 5. Change information about station" << std::endl
             << " 6. Save Changes" << std::endl;
    }
    std::cout << " 0. Exit" << std::endl << std::endl;
    std::cout << "-->";

    char choice_in_menu = getCharFromConsole();

    std::cout << std::endl;
    switch(choice_in_menu)
    {
    case '1':
    {
        routeInformation();
        break;
    }
    case '2':
    {
        informationAboutStation();
        break;
    }
    case '3':
    {
        definitionOfAdministrator();
        break;
    }
    case '4':
    {
        changeItinerarys();
        break;
    }
    case '5':
    {
        changeInfoAboutStation();
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
        return false;
    }
    }
    return true;
}
