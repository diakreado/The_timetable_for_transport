#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file_handling.h"

/**
 *  @brief Класс для обработки первой строчки файла, в которой находится информация о маршрутах
 */
// todo текстовый файл со станциями и маршрутами - какая-то боль. Почему нельзя хранить
// в первой строке номер маршрута, станции в столбик, а рядом время их работы?
// проще же будет парсить все это...
// todo дописать noexcept для методов, не генерирующих исключения
class FileRouteInformation : public FileHandling
{
public:

    void readingFromFile() override;

    /**
     * @brief Переписать часть строки
     * @param number_of_block - номер части строки, которую надо перезаписать
     * @param InExchange - что нужно написать на этом месте
     */
    void changeBlockFromLine(const int number_of_block, std::string &InExchange);

    /**
     * @brief Удалить определённую часть отделёную знаками '/'
     * @param number_of_block номер части, которую нужно удалить
     */
    void deleteBlockFromLine(const int number_of_block);

    /**
     * @brief Добавляет блок с информацией в строчку (добавляется в конец)
     */
    void addNewBlock();

    /**
     * @return Количество частей, на которые разбивается строчка
     */
    unsigned getNumberOfBlocksInTheLine() const {return FileData.size();}

    void saveChanges() override;

    /**
     *  @param number_of_the_part - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    std::string getFileData(int number_of_part) const;
};

#endif // FILETIMETABLE_H
