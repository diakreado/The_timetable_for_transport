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

void ConsoleForTimetable::definitionOfAdministrator()
{
    std::cout << " Are you the administrator? Y/N" << std::endl << std::endl << "-->";
    char answer_about_rights = getCharFromConsole();

    if (answer_about_rights == 'Y' or answer_about_rights == 'y')
    {
        core.putOfRights(Rights_of_customers::administrator);
        std::cout << std::endl << " You got administrator rights" << std::endl << std::endl;
    }
    else
    {
        core.putOfRights(Rights_of_customers::user);
        std::cout << std::endl << " You got rights as a usual user" << std::endl << std::endl;
    }

    std::cout << std::endl << " Press Enter..." << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::loadFromFile()
{
    if (core.getInformationOfTheRights() == Rights_of_customers::user)
    {
        return;
    }
    try
    {
        core.loadInfoFromFile("metro_Saint-Petersburg_route_info.txt", "metro_Saint-Petersburg_station_info.txt");
        std::cout << std::endl << "File was read" << std::endl << std::endl;
    }
    catch(MissingFile&)
    {
        std::cout << std::endl << "File does not exis" << std::endl << std::endl;
    }

    std::cout << std::endl << " Press Enter..." << std::endl;
    std::cin.get();
}

void ConsoleForTimetable::saveChanges()
{
    if (core.getInformationOfTheRights() == Rights_of_customers::user)
    {
        return;
    }
    std::cout << std::endl << " Do you want to save changes? (Y/N)" << std::endl << std::endl << "-->";

    char answer_about_save = getCharFromConsole();

    if (answer_about_save == 'Y' || answer_about_save == 'y')
    {
//        core.saveChanges();
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

    if (core.getInformationOfTheRights() == Rights_of_customers::administrator)
    {
        std::cout << " 4. Change route table for the train" << std::endl
             << " 5. Change information about station" << std::endl
             << " 6. Load from file" << std::endl
             << " 7. Save Changes" << std::endl;
    }
    std::cout << " 0. Exit" << std::endl << std::endl;
    std::cout << "-->";

    char choice_in_menu = getCharFromConsole();

    std::cout << std::endl;
    switch(choice_in_menu)
    {
    case '1':
    {
        route_info.routeInformation(core);
        break;
    }
    case '2':
    {
        stations_info.informationAboutStation(core);
        break;
    }
    case '3':
    {
        definitionOfAdministrator();
        break;
    }
    case '4':
    {
        route_info.changeItinerarys(core);
        break;
    }
    case '5':
    {
        stations_info.changeInfoAboutStation(core);
        break;
    }
    case '6':
    {
        loadFromFile();
        break;
    }
    case '7':
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
