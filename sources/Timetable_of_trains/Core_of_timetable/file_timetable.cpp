#include "file_timetable.h"

void FileTimetable::readingFromFile()
{
    ifstream inputFile_for_reading("Schedule.txt");
    if (!inputFile_for_reading.is_open())
    {
        return;
    }
    string LineFromFile;
    string PartOfTheLine;
    getline(inputFile_for_reading, LineFromFile);
    for (unsigned i = 0; i < LineFromFile.size(); i++)
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
    string buffer;
    string name_of_buffer;
    string value_of_buffer;
    int what_part;        ///  Cppcheck говорит, что можно уменьшить видимость, но стоит ли определять её в цикле?
    for(unsigned i = 0; i < FileData.size(); i++)
    {
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

string FileTimetable::getFileData(const string &name_of_station)
{
    if(Timetable[name_of_station] == "")
    {
        throw StationDoesNotExist();
    }
    return Timetable[name_of_station];
}

void FileTimetable::removeLine(const string &what_remove)
{
    if(Timetable[what_remove] == "")
    {
        throw StationDoesNotExist();
    }
    Timetable.erase(Timetable.find(what_remove));

    string buffer;
    string name_of_buffer;
    int what_part;
    for(unsigned i = 0; i < FileData.size(); i++)       /// В FileData находиться и удаляется запрашиваемый элемент
    {
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

void FileTimetable::addStationInTimetable(string &what_add, string &what_value)
{
    Timetable[what_add] = what_value;

    string buffer;
    string name_of_buffer;
    int what_part;
    int number_of_the_same = -1;
    for(unsigned i = 0; i < FileData.size(); i++)
    {                                                    /// Проверяется содерижтся ли такой элемент в FileData или нет
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
        if (name_of_buffer == what_add)
        {
            number_of_the_same = i;
        }
    }
    if (number_of_the_same != -1)
    {
        FileData[number_of_the_same] = what_add + '~' + what_value;
    }
    else
    {
        FileData.push_back(what_add + '~' + what_value);
    }
}

void FileTimetable::saveChanges()
{
    ofstream inputFileForChangeTimetable("Schedule.txt");

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

vector<string> FileTimetable::getAllItem()
{

    return FileData;
}

