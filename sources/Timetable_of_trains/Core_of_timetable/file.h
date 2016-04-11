#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

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
    virtual void readingFromFile() = 0;

    /**
     * @return Информация о том уалось ли прочитать файл
     */
    bool getInformAboutSuccessfullyReading() {return have_successfully_read_the_file;};

    virtual ~File(){};

protected:

    /**
     * @brief Удалось ли прочитать файлы
     */
    bool have_successfully_read_the_file;

    /**
     *  @brief Сюда записываются данные извлечённые из файла
     */
    vector<string> FileData;
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
