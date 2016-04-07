#include "file_timetable.h"

void FileTimetable::ReadingFromFile()
{
    ifstream inputFile_for_reading("../../Schedule.txt");
    if (!inputFile_for_reading.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFile_for_reading >> max_number_of_the_string;
    FileDataForTimetable.resize(max_number_of_the_string + 1);
    int the_number_of_passes = 0;    /// Количество проходов
    while (inputFile_for_reading.peek()!=EOF)    /// Считывание до окончания файла
    {
        getline(inputFile_for_reading,FileDataForTimetable[the_number_of_passes]); /// Получить строчку(на вход принимает поток откуда и место куда)
        the_number_of_passes++;  /// Получается, что у  fileData существует
    }                           /// нулевой элемент, он пустой, так как первую строчку уже читали
    inputFile_for_reading.close();
    int empty_string = 0;
    for(unsigned int i = 0; i < FileDataForTimetable.size(); i++)
    {
        if (FileDataForTimetable[i] == "")
        {
            empty_string++;
        }
    }
    FileDataForTimetable.resize(max_number_of_the_string - empty_string);
    string buffer;
    string name_of_buffer;
    string value_of_buffer;
    int what_part;
    for(unsigned int i = 0; i < FileDataForTimetable.size(); i++)
    {
        buffer = FileDataForTimetable[i];
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
        if (FileDataForTimetable[step] != "")
        {
            inputFileForRewriteMaxQuantity << endl << FileDataForTimetable[step];
        }
    }
    inputFileForRewriteMaxQuantity.close();
}

void FileTimetable::changeTable(int const number_of_line, string ToPrintToFile)
{
    ofstream inputFileForChangeRoute("../../Schedule.txt");
    if (!inputFileForChangeRoute.is_open())
    {
        throw FailedToOpen();      /// Исключение бросается при неудачном открытие файла
    }
    inputFileForChangeRoute << max_number_of_the_string;
    FileDataForTimetable[number_of_line] = ToPrintToFile;
    for(unsigned int i = 0; i < FileDataForTimetable.size(); i++)
    {
        if (FileDataForTimetable[i] != "")
        {
            inputFileForChangeRoute << endl << FileDataForTimetable[i] ;
        }
    }
    inputFileForChangeRoute.close();
}

string FileTimetable::getFileData(string const name_of_station)
{
    return Timetable[name_of_station];
}
