#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        have_successfully_read_the_file = false;
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    string LineFromFile;
    string buffer;
    getline(inputFile_for_reading, LineFromFile);
    for (unsigned int i = 0; i < LineFromFile.size(); i++)
    {
        if (LineFromFile[i] == '/')
        {
            FileData.push_back(buffer);
            buffer = "";
        }
        else
        {
        buffer += LineFromFile[i];
        }
    }
    FileData.push_back(buffer);
    inputFile_for_reading.close();
    if (FileData.empty())
    {
        have_successfully_read_the_file = false;
        throw EmptyFile();      /// Исключение бросается когда файл пуст
    }
    have_successfully_read_the_file = true;
}

void FileRoute::changeTable(unsigned const int number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("Routetable.txt");
    if(have_successfully_read_the_file == false || number_of_line > FileData.size())
    {
        FileData.push_back(ToPrintToFile);
    }
    else
    {
        FileData[number_of_line] = ToPrintToFile;
    }
    inputFileForChangeRoute << FileData[0];
    for(unsigned int i = 1; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << '/' << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();
    have_successfully_read_the_file = true;
}

string FileRoute::getFileData(int number_of_the_line) const
{
    return FileData[number_of_the_line - 1];
}


