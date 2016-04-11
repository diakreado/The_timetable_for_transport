#include "core.h"

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    try
    {
    DataSetOfTheRoute.readingFromFile();
    DataSetOfTimetable.readingFromFile();
    }
    catch(FailedToOpen)
    {
        /// Вроде как, ничего не надо делать, потому что уже всё сделано
    }
}

void CoreOfTimetable::issuanceOfRights(int const what_rights)
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

vector<string> CoreOfTimetable::getRouteOfTrain(int const number_of_the_route)
{
    if (number_of_the_route < 1 || number_of_the_route > DataSetOfTheRoute.getMaxQuantityStringInFile() + 1)
    {
        throw RouteDoesNotExist();
    }
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false)
    {
        vector<string> Null;
        return Null;
    }
    string InputString = DataSetOfTheRoute.getFileData(number_of_the_route);
    vector<string> OutputVectorString;
    char symbol_int_string;
    string LineFromFile;
    for (unsigned int character_number = 0; character_number < InputString.length(); character_number++)
    {
        symbol_int_string = InputString[character_number];
        if (symbol_int_string == ' ')
        {
            OutputVectorString.push_back(LineFromFile);
            LineFromFile = "";
        }
        else
        {
            if (symbol_int_string == '_')
            {
                symbol_int_string = ' ';
            }
            LineFromFile += symbol_int_string;
        }
    }
    OutputVectorString.push_back(LineFromFile);
    return OutputVectorString;
}

string CoreOfTimetable::getWhenStartMovementOnTheStation(string const name_of_the_station)
{
    return DataSetOfTimetable.getFileData(name_of_the_station);
}

string CoreOfTimetable::findSuitableRoute(string departure, string arrival, int time)
{
    return "Hello";
}

void CoreOfTimetable::changeRouteTable(int const choice_route, int choice_station, string what_to_replace)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);    /// Удобнее работать сразу с
    choice_station--;       /// потому что с отсчёт с нуля               ///  сформированым вектором
    string buffer;
    for (unsigned int i = 0; i < NewVariantOfString.size(); i++)
    {
        buffer = NewVariantOfString[i];
        for (unsigned int j = 0; j < buffer.size(); j++)
        {
            if (buffer[j] == ' ')     /// Заменяем пробелы в строчках, считаных из файла,
            {                        ///  но преобразованых в вектор, знаком "_"
                buffer[j] = '_';
            }
        }
        NewVariantOfString[i] = buffer;
    }
    for (unsigned int i = 0; i < what_to_replace.size(); i++)
    {
        if (what_to_replace[i] == ' ')
        {
            what_to_replace[i] = '_';       /// Заменяем пробелы в введённой строчке знаком "_"
        }
    }
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false)
    {
        NewVariantOfString.push_back(what_to_replace);
    }
    else
    {
        NewVariantOfString[choice_station] = what_to_replace;
    }
    string ToPrintToFile;
    for (unsigned int i = 0; i < NewVariantOfString.size(); i++)
    {
        ToPrintToFile += NewVariantOfString[i] + ' ';
    }
    bool flag = 0;
    unsigned int size_of_string;
    while(flag == 0)
    {
        size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ' || ToPrintToFile[size_of_string] == '_')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);
        }
        else
        {
            flag = 1;
        }
    }
    DataSetOfTheRoute.changeTable(choice_route,ToPrintToFile);
}

int CoreOfTimetable::whenWillTheTrainsArrive(string station, int time)
{
    station = 1;  /// Будет попозже реализация
    time += 2;
    return 0;
}


void CoreOfTimetable::changeTimetable(string const what_change, string const in_exchange)
{

}

void CoreOfTimetable::removeStationFromTimetalbe(string const what_remove)
{
    DataSetOfTimetable.removeLine(what_remove);
}

