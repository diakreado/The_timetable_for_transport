#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

//todo было бы неплохо переименовать enum
//todo использовать enum с областью видимости:
// enum class Rights...
//todo может быть, usual_user --> user
//Вопрос в названии - не очень, лучше просто что-нибудь типа Rights
enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится основная бизнес-логика приложения
 */
// todo дописать noexcept для методов, не бросающих исключения
class CoreOfTimetable : public API
{

public:
    CoreOfTimetable();

    void issuanceOfRights(const int what_rights) override;   /// Я что-то делаю не так и у меня на каждый override //todo добавь флаг компилятора -std=c++11
                                                      ///выходи предупреждениеonly available with -std=c++11 or -std=gnu++11
    bool informationOfTheRights() const override;

    std::vector<std::string> getItinerary(int number_of_the_route) override;

    std::string getInformationAboutStation(const std::string &name_of_the_station) override;

    void changeItinerary(unsigned choice_route, unsigned choice_station, std::string &what_to_replace) override;

    void deleteStationFromItinerary(unsigned choice_route, unsigned choice_station) override;

    void addStationInItinerary(unsigned choice_route, std::string &what_to_add) override;

    void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) override;

    void removeInformationAboutStation(const std::string &what_station_to_remove) override;

    std::string findSuitableRoute(std::string &departure, std::string &arrival) override;

    std::vector<std::string> getAllItemWhichHaveDescription() override;

    unsigned addRoute() override;

    void deleteRoute(unsigned choice_route) override;

    void saveChanges() override;

    unsigned howManyRoutes() override;

private:
//todo enum можно использовать как тип
// what_rights right;
    int right;

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
