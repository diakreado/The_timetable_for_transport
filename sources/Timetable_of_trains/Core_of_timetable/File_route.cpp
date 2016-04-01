#include "file_route.h"
#include "core.h"

void FileTimetable::ReadingFromFile()
{
    ifstream inputFile_for_reading("../../Timetable.txt");

    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFile_for_reading >> max_number_of_the_string;

    fileData.resize(max_number_of_the_string);

    int the_number_of_passes = 0;    /// Количество проходов

    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading,fileData[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;  /// Получается, что у  fileData существует
    }                           /// нулевой элемент, он пусой, так как первую строчку уже читали

    inputFile_for_reading.close();
}

string FileTimetable::getFileData(int number_of_the_route) const
{
    if (number_of_the_route < 1 || number_of_the_route > max_number_of_the_string)
    {
        throw BeyondTheArray();
    }

    return fileData[number_of_the_route];
}

int FileTimetable::getMaxQuantityStringInFile()const
{
    return max_number_of_the_string;
}

void FileTimetable::setMaxQuantityStringInFile(int new_max_quantity)
{
    ofstream inputFile_for_rewrite("../../Timetable.txt");

    if (!inputFile_for_rewrite.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFile_for_rewrite << new_max_quantity;

    for (int step = 0; step < max_number_of_the_string; step++)
    {
        if (fileData[step] != "")
        {
             inputFile_for_rewrite << endl << fileData[step];
        }
    }

    inputFile_for_rewrite.close();
}






