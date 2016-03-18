#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include <string>
#include <vector>
#include "filetimetable.h"

using namespace std;

enum what_rights{usual_user = 0, administrator=1};


/**
* Класс в котором содержится бизнес-логика приложения
*/
class CoreOfTimetable
{

public:
    CoreOfTimetable();

    void issuanceOfAdministratorRights();  /*Выдача прав администатору*/

    int informationOfTheRights(); /*Получение информации о правах пользователя(обычный или администратор)*/

    string timetableForTrain(int number_of_the_train); /*Возвращяет расписание, для дальнеёшего распечатывания*/

private:
    int right;

    FileTimetable data_set;
};

#endif // CORE_OF_TIMETABLE_H
