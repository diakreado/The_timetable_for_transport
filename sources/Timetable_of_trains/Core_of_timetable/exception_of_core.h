#ifndef EXCEPTION_OF_CORE_H
#define EXCEPTION_OF_CORE_H

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class ThereAreNoRoutes : public std::exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class StationDoesNotExist : public std::exception {};

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class RouteDoesNotExist : public std::exception {};


/// --------------------------   Исключения не выходящие за пределы ядра   -------------------------- ///

//todo класс лучше вынести в отдельный header (можно без cpp все inline)
//todo было бы не плохо переопредлить метод const char* what() const (он опредлен в классе std::exception)
class ItemDoesNotExist : public std::exception {};

#endif // EXCEPTION_OF_CORE_H
