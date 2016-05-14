#include "stations_info.h"

std::string StationsInfo::getInfoAboutStation(const std::string &name_of_the_station) noexcept
{
    return infoAboutStationsInMap[name_of_the_station];
}

void StationsInfo::addInfoAboutStation(const std::string &name_of_the_station, const std::string &station_description) noexcept
{
    infoAboutStationsInMap[name_of_the_station] = station_description;
}

void StationsInfo::removeInfoAboutStation(const std::string &what_station_to_remove) noexcept
{
    infoAboutStationsInMap.erase(infoAboutStationsInMap.find(what_station_to_remove));
}

std::vector<std::pair<std::string, std::string>> StationsInfo::getAllStations() noexcept
{
    std::vector<std::pair<std::string, std::string>> infoAboutStationsInVector;
    std::pair<std::string, std::string> name_and_value;


    for(auto it_for_map = infoAboutStationsInMap.begin(); it_for_map != infoAboutStationsInMap.end(); ++it_for_map)
    {
        name_and_value.first = it_for_map->first;
        name_and_value.second = it_for_map->second;

        infoAboutStationsInVector.push_back(name_and_value);
    }

   return infoAboutStationsInVector;
}










