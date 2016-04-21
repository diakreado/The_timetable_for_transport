#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        have_successfully_read_the_file = false;
        return;
    }
    string LineFromFile;
    string PartOfTheLine;
    getline(inputFile_for_reading, LineFromFile);           /// Считывание информации из файла(там она длинной строкой)
    for (unsigned  i = 0; i < LineFromFile.size(); i++)
    {
        if (LineFromFile[i] == '/')
        {
            FileData.push_back(PartOfTheLine);       /// Если встречаем символ '/', то следовательно это новый элемент
            PartOfTheLine = "";
        }
        else
        {
        PartOfTheLine += LineFromFile[i];
        }
    }
    FileData.push_back(PartOfTheLine);
    inputFile_for_reading.close();
    if (FileData.empty())
    {
        have_successfully_read_the_file = false;
        return;
    }
    have_successfully_read_the_file = true;   /// Если всё прочиталось хорошо, то поднимается флаг
}

void FileRoute::changeTable(const unsigned number_of_part, const string &ToPrintToFile)
{
    ofstream inputFileForChangeRoute("Routetable.txt");
    if(have_successfully_read_the_file == false || number_of_part >= FileData.size())
    {
        FileData.push_back(ToPrintToFile);          /// Если файл плохо прочитан или номер вводимой станции
    }                                              /// больше чем размер существующей строчки
    else
    {
        FileData[number_of_part] = ToPrintToFile;
    }
    inputFileForChangeRoute << FileData[0];             /// В файл печатается первый элемент(он всегда есть),
    for(unsigned i = 1; i < FileData.size(); i++)  ///  а отдельно потому что перед ним не надо ставить '/'
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << '/' << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();
    have_successfully_read_the_file = true;   /// Теперь у нас есть файл, и мы знаем, что в нём лежит инофрмация,
}                                            ///  поэтому имеем право поднять этот флаг

string FileRoute::getFileData(int number_of_the_line) const
{
    return FileData[number_of_the_line];
}


