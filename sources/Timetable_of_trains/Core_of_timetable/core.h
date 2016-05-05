#ifndef CORE_OF_TIMETABLE_H
#define CORE_OF_TIMETABLE_H

#include "api.h"

//todo было бы неплохо перименовать enum
//Вопрос в названии - не очень, лучше просто что-нибудь типа Rights
enum what_rights{usual_user = 0, administrator = 1};

/**
 * @brief Класс в котором содержится основная бизнес-логика приложения
 */
class CoreOfTimetable : public API
{

public:
    CoreOfTimetable();

    void issuanceOfRights(const int what_rights) override;   /// Я что-то делаю не так и у меня на каждый override //todo добавь флаг компилятора -std=c++11
                                                      ///выходи предупреждениеonly available with -std=c++11 or -std=gnu++11
    bool informationOfTheRights() const override;

    vector<string> getItinerary(int number_of_the_route) override;

    string getInformationAboutStation(const string &name_of_the_station) override;

    void changeItinerary(unsigned choice_route, unsigned choice_station, string &what_to_replace) override;

    void deleteStationFromItinerary(unsigned choice_route, unsigned choice_station) override;

    void addStationInItinerary(unsigned choice_route, string &what_to_add) override;

    void addInformationAboutStation(string &name_of_the_station, string &station_description) override;

    void removeInformationAboutStation(const string &what_station_to_remove) override;

    string findSuitableRoute(string &departure, string &arrival) override;

    vector<string> getAllItemWhichHaveDescription() override;

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
class ThereAreNoRoutes : public exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class StationDoesNotExist : public exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class RouteDoesNotExist : public exception {};

#endif // CORE_OF_TIMETABLE_H
