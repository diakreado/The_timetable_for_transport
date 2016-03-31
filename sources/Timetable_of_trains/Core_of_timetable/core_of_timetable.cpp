#include "core_of_timetable.h"
#include <iostream>

using namespace std;

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    data_set.ReadingFromFile();
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

vector<string> CoreOfTimetable::timetableForTrain(int const number_of_the_route)
{
    string input_string = data_set.getFileData(number_of_the_route);

    vector<string> output_vector_string;

    output_vector_string.resize(50);

    int number_newlines = 0;

    char symbol_int_string;

    for (unsigned int character_number = 0; character_number < input_string.length(); character_number++)
    {
        symbol_int_string = input_string[character_number];
        output_vector_string[number_newlines] += symbol_int_string;
        if (symbol_int_string == ' ')
        {
            number_newlines++;
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



int CoreOfTimetable::whenWillTheTrainsArrive(string station, int time)
{
    station = 1;
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
        data_set.setMaxQuantityStringInFile(new_max_quantity);
        data_set.ReadingFromFile();
    }
    else
    {
        throw InsufficientRights();   /// По факту исключение никогда не броситься, но по моему ядро всё равно не должно
    }                                /// давать изменять этот параметр без прав администратора
}

int CoreOfTimetable::getMaxNumberStringInFile()
{
    return data_set.getMaxQuantityStringInFile();
}








