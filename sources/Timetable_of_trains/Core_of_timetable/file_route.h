#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file.h"

/**
 *  @brief Наследник класса File, который нужен, чтобы работать с файлом "Routetable.txt"
 */
class FileRoute : public File
{
public:

    void readingFromFile();

    /**
     * @brief Переписывает часть строчки в файле "Routetable.txt"
     * @param number_of_line - номер части строки которую надо переписать
     * @param ToPrintToFile - что нужно написать на месте части строки
     */
    void changeTable(const unsigned number_of_line, const string &ToPrintToFile);

    /**
     * @return Количество частей, на которые разибвается строчка
     */
    int getMaxQuantityStringInFile() const {return FileData.size();}

    /**
     *  @param number_of_the_line - часть строчки из файла "Routetable.txt"
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_line) const;
};

#endif // FILETIMETABLE_H
