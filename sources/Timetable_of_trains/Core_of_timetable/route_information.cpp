#include "route_information.h"

void FileRouteInformation::readingFromFile() noexcept
{
    std::ifstream inputFile_for_reading("metro_Saint-Petersburg.txt");
    if (!inputFile_for_reading.is_open())
    // todo может, в этом случае, бросать исключение?
    {
        return;                                             /// Если нет файла, то и читать его нет смысла
    }

    std::string LineFromFile;
    std::getline(inputFile_for_reading, LineFromFile);           /// Считывание информации из файла(там она длинной строкой)

    std::string PartOfTheLine;
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

void FileRouteInformation::changeBlockFromLine(const int number_of_block, std::string &InExchange)
{
    checkForExistenceOfElement(number_of_block);

    FileData[number_of_block] = InExchange;
}

void FileRouteInformation::checkForExistenceOfElement(const int number_of_block)
{
    int size_of_vector = FileData.size();
    if (number_of_block < 0 || number_of_block >= size_of_vector)
    {
        throw ItemDoesNotExist();
    }
}

void FileRouteInformation::deleteBlockFromLine(const int number_of_block)
{
    checkForExistenceOfElement(number_of_block);

    if (number_of_block != 0)
    {
        FileData.erase(FileData.begin() + number_of_block);
    }
    else
    {
        FileData[number_of_block] = "";
    }
}

void FileRouteInformation::addNewBlock() noexcept
{
    FileData.push_back("");
}

std::string FileRouteInformation::getFileData(const int number_of_part)
{
    checkForExistenceOfElement(number_of_part);

    return FileData[number_of_part];
}

void FileRouteInformation::saveChanges() noexcept
{
    std::ofstream inputFileForChangeRoute("metro_Saint-Petersburg.txt");
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
