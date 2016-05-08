#ifndef FILESCHEDULE_H
#define FILESCHEDULE_H

#include "file_handling.h"
#include <map>

enum class part_of_buffer{name = 0, value = 1};

/**
 *  @brief Класс,для обработки второй строчки файла, в которой находится информация о станциях
 */
class FileStationInformation : public FileHandling
{
public:

    void readingFromFile() noexcept override;

    /**
     * @brief Добавляет блок( отделённый знаками '/') с информацией в общую строчку или изменяет существующий
     * @param name_of_the_block - название блока, которому принадлежит информация
     * @param block_description - информация, которую нужно добавить
     */
    void addNewBlockOrChangeExisting(std::string &name_of_the_block, std::string &block_description) noexcept;

    /**
     *  @param number_of_the_block - номер запрашиваемой части строки
     *  @return Строчка с необходимыми данными
     */
    std::string getFileData(const std::string &number_of_the_block);

    /**
     *  @brief Удаляет блок с информацией
     *  @param by_what_name_to_delete - название блока, который нужно удалить
     */
    void deleteBlockFromLine(const std::string &by_what_name_to_delete);

    /**
     * @return Возвращает все элементы находящиеся в контейнерах
     */
    std::vector<std::string> getAllItem() noexcept;

    void saveChanges() noexcept override;

private:

    /**
     *  @brief Удобный формат хранения извлечённых данных
     */
    //todo в комментарии указать, что конкретно хранится в строках
    std::map<std::string,std::string> Timetable;
};

#endif // FILESCHEDULE_H
