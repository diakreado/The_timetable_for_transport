#include "file_route.h"

void FileRoute::ReadingFromFile()
{
    ifstream inputFile_for_reading("../../Routetable.txt");

    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFile_for_reading >> max_number_of_the_string;

    FileDataForRoute.resize(max_number_of_the_string + 1);

    int the_number_of_passes = 0;    /// Количество проходов

    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading,FileDataForRoute[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;  /// Получается, что у  fileData существует
    }                           /// нулевой элемент, он пусой, так как первую строчку уже читали

    inputFile_for_reading.close();
}

void FileRoute::setMaxQuantityStringInFile(int const new_max_quantity)
{
    ofstream inputFileForRewriteMaxQuantity("../../Routetable.txt");

    if (!inputFileForRewriteMaxQuantity.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFileForRewriteMaxQuantity << new_max_quantity;

    for (int step = 0; step < max_number_of_the_string; step++)
    {
        if (FileDataForRoute[step] != "")
        {
             inputFileForRewriteMaxQuantity << endl << FileDataForRoute[step];
        }
    }

    inputFileForRewriteMaxQuantity.close();
}

void FileRoute::changeTable(const int number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("../../Routetable.txt");

    if (!inputFileForChangeRoute.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }

    inputFileForChangeRoute << max_number_of_the_string;

    FileDataForRoute[number_of_line] = ToPrintToFile;

    for(unsigned int i = 0; i < FileDataForRoute.size(); i++)
    {
        if (FileDataForRoute[i] != "")
        {
            inputFileForChangeRoute << endl << FileDataForRoute[i] ;
        }
    }

    inputFileForChangeRoute.close();
}

string FileRoute::getFileData(int number_of_the_line) const
{
    return FileDataForRoute[number_of_the_line];
}


