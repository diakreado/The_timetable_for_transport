#include "core.h"

void CoreOfInfoAboutMetro::putOfRights(const Rights_of_customers rights) noexcept
{
    if (rights == Rights_of_customers::administrator)
    {
        this->rights = Rights_of_customers::administrator;
    }
    else
    {
        this->rights = Rights_of_customers::user;
    }
}

Rights_of_customers CoreOfInfoAboutMetro::getInformationOfTheRights() const noexcept
{
    return rights;
}

void CoreOfInfoAboutMetro::putInfoAboutMetro(const std::string &infoAboutRoutes, const std::string &infoAboutStations) noexcept
{
    parsingInformation.putInfoAboutRoutes(infoAboutRoutes, routeInfo);

    parsingInformation.putInfoAboutStations(infoAboutStations, stationInfo);
}

void CoreOfInfoAboutMetro::loadInfoFromFile(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station)
{
    parsingInformation.loadFromFile(name_of_the_file_with_route, name_of_the_file_with_station, routeInfo, stationInfo);
}

int CoreOfInfoAboutMetro::howManyRoutes() const noexcept
{
    return routeInfo.getHowManyRoute();
}

std::vector<std::string> CoreOfInfoAboutMetro::getRoute(const int number_of_the_route)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;

    return routeInfo.getRoute(number_of_the_route_in_the_vector);;
}

std::string CoreOfInfoAboutMetro::getInfoAboutStation(const std::string &name_of_the_station)
{
    std::string info_about_station =  stationInfo.getInfoAboutStation(name_of_the_station);
    std::string void_string;

    if(info_about_station == void_string)
    {
        throw StationDoesNotExist(name_of_the_station);
    }

    return info_about_station;
}

std::string CoreOfInfoAboutMetro::getInfoAboutStation(const int number_of_the_route, const int number_of_the_station)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;
    const int number_of_the_station_in_the_vector = number_of_the_station - 1;

    std::vector<std::string> route = routeInfo.getRoute(number_of_the_route_in_the_vector);

    int size_of_vector = route.size();
    if(number_of_the_station > size_of_vector || number_of_the_station < 1)
    {
        throw StationDoesNotExist(number_of_the_station);
    }


    std::string info_about_station =  stationInfo.getInfoAboutStation(route[number_of_the_station_in_the_vector]);
    std::string void_string;

    if(info_about_station == void_string)
    {
        throw StationDoesNotExist(route[number_of_the_station_in_the_vector]);
    }

    return info_about_station;
}

void CoreOfInfoAboutMetro::changeStationInRoute(const int number_of_the_route, const int number_of_the_station, const std::string &new_marking)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;
    const int number_of_the_station_in_the_vector = number_of_the_station - 1;

    int size_of_vector = (routeInfo.getRoute(number_of_the_route_in_the_vector)).size();

    if(number_of_the_station < 1 || number_of_the_station > size_of_vector)
    {
        throw StationDoesNotExist(number_of_the_station);
    }

    routeInfo.changeStationInRoute(number_of_the_route_in_the_vector, number_of_the_station_in_the_vector, new_marking);
}

void CoreOfInfoAboutMetro::addStationInRoute(const int number_of_the_route, const std::string &what_to_add)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;

    routeInfo.addStationInRoute(number_of_the_route_in_the_vector, what_to_add);
}

int CoreOfInfoAboutMetro::addRoute() noexcept
{
    routeInfo.addRoute();

    return routeInfo.getHowManyRoute();
}

void CoreOfInfoAboutMetro::deleteStationFromRoute(const int number_of_the_route, const int number_of_the_station)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;
    const int number_of_the_station_in_the_vector = number_of_the_station - 1;

    int size_of_vector = (routeInfo.getRoute(number_of_the_route_in_the_vector)).size();

    if(number_of_the_station < 1 || number_of_the_station > size_of_vector)
    {
        throw StationDoesNotExist(number_of_the_station);
    }

    routeInfo.deleteStationFromRoute(number_of_the_route_in_the_vector, number_of_the_station_in_the_vector);
}

void CoreOfInfoAboutMetro::deleteRoute(const int number_of_the_route)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;

    routeInfo.deleteRoute(number_of_the_route_in_the_vector);
}

void CoreOfInfoAboutMetro::addInfoAboutStation(const std::string &name_of_the_station, const std::string &station_description) noexcept
{
    stationInfo.addInfoAboutStation(name_of_the_station, station_description);
}

void CoreOfInfoAboutMetro::addInfoAboutStation(const int number_of_the_route, const int number_of_the_station, const std::string &station_description)
{
    if(number_of_the_route > routeInfo.getHowManyRoute() || number_of_the_route < 1)
    {
        throw RouteDoesNotExist(number_of_the_route);
    }

    const int number_of_the_route_in_the_vector = number_of_the_route - 1;
    const int number_of_the_station_in_the_vector = number_of_the_station - 1;

    std::vector<std::string> route = routeInfo.getRoute(number_of_the_route_in_the_vector);

    int size_of_vector = route.size();

    if(number_of_the_station < 1 || number_of_the_station > size_of_vector)
    {
        throw StationDoesNotExist(number_of_the_station);
    }

    stationInfo.addInfoAboutStation(route[number_of_the_station_in_the_vector], station_description);
}

void CoreOfInfoAboutMetro::removeInfoAboutStation(const std::string &what_station_to_remove)
{
    if (stationInfo.getInfoAboutStation(what_station_to_remove) == "")
    {
        throw StationDoesNotExist(what_station_to_remove);
    }

    stationInfo.removeInfoAboutStation(what_station_to_remove);
}

void CoreOfInfoAboutMetro::removeInfoAboutStation(const int number_of_the_station)
{
    const int number_of_the_station_in_the_vector = number_of_the_station - 1;

    int size_of_vector = (stationInfo.getAllStations()).size();
    if (size_of_vector > number_of_the_station || number_of_the_station < 1)
    {
        throw StationDoesNotExist(number_of_the_station);
    }

    auto info_about_station = (stationInfo.getAllStations())[number_of_the_station_in_the_vector];

    stationInfo.removeInfoAboutStation(info_about_station.first);
}

std::vector<std::pair<std::string, std::string>> CoreOfInfoAboutMetro::getAllStationsWhichHaveDescription() noexcept
{
    auto all_station = stationInfo.getAllStations();

    for(unsigned int i = 0; i < all_station.size(); i++)
    {
        if ((all_station[i]).second == "")
        {
            all_station.erase(all_station.begin() + i);
        }
    }

    return all_station;
}











