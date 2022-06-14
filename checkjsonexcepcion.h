#ifndef CHECKJSONEXCEPCION_H
#define CHECKJSONEXCEPCION_H

#include <iostream>
#include <cstring>

class JsonException: std::exception {
private:
    std::string errorMsg;
    const int size = 50;
public:
    JsonException(const std::string msg) {
        errorMsg = msg;
    }
    virtual const char* what() const noexcept override{
        char* error = new char[size];
        strcpy(error, "Incorrect ");
        strcat(error, errorMsg.c_str());
        return error; // Возвращает ошибку (c_str() Преобразует std::string в char*)
    }
};

#endif // CHECKJSONEXCEPCION_H
