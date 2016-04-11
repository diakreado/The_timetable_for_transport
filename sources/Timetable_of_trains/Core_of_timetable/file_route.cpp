#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("../../Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        have_successfully_read_the_file = false;
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    string LineFromFile;
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading, LineFromFile); /// Получить строчку(на вход принимает поток откуда и место куда)
        FileData.push_back(LineFromFile);
    }
    inputFile_for_reading.close();
    have_successfully_read_the_file = true;
}

void FileRoute::changeTable(const int number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("../../Routetable.txt");
    if(have_successfully_read_the_file == true)
    {
        FileData[number_of_line] = ToPrintToFile;           /// ToDo Как-то неправильно печатет
    }                                                      /// надо фопиксить
    else
    {
        FileData.push_back(ToPrintToFile);
    }
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


