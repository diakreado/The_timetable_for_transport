#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


/// Смысл класса в обмене информации между ядром и файлом
class FileTimetable
{
public:
    FileTimetable();

    ///  Получить строчку из файла по её номеру
    string getFileData(int  number_of_the_train) const;

private:
    /// Сюда записываются данные извлечённые из файла
    vector<string> fileData;

    int max_number_of_the_string;
};

/// Не удалось открыть файл
class FailedToOpen : public exception {};

/// Выход за пределы массива
class BeyondTheArray : public exception {};

#endif // FILETIMETABLE_H
