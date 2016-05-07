#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include "file_handling.h"
#include <map>

//todo убрать What из названия
//todo использовать enum с областью видимости
enum what_part_of_buffer{name = 0, value = 1};

/**
 *  @brief Класс,для обработки второй строчки файла, в которой находится информация о станциях
 */
// todo дописать noexcept для методов, не генерирующих исключения
class FileStationInformation : public FileHandling
{
public:

    void readingFromFile() override;

    /**
     * @brief Добавляет блок( отделённый знаками '/') с информацией в общую строчку или изменяет существующий
     * @param name_of_the_block - название блока, которому принадлежит информация
     * @param block_description - информация, которую нужно добавить
     */
    void addNewBlockOrChangeExisting(string &name_of_the_block, string &block_description);

    /**
     *  @param number_of_the_block - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    string getFileData(const string &number_of_the_block);

    /**
     *  @brief Удаляет блок с информацией
     *  @param by_what_name_to_delete - название блока, который нужно удалить
     */
    // todo возможно, в названии метода лишняя буква ...From"e"Line(...)
    void deleteBlockFromeLine(const string &by_what_name_to_delete);

    /**
     * @return Возвращает все элементы находящиеся в контейнерах
     */
    vector<string> getAllItem();

    void saveChanges() override;

private:

    /**
     *  @brief Удобный формат хранения извлечённых данных
     */
    //todo в комментарии указать, что конкретно хранится в строках
    map<string,string> Timetable;
};

#endif // FILESCHEDULE_H
