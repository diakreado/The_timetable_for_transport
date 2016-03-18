#include "filetimetable.h"

#include <iostream>

FileTimetable::FileTimetable()
{
    ifstream inputFile("Timetable.txt");

    if (!inputFile.is_open())
    {
        throw FailedToOpen();
    }

    string buffer;

    while (inputFile.peek()!=EOF) /*Считывание до окончания файла*/
    {
        inputFile >> buffer;
        fileData+=buffer;
    }

    inputFile.close();
}

string FileTimetable::getFileData()
{
    return fileData;
}
