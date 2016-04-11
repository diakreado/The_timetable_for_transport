#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("../../Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    string LineFromFile;
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading, LineFromFile); /// Получить строчку(на вход принимает поток откуда и место куда)
        FileData.push_back(LineFromFile);
    }
    inputFile_for_reading.close();
}

void FileRoute::changeTable(const int number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("../../Routetable.txt");
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
    return FileData[number_of_the_line - 1];
}


