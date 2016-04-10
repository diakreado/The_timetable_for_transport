#include "file_timetable.h"

void FileTimetable::readingFromFile()
{
    ifstream inputFile_for_reading("../../Schedule.txt");
    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFile_for_reading >> max_number_of_the_string;
    FileData.resize(max_number_of_the_string + 1);
    int the_number_of_passes = 0;    /// Количество проходов
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading,FileData[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;  /// Получается, что у  fileData существует
    }                           /// нулевой элемент, он пустой, так как первую строчку уже читали
    inputFile_for_reading.close();
    int empty_string = 0;
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        if (FileData[i] == "")
        {
            empty_string++;
        }
    }
    FileData.resize(max_number_of_the_string - empty_string);  //// ToDo переделать, тут теряются информация, при прераспределение помяти
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

void FileTimetable::setMaxQuantityStringInFile(int const  new_max_quantity)
{
    ofstream inputFileForRewriteMaxQuantity("../../Schedule.txt");
    if (!inputFileForRewriteMaxQuantity.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFileForRewriteMaxQuantity << new_max_quantity;
    for (int step = 0; step < max_number_of_the_string; step++)
    {
        if (FileData[step] != "")
        {
            inputFileForRewriteMaxQuantity << endl << FileData[step];
        }
    }
    inputFileForRewriteMaxQuantity.close();
}

void FileTimetable::changeTable(int const number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeTimetable("../../Schedule.txt");
    if (!inputFileForChangeTimetable.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFileForChangeTimetable << max_number_of_the_string;
    FileData[number_of_line] = ToPrintToFile;
    for(unsigned int i = 0; i < FileData.size(); i++)
    {
        if (FileData[i] != "")
        {
            inputFileForChangeTimetable << endl << FileData[i] ;
        }
    }
    inputFileForChangeTimetable.close();
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
    ofstream inputFileForChangeTimetable("../../Schedule.txt");
    if (!inputFileForChangeTimetable.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFileForChangeTimetable << max_number_of_the_string;
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







