#include "route_information.h"

void FileRouteInformation::readingFromFile()
{
    ifstream inputFile_for_reading("metro_Saint-Petersburg.txt");
    if (!inputFile_for_reading.is_open())
    // todo может, в этом случае, бросать исключение?
    {
        return;                                             /// Если нет файла, то и читать его нет смысла
    }

    string LineFromFile;
    getline(inputFile_for_reading, LineFromFile);           /// Считывание информации из файла(там она длинной строкой)

    string PartOfTheLine;
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

void FileRouteInformation::changeBlockFromLine(const int number_of_block, string &InExchange)
{
    // todo здесь сравнение unsigned int и int, как в других методах
    // todo дублирование этого ветвления далее.
    // Может быть, вынести метод, который проверяет number_of_block и бросает исключение
    if (number_of_block < 0 || number_of_block >= FileData.size())
    {
        throw ItemDoesNotExist();
    }

    FileData[number_of_block] = InExchange;
}

void FileRouteInformation::deleteBlockFromLine(const int number_of_block)
{
    if (number_of_block < 0 || number_of_block > FileData.size() - 1)
    {
        throw ItemDoesNotExist();
    }

    if (number_of_block != 0)
    {
        FileData.erase(FileData.begin() + number_of_block);
    }
    else
    {
        FileData[number_of_block] = "";
    }
}

void FileRouteInformation::addNewBlock()
{
    FileData.push_back("");
}

string FileRouteInformation::getFileData(int number_of_part) const
{
    if (number_of_part < 0 || number_of_part > FileData.size() - 1)
    {
        throw ItemDoesNotExist();
    }
    return FileData[number_of_part];
}

void FileRouteInformation::saveChanges()
{
    ofstream inputFileForChangeRoute("metro_Saint-Petersburg.txt");
    inputFileForChangeRoute << FileData[0];             /// В файл печатается первый элемент(он всегда есть),
    for(unsigned i = 1; i < FileData.size(); i++)      ///  а отдельно потому что перед ним не надо ставить '/'
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << '/' << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();

}
