#include "work_with_routes.h"

void WorkWithRoutes::routeInformation(CoreOfTimetable &core)
{
    unsigned how_many_routes;
    try
    {
        how_many_routes = core.howManyRoutes();

        std::cout << " What route are you interested in?  (Enter number: 1-" << how_many_routes << ')' << std::endl << std::endl << "-->";
        int choice_of_the_route =  getIntFromConsole();
        std::cout << std::endl;

        std::vector<std::string> output_for_console = core.getItinerary(choice_of_the_route);

        displayRoute(output_for_console);
    }
    catch(RouteDoesNotExist& exception)
    {
        std::cout << " The route "
                  << '"' << exception.getWhatRequested() << '"' << " does not exist" << std::endl
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

void WorkWithRoutes::changeItinerarys(CoreOfTimetable &core)
{
    if (core.getInformationOfTheRights() == Rights_of_customers::user)  /// Пользователь не сможет вызвать метод, если он не админ
    {
        return;
    }

    std::cout << " What do you want to do with route table? ";
    try
    {
        unsigned how_many_routes = 0;
        how_many_routes = core.howManyRoutes();
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
        addRoute(core);
        break;
    }
    case 2:
    {
        changeRoute(core);
        break;
    }
    case 3:
    {
        deleteRoute(core);
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


void WorkWithRoutes::addRoute(CoreOfTimetable &core)
{
    std::cout << std::endl << " Was created the route " << core.addRoute() << std::endl;
}

void WorkWithRoutes::deleteRoute(CoreOfTimetable &core)
{
    std::cout << std::endl << " Which route you want to delete" << std::endl << std::endl << "-->";
    int choice_route = getIntFromConsole();

    try
    {
        core.deleteRoute(choice_route);
        std::cout << std::endl << " The route " << choice_route << " was successfully deleted" << std::endl;
    }
    catch(RouteDoesNotExist& exception)
    {
        std::cout << std::endl << " The route "
                  << '"' << exception.getWhatRequested() << '"' << " does not exist" << std::endl;
    }
    std::cout << std::endl;
}

void WorkWithRoutes::changeRoute(CoreOfTimetable &core)
{
    bool how_successful_changes = 1;
    std::cout << std::endl << " Which do route you want to change?" << std::endl << std::endl << "-->";
    int choice_route = getIntFromConsole();
    std::cout << std::endl;

    try
    {
        std::vector<std::string> output_for_console = core.getItinerary(choice_route);

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

            core.addStationInItinerary(choice_route, what_to_add);
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

            core.changeStationInItinerary(choice_route, choice_station, what_to_replace);
            break;
        }
        case 3:
        {
            std::cout << " What station do you want to delete?" << std::endl << std::endl << "-->";
            int choice_station = getIntFromConsole();

            core.deleteStationFromItinerary(choice_route, choice_station);
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
    catch(RouteDoesNotExist& exception)
    {
        std::cout << " The route "
                  << '"' << exception.getWhatRequested() << '"' << " does not exist" << std::endl;
        how_successful_changes = 0;
    }
    catch(StationDoesNotExist& exception)
    {
        std::cout << std::endl << " The station with number "
                  << '"' << exception.getWhatRequested() << '"' << " does not exist" << std::endl;
        how_successful_changes = 0;
    }

    if (how_successful_changes == 1)
    {
        std::cout << std::endl << " The changes have been well accepted" << std::endl;
    }
}
