#ifndef WORKWITHINFO_H
#define WORKWITHINFO_H

#include <core.h>
#include <algorithm>

/**
 * @brief Абстрактный класс, содержащий несколько функций помогающих при работе с пользователем
 */
class WorkWithInfo
{
public:
    WorkWithInfo() = default;

    /**
     * @return Число считаное из консоли
     */
    int getIntFromConsole();

    /**
     * @brief Удобный вывод маршрута в консоль
     * @param Что за маршрут нужно вывести
     */
    void displayRoute(std::vector<std::string> &output_for_console);

    /**
     * @brief Так как наследники должны иметь свой
     */
    virtual ~WorkWithInfo(){}

    /// Они мне не нужны, но по правилу: переопределил деструктор, переопределяй и эти конструкторы
    WorkWithInfo(const WorkWithInfo&) = default;
    WorkWithInfo& operator= (const WorkWithInfo&) = default;
};

#endif // WORKWITHINFO_H
