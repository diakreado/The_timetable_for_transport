 #ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "exception_of_core/exception_of_core.h"
#include "routes_info.h"
#include "stations_info.h"

/**
 * @brief The ParsingInfo class
 */
class ParsingInfo
{
public:

    /**
     * @brief Получает на вход строчку, парсит её, а потом заполняет информацию о маршрутах
     * @param info - строчка, которую надо парсить
     * @param routeInfo - то, с чем работают заполнители
     */
    void putInfoAboutRoutes(const std::string &info, RoutesInfo &routeInfo) noexcept;

    /**
     * @brief Получает на вход строчку, парсит её, а потом заполняет информацию о станциях
     * @param info - строчка, которую нужно парсить
     * @param stationInfo - то, с чем работают заполнители
     */
    void putInfoAboutStations(const std::string &info, StationsInfo &stationInfo) noexcept;

    /**
     * @brief Загружает данные из файла и заполняет маршруты и информацию о станциях, путём вызова двух пред идущих функций
     * @param name_of_the_file_with_route - название файла, содержащего информацию о маршрутах
     * @param name_of_the_file_with_station - название файла, содержащего информацию о станциях
     * @param routeInfo - то, с чем работают заполнители
     * @param stationInfo - то, с чем работают заполнители
     * @exception При неудачном открытие файла бросается MissingFile
     */
    void loadFromFile(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station, RoutesInfo &routeInfo, StationsInfo &stationInfo);

    /**
     * @brief Сохраняет изменения
     * @param name_of_the_file_with_route - название файла, содержащего информацию о маршрутах
     * @param name_of_the_file_with_station - название файла, содержащего информацию о станциях
     * @param routeInfo - то, с чем работают заполнители
     * @param stationInfo - то, с чем работают заполнители
     */
    void saveChanges(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station, RoutesInfo &routeInfo, StationsInfo &stationInfo);

    /**
     * @brief Сохраняет изменения проведённые со станциями
     * @param name_of_the_file_with_route - название файла, содержащего информацию о станциях
     * @param routeInfo - то, с чем работают заполнители
     */
    void saveChangesForRoute(const std::string &name_of_the_file_with_route,RoutesInfo &routeInfo);

    /**
     * @brief Сохраняет изменения проведённые с маршрутами
     * @param name_of_the_file_with_station - название файла, содержащего информацию о маршрутах
     * @param stationInfo - то, с чем работают заполнители
     */
    void saveChangesForStation(const std::string &name_of_the_file_with_station,StationsInfo &stationInfo);

private:

    /**
     * @brief Функция использующаяся для разделения строчки на название станции и информацию о ней
     * @param blockWithInfo - строчка, которую нужно парсить
     * @return Пара, первый элемент которой название станции, а второй информация о ней
     */
    std::pair<std::string, std::string> parsingForMap(const std::string &blockWithInfo) noexcept;
};

#endif // FILE_H
