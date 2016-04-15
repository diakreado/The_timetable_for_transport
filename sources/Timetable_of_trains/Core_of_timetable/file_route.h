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
     * @brief Переписывает строчку в файле "Routetable.txt"
     * @param Номер строки которую надо переписать
     * @param Что нужно написать на месте строки
     */
    void changeTable(unsigned int const number_of_line, const string &ToPrintToFile);

    /**
     * @return Максимальное читаемое количество строчек в файле
     */
    int getMaxQuantityStringInFile() const {return FileData.size();}

    /**
     *  @param Номер строчки из файла "Routetable.txt"
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_line) const;
};

#endif // FILETIMETABLE_H
