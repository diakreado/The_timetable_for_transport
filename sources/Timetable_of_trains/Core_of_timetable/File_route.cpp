#include "file_route.h"
#include "core.h"

void FileTimetable::ReadingFromFile()
{
    ifstream inputFile_for_reading("../../Routetable.txt");

    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFile_for_reading >> max_number_of_the_string;

    fileData.resize(max_number_of_the_string + 1);

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
    return fileData[number_of_the_route];
}

int FileTimetable::getMaxQuantityStringInFile()const
{
    return max_number_of_the_string;
}

void FileTimetable::setMaxQuantityStringInFile(int const new_max_quantity)
{
    ofstream inputFileForRewriteMaxQuantity("../../Routetable.txt");

    if (!inputFileForRewriteMaxQuantity.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFileForRewriteMaxQuantity << new_max_quantity;

    for (int step = 0; step < max_number_of_the_string; step++)
    {
        if (fileData[step] != "")
        {
             inputFileForRewriteMaxQuantity << endl << fileData[step];
        }
    }

    inputFileForRewriteMaxQuantity.close();
}

void FileTimetable::changeRouteTable(const int choice_route, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("../../Routetable.txt");

    if (!inputFileForChangeRoute.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFileForChangeRoute << max_number_of_the_string;

    fileData[choice_route] = ToPrintToFile;

    for(unsigned int i = 0; i < fileData.size(); i++)
    {
        if (fileData[i] != "")
        {
            inputFileForChangeRoute << endl << fileData[i] ;
        }
    }

    inputFileForChangeRoute.close();
}





