#include "core.h"

//TODO: это бред, что у вас парсинг файлов размазан по всему приложению
CoreOfTimetable::CoreOfTimetable() : rights(rights_of_customers::user)
{
    //todo поскольку наличие файла не является необходимым для создания объекто, то
    //лучше не заниматься чтением файла в конструкторе (велик риск отсутствия файла)
    //сделать отдельный метод и передавать в него объект, реализиющий получение данных
    //из внешнего источника

    DataSetOfInfoRoute.readingFromFile();
    DataSetOfInfoStation.readingFromFile();
}

void CoreOfTimetable::issuanceOfRights(const rights_of_customers rights) noexcept
{
    if (rights == rights_of_customers::administrator)
    {
        this->rights = rights_of_customers::administrator;
    }
    else
    {
        this->rights = rights_of_customers::user;
    }
}

rights_of_customers CoreOfTimetable::informationOfTheRights() const noexcept
{
    return rights;
}

std::vector<std::string> CoreOfTimetable::getItinerary(int number_of_the_route)
{
    number_of_the_route--;      /// Так как отсчёт с нуля, но пользователь не должен этого знать

    std::vector<std::string> Route;
    try
    {
        std::string StringFromFile = DataSetOfInfoRoute.getFileData(number_of_the_route);
        std::string NameOfTheStation;
        //todo: это бред...
        for (char symbol_in_string : StringFromFile)
        {
            if (symbol_in_string == ',')
            {                                           /// Была получена строчка, в которой через запятую находятся
                Route.push_back(NameOfTheStation);     ///  название станций, а мы её превращяем в vector<string>, где
                NameOfTheStation = "";                ///   элемент вектора название станции
            }
            else
            {
                NameOfTheStation += symbol_in_string;
            }
        }
        Route.push_back(NameOfTheStation);
    }
    // todo мы ловим исключение, чтобы бросить другое? может быть, я не понимаю чего-то
    /// Тут непростая ситуация, класс работающий с файлом не должен знать про маршруты, следовательно RouteDoesNotExist
    /// он бросать не может, а если не перекидывать то, исключение малоинформативно, в ближайшем будущем будет реализован
    /// метод у RouteDoesNotExist позволяющий получить какую-нибудь информацию об ошибке

    catch(ItemDoesNotExist&)
    {
        number_of_the_route++;  /// Так как пользователь вводил именно это число
        throw RouteDoesNotExist(number_of_the_route);
    }

    return Route;
}

std::string CoreOfTimetable::getInformationAboutStation(const std::string &name_of_the_station)
{
    try
    {
        return DataSetOfInfoStation.getFileData(name_of_the_station);
    }
    //TODO: проблема в дизайне, если приходится так перекидывать исключения
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist(name_of_the_station);
    }
}

std::string CoreOfTimetable::getInformationAboutStation(int choice_route, int choice_station)
{
    std::vector<std::string> Route = getItinerary(choice_route);

    choice_station--;
    std::string name_of_the_station = Route[choice_station];
                                                                    /// Добавляется название станции, так как
    std::string output_string = name_of_the_station + " : ";       ///  пользователь указывает его не явно

    try               /// действия те же, что и выше но только мы название стаанции получаем из информации о маршрутах
    {
        output_string += DataSetOfInfoStation.getFileData(name_of_the_station);
    }
    //TODO: проблема в дизайне, если приходится так перекидывать исключения когда у вас полтора класса в программе
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist(name_of_the_station);
    }

    return output_string;
}

void CoreOfTimetable::changeStationInItinerary(int choice_route, int choice_station, std::string &what_to_replace)
{
    std::vector<std::string> Route = getItinerary(choice_route);
    choice_station--;
    choice_route--;

    int route_size = Route.size();  /// Чтобы не было конфликта типов при сравнение

    if(choice_station >= route_size || choice_station < 0)
    {
        choice_station++;     /// Потому что пользователь вводил именно такое число
        throw StationDoesNotExist(choice_station);
    }
    else
    {
        Route[choice_station] = what_to_replace;
    }

    std::string ToPrintToFile;
    //todo: это бред2...
    for (unsigned int i = 0; i < Route.size()-1; i++)
    {
        ToPrintToFile += Route[i] + ',';
    }
    ToPrintToFile += Route[Route.size()-1];   /// Потому что в конце запятая не нужна

    bool correct_beginning_of_the_line = 0;          /// Правильное ли начало строки
    while(correct_beginning_of_the_line == 0)
    {
        unsigned int size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале строки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }                                            /// Потому что отсчёт с нуля

    try
    {
        DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
    }
    //TODO: проблема в дизайне, если приходится так перекидывать исключения когда у вас полтора класса в программе
    catch(ItemDoesNotExist&)
    {
        choice_route++;
        throw RouteDoesNotExist(choice_route);
    }
}

