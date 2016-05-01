#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include "file_handling.h"
#include <map>

enum what_part_of_buffer{name = 0, value = 1};

/**
 *  @brief Класс,для обработатки второй строчки файла, в которой находиться информация о станциях
 */
class FileStationInformation : public FileHandling
{
public:

    void readingFromFile() override;

    void addInformationAboutStation(string &name_of_the_station, string &station_description);

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
