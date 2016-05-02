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
     * @brief Переписать часть строки
     * @param number_of_part - номер части строки, которую надо перезаписать
     * @param ToPrintToFile - что нужно написать на этом месте
     */
    void changePartOfTheLine(const int number_of_part,  string &InExchange);


    void deletePartOfTheLine(const int number_of_part);

    void addPartOfTheLine();

    /**
     * @return Количество частей, на которые разибвается строчка
     */
    unsigned getNumberOfPartsOfLine() const {return FileData.size();}

    void saveChanges() override;

    /**
     *  @param number_of_the_part - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    string getFileData(int number_of_part) const;
};

#endif // FILETIMETABLE_H
