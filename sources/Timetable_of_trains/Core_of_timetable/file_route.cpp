#include "file_route.h"

void FileRoute::readingFromFile()
{
    ifstream inputFile_for_reading("Routetable.txt");
    if (!inputFile_for_reading.is_open())
    {
        return;                                             /// Если нет файла, то и читать его нет смысла
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
}

void FileRoute::changeTable(const unsigned number_of_part, string &ToPrintToFile)
{
    if (ToPrintToFile == "" && number_of_part != 0)
    {
        FileData.erase(FileData.begin()+number_of_part);
        return;
    }
    if (ToPrintToFile == " ")
    {
        ToPrintToFile = "";
    }
    if(number_of_part >= FileData.size())
    {
        FileData.push_back(ToPrintToFile);          /// Если файл плохо прочитан или номер вводимой станции
    }                                              /// больше чем размер существующей строчки
    else
    {
        FileData[number_of_part] = ToPrintToFile;
    }
}


string FileRoute::getFileData(int number_of_the_line) const
{
    return FileData[number_of_the_line];
}

void FileRoute::saveChanges()
{
    ofstream inputFileForChangeRoute("Routetable.txt");
    inputFileForChangeRoute << FileData[0];             /// В файл печатается первый элемент(он всегда есть),
    for(unsigned i = 1; i < FileData.size(); i++)  ///  а отдельно потому что перед ним не надо ставить '/'
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << '/' << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();

}
