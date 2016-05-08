 #include "core.h"

// todo использовать список инициализации
CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    DataSetOfInfoRoute.readingFromFile();
    DataSetOfInfoStation.readingFromFile();
}

// todo what_rights --> rights
void CoreOfTimetable::issuanceOfRights(const int what_rights)
{
    if (what_rights == 1)
    {
        right = administrator;
    }
    else
    {
        right = usual_user;
    }
}

bool CoreOfTimetable::informationOfTheRights() const
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
            {
                Route.push_back(NameOfTheStation);
                NameOfTheStation = "";
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
    catch(ItemDoesNotExist)
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
    // todo ловить исключение по ссылке
    catch(ItemDoesNotExist)
    {
        throw StationDoesNotExist();
    }
}

std::string CoreOfTimetable::findSuitableRoute(std::string &departure, std::string &arrival)
{
    departure = "123";                  /// ToDo  Реализовать
    arrival = "321";
    return "Hello";
}

// todo unigned int? или unsigned double?
void CoreOfTimetable::changeItinerary(unsigned choice_route, unsigned choice_station, std::string &what_to_replace)
{
    std::vector<std::string> Route = getItinerary(choice_route);
    choice_station--;
    choice_route--;

    // todo здесь сравнение unsigned int с нулем. Всегда дает false
    if(choice_station >= Route.size() || choice_station < 0)
    {
        throw StationDoesNotExist();
    }
    else
    {
        Route[choice_station] = what_to_replace;
    }

    std::string ToPrintToFile;
    for (unsigned i = 0; i < Route.size()-1; i++)
    {
        ToPrintToFile += Route[i] + ',';
    }
    ToPrintToFile += Route[Route.size()-1];   /// Потому что в конце запятая не нужна

    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    while(correct_beginning_of_the_line == 0)
    {
        unsigned size_of_string = ToPrintToFile.size()-1;
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
    // todo ловить исключение по ссылке
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }
}

unsigned CoreOfTimetable::addRoute()
{
    unsigned choice_route = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();

    DataSetOfInfoRoute.addNewBlock();

    choice_route++;
    return choice_route;
}

void CoreOfTimetable::deleteRoute(unsigned choice_route)
{
    choice_route--;

    try
    {
        DataSetOfInfoRoute.deleteBlockFromLine(choice_route);
    }
    // todo ловить исключение по ссылке
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }
}

// todo unsigned int? или все-таки unsigned double?
void CoreOfTimetable::deleteStationFromItinerary(unsigned choice_route, unsigned choice_station)
{
    std::vector<std::string> NewVariantOfString = getItinerary(choice_route);
    choice_station--;

    // todo здесь сравнение unsigned int с нулем. Всегда дает false
    if(choice_station >= NewVariantOfString.size() || choice_station < 0)
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

// todo unigned int? или unsigned double?
void CoreOfTimetable::addStationInItinerary(unsigned choice_route, std::string &what_to_add)
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

void CoreOfTimetable::addInformationAboutStation(std::string &name_of_the_station, std::string &station_description)
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
    DataSetOfInfoStation.deleteBlockFromeLine(new_what_station_to_remove);
    }
    // todo ловить исключение по ссылке
    catch(ItemDoesNotExist)
    {
        throw StationDoesNotExist();
    }
}

void CoreOfTimetable::saveChanges()
{
    DataSetOfInfoRoute.saveChanges();
    DataSetOfInfoStation.saveChanges();
}

// todo какой тип возвращает метод?
unsigned CoreOfTimetable::howManyRoutes()
{
    unsigned how_many_routes = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();
    if (how_many_routes == 0)
    {
        throw ThereAreNoRoutes();
    }
    return how_many_routes;
}

std::vector<std::string> CoreOfTimetable::getAllItemWhichHaveDescription()
{
    return DataSetOfInfoStation.getAllItem();
}


