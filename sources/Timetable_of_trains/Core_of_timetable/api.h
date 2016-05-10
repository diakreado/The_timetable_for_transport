#ifndef API_H
#define API_H

#include "file_handling/file_route_information.h"
#include "file_handling/file_station_information.h"
#include "exception_of_core/exception_of_core.h"

//todo используйте спецификатор const для параметров метода, где это возможно
/// Я использую, просто часто параметры изменяются, например когда передётся номер станции, то нужно из него вычесть
/// еденицу, так как польззователь не должен знать про то, что отсчёт с 0 или это делать в консоли?

enum class Rights_of_customers{user = 0, administrator = 1};

/**
 * @brief Абстрактный класс, которым описывается функциональность предоставляемая ядром приложения
 */
class API
{
public:

    /**
     * @brief Выдача прав
     * @param rights - какие права нужно выдать
     */
    virtual void putOfRights(const Rights_of_customers rights) noexcept = 0;

    /**
     * @return Информация о правах
     */
    virtual Rights_of_customers getInformationOfTheRights() const noexcept = 0;

    /**
     * @param number_of_the_route - номер маршрута
     * @return Маршрут поезда в формате vector<string> (массив названий станций)
     * @throws Может быть брошено исключение RouteDoesNotExist
     */
    virtual std::vector<std::string> getItinerary(int number_of_the_route) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции
     * @param name_of_the_station - название станции
     * @return Информация о станции в формате string, здесь возвращяется только информация о станции,
     *  так как название станции заранее известно
     * @throws Может быть брошено исключение StationDoesNotExist
     */
    virtual std::string getInformationAboutStation(const std::string &name_of_the_station) = 0;

    /**
     * @brief Используется для более удобного вывода информации о станции, аналог предидущего
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @return Информация о станции в формате string, здесь кроме информации о станции возвращяется и название станции,
     *  т.е. string  в формате "Parnas : Info", сделанно потому что пользователь может не знать о станции
     * @throws Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual std::string getInformationAboutStation(int choice_route, int choice_station) = 0;

    /**
     * @brief Изменение маршрута поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param what_to_replace - что нужно поставить взамен
     * @throws Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual void changeStationInItinerary(int choice_route, int choice_station, std::string &what_to_replace) = 0;

    /**
     * @brief Удалить станцию из определённого маршрута
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @throws Могут быть брошены исключения RouteDoesNotExist и StationDoesNotExist
     */
    virtual void deleteStationFromItinerary(int choice_route, int choice_station) = 0;

    /**
     * @brief Добавить станцию маршрут поезда
     * @param choice_route - номер маршрута, который нужно изменить
     * @param what_to_add - что нужно добавить
     * @throws Может быть брошено исключение RouteDoesNotExist
     */
    virtual void addStationInItinerary(int choice_route, std::string &what_to_add) = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры
     * @param name_of_the_station - название маршрута
     * @param station_description - описание маршрута
     */
    virtual void addInformationAboutStation(std::string &name_of_the_station, std::string &station_description) noexcept = 0;

    /**
     * @brief Добавляет информацию о новом маршруте в контейнеры, альтернативный путь, в котором название станции получаем
     * из информации о маршрутах
     * @param choice_route - номер маршрута, который нужно изменить
     * @param choice_station - номер станции
     * @param station_description - описание маршрута
     * @throws Может быть брошено исключение RouteDoesNotExist
     */
    virtual void addInformationAboutStation(int choice_route, int choice_station, std::string &station_description) = 0;


    /**
     * @brief Удаление информации о станции из расписания
     * @param what_station_to_remove - название станции, которую нужно удалить
     * @throws Может быть брошено исключение StationDoesNotExist
     */
    virtual void removeInformationAboutStation(const std::string &what_station_to_remove)= 0;

    /**
     * @brief Удаление информации о станции из расписания
     * @param choice_station - номер станции, только в данном случае номер маршрута берётся не из информации о маршрутах,
     * а из списка станций, о которых существует информация (список можно получить с помощью getAllStations...)
     * @throws Может быть брошено исключение StationDoesNotExist
     */
    virtual void removeInformationAboutStation(int choice_station)= 0;

    /**
     * @brief Добавить новый маршурт в таблицу
     * @return Номер добавленного маршрута
     */
    virtual int addRoute() noexcept = 0;

    /**
     * @brief Удаление маршрута
     * @param choice_route - номер маршрута, который нужно удалить
     * @throws Может быть брошено исключение RouteDoesNotExist
     */
    virtual void deleteRoute(int choice_route) = 0;

    /**
     * @brief Сохраняет изменения в файле "metro_Saint-Petersburg"
     */
    virtual void saveChanges() noexcept = 0;

    /**
     * @return Возвращает количество существующих маршрутов
     * @throws Может быть брошено исключение ThereAreNoRoutes
     */
    virtual int howManyRoutes() = 0;

    /**
     * @brief Используется для того, чтобы просмотреть существующие станции перед их удалением
     * @return Возвращает все элементы из контейнера, связанного с описанием станций
     */
    virtual std::vector<std::string> getAllStationsWhichHaveDescription() noexcept = 0;
    //todo как получить станции, у которых нет описания
    /// getItinerary возвраящет станции маршрута, там могут быть станции без описания

    virtual ~API(){}
};

#endif // API_H
