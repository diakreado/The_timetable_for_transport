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

    void readingFromFile();

    void setMaxQuantityStringInFile(int const  new_max_quantity);

    /**
     * @brief Переписывает строчку в файле "Schedule.txt"
     * @param Номер строки которую надо переписать
     * @param Что нужно написать на месте строки
     */
    void changeTable(int const number_of_line, string ToPrintToFile);

    /**
     *  @param Номер строчки из файла "Schedule.txt"
     *  @return Строчка с необходимым временем
     */
    string getFileData(const string name_of_station);

    /**
     *  @brief Удаляет строчку из "Schedule.txt"
     *  @param какую строчку удалить
     */
    void removeLine(string const what_remove);

private:

    /**
     *  @brief Удобный формат хранения извлечённых данных
     */
    map<string,string> Timetable;
};

class StationDoesNotExist : public exception {};

#endif // FILESCHEDULE_H
