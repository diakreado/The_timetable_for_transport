#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include "file.h"
#include <map>

enum what_part_of_buffer{name = 0, value = 1};

/**
 *  @brief Наследник класса File, который нужен, чтобы работать с файлом "Schedule.txt"
 */
class FileTimetable : public File
{
public:

    void readingFromFile() override;

    void addStationInTimetable(string &name_of_the_route, string &route_description);

    /**
     *  @param name_of_station - некоторая часть строчки из файла "Schedule.txt"
     *  @return Строчка с необходимыми данными
     */
    string getFileData(const string &name_of_station);

    /**
     *  @brief Удаляет часть строчку из "Schedule.txt"
     *  @param what_remove - какую часть строчки удалить
     */
    void removeLine(const string &what_remove);

    /**
     * @return Возвращяет все элементы находящиеся в контейнерах
     */
    vector<string> getAllItem();

    void saveChanges() override;

private:

    /**
     *  @brief Удобный формат хранения извлечённых данных
     */
    map<string,string> Timetable;
};

class StationDoesNotExist : public exception {};

#endif // FILESCHEDULE_H
