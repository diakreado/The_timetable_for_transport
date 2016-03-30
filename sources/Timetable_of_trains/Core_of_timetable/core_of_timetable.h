#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include <string>
#include <vector>
#include "filetimetable.h"

using namespace std;

enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится бизнес-логика приложения
 */
class CoreOfTimetable
{

public:
    CoreOfTimetable();

    /**
     * @brief Выдача прав
     *
     * @param Какие права нужно выдать
     */
    void issuanceOfRights(int const what_rights);

    /**
     * @return Информация о правах
     */
    bool informationOfTheRights() const;

    /**
     * @param Номер маршрута
     *
     * @return Маршрут поезда в формате string
     */
    string timetableForTrain(int number_of_the_route) const;

    /**
     * @param station - станция
     * @param time - время относительно которого делается вывод
     *
     * @return время до прибытия следующего поезда
     */
    int whenWillTheTrainsArrive(string station, int time);

    /// Выставить максимально возможное количество строк в файле
//    void setMaxNumberOfStringInTheFile(int const new_max_number);

private:
    int right;

    FileTimetable data_set;
};

/**
 * @brief Недостаточно прав
 */
class InsufficientRights : public exception {};

#endif // CORE_OF_TIMETABLE_H
