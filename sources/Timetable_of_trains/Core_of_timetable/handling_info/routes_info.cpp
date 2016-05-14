#include "routes_info.h"

std::vector<std::string> RoutesInfo::getRoute(const int number_of_the_route) noexcept
{
    return many_routes[number_of_the_route];
}

int RoutesInfo::getHowManyRoute() const noexcept
{
    return many_routes.size();
}

void RoutesInfo::changeStationInRoute(const int number_of_the_route, const int number_of_the_station, const std::string &new_marking) noexcept
{
    many_routes[number_of_the_route][number_of_the_station] = new_marking;
}

void RoutesInfo::addStationInRoute(const int number_of_the_route, const std::string &what_add) noexcept
{
    auto it = many_routes.begin() + number_of_the_route;

    std::vector<std::string> route = *it;

    route.push_back(what_add);

    *it = route;
}

void RoutesInfo::addRoute() noexcept
{
    std::vector<std::string> what_add;

    many_routes.push_back(what_add);
}

void RoutesInfo::deleteStationFromRoute(const int number_of_the_route, const int number_of_the_station) noexcept
{
    auto it = many_routes.begin() + number_of_the_route;

    std::vector<std::string> route = *it;

    route.erase(route.begin() + number_of_the_station);

    *it = route;
}

void RoutesInfo::deleteRoute(const int number_of_the_route) noexcept
{
    many_routes.erase(many_routes.begin() + number_of_the_route);
}







