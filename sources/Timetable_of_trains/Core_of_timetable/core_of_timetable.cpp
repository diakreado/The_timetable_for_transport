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

string CoreOfTimetable::timetableForTrain(int number_of_the_route) const
{
    return data_set.getFileData(number_of_the_route);
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
        throw InsufficientRights();   /// По факту исключение никогда не броситься, но по моему ядро не должно
    }                                /// давать изменять этот параметр без прав администратора
}

int CoreOfTimetable::getMaxNumberStringInFile()
{
    return data_set.getMaxQuantityStringInFile();
}








