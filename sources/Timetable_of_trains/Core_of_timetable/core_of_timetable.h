#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include <string>
#include <vector>
#include "filetimetable.h"

using namespace std;

enum what_rights{usual_user = 0, administrator = 1};



/// Класс в котором содержится бизнес-логика приложения
class CoreOfTimetable
{

public:
    CoreOfTimetable();

    /// Выдача прав администатора
    void issuanceOfRights(int const what_rights);

    /// Получение информации о правах пользователя(обычный или администратор)
    bool informationOfTheRights() const;

    /// Возвращяет расписание, для дальнеёшего распечатывания
    string timetableForTrain(int number_of_the_train) const;

    /// Относительно настоящего времени определяет через сколько секунд прибудет поезд
    string whenWillTheTrainsArrive(string station, int time);

private:
    int right;

    FileTimetable data_set;
};

#endif // CORE_OF_TIMETABLE_H
