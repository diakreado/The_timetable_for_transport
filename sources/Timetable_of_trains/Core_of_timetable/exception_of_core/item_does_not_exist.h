#ifndef ITEM_DOES_NOT_EXIST_H
#define ITEM_DOES_NOT_EXIST_H

#include <exception>

/**
 * @brief Исключение бросается в том случае, если оказывается, что запрашиваемого элмента не существует
 *
 * Это исключение не выходит за пределы ядра.
 * Его бросают классы обрабатывающие файлы.
 */
class ItemDoesNotExist : public std::exception {};

#endif // ITEM_DOES_NOT_EXIST_H
