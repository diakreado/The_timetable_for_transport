#include "parsing_info.h"

void ParsingInfo::putInfoAboutRoutes(const std::string &info , RoutesInfo &routeInfo) noexcept
{
    std::string station;

    routeInfo.addRoute();

    int number_of_the_route = 0;

    for (auto it = info.begin(); it != info.end(); ++it)
    {
        if( *it == '/' )
        {
            routeInfo.addRoute();

            routeInfo.addStationInRoute(number_of_the_route, station);

            station = "";

            number_of_the_route++;
        }
        else
        {
            if ( *it == ',')
            {
                routeInfo.addStationInRoute(number_of_the_route, station);

                station = "";
            }
            else
            {
                station += *it;
            }
        }
    }
    routeInfo.addStationInRoute(number_of_the_route, station);
}

void ParsingInfo::putInfoAboutStations(const std::string &info, StationsInfo &stationInfo) noexcept
{
    std::string blockWithInfo;
    std::pair<std::string, std::string> pairNameValue;

    for (auto it = info.begin(); it != info.end(); ++it)
    {
        if( *it == '/' )
        {
            pairNameValue = parsingForMap(blockWithInfo);

            stationInfo.addInfoAboutStation(pairNameValue.first, pairNameValue.second);

            blockWithInfo = "";
        }
        else
        {
            blockWithInfo += *it;
        }
    }

    pairNameValue = parsingForMap(blockWithInfo);

    stationInfo.addInfoAboutStation(pairNameValue.first, pairNameValue.second);
}

std::pair<std::string, std::string> ParsingInfo::parsingForMap(const std::string &blockWithInfo) noexcept
{
    Part_of_buffer part = Part_of_buffer::name;
    std::string name_of_buffer = "";
    std::string value_of_bufer = "";

    for (auto it = blockWithInfo.begin(); it != blockWithInfo.end(); ++it)
    {
        if (*it == '~')
        {
            part = Part_of_buffer::value;
        }
        else
        {
            if (part == Part_of_buffer::name)
            {
                name_of_buffer += *it;
            }
            else
            {
                value_of_bufer += *it;
            }
        }
    }

    std::pair<std::string, std::string> pairNameValue;

    pairNameValue.first = name_of_buffer;
    pairNameValue.second = value_of_bufer;

    return pairNameValue;
}

void ParsingInfo::loadFromFile(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station,
                              RoutesInfo &routeInfo, StationsInfo &stationInfo)
{
    std::ifstream reading_file_with_routes(name_of_the_file_with_route);
    if (!reading_file_with_routes.is_open())
    {
        throw MissingFile(name_of_the_file_with_route);
    }

    std::string line_from_file;
    std::getline(reading_file_with_routes, line_from_file);

    putInfoAboutRoutes(line_from_file, routeInfo);

    reading_file_with_routes.close();




    std::ifstream reading_file_with_stations(name_of_the_file_with_station);
    if (!reading_file_with_stations.is_open())
    {
        throw MissingFile(name_of_the_file_with_station);
    }

    std::getline(reading_file_with_stations, line_from_file);

    putInfoAboutStations(line_from_file, stationInfo);

    reading_file_with_stations.close();
}

void ParsingInfo::saveChanges(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station, RoutesInfo &routeInfo, StationsInfo &stationInfo)
{
    saveChangesForRoute(name_of_the_file_with_route,routeInfo);

    saveChangesForStation(name_of_the_file_with_station,stationInfo);
}

void ParsingInfo::saveChangesForRoute(const std::string &name_of_the_file_with_route,RoutesInfo &routeInfo)
{
    std::ofstream rewriting_file_with_routes(name_of_the_file_with_route);

    std::vector<std::string> route;

    if (routeInfo.getHowManyRoutes() != 0)
    {
        route = routeInfo.getRoute(0);

        rewriting_file_with_routes << route[0];


        for(auto it = route.begin() + 1; it != route.end(); ++it)
        {
            rewriting_file_with_routes << ',' << *it;
        }

        for(int i = 1; i < routeInfo.getHowManyRoutes(); i++)
        {
            route = routeInfo.getRoute(i);

            rewriting_file_with_routes << '/';

            rewriting_file_with_routes << route[0];

            for(auto it = route.begin() + 1; it != route.end(); ++it)
            {
                rewriting_file_with_routes << ',' << *it;
            }
        }
    }

    rewriting_file_with_routes.close();
}

void ParsingInfo::saveChangesForStation(const std::string &name_of_the_file_with_station,StationsInfo &stationInfo)
{
    std::ofstream rewriting_file_with_stations(name_of_the_file_with_station);

    auto all_station = stationInfo.getAllStations();

    if (all_station.size() != 0)
    {
        rewriting_file_with_stations << (all_station[0]).first << '~' << (all_station[0]).second;


        for(auto it = all_station.begin() + 1; it != all_station.end(); ++it)
        {
            rewriting_file_with_stations << '/' << (*it).first << '~' << (*it).second;
        }
    }

    rewriting_file_with_stations.close();
}












