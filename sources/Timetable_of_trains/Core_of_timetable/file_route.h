#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


/**
 *  @brief Смысл класса в обмене информации между ядром и файлом
 */
class FileTimetable
{
public:
    void ReadingFromFile();

    /**
     *  @param Номер маршрута
     *  @return Строчка с необходимым маршрутом
     */
    string getFileData(int number_of_the_route) const;

    /**
     * @return Максимальное читаемое количество строчек в файле
     */
    int getMaxQuantityStringInFile() const;

    /**
     * @brief Устанавливает максимальное количество читаемых строчек в файле
     *
     * @param Новое значение
     */
    void setMaxQuantityStringInFile(int const  new_max_quantity);


    void changeRouteTable(int const choice_route, string ToPrintToFile);

private:
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

#endif // FILETIMETABLE_H
