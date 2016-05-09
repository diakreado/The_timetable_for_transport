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

    RouteDoesNotExist(int requested) : requested_by_customer(requested) {}

    /**
     * @return Возвращяем информацию о том, из-за чего было возбужденно исключение
     */
    int getWhatRequested() noexcept {return requested_by_customer;}

private:

    /**
     * @brief Здесь храниться информация о том, из-за чего было возбужденно исключение
     */
    int requested_by_customer;
};

#endif // ROUTE_DOES_NOT_EXIST_H
