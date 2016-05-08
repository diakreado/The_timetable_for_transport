#include <app.h>

// todo позвольте, я уберу это
//using namespace std;

int main()
{   
    // todo пусть вся эта конструкция скрыта где-то внутри app
    try
    {
        ConsoleForTimetable start;
        while(start.menu()) {}
    }
    catch(std::exception &Error)
    {
       std::cout << " Exception :  " << Error.what() << std::endl << std::endl;
    }
    catch(...)
    {
        std::cout << " Unspecified error" << std::endl << std::endl;
    }

    std::cout << "  Come back soon!" << std::endl;

    return 0;
}
