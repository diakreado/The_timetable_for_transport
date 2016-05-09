#ifndef THERE_ARE_NO_ROUTES_H
#define THERE_ARE_NO_ROUTES_H

#include <exception>

/**
 * @brief Исключение бросается в том случае, если оказывается, что маршрутов не существует
 *
 * Сомневаюсь, что стоит создавать метод, говорящий о том, что маршрутов нет, ведь это очевидно из названия
 */
class ThereAreNoRoutes : public std::exception {};

#endif // THERE_ARE_NO_ROUTES_H
