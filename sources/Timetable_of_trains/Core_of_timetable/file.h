#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 *  @brief Абстрактный класс объединяющий взаимодействие с файлами
 */
class File
{
public:

    /**
     * @brief Прочитывает файл и помещает информацию из него в удобный для вывода контейрнер
     */
    virtual void ReadingFromFile() = 0;

    /**
     * @return Максимальное читаемое количество строчек в файле
     */
    int getMaxQuantityStringInFile() const;

    /**
     * @brief Устанавливает максимальное количество читаемых строчек в файле
     * @param Новое значение
     */
    virtual void setMaxQuantityStringInFile(int const  new_max_quantity) = 0;

    /**
     * @brief Переписывает строчку в файле
     * @param Номер строки которую надо переписать
     * @param Что нужно написать на месте строки
     */
    virtual void changeTable(int const number_of_line, string ToPrintToFile) = 0;

protected:

    /**
     * @brief Максимальное читаемое количество строчек в файле
     */
    int max_number_of_the_string;
};

/**
 * @brief Исключение "Не удалось открыть файл"
 */
class FailedToOpen : public exception {};

/**
 * @brief Исключение "Выход за пределы массива"
 */
class RouteDoesNotExist : public exception {};

#endif // FILE_H
