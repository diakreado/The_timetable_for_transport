#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

enum what_rights{usual_user = 0, administrator=1};

class Core_of_timetable
{

public:
    Core_of_timetable();
    void issuanceOfTheRights();
    int informationOnTheRights();

private:
    int right;
};

#endif // CORE_OF_TIMETABLE_H
