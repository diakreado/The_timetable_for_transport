#include "station_information.h"

void FileStationInformation::readingFromFile()  noexcept
{
    std::ifstream inputFile_for_reading("metro_Saint-Petersburg.txt");
    if (!inputFile_for_reading.is_open())
    // todo может быть, бросать исключение
    {
        return;
    }
    std::string LineFromFile;
    std::string PartOfTheLine;
    // todo вы уверены, что вам нужна эта строчка? вы ее нигде не используйте
    // todo в любом, случае переименовать
    std::string Pustota;
    std::getline(inputFile_for_reading, Pustota);      /// В этой строчке находится информация о маршрутах, она уже считана
    std::getline(inputFile_for_reading, LineFromFile);
    for (unsigned i = 0; i < LineFromFile.size(); i++)
    {
        if (LineFromFile[i] == '/')
        {
            FileData.push_back(PartOfTheLine);      /// Здесь происходят действия аналогичные тем, что происходили
            PartOfTheLine = "";                    ///  в file_route.cpp
                                                   // todo если это так, то, может быть, вынести отдельный метод
                                                   // в базовый класс. Файла file_route.cpp нет
        }
        else
        {
            PartOfTheLine += LineFromFile[i];
        }
    }
    FileData.push_back(PartOfTheLine);
    inputFile_for_reading.close();
    std::string buffer;
    std::string name_of_buffer;
    std::string value_of_buffer;
    for(unsigned i = 0; i < FileData.size(); i++)
    {
        // todo what_part --> part
        int what_part;
        buffer = FileData[i];
        name_of_buffer = "";
        value_of_buffer = "";
        what_part = name;                                   /// Идёт заполение контейнера map
        for(unsigned j = 0; j < buffer.size(); j++)
        {
            if (buffer[j] == '~')
            {
                what_part = value;                    ///  отделяются имя и значение
                j++;
            }
            if (what_part == name)
            {
                name_of_buffer += buffer[j];
            }
            else
            {
                value_of_buffer += buffer[j];
            }
        }
        Timetable[name_of_buffer] = value_of_buffer;
    }
}

std::string FileStationInformation::getFileData(const std::string &number_of_the_block)
{
    if(Timetable[number_of_the_block] == "")
    {
        throw ItemDoesNotExist();
    }
    return Timetable[number_of_the_block];
}

void FileStationInformation::deleteBlockFromeLine(const std::string &by_what_name_to_delete)
{
    if(Timetable[by_what_name_to_delete] == "")
    {
        throw ItemDoesNotExist();
    }
    Timetable.erase(Timetable.find(by_what_name_to_delete));

    std::string buffer;
    std::string name_of_buffer;
    for(unsigned i = 0; i < FileData.size(); i++)       /// В FileData находится и удаляется запрашиваемый элемент
    {
        int what_part;
        buffer = FileData[i];
        name_of_buffer = "";
        what_part = name;
        for(unsigned j = 0; j < buffer.size(); j++)
        {
            if (buffer[j] == '~')
            {
                what_part = value;
                j++;
            }
            if (what_part == name)
            {
                name_of_buffer += buffer[j];
            }
        }
        if (Timetable[name_of_buffer] == "" )
        {
            FileData.erase(FileData.begin() + i);
        }
    }
}

void FileStationInformation::addNewBlockOrChangeExisting(std::string &name_of_the_block, std::string &block_description)  noexcept
{
    Timetable[name_of_the_block] = block_description;

    std::string buffer;
    std::string name_of_buffer;
    int number_of_the_same = -1;
    for(unsigned i = 0; i < FileData.size(); i++)
    {                                                    /// Проверяется содерижтся ли такой элемент в FileData или нет
        int what_part;
        buffer = FileData[i];
        name_of_buffer = "";
        what_part = name;
        // todo этот цикл for встречается в нескольких методах, постараться выделить метод
        for(unsigned j = 0; j < buffer.size(); j++)
        {
            if (buffer[j] == '~')
            {
                what_part = value;
                j++;
            }
            if (what_part == name)
            {
                name_of_buffer += buffer[j];
            }
        }
        if (name_of_buffer == name_of_the_block)
        {
            number_of_the_same = i;
        }
    }
    if (number_of_the_same != -1)
    {
        FileData[number_of_the_same] = name_of_the_block + '~' + block_description;
    }
    else
    {
        FileData.push_back(name_of_the_block + '~' + block_description);
    }
}

void FileStationInformation::saveChanges() noexcept
{
    std::ofstream inputFileForChangeTimetable;
    inputFileForChangeTimetable.open(("metro_Saint-Petersburg.txt"),std::ios::app);

    inputFileForChangeTimetable << std::endl;

    for(unsigned i = 0; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeTimetable << '/' << FileData[i];
        }
        else
        {
            if (i == 0)
            {
                i++;
                inputFileForChangeTimetable << FileData[i];
            }
        }
    }
    inputFileForChangeTimetable.close();
}

std::vector<std::string> FileStationInformation::getAllItem() noexcept
{
    return FileData;
}

