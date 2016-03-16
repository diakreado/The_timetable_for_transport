#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include <string>
#include <vector>

using namespace std;

enum what_rights{usual_user = 0, administrator=1};


/**
* Класс в котором содержится бизнес-логика приложения
*/
class Core_of_timetable
{

public:
    Core_of_timetable();

    void issuanceOfAdministratorRights();  /*Выдача прав администатору*/

    int informationOnTheRights(); /*Получение информации о правах пользователя(обычный или администратор)*/

    vector<string>* routOfTheTrain(int number_of_the_train);


private:
    int right;
};

#endif // CORE_OF_TIMETABLE_H
