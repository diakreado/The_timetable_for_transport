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

    /**
     * @brief Прочитывает файл "Schedule.txt" и помещает информацию из него в вектор стрингов
     */
    void ReadingFromFile();

    /**
     * @brief Устанавливает максимальное количество читаемых строчек в файле "Schedule.txt"
     * @param Новое значение
     */
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

private:

    /**
     *  @brief Сюда записываются данные извлечённые из файла "Schedule.txt"
     */
    vector<string> FileDataForTimetable;

    map<string,string> Timetable;
};

#endif // FILESCHEDULE_H
