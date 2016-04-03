#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/**
 *  @brief Смысл класса в обмене информации между ядром и файлом
 */
class File
{
public:
    /**
     *  @param Номер строчки из файла
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_line) const;


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
     *  @brief Сюда записываются данные извлечённые из файла
     */
    vector<string> fileData;

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
