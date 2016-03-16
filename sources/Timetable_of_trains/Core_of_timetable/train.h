#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <vector>

using namespace std;

/**
* Класс хранящий информацию о поездах
*/
class Train
{
public:
    Train();

    vector<string>* getRoute(int number_of_the_train); /*Получить информацию о маршруте поезда*/

    int getNumber(); /*Получить номер поезда*/

private:
    int number;

};

#endif // TRAIN_H
