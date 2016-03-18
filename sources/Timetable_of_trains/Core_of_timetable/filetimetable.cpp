#include "filetimetable.h"

FileTimetable::FileTimetable()
{
    ifstream inputFile("Timetable.txt");

    if (!inputFile.is_open())
    {
        throw FailedToOpen();
    }

    fileData.resize(30);

    int the_number_of_passes = 0;  /*Количество проходов*/

    while (inputFile.peek()!=EOF) /*Считывание до окончания файла*/
    {
        inputFile >> fileData[the_number_of_passes];
        the_number_of_passes++;
    }

    inputFile.close();
}

string FileTimetable::getFileData(int number_of_the_train)
{
    if (number_of_the_train < 0 || number_of_the_train > 29)
    {
        throw BeyondTheArray();
    }

    return fileData[number_of_the_train];
}
