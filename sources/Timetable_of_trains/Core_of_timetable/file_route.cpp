#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("../../Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFile_for_reading >> max_number_of_the_string;
    FileData.resize(max_number_of_the_string + 1);
    int the_number_of_passes = 0;    /// Количество проходов
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading,FileData[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;  /// Получается, что у  fileData существует
    }                           /// нулевой элемент, он пустой, так как первую строчку уже читали
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
        if (FileData[step] != "")
        {
             inputFileForRewriteMaxQuantity << endl << FileData[step];
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
    FileData[number_of_line] = ToPrintToFile;
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << endl << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();
}

string FileRoute::getFileData(int number_of_the_line) const
{
    return FileData[number_of_the_line];
}


