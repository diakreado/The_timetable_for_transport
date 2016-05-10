#include "work_with_info.h"

int WorkWithInfo::getIntFromConsole()
{
    int number;

    std::cin >> number;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  /// Мешает считать кучу символов(ведь нам нужен один)

    return number;
}

void WorkWithInfo::displayRoute(std::vector<std::string> &output_for_console)
{
    for(unsigned i = 0; i < output_for_console.size(); i++)
    {
        std::cout << ' ' << i+1 << '.' << output_for_console[i] << std::endl;  /// Выводится в виде: 1.Parnas
    }                                                               ///                    2.Prospekt Prosvescheniya
    std::cout << std::endl;
}
