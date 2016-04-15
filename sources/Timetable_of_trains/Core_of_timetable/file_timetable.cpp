#include "file_timetable.h"

void FileTimetable::readingFromFile()
{
    ifstream inputFile_for_reading("Schedule.txt");
    if (!inputFile_for_reading.is_open())
    {
        have_successfully_read_the_file = false;
        throw FailedToOpen();                       /// Исключение бросается при неудачном открытие файла
    }
    string LineFromFile;
    string PartOfTheLine;
    getline(inputFile_for_reading, LineFromFile);
    for (unsigned int i = 0; i < LineFromFile.size(); i++)
    {
        if (LineFromFile[i] == '/')
        {
            FileData.push_back(PartOfTheLine);      /// Здесь происходят действия аналогичные тем, что происходили
            PartOfTheLine = "";                    ///  в file_route.cpp
        }
        else
        {
            PartOfTheLine += LineFromFile[i];
        }
    }
    FileData.push_back(PartOfTheLine);
    inputFile_for_reading.close();
    have_successfully_read_the_file = true;
    string buffer;
    string name_of_buffer;
    string value_of_buffer;
    int what_part;        ///  Cppcheck говорит, что можно уменьшить видимость, но стоит ли определять её в цикле?
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        buffer = FileData[i];
        name_of_buffer = "";
        value_of_buffer = "";
        what_part = name;                                   /// Идёт заполение контейнера map
        for(unsigned int j = 0; j < buffer.size(); j++)
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

string FileTimetable::getFileData(string const &name_of_station)
{
    if(Timetable[name_of_station] == "")
    {
        throw StationDoesNotExist();
    }
    return Timetable[name_of_station];
}

void FileTimetable::removeLine(string const &what_remove)
{
    if(Timetable[what_remove] == "")
    {
        throw StationDoesNotExist();
    }
    Timetable.erase(Timetable.find(what_remove));
    ofstream inputFileForChangeTimetable("Schedule.txt");
    string buffer;
    string name_of_buffer;
    int what_part;
    for(unsigned int i = 0; i < FileData.size(); i++)    /// ToDo  это был копипаст, нужно убрать лишнее
    {
        buffer = FileData[i];
        name_of_buffer = "";
        what_part = name;
        for(unsigned int j = 0; j < buffer.size(); j++)
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
            FileData[i] = "";
            continue;
        }
    }
    for(unsigned int i = 0; i < FileData.size(); i++)       /// Я этот метод ещё доработаю
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







