#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

/**
 * @brief Класс в котором содержится основная бизнес-логика приложения
 */
class CoreOfTimetable : public API
{

public:

    CoreOfTimetable();

    void issuanceOfRights(const rights_of_customers right) noexcept override;

    rights_of_customers informationOfTheRights() const noexcept override;

    std::vector<std::string> getItinerary(int number_of_the_route) override;

    std::string getInformationAboutStation(const std::string &name_of_the_station) override;

    void changeItinerary(int choice_route, int choice_station, std::string &what_to_replace) override;

    void deleteStationFromItinerary(int choice_route, int choice_station) override;

    void addStationInItinerary(int choice_route, std::string &what_to_add) override;

    void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept override;

    void removeInformationAboutStation(const std::string &what_station_to_remove) override;

    std::vector<std::string> getAllItemWhichHaveDescription() noexcept override;

    int addRoute() noexcept override;

    void deleteRoute(int choice_route) override;

    void saveChanges() noexcept override;

    int howManyRoutes() override;

private:

//todo enum можно использовать как тип
// what_rights right;

    rights_of_customers right;

    FileRouteInformation DataSetOfInfoRoute;

    FileStationInformation DataSetOfInfoStation;
};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class ThereAreNoRoutes : public std::exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class StationDoesNotExist : public std::exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class RouteDoesNotExist : public std::exception {};

#endif // CORE_OF_TIMETABLE_H
