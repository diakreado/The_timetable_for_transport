#ifndef API_H
#define API_H

#include "handling_info/routes_info.h"
#include "handling_info/stations_info.h"
#include "handling_info/parsing_info.h"
#include "exception_of_core/exception_of_core.h"

enum class Rights_of_customers{user = 0, administrator = 1};

/**
 * @brief Абстрактный класс, которым описывается функциональность предоставляемая ядром приложения
 */
class API
{
public:

    API() = default;

    API(const API&) = delete;
    API& operator= (const API&) = delete;

    virtual ~API(){}

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
     * @brief Один из способ передать входные данные
     * @param infoAboutRoutes - информация о маршрутах в формате: Devyatkino,Grazhdansky Prospekt/Parnas,Prospekt Prosvescheniya
     * где через запятую указываются называние станций, а слеш отедляет маршруты
     * @param infoAboutStations - информация о станциях в формате: Parnas~5.47-0.00/Prospekt Prosvescheniya~5.37-0.40
     * где слеш отедляет станции, а тильда отедляет название станции от информации связаной с ней
     */
    virtual void putInfoAboutMetro(const std::string &infoAboutRoutes, const std::string &infoAboutStations) noexcept = 0;

    /**
     * @brief Загрузить входные данные из файла
     * @param name_of_the_file_with_route - название файла, для хранения информации о маршрутах
     * @param name_of_the_file_with_station - название файла, для хранения информации о станциях
     * Информация должна находиться в таком же формате, как и в putInfoAboutMetro
     * @exception При неудачном открытие файла бросается MissingFile, от объекта которого можно
     * получить информацию о неверно имени файла
     */
    virtual void loadInfoFromFile(const std::string &name_of_the_file_with_route, const std::string &name_of_the_file_with_station) = 0;

    /**
     * @return Сколько маршрутов существует на данный момент
     */
    virtual int howManyRoutes() const noexcept = 0;

    /**
     * @param number_of_the_route - номер запрашиваемого маршрута
     * @return Запрашиваемый маршрут в формате vector<string> , где string - это название станций
     * @exception При запросе несуществующего маршрута бросается RouteDoesNotExist, от объекта
     * которого можно получить информацию, какой маршрут запрашивали
     */
    virtual std::vector<std::string> getRoute(const int number_of_the_route) = 0;

    /**
     * @param name_of_the_station - название станции, о которой нужно получить информацию
     * @return информация о запрашиваемой станции
     * @exception При запросе несуществующеё станции бросается StationDoesNotExist
     */
    virtual std::string getInfoAboutStation(const std::string &name_of_the_station) = 0;

    /**
     * @brief Способ альтернативный предидущему
     * @param number_of_the_route - номер маршрута, содержащего станцию
     * @param number_of_the_station - номер станции в маршруте
     * @return информация о запрашиваемой станции
     * @exception При запросе несуществующеё станции бросается StationDoesNotExist, а RouteDoesNotExist, если маршрута не ссуществует
     */
    virtual std::string getInfoAboutStation(const int number_of_the_route, const int number_of_the_station) = 0;

    /**
     * @brief Изменение станции в маршруте
     * @param number_of_the_route - номер маршрута
     * @param number_of_the_station - номер станции
     * @param new_marking - то, что нужно поставить в замен
     * @exception При неверном запросе бросаются StationDoesNotExist и RouteDoesNotExist
     */
    virtual void changeStationInRoute(const int number_of_the_route, const int number_of_the_station, const std::string &new_marking) = 0;

    /**
     * @brief Добавляет станцию в маршрут
     * @param number_of_the_route - номер маршрута, в который нужно добавить станцию
     * @param what_to_add - название станции, которую нужно добавить
     * @exception При неверном запросе бросается RouteDoesNotExist
     */
    virtual void addStationInRoute(const int number_of_the_route, const std::string &what_to_add) = 0;

    /**
     * @brief Добавляет новый (пустой) маршрут
     * @return Номер добавленного маршрута
     */
    virtual int addRoute() noexcept = 0;

    /**
     * @brief Удаляет станцию из маршрута
     * @param number_of_the_route - номер маршрута, из которого нужно удалить станцию
     * @param number_of_the_station - номер станции, которую нужно удалить
     * @exception При неверном запросе бросаются StationDoesNotExist и RouteDoesNotExist
     */
    virtual void deleteStationFromRoute(const int number_of_the_route, const int number_of_the_station) = 0;

    /**
     * @brief Удаляет маршрут
     * @param number_of_the_route - номер маршрута, который нужно удалить
     * @exception При неверном запросе бросается RouteDoesNotExist
     */
    virtual void deleteRoute(const int number_of_the_route) = 0;

    /**
     * @brief Добавляет информацию о станции
     * @param name_of_the_station - номер станции, о которой информация
     * @param station_description - информация о станции
     */
    virtual void addInfoAboutStation(const std::string &name_of_the_station, const std::string &station_description) noexcept = 0;

    /**
     * @brief Альтернативный путь добавления информации о станции
     * @param number_of_the_route - номер маршрута, в котором содерижтся станция, про которую информация
     * @param number_of_the_station - номер станции, про которую информация
     * @param station_description - информация о станции
     * @exception При неверном запросе бросаются StationDoesNotExist и RouteDoesNotExist
     */
    virtual void addInfoAboutStation(const int number_of_the_route, const int number_of_the_station, const std::string &station_description) = 0;

    /**
     * @brief Удаляет информацию о станции
     * @param what_station_to_remove - название станции, которую нужно удалить
     * @exception При неверном запросе бросается StationDoesNotExist
     */
    virtual void removeInfoAboutStation(const std::string &what_station_to_remove) = 0;

    /**
     * @brief Альтернативный путь удаления информации о станции, в месте с ним используется метод
     * getAllStationsWhichHaveDescription(), именно из него берётся номер станции
     * @param number_of_the_station - номер станции из getAllStationsWh..
     * @exception При неверном запросе бросается StationDoesNotExist
     */
    virtual void removeInfoAboutStation(const int number_of_the_station) = 0;

    /**
     * @return Всё станции, про котороые содержится информация, первая часть пары название станции,
     * вторая информация о ней
     */
    virtual std::vector<std::pair<std::string, std::string>> getAllStationsWhichHaveDescription() noexcept = 0;
};

#endif // API_H
