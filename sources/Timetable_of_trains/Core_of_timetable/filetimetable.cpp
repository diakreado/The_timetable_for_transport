#include "filetimetable.h"
#include "core_of_timetable.h"

FileTimetable::FileTimetable()
{
    ifstream inputFile("../../Timetable.txt");

    if (!inputFile.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFile >> max_number_of_the_string;

    fileData.resize(max_number_of_the_string);

    int the_number_of_passes = 0;    /// Количество проходов

    while (inputFile.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile,fileData[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;
    }

    inputFile.close();
}

string FileTimetable::getFileData(int number_of_the_train) const
{
    if (number_of_the_train < 1 || number_of_the_train > 29) /// На самом деле поле с номером 0 существует, но там содержится
    {                                                       /// информация для дальнейшей обработки файла
        throw BeyondTheArray();
    }

    return fileData[number_of_the_train];
}
