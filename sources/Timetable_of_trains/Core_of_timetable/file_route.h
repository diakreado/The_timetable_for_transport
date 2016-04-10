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

    void setMaxQuantityStringInFile(int const  new_max_quantity);

    /**
     * @brief Переписывает строчку в файле "Routetable.txt"
     * @param Номер строки которую надо переписать
     * @param Что нужно написать на месте строки
     *
     *
     * Скоро переделаю
     */
    void changeTable(int const number_of_line, string ToPrintToFile);

    /**
     *  @param Номер строчки из файла "Routetable.txt"
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_line) const;
};

#endif // FILETIMETABLE_H
