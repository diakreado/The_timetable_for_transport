#include <iostream>
#include <app.h>

using namespace std;

int main()
{   
    try
    {
        ConsoleForTimetable start;
        while(start.menu()) {}
    }
    catch(exception &Error)
    {
        cout << " Exception :  " << Error.what() << endl << endl;
    }
    catch(...)
    {
        cout << " Unspecified error" << endl << endl;
    }

    cout << "  Come back soon!" << endl;

    return 0;
}
