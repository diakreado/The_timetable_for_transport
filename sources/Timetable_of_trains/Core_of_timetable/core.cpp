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
    if (number_of_the_route < 1 || number_of_the_route > DataSetOfTheRoute.getMaxQuantityStringInFile())
    {
        throw RouteDoesNotExist();
    }
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false ||
            number_of_the_route == DataSetOfTheRoute.getMaxQuantityStringInFile() + 1)
    {
        vector<string> Null;        ///  Если была ошибка при чтение файла,
        return Null;               ///  то возвращяем пустой вектор (нет файла, нет данных)
    }
    number_of_the_route--;      /// Так как отсчёт с нуля
    string StringFromFile = DataSetOfTheRoute.getFileData(number_of_the_route);
    vector<string> OutputVectorString;
    string PartOfTheLineFromFile;
    for (char symbol_in_string : StringFromFile)
    {
        if (symbol_in_string == ',')
        {
            OutputVectorString.push_back(PartOfTheLineFromFile);
            PartOfTheLineFromFile = "";
        }
        else
        {
            PartOfTheLineFromFile += symbol_in_string;
        }
    }
    OutputVectorString.push_back(PartOfTheLineFromFile);
    return OutputVectorString;
}

string CoreOfTimetable::getWhenStartMovementOnTheStation(const string &name_of_the_station)
{
    return DataSetOfTimetable.getFileData(name_of_the_station);
}

string CoreOfTimetable::findSuitableRoute(string &departure, string &arrival)
{
    departure = "123";                  ///  ToDo  Не относиться к MVP, но если будет время реализую
    arrival = "321";
    return "Hello";
}

void CoreOfTimetable::changeRouteTable(unsigned choice_route, unsigned choice_station, string &what_to_replace)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);
    choice_station--;
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false || choice_station >= NewVariantOfString.size())
    {
        throw NotSuitableInquiry();
    }
    else
    {
        NewVariantOfString[choice_station] = what_to_replace;
    }
    string ToPrintToFile;
    for (unsigned i = 0; i < NewVariantOfString.size()-1; i++)
    {
        ToPrintToFile += NewVariantOfString[i] + ',';
    }
    ToPrintToFile += NewVariantOfString[NewVariantOfString.size()-1];   /// Потому что в конце запятая не нужна
    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    unsigned size_of_string;
    while(correct_beginning_of_the_line == 0)
    {
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
    DataSetOfTheRoute.changeTable(choice_route,ToPrintToFile);
}

void CoreOfTimetable::deleteStationFromRouteTable(unsigned choice_route, unsigned choice_station)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);
    choice_station--;
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false || choice_station >= NewVariantOfString.size())
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
    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    unsigned size_of_string;
    while(correct_beginning_of_the_line == 0)
    {
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
    DataSetOfTheRoute.changeTable(choice_route,ToPrintToFile);
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
    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    unsigned size_of_string;
    while(correct_beginning_of_the_line == 0)
    {
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
    DataSetOfTheRoute.changeTable(choice_route,ToPrintToFile);
}

void CoreOfTimetable::changeTimetable(string &what_change, string &in_exchange)
{
    string abc = what_change + in_exchange;
    /// Просто нет реализации, а действие сделано, чтобы не выводилось предупреждение
}

void CoreOfTimetable::removeStationFromTimetalbe(const string &what_remove)
{
    DataSetOfTimetable.removeLine(what_remove);
}

