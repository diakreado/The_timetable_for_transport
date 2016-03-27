#include <iostream>
#include <console_for_timetable.h>

using namespace std;

int main()
{   
    try
    {
        ConsoleForTimetable start;
    }
    catch(exception &Error)
    {
        cout << Error.what() << endl << endl;
    }
    catch(...)
    {
        cout << " Unspecified error" << endl << endl;
    }
    cout << "  Come back soon!" << endl;

    return 0;
}