int CoreOfTimetable::addRoute() noexcept
{
    int choice_route = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();

    DataSetOfInfoRoute.addNewBlock();

    choice_route++;
    return choice_route;
}

void CoreOfTimetable::deleteRoute(int choice_route)
{
    choice_route--;

    try
    {
        DataSetOfInfoRoute.deleteBlockFromLine(choice_route);
    }
    //TODO: проблема в дизайне, если приходится так перекидывать исключения когда у вас полтора класса в программе
    catch(ItemDoesNotExist&)
    {
        choice_route++;
        throw RouteDoesNotExist(choice_route);
    }
}

void CoreOfTimetable::deleteStationFromItinerary(int choice_route, int choice_station)
{
    std::vector<std::string> NewVariantOfString = getItinerary(choice_route);
    choice_station--;

    int size_of_vector = NewVariantOfString.size();

    if(choice_station >= size_of_vector || choice_station < 0)
    {
        choice_station++;
        throw StationDoesNotExist(choice_station);
    }

    NewVariantOfString[choice_station] = "";
    std::string ToPrintToFile;
    //todo: это бред3...
    for (unsigned i = 0; i < NewVariantOfString.size()-1; i++)
    {
        if (NewVariantOfString[i] != "")
        {
            ToPrintToFile += NewVariantOfString[i] + ',';
        }
    }

    if (NewVariantOfString[NewVariantOfString.size()-1] != "")
    {
        ToPrintToFile += NewVariantOfString[NewVariantOfString.size()-1];   /// Потому что в конце запятая не нужна
    }
    else
    {
        ToPrintToFile.erase(ToPrintToFile.size()-1);  /// Убрал запятую
    }

    bool correct_beginning_of_the_line = 0;

    while(correct_beginning_of_the_line == 0)
    {
        unsigned size_of_string;
        size_of_string = ToPrintToFile.size()-1;
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }

    choice_route--;                                                     /// Потому что отсчёт с нуля
    DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addStationInItinerary(int choice_route, std::string &what_to_add)
{
    std::vector<std::string> NewVariantOfString = getItinerary(choice_route);

    NewVariantOfString.push_back(what_to_add);
    std::string ToPrintToFile;

    for (unsigned i = 0; i < NewVariantOfString.size()-1; i++)
    {
        ToPrintToFile += NewVariantOfString[i] + ',';
    }
    ToPrintToFile += NewVariantOfString[NewVariantOfString.size()-1];   /// Потому что в конце запятая не нужна

    bool correct_beginning_of_the_line = 0;
    while(correct_beginning_of_the_line == 0)
    {
        unsigned size_of_string;
        size_of_string = ToPrintToFile.size()-1;
//TODO: это бред4...
        if (ToPrintToFile[size_of_string] == ' ')
        {
            ToPrintToFile.erase(ToPrintToFile.end()-1);  /// Сделано для того, чтобы если удалялся какой-либо элемент
        }                                               /// не оставалось в начале сторки символы '_' и пробелы
        else
        {
            correct_beginning_of_the_line = 1;
        }
    }

    choice_route--;                                            /// Потому что отсчёт с нуля
    DataSetOfInfoRoute.changeBlockFromLine(choice_route,ToPrintToFile);
}

void CoreOfTimetable::addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept
{
    DataSetOfInfoStation.addNewBlockOrChangeExisting(name_of_the_station, station_description);
}

void CoreOfTimetable::addInformationAboutStation(int choice_route, int choice_station, std::string &station_description)
{
    std::vector<std::string> Route = getItinerary(choice_route);

    choice_station--;
    std::string name_of_the_station = Route[choice_station];

    DataSetOfInfoStation.addNewBlockOrChangeExisting(name_of_the_station, station_description);
}

void CoreOfTimetable::removeInformationAboutStation(const std::string &what_station_to_remove)
{
    std::string new_what_station_to_remove;
    for(char j : what_station_to_remove)
    {
        if (j == '~')
        {
            break;
        }
        new_what_station_to_remove += j;
    }

    try
    {
        DataSetOfInfoStation.deleteBlockFromLine(new_what_station_to_remove);
    }
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist(what_station_to_remove);
    }
}

