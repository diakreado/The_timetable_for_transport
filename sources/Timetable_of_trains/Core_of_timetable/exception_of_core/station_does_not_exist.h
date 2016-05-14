#ifndef STATION_DOES_NOT_EXIST_H
#define STATION_DOES_NOT_EXIST_H

#include <string>
#include <sstream>
#include <exception>

/**
 * @brief Исключение бросается в том случае, если оказывается, что запрашиваемой станции не существует
 */
class StationDoesNotExist : public std::exception
{
public:
    StationDoesNotExist() = default;

    /**
     * @brief Используется при необходимости передать информацию об ошибке, в том случае, если она в название станции
     * @param requested - название станции, которая не существует, но была запрошена пользователем
     */
    explicit StationDoesNotExist(const std::string &requested) : requested_by_customer(requested) {}

    /**
     * @brief Используется при необходимости передать информацию об ошибке, в том случае, если она в номере станции
     * @param requested - номер станции, которая не существует, но была запрошена пользователем
     */
    explicit StationDoesNotExist(int requested)
    {
        std::stringstream print_int;
        print_int << requested;
        requested_by_customer = print_int.str();
    }

    /**
     * @return Возвращяем информацию о том, из-за чего было возбужденно исключение
     */
    std::string getWhatRequested() noexcept {return requested_by_customer;}

private:

    /**
     * @brief Здесь храниться информация о том, из-за чего было возбужденно исключение
     */
    std::string requested_by_customer;
};

#endif // STATION_DOES_NOT_EXIST_H
