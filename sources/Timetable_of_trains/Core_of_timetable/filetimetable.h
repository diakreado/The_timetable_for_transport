#ifndef FILETIMETABLE_H
#define FILETIMETABLE_H

#include <fstream>
#include <string>

using namespace std;

class FileTimetable
{
public:
    FileTimetable();

    string getFileData();

private:
    string fileData;
};

class FailedToOpen : public exception {}; /* не удалось открыть файл*/

#endif // FILETIMETABLE_H
