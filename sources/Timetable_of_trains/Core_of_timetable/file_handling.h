#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

/**
 *  @brief Абстрактный класс объединяющий взаимодействие с файлами
 */
// todo дописать noexcept для методов, не генерирующих исключения
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
    std::vector<std::string> FileData;
};
//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class ItemDoesNotExist : public std::exception {};


#endif // FILE_H
