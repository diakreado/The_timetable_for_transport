#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "exception_of_core/exception_of_core.h"

/**
 *  @brief Абстрактный класс объединяющий взаимодействие с файлами
 */
class FileHandling
{
public:

    /**
     * @brief Читает файл и помещает информацию из него в удобный для вывода контейнер
     */
    virtual void readingFromFile() noexcept = 0;

    /**
     * @brief Сохранить изменения в файле
     */
    virtual void saveChanges() noexcept = 0;

    virtual ~FileHandling(){}

protected:

    /**
     *  @brief Сюда записываются данные извлечённые из файла
     */
    std::vector<std::string> fileData;
};

#endif // FILE_H
