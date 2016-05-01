#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file_handling.h"

/**
 *  @brief Наследник класса FileHandling, который нужен, чтобы работать с файлом "Routetable.txt"
 */
class FileRouteInformation : public FileHandling
{
public:

    void readingFromFile() override;

    /**
     * @brief Переписывает часть строчки в файле "Routetable.txt"
     * @param number_of_part - номер части строки которую надо переписать
     * @param ToPrintToFile - что нужно написать на месте части строки
     */
    void changeTable(const unsigned number_of_part,  string &ToPrintToFile);

    /**
     * @return Количество частей, на которые разибвается строчка
     */
    unsigned getMaxQuantityPartInFile() const {return FileData.size();}

    void saveChanges() override;

    /**
     *  @param number_of_the_line - часть строчки из файла "Routetable.txt"
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_line) const;
};

#endif // FILETIMETABLE_H
