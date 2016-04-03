#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file.h"

/**
 *  @brief Наследник класса File, который нужен, чтобы работать с файлом
 */
class FileTimetable : public File
{
public:

    /**
     * @brief Прочитывает файл и помещает информацию из него в вектор стрингов
     */
    void ReadingFromFile();

    /**
     * @brief Устанавливает максимальное количество читаемых строчек в файле
     * @param Новое значение
     */
    void setMaxQuantityStringInFile(int const  new_max_quantity);

    /**
     * @brief Переписывает строчку в файле
     * @param Номер строки которую надо переписать
     * @param Что нужно написать на месте строки
     */
    void changeTable(int const number_of_line, string ToPrintToFile);
};

#endif // FILETIMETABLE_H
