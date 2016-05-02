 #include "core.h"

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    DataSetOfTheRoute.readingFromFile();
    DataSetOfTimetable.readingFromFile();
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

vector<string> CoreOfTimetable::getRouteOfTrain(int number_of_the_route)
{
    number_of_the_route--;      /// Так как отсчёт с нуля, но пользователь не должен этого знать

    vector<string> Route;
    try
    {
        string StringFromFile = DataSetOfTheRoute.getFileData(number_of_the_route);
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
    return DataSetOfTimetable.getFileData(name_of_the_station);
}

string CoreOfTimetable::findSuitableRoute(string &departure, string &arrival)
{
    departure = "123";                  /// ToDo  Реализовать
    arrival = "321";
    return "Hello";
}

void CoreOfTimetable::changeItinerary(unsigned choice_route, unsigned choice_station, string &what_to_replace)
{
    vector<string> Route = getRouteOfTrain(choice_route);
    choice_station--;
    if(choice_station >= Route.size())
    {
        throw NotSuitableInquiry();
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

    try
    {
        DataSetOfTheRoute.changePartOfTheLine(choice_route,ToPrintToFile);
    }
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }
}

unsigned CoreOfTimetable::addRoute()
{
    unsigned choice_route = DataSetOfTheRoute.getNumberOfPartsOfLine();

    DataSetOfTheRoute.addPartOfTheLine();

    choice_route++;
    return choice_route;
}

void CoreOfTimetable::deleteRoute(unsigned choice_route)
{
    choice_route--;

    try
    {
        DataSetOfTheRoute.deletePartOfTheLine(choice_route);
    }
    catch(ItemDoesNotExist)
    {
        throw RouteDoesNotExist();
    }
}

void CoreOfTimetable::deleteStationFromRouteTable(unsigned choice_route, unsigned choice_station)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);
    choice_station--;
    if(choice_station >= NewVariantOfString.size())
    {
        throw NotSuitableInquiry();
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
    DataSetOfTheRoute.changePartOfTheLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addStationInRouteTable(unsigned choice_route, string &what_to_add)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);
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
    DataSetOfTheRoute.changePartOfTheLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addStationInTimetable(string &name_of_the_route, string &route_description)
{
    DataSetOfTimetable.addInformationAboutStation(name_of_the_route, route_description);
}

void CoreOfTimetable::removeStationFromTimetalbe(const string &what_remove)
{
    string new_what_remove;
    for(char j : what_remove)
    {
        if (j == '~')
        {
            break;
        }
        new_what_remove += j;
    }

    DataSetOfTimetable.removeLine(new_what_remove);
}

void CoreOfTimetable::saveChanges()
{
    DataSetOfTheRoute.saveChanges();
    DataSetOfTimetable.saveChanges();
}

unsigned CoreOfTimetable::howManyRoutes()
{
    unsigned how_many_routes = DataSetOfTheRoute.getNumberOfPartsOfLine();
    if (how_many_routes == 0)
    {
        throw ThereAreNoRoutes();
    }
    return how_many_routes;
}

vector<string> CoreOfTimetable::getAllItemFromTimetable()
{
    return DataSetOfTimetable.getAllItem();
}


