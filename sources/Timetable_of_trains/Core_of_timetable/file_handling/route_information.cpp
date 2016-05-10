#include "route_information.h"

void FileRouteInformation::readingFromFile() noexcept
{
    //todo не хардкодить названия файлов, лучше вынести их в отдельную константу.
    std::ifstream inputFile_for_reading("metro_Saint-Petersburg_route_info.txt");
    if (!inputFile_for_reading.is_open())
    {
        //todo нужно сообщать об этой ситуации
        return;                                             /// Если нет файла, то и читать его нет смысла
    }

    // todo может, в этом случае, бросать исключение?
    /// Зачем бросать исключение? Ведь если файла нет, это не плохо. Мы просто считаем, что сохранённой информации нет.
    /// Раньше я бросал исключение, но в связи с тем, что оно никак не обрабатывалось, я отказался от этого.

    //todo лучше везде объекты называть одинаково с маленьких или больших букв
    std::string LineFromFile;
    std::getline(inputFile_for_reading, LineFromFile);           /// Считывание информации из файла(там она длинной строкой)

    std::string PartOfTheLine;
    //todo использовать итератор для строк
    //todo unsigned INT
    //todo рассмотреть возможность использования методов класса string для парсинга строк
    //или регулярных выражений
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

    //TODO: УЖАСНО ДИКО ПУТАЕТ НАЗВАНИЕ С ЗАГЛАВНОЙ БУКВЫ
void FileRouteInformation::changeBlockFromLine(const int number_of_block, std::string &InExchange)
{
    checkForExistenceOfElement(number_of_block);

    FileData[number_of_block] = InExchange;
}

//todo: рассмотреть возможность возвращения boolean значения, если проверка не прошла
void FileRouteInformation::checkForExistenceOfElement(const int number_of_block)
{
    int size_of_vector = FileData.size();
    if (number_of_block < 0 || number_of_block >= size_of_vector)
    {
        throw ItemDoesNotExist();                    /// проверяется, чтобы избежать обращения к несуществующим ячейкам
    }
}

void FileRouteInformation::deleteBlockFromLine(const int number_of_block)
{
    checkForExistenceOfElement(number_of_block);

    if (number_of_block != 0 || FileData.size() > 1)
    {
        FileData.erase(FileData.begin() + number_of_block);    /// Если элемент не нулевой или элементов больше 1,
    }                                                         ///   то удаляем его, а если первый,
    else                                                     ///    то заменяем пустой строчкой.
    {
        //TODO: выглядит подозрительно, зачем понадобился этот хак
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
        //todo не хардкодить названия файлов, лучше вынести их в отдельную константу.
    std::ofstream inputFileForChangeRoute("metro_Saint-Petersburg_route_info.txt");

    inputFileForChangeRoute << FileData[0];        /// В файл печатается первый элемент(он всегда есть),
                                                  ///  а отдельно потому что перед ним не надо ставить '/'
    //TODO unsigned INT
    for(unsigned i = 1; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeRoute << '/' << FileData[i] ;
        }
    }
    inputFileForChangeRoute.close();

}
