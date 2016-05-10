#include "file_route_information.h"

void FileRouteInformation::readingFromFile() noexcept
{
    //todo не хардкодить названия файлов, лучше вынести их в отдельную константу.
    /// Учту
    std::ifstream inputFile_for_reading("metro_Saint-Petersburg_route_info.txt");
    if (!inputFile_for_reading.is_open())
    {
        //todo нужно сообщать об этой ситуации
        /// Зачем? Эта ситуация всё равно обыгрывается
        return;                                             /// Если нет файла, то и читать его нет смысла
    }

    // todo может, в этом случае, бросать исключение?
    /// Зачем бросать исключение? Ведь если файла нет, это не плохо. Мы просто считаем, что сохранённой информации нет.
    /// Раньше я бросал исключение, но в связи с тем, что оно никак не обрабатывалось, я отказался от этого.

    std::string lineFromFile;
    std::getline(inputFile_for_reading, lineFromFile);           /// Считывание информации из файла(там она длинной строкой)

    std::string partOfTheLine;
    //todo использовать итератор для строк
    //todo рассмотреть возможность использования методов класса string для парсинга строк
    //или регулярных выражений
    for (unsigned int  i = 0; i < lineFromFile.size(); i++)
    {
        if (lineFromFile[i] == '/')
        {
            fileData.push_back(partOfTheLine);       /// Если встречаем символ '/', то следовательно это новый элемент
            partOfTheLine = "";
        }
        else
        {
            partOfTheLine += lineFromFile[i];
        }
    }
    fileData.push_back(partOfTheLine);
    inputFile_for_reading.close();
}

    //TODO: УЖАСНО ДИКО ПУТАЕТ НАЗВАНИЕ С ЗАГЛАВНОЙ БУКВЫ
void FileRouteInformation::changeBlockFromLine(const int number_of_block, std::string &InExchange)
{
    checkForExistenceOfElement(number_of_block);

    fileData[number_of_block] = InExchange;
}

//todo: рассмотреть возможность возвращения boolean значения, если проверка не прошла
void FileRouteInformation::checkForExistenceOfElement(const int number_of_block)
{
    int size_of_vector = fileData.size();
    if (number_of_block < 0 || number_of_block >= size_of_vector)
    {
        throw ItemDoesNotExist();                    /// проверяется, чтобы избежать обращения к несуществующим ячейкам
    }
}

void FileRouteInformation::deleteBlockFromLine(const int number_of_block)
{
    checkForExistenceOfElement(number_of_block);

    fileData.erase(fileData.begin() + number_of_block);
}

void FileRouteInformation::addNewBlock() noexcept
{
    fileData.push_back("");
}

std::string FileRouteInformation::getFileData(const int number_of_part)
{
    checkForExistenceOfElement(number_of_part);

    return fileData[number_of_part];
}

void FileRouteInformation::saveChanges() noexcept
{
        //todo не хардкодить названия файлов, лучше вынести их в отдельную константу.
    std::ofstream inputFileForChangeRoute("metro_Saint-Petersburg_route_info.txt");

    inputFileForChangeRoute << fileData[0];        /// В файл печатается первый элемент(он всегда есть),
                                                  ///  а отдельно потому что перед ним не надо ставить '/'
    for(unsigned int i = 1; i < fileData.size(); i++)
    {
        if (fileData[i] != "")
        {
            inputFileForChangeRoute << '/' << fileData[i] ;
        }
    }
    inputFileForChangeRoute.close();

}
