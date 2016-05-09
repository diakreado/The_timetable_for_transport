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

    StationDoesNotExist(const std::string &requested) : requested_by_customer(requested) {}

    StationDoesNotExist(int requested)
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
