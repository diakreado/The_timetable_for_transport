 #include "core.h"

// todo использовать список инициализации
CoreOfTimetable::CoreOfTimetable()
{
    right = rights_of_customers::user;
    DataSetOfInfoRoute.readingFromFile();
    DataSetOfInfoStation.readingFromFile();
}

// todo what_rights --> rights
void CoreOfTimetable::issuanceOfRights(const rights_of_customers right) noexcept
{
    if (right == rights_of_customers::administrator)
    {
        this->right = rights_of_customers::administrator;
    }
    else
    {
        this->right = rights_of_customers::user;
    }
}

rights_of_customers CoreOfTimetable::informationOfTheRights() const noexcept
{
    return right;
}

std::vector<std::string> CoreOfTimetable::getItinerary(int number_of_the_route)
{
    number_of_the_route--;      /// Так как отсчёт с нуля, но пользователь не должен этого знать

    std::vector<std::string> Route;
    try
    {
        std::string StringFromFile = DataSetOfInfoRoute.getFileData(number_of_the_route);
        std::string NameOfTheStation;
        for (char symbol_in_string : StringFromFile)
        {
            if (symbol_in_string == ',')
            {                                           /// Была получена строчка, в которой через запятую находятся
                Route.push_back(NameOfTheStation);     ///  название станций, а мы её превращяем в vector<string>, где
                NameOfTheStation = "";                ///   элемент вектора название станции
            }
            else
            {
                NameOfTheStation += symbol_in_string;
            }
        }
        Route.push_back(NameOfTheStation);
    }
    // todo мы ловим исключение, чтобы бросить другое? может быть, я не понимаю чего-то
    // todo в любом случае, ловить исключение по ссылке catch(ItemDoesNotExist &)
    catch(ItemDoesNotExist&)
    {
        throw RouteDoesNotExist();
    }

    return Route;
}

std::string CoreOfTimetable::getInformationAboutStation(const std::string &name_of_the_station)
{
    try
    {
        return DataSetOfInfoStation.getFileData(name_of_the_station);
    }
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist();
    }
}

void CoreOfTimetable::changeItinerary(int choice_route, int choice_station, std::string &what_to_replace)
{
    std::vector<std::string> Route = getItinerary(choice_route);
    choice_station--;
    choice_route--;

    int route_size = Route.size();  /// Чтобы не было конфликта типов при сравнение

    if(choice_station >= route_size || choice_station < 0)
    {
        throw StationDoesNotExist();
    }
    else
    {
        Route[choice_station] = what_to_replace;
    }

    std::string ToPrintToFile;
    for (unsigned int i = 0; i < Route.size()-1; i++)
    {
        ToPrintToFile += Route[i] + ',';
    }
    ToPrintToFile += Route[Route.size()-1];   /// Потому что в конце запятая не нужна

    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    while(correct_beginning_of_the_line == 0)
    {
        unsigned int size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале строки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }                                            /// Потому что отсчёт с нуля

    try
    {
        DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
    }
    catch(ItemDoesNotExist&)
    {
        throw RouteDoesNotExist();
    }
}

int CoreOfTimetable::addRoute() noexcept
{
    int choice_route = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();

    DataSetOfInfoRoute.addNewBlock();

    choice_route++;
    return choice_route;
}

void CoreOfTimetable::deleteRoute(int choice_route)
{
    choice_route--;

    try
    {
        DataSetOfInfoRoute.deleteBlockFromLine(choice_route);
    }
    catch(ItemDoesNotExist&)
    {
        throw RouteDoesNotExist();
    }
}

void CoreOfTimetable::deleteStationFromItinerary(int choice_route, int choice_station)
{
    std::vector<std::string> NewVariantOfString = getItinerary(choice_route);
    choice_station--;

    int size_of_vector = NewVariantOfString.size();
    if(choice_station >= size_of_vector || choice_station < 0)
    {
        throw StationDoesNotExist();
    }

    NewVariantOfString[choice_station] = "";
    std::string ToPrintToFile;
    for (unsigned i = 0; i < NewVariantOfString.size()-1; i++)
    {
        if (NewVariantOfString[i] != "")
        {
            ToPrintToFile += NewVariantOfString[i] + ',';
        }
    }
    if (NewVariantOfString[NewVariantOfString.size()-1] != "")
    {
        ToPrintToFile += NewVariantOfString[NewVariantOfString.size()-1];   /// Потому что в конце запятая не нужна
    }
    else
    {
        ToPrintToFile.erase(ToPrintToFile.size()-1);  /// Убрал запятую
    }
    bool correct_beginning_of_the_line = 0;
    while(correct_beginning_of_the_line == 0)
    {
        unsigned size_of_string;
        size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }
    choice_route--;                                                     /// Потому что отсчёт с нуля
    DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addStationInItinerary(int choice_route, std::string &what_to_add)
{
    std::vector<std::string> NewVariantOfString = getItinerary(choice_route);
    NewVariantOfString.push_back(what_to_add);
    std::string ToPrintToFile;
    for (unsigned i = 0; i < NewVariantOfString.size()-1; i++)
    {
        ToPrintToFile += NewVariantOfString[i] + ',';
    }
    ToPrintToFile += NewVariantOfString[NewVariantOfString.size()-1];   /// Потому что в конце запятая не нужна

    bool correct_beginning_of_the_line = 0;
    while(correct_beginning_of_the_line == 0)
    {
        unsigned size_of_string;
        size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }
    choice_route--;                                            /// Потому что отсчёт с нуля
    DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept
{
    DataSetOfInfoStation.addNewBlockOrChangeExisting(name_of_the_station, station_description);
}

void CoreOfTimetable::removeInformationAboutStation(const std::string &what_station_to_remove)
{
    std::string new_what_station_to_remove;
    for(char j : what_station_to_remove)
    {
        if (j == '~')
        {
            break;
        }
        new_what_station_to_remove += j;
    }

    try
    {
        DataSetOfInfoStation.deleteBlockFromLine(new_what_station_to_remove);
    }
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist();
    }
}

void CoreOfTimetable::saveChanges() noexcept
{
    DataSetOfInfoRoute.saveChanges();
    DataSetOfInfoStation.saveChanges();
}

int CoreOfTimetable::howManyRoutes()
{
    int how_many_routes = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();
    if (how_many_routes == 0)
    {
        throw ThereAreNoRoutes();
    }
    return how_many_routes;
}

std::vector<std::string> CoreOfTimetable::getAllItemWhichHaveDescription()  noexcept
{
    return DataSetOfInfoStation.getAllItem();
}


