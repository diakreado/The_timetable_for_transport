#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file_handling.h"

/**
 *  @brief Класс,для обработатки первой строчки файла, в которой находиться информация о маршрутах
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
    unsigned getNumberOfPartsOfLine() const {return FileData.size();}

    void saveChanges() override;

    /**
     *  @param number_of_the_part - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    string getFileData(int number_of_the_part) const;
};

#endif // FILETIMETABLE_H
