#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include "file.h"
#include <map>

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
    string getFileData(int number_of_the_line) const;

private:

    /**
     *  @brief Сюда записываются данные извлечённые из файла "Schedule.txt"
     */
    vector<string> FileDataForTimetable;

    map<string,string> Timetable;
};

#endif // FILESCHEDULE_H
