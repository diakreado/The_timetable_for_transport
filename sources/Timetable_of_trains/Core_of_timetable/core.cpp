#include "core.h"

CoreOfTimetable::CoreOfTimetable()
{
    right = usual_user;
    try
    {
        DataSetOfTheRoute.readingFromFile();     /// Читаются файлы "Routetable.txt"  и "Schedule.txt"  и если, были
        DataSetOfTimetable.readingFromFile();   /// проблемы, кидаются исключения, и ставиться флаг неудачно прочитаны
    }
    catch(FailedToOpen)
    {
        /// Вроде как, ничего не надо делать, потому что уже всё сделано
    }
    catch(EmptyFile)
    {
    }
}

void CoreOfTimetable::issuanceOfRights(int const what_rights)
{
    if (what_rights == 1)
    {
        right = administrator;
    }
    else
    {
        right = usual_user;
    }
}

bool CoreOfTimetable::informationOfTheRights() const
{
    return right;
}

vector<string> CoreOfTimetable::getRouteOfTrain(int number_of_the_route)
{
    if (number_of_the_route < 1 || number_of_the_route > DataSetOfTheRoute.getMaxQuantityStringInFile() + 1)
    {                                /// Бросается, если номер маршрута неверен, но если спросили про номер на 1
        throw RouteDoesNotExist();  ///  больше, чем размер, то возвращяется пустой вектор, сделанно для того, чтобы
    }                              ///   нормально работало добавление нового маршрута, возможно исправлю на более
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false ||                    /// правильную версию
            number_of_the_route == DataSetOfTheRoute.getMaxQuantityStringInFile() + 1)
    {
        vector<string> Null;        ///  Если была ошибка при чтение файла,
        return Null;               ///  то возвращяем пустой вектор (нет файла, нет данных)
    }
    number_of_the_route--;      /// Так как отсчёт с нуля
    string StringFromFile = DataSetOfTheRoute.getFileData(number_of_the_route);
    vector<string> OutputVectorString;
    char symbol_int_string;
    string PartOfTheLineFromFile;
    for (unsigned int character_number = 0; character_number < StringFromFile.length(); character_number++)
    {
        symbol_int_string = StringFromFile[character_number];
        if (symbol_int_string == ' ')
        {
            OutputVectorString.push_back(PartOfTheLineFromFile);
            PartOfTheLineFromFile = "";
        }
        else
        {
            if (symbol_int_string == '_')       /// Заменяются знаки '_' на пробелы
            {
                symbol_int_string = ' ';
            }
            PartOfTheLineFromFile += symbol_int_string;
        }
    }
    OutputVectorString.push_back(PartOfTheLineFromFile);
    return OutputVectorString;
}

string CoreOfTimetable::getWhenStartMovementOnTheStation(string const &name_of_the_station)
{
    return DataSetOfTimetable.getFileData(name_of_the_station);
}

string CoreOfTimetable::findSuitableRoute(string &departure, string &arrival)
{
    departure = "123";                  ///  ToDo  Не относиться к MVP, но если будет время реализую
    arrival = "321";
    return "Hello";
}

void CoreOfTimetable::changeRouteTable(unsigned int choice_route,unsigned int choice_station,string &what_to_replace)
{
    vector<string> NewVariantOfString = getRouteOfTrain(choice_route);                   /// Удобнее работать сразу с
    choice_station--;            /// потому что с отсчёт элементов массива с нуля       ///  сформированым вектором
    string OneSationFromTheRoute;  /// Какая-то станция из маршрута  (один элемент vector)
    for (unsigned int i = 0; i < NewVariantOfString.size(); i++)
    {
        OneSationFromTheRoute = NewVariantOfString[i];
        for (unsigned int j = 0; j < OneSationFromTheRoute.size(); j++)
        {
            if (OneSationFromTheRoute[j] == ' ')     /// Заменяем пробелы в строчках, считаных из файла,
            {                                         ///  но преобразованых в вектор, знаком "_"
                OneSationFromTheRoute[j] = '_';
            }
        }
        NewVariantOfString[i] = OneSationFromTheRoute;
    }
    for (unsigned int i = 0; i < what_to_replace.size(); i++)
    {
        if (what_to_replace[i] == ' ')
        {
            what_to_replace[i] = '_';       /// Заменяем пробелы в введённой строчке знаком "_"
        }
    }
    if(DataSetOfTheRoute.getInformAboutSuccessfullyReading() == false || choice_station >= NewVariantOfString.size())
    {
        NewVariantOfString.push_back(what_to_replace);  /// Если файл плохо прочитан или номер вводимой станции
    }                                                  /// больше чем размер существующего vector
    else
    {
        NewVariantOfString[choice_station] = what_to_replace;
    }
    string ToPrintToFile;                                       /// Та строчка, что будет напечатана в файл
    for (unsigned int i = 0; i < NewVariantOfString.size(); i++)
    {
        ToPrintToFile += NewVariantOfString[i] + ' ';
    }
    bool correct_beginning_of_the_line = 0;  /// Правильное ли начало строки
    unsigned int size_of_string;     /// Говорится, что можно уменьшить область видимости, но я не хочу определять её
    while(correct_beginning_of_the_line == 0)                                               ///  в цикле
    {
        size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ' || ToPrintToFile[size_of_string] == '_')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }
    choice_route--;    /// Потому что отсчёт с нуля
    DataSetOfTheRoute.changeTable(choice_route,ToPrintToFile);
}

void CoreOfTimetable::changeTimetable(string &what_change, string &in_exchange)
{
    string abc = what_change + in_exchange;
    /// Просто нет реализации, а действие сделано, чтобы не выводилось предупреждение
}

void CoreOfTimetable::removeStationFromTimetalbe(const string &what_remove)
{
    DataSetOfTimetable.removeLine(what_remove);
}

