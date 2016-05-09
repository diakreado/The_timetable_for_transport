#ifndef ROUTE_DOES_NOT_EXIST_H
#define ROUTE_DOES_NOT_EXIST_H

#include <string>
#include <sstream>
#include <exception>

/**
 * @brief Исключение бросается в том случае, если оказывается, что запрашиваемого маршрута не существует
 */
class RouteDoesNotExist : public std::exception
{
public:
    RouteDoesNotExist() = default;

    RouteDoesNotExist(const std::string &requested) : requested_by_customer(requested) {}

    RouteDoesNotExist(int requested)
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

#endif // ROUTE_DOES_NOT_EXIST_H
