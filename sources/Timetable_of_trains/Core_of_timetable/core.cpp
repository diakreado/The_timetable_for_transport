#include "core.h"
#include <iostream>

using namespace std;

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    DataSet.ReadingFromFile();
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
    string input_string = DataSet.getFileData(number_of_the_route);
    vector<string> output_vector_string;
    output_vector_string.resize(50);
    int number_newlines = 0;
    char symbol_int_string;
    for (unsigned int character_number = 0; character_number < input_string.length(); character_number++)
    {
        symbol_int_string = input_string[character_number];
        if (symbol_int_string == ' ')
        {
            number_newlines++;
        }
        else
        {
        if (symbol_int_string == '_')
        {
            symbol_int_string = ' ';
        }
        output_vector_string[number_newlines] += symbol_int_string;
        }
    }
    int empty_string = 0;
    for(unsigned int i = 0; i < output_vector_string.size(); i++)
    {
        if (output_vector_string[i] == "")
        {
            empty_string++;
        }
    }
    output_vector_string.resize(50 - empty_string);
    return output_vector_string;
}

void CoreOfTimetable::changeRouteTable(int const choice_route, int choice_station, string what_to_replace)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);
    NewVariantOfString.resize(50);
    choice_station--;                                                        /// потому что с отсчёт с нуля
    string buffer;
    for (unsigned int i = 0; i < NewVariantOfString.size(); i++)
    {
        buffer = NewVariantOfString[i];
        for (unsigned int j = 0; j < buffer.size(); j++)
        {
            if (buffer[j] == ' ')
            {
                buffer[j] = '_';
            }
        }
        NewVariantOfString[i] = buffer;
    }
    for (unsigned int i = 0; i < what_to_replace.size(); i++)
    {
        if (what_to_replace[i] == ' ')
        {
            what_to_replace[i] = '_';
        }
    }
    NewVariantOfString[choice_station] = what_to_replace;
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
    DataSet.changeRouteTable(choice_route,ToPrintToFile);
}

int CoreOfTimetable::whenWillTheTrainsArrive(string station, int time)
{
    station = 1;  /// Будет попозже реализация
    time += 2;
    return 0;
}

void CoreOfTimetable::setMaxNumberStringInFile(int const new_max_quantity)
{
    if (right == administrator)
    {
        if (new_max_quantity < 10)
        {
            throw RecommendedSettings();
        }
        DataSet.setMaxQuantityStringInFile(new_max_quantity);
        DataSet.ReadingFromFile();
    }
    else
    {
        throw InsufficientRights();   /// По факту исключение никогда не броситься, но по моему ядро всё равно не должно
    }                                /// давать изменять этот параметр без прав администратора
}

int CoreOfTimetable::getMaxNumberStringInFile()
{
    return DataSet.getMaxQuantityStringInFile();
}




