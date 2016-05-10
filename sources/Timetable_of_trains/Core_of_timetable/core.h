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

    //todo для конструктора копирования и оператора присваивания
    //явно написать default или delete
    /// Вероятно, вы слышали о рекомендации о большой тройке. Она утверждает, что если
    /// вы объявили хотя бы одну из трех операций - копирующий конструктор, копирующий
    /// оператор присваивания или деструктор, - то вы должны объявить все три операции.
    /// Скотт Мейерс. Эффективный и современный С++. стр 119
    ///
    /// Я не объявлял деструктор, следовательно, мне и конструкторы можно не трогать, разве не так???

    void putOfRights(const Rights_of_customers rights) noexcept override;

    Rights_of_customers getInformationOfTheRights() const noexcept override;

    std::vector<std::string> getItinerary(int number_of_the_route) override;

    std::string getInformationAboutStation(const std::string &name_of_the_station) override;

    std::string getInformationAboutStation(int choice_route, int choice_station) override;

    void changeStationInItinerary(int choice_route, int choice_station, std::string &what_to_replace) override;

    void deleteStationFromItinerary(int choice_route, int choice_station) override;

    void addStationInItinerary(int choice_route, std::string &what_to_add) override;

    void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept override;

    void addInformationAboutStation(int choice_route, int choice_station, std::string &station_description) override;

    void removeInformationAboutStation(const std::string &what_station_to_remove) override;

    void removeInformationAboutStation(int choice_station) override;

    std::vector<std::string> getAllStationsWhichHaveDescription() noexcept override;

    int addRoute() noexcept override;

    void deleteRoute(int choice_route) override;

    void saveChanges() noexcept override;

    int howManyRoutes() override;

    std::vector<std::string> findTrack(int num_route_from, int num_station_from, int num_route_to, int num_station_to);

private:

    Rights_of_customers rights;

    //TODO: УЖАСНО ДИКО ПУТАЕТ НАЗВАНИЕ С ЗАГЛАВНОЙ БУКВЫ
    //TODO: не надо делать такую жесткую привязку вашего ядра к файлам,
    //есть масса других мест, откуда можно получать и где сохранять данные (сеть, бд, другое)
    //TODO: сделайте в этом классе поле, хранящее в себе данные о модели маршрутов и станций, с адекватными методами доступа
    //чтобы заполнить эту структуру данных, можно передавать в этот класс объект , реализующий получение данных
    //из внешнего источника
    FileRouteInformation dataSetOfInfoRoute;

    FileStationInformation dataSetOfInfoStation;

    //TODO: у вас в коде ужасное количество боли от того, что вы не храните внятную структуру данных обернутую в класс с методами доступа
    //поэтому везде-везде постоянно приходится парсить строки, так НЕПРИЕМЛЕМО!!!

    //todo пусть метод возвращает вектор строк, а не модфицирует его по ссылке.
    void findTrackInOneRoute(int num_route, int num_station_from,
                                                 int num_station_to, std::vector<std::string> &Track);
    //todo лучше задокументировать этот метод, а то не понятно из названия, что он делает
    //и, может быть, стоит переименовать его.
    std::pair<int,int> findStationWithTheSameName(int num_route_one, int num_route_two);
};

#endif // CORE_OF_TIMETABLE_H
