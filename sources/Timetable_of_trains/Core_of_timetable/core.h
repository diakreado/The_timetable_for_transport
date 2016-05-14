#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

/**
 * @brief Класс в котором содержится основная бизнес-логика приложения
 */
class CoreOfInfoAboutMetro : public API
{

public:

    CoreOfInfoAboutMetro() : rights(Rights_of_customers::user) {}

    void putOfRights(const Rights_of_customers rights) noexcept override;

    Rights_of_customers getInformationOfTheRights() const noexcept override;

    void putInfoAboutMetro(const std::string &infoAboutRoutes, const std::string &infoAboutStations) noexcept override;

    void loadInfoFromFile(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station) override;

    int howManyRoutes() const noexcept override;

    std::vector<std::string> getRoute(const int number_of_the_route) override;

    std::string getInfoAboutStation(const std::string &name_of_the_station) override;

    std::string getInfoAboutStation(const int number_of_the_route, const int number_of_the_station) override;

    void changeStationInRoute(const int number_of_the_route, const int number_of_the_station, const std::string &new_marking) override;

    void addStationInRoute(const int number_of_the_route, const std::string &what_to_add)override;

    int addRoute() noexcept override;

    void deleteStationFromRoute(const int number_of_the_route, const int number_of_the_station) override;

    void deleteRoute(const int number_of_the_route) override;

    void addInfoAboutStation(const std::string &name_of_the_station, const std::string &station_description) noexcept override;

    void addInfoAboutStation(const int number_of_the_route, const int number_of_the_station, const std::string &station_description) override;

    void removeInfoAboutStation(const std::string &what_station_to_remove) override;

    void removeInfoAboutStation(const int number_of_the_station) override;

    std::vector<std::pair<std::string, std::string>> getAllStationsWhichHaveDescription() noexcept override;

private:

    Rights_of_customers rights;

    RoutesInfo routeInfo;

    StationsInfo stationInfo;

    ParsingInfo parsingInformation;
};

#endif // CORE_OF_TIMETABLE_H