//TODO: слишком длинным метод
void CoreOfTimetable::removeInformationAboutStation(int choice_station)
{
    //
    std::vector<std::string> AllElement = DataSetOfInfoStation.getAllElement();

    int size_of_vector = AllElement.size();
    if (choice_station < 1 || choice_station > size_of_vector)
    {
        choice_station++;
        throw StationDoesNotExist(choice_station);
    }

    choice_station--;
    const std::string what_station_to_remove = AllElement[choice_station];

    std::string new_what_station_to_remove;
    for(char j : what_station_to_remove)
    {
        //TODO: уже видели такое
        if (j == '~')
        {
            break;
        }
        new_what_station_to_remove += j;
    }

    try
    {
        DataSetOfInfoStation.deleteBlockFromLine(new_what_station_to_remove);
    }
    catch(ItemDoesNotExist&)
    {
        throw StationDoesNotExist(new_what_station_to_remove);
    }
}

void CoreOfTimetable::saveChanges() noexcept
{
    DataSetOfInfoRoute.saveChanges();
    DataSetOfInfoStation.saveChanges();
}

int CoreOfTimetable::howManyRoutes()
{
    int how_many_routes = DataSetOfInfoRoute.getNumberOfBlocksInTheLine();
    if (how_many_routes == 0)
    {
        throw ThereAreNoRoutes();
    }
    return how_many_routes;
}

std::vector<std::string> CoreOfTimetable::getAllStationsWhichHaveDescription()  noexcept
{
    return DataSetOfInfoStation.getAllElement();
}

std::vector<std::string> CoreOfTimetable::findTrack(int num_route_from,int num_station_from,int num_route_to,int num_station_to)
{
    num_station_from--;
    num_station_to--;

    std::vector<std::string> Track;

    if (num_route_from == num_route_to)                  /// Если нужно проложить маршрут в пределах одной ветки
    {
        findTrackInOneRoute(num_route_from, num_station_from, num_station_to, Track);

        return Track;
    }

    /// В паре номера станций из двух маршрутов, с одинаковыми названиями. Первое из маршрута "откуда", второе из "куда"
    std::pair<int,int> From_To = findStationWithTheSameName(num_route_from, num_route_to);

    findTrackInOneRoute(num_route_from, num_station_from, From_To.first, Track); /// Путь по первому маршруту


    findTrackInOneRoute(num_route_to, From_To.second, num_station_to, Track); /// Путь по второму маршруту

    return Track;
}

void CoreOfTimetable::findTrackInOneRoute(int num_route, int num_station_from,
                                                              int num_station_to,std::vector<std::string> &Track)
{
    std::vector<std::string> Route = getItinerary(num_route);

    if (num_station_from < num_station_to)          /// Если мы собираемся двигаться по ветке вниз
    {
        for(int i = num_station_from; i <= num_station_to; i++)
        {
            Track.push_back(Route[i]);
        }
    }
    else                                            /// Если мы собираемся двигаться по ветке вверх
    {
        for(int i = num_station_from; i >= num_station_to; i--)
        {
            Track.push_back(Route[i]);
        }
    }
}

std::pair<int,int> CoreOfTimetable::findStationWithTheSameName(int num_route_one, int num_route_two)
{
    std::vector<std::string> RouteOne = getItinerary(num_route_one);
    std::vector<std::string> RouteTwo = getItinerary(num_route_two);

    /// Не знаю, как иначе

    int size_one = RouteOne.size();
    int size_two = RouteTwo.size();

    for(int i = 0; i < size_one; i++)
    {
        for(int j = 0; j < size_two; j++)
        {
            if (RouteOne[i] == RouteTwo[j])
            {
                std::pair<int,int> answer;

                answer.first = i;
                answer.second = j;

                return answer;
            }
        }
    }

    /// ToDo Ну здесь исключение надо бросить

    std::pair<int,int> answer;

    answer.first = -1;
    answer.second = -1;

    return answer;
}




