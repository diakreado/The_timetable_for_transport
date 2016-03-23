#include "filetimetable.h"

FileTimetable::FileTimetable()
{
    ifstream inputFile("../../Timetable.txt");

    if (!inputFile.is_open())
    {
        throw FailedToOpen();   /// Исключение бросается при неудачном открытие файла
    }

    fileData.resize(30); ///  Стоит 30 временно, этот параметр будет изменять администратор спец методом

    int the_number_of_passes = 0;  /// Количество проходов

    while (inputFile.peek()!=EOF) /// Считывание до окончания файла
    {
        getline(inputFile,fileData[the_number_of_passes]);  /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;
    }

    inputFile.close();
}

string FileTimetable::getFileData(int number_of_the_train) const
{
    if (number_of_the_train < 0 || number_of_the_train > 29)
    {
        throw BeyondTheArray();
    }

    return fileData[number_of_the_train];
}
