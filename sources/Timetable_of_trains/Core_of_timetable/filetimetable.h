#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FileTimetable
{
public:
    FileTimetable();

    string getFileData(int number_of_the_train);

private:
    vector<string> fileData;
};

class FailedToOpen : public exception {}; /* не удалось открыть файл*/

class BeyondTheArray : public exception {}; /*Выход за пределы массива*/

#endif // FILETIMETABLE_H
