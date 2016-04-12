#include "file_timetable.h"

void FileTimetable::readingFromFile()
{
    ifstream inputFile_for_reading("Schedule.txt");     ///ToDo сделать так, чтобы всё читалось с одной строки
    if (!inputFile_for_reading.is_open())
    {
        have_successfully_read_the_file = false;
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    string LineFromFile;
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading, LineFromFile); /// Получить строчку(на вход принимает поток откуда и место куда)
        FileData.push_back(LineFromFile);
    }
    inputFile_for_reading.close();
    have_successfully_read_the_file = true;
    string buffer;
    string name_of_buffer;
    string value_of_buffer;
    int what_part;
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        buffer = FileData[i];
        name_of_buffer = "";
        value_of_buffer = "";
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
            else
            {
                value_of_buffer += buffer[j];
            }
        }
        Timetable[name_of_buffer] = value_of_buffer;
    }
}

string FileTimetable::getFileData(string const name_of_station)
{
    if(Timetable[name_of_station] == "")
    {
        throw StationDoesNotExist();
    }
    return Timetable[name_of_station];
}

void FileTimetable::removeLine(string const what_remove)
{
    if(Timetable[what_remove] == "")
    {
        throw StationDoesNotExist();
    }
    Timetable.erase(Timetable.find(what_remove));
    ofstream inputFileForChangeTimetable("Schedule.txt");
    string buffer;
    string name_of_buffer;
    string value_of_buffer;
    int what_part;
    for(unsigned int i = 0; i < FileData.size(); i++)   /// ToDo  это был копипаст, нужно убрать лишнее
    {
        buffer = FileData[i];
        name_of_buffer = "";
        value_of_buffer = "";
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
            else
            {
                value_of_buffer += buffer[j];
            }
        }
        if (Timetable[name_of_buffer] == "" )
        {
            FileData[i] = "";
            continue;
        }
    }
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeTimetable << endl << FileData[i] ;
        }
    }
    inputFileForChangeTimetable.close();
}







