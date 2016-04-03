#include "file.h"

string File::getFileData(int number_of_the_line) const
{
    return fileData[number_of_the_line];
}

int File::getMaxQuantityStringInFile()const
{
    return max_number_of_the_string;
}
