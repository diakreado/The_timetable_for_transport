#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include "file_handling.h"


// todo текстовый файл со станциями и маршрутами - какая-то боль. Почему нельзя хранить
// в первой строке номер маршрута, станции в столбик, а рядом время их работы?
// проще же будет парсить все это...
/// Если у меня будет перенос строки, то теряется кроссплатформенность.
/// Итог: должно быть два файла, в которых по одной строчке. Если есть какой-то иной путь, я его не знаю

//TODO: добавить override
/**
 *  @brief Класс, для обработки файла отвечающего за информацию о маршрутах
 */
class FileRouteInformation : public FileHandling
{
public:
    //todo как чтение из файла может быть noexcept? А вдруг файла нет или диск отвалился?
    /// Штатная ситуация
    void readingFromFile() noexcept override;

    /**
     * @brief Переписать часть строки
     * @param number_of_block - номер части строки, которую надо перезаписать
     * @param InExchange - что нужно написать на этом месте
     */
        //TODO: УЖАСНО ДИКО ПУТАЕТ именование блоками позиций в списке
    void changeBlockFromLine(const int number_of_block, std::string &InExchange);

    /**
     * @brief Удалить определённую часть отделёную знаками '/'
     * @param number_of_block - номер части, которую нужно удалить
     */
    void deleteBlockFromLine(const int number_of_block);

    /**
     * @brief Добавляет блок с информацией в строчку (добавляется в конец)
     */
    void addNewBlock() noexcept;

    /**
     * @return Количество частей, на которые разбивается строчка
     */
    unsigned getNumberOfBlocksInTheLine() const noexcept {return fileData.size();}

    void saveChanges() noexcept override;

    /**
     *  @param number_of_part - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    std::string getFileData(const int number_of_part);

private:

    /**
     * @brief Если номер принадлежит несуществующему блоку, то кидается исключение ItemDoesNotExist
     * @param number_of_block - номер блока
     */
    void checkForExistenceOfElement(const int number_of_block);

};

#endif // FILETIMETABLE_H
