#ifndef THERE_ARE_NO_ROUTES_H
#define THERE_ARE_NO_ROUTES_H

#include <exception>
#include <string>

/**
 * @brief Исключение, которое бросается при неудачном открытие файла, от него можно получить, информацию о том, какой файл
 * запрашивал пользователь, перед появлением исключения
 */
class MissingFile : public std::exception
{
public:
    MissingFile() = default;

    /**
     * @brief Используется, при необходимости передать информацию об ошибке
     * @param requested - название файла, который хотел открыть пользователь
     */
    explicit MissingFile(std::string requested) : requested_by_customer(requested) {}

    /**
     * @return Возвращяем информацию о том, из-за чего было возбужденно исключение
     */
    std::string getWhatRequested() noexcept {return requested_by_customer;}

private:

    std::string requested_by_customer;
};

#endif // THERE_ARE_NO_ROUTES_H
