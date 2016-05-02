 #include "core.h"

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    DataSetOfInfoRoute.readingFromFile();
    DataSetOfInfoStation.readingFromFile();
}

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

vector<string> CoreOfTimetable::getItinerary(int number_of_the_route)
{
    number_of_the_route--;      /// Так как отсчёт с нуля, но пользователь не должен этого знать

    vector<string> Route;
    try
    {
        string StringFromFile = DataSetOfInfoRoute.getFileData(number_of_the_route);
        string NameOfTheStation;
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
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }

    return Route;
}

string CoreOfTimetable::getInformationAboutStation(const string &name_of_the_station)
{
    try
    {
        return DataSetOfInfoStation.getFileData(name_of_the_station);
    }
    catch(ItemDoesNotExist)
    {
        throw StationDoesNotExist();
    }
}

string CoreOfTimetable::findSuitableRoute(string &departure, string &arrival)
{
    departure = "123";                  /// ToDo  Реализовать
    arrival = "321";
    return "Hello";
}

void CoreOfTimetable::changeItinerary(unsigned choice_route, unsigned choice_station, string &what_to_replace)
{
    vector<string> Route = getItinerary(choice_route);
    choice_station--;
    choice_route--;

    if(choice_station >= Route.size() || choice_station < 0)
    {
        throw StationDoesNotExist();
    }
    else
    {
        Route[choice_station] = what_to_replace;
    }

    string ToPrintToFile;
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
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }                                            /// Потому что отсчёт с нуля

    try
    {
        DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
    }
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
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }
}

void CoreOfTimetable::deleteStationFromItinerary(unsigned choice_route, unsigned choice_station)
{
    vector<string> NewVariantOfString = getItinerary(choice_route);
    choice_station--;

    if(choice_station >= NewVariantOfString.size() || choice_station < 0)
    {
        throw StationDoesNotExist();
    }

    NewVariantOfString[choice_station] = "";
    string ToPrintToFile;
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

void CoreOfTimetable::addStationInItinerary(unsigned choice_route, string &what_to_add)
{
    vector<string> NewVariantOfString = getItinerary(choice_route);
    NewVariantOfString.push_back(what_to_add);
    string ToPrintToFile;
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

void CoreOfTimetable::addInformationAboutStation(string &name_of_the_station, string &station_description)
{
    DataSetOfInfoStation.addNewBlockOrChangeExisting(name_of_the_station, station_description);
}

void CoreOfTimetable::removeInformationAboutStation(const string &what_station_to_remove)
{
    string new_what_station_to_remove;
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

unsigned CoreOfTimetable::howManyRoutes()
{
    unsigned how_many_routes = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();
    if (how_many_routes == 0)
    {
        throw ThereAreNoRoutes();
    }
    return how_many_routes;
}

vector<string> CoreOfTimetable::getAllItemWhichHaveDescription()
{
    return DataSetOfInfoStation.getAllItem();
}


