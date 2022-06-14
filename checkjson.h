#ifndef CHECKJSON_H
#define CHECKJSON_H

#include <iostream>
#include <memory>
#include "checkjsonexcepcion.h"


class JsonExamination {
private:
    const std::string valueNum = "0123456789-.";
    const std::string valueBool = "tfn";

    std::shared_ptr<char> json;
    int index;

    void missSpace();
    void checkArr();
    void checkObject();
    void checkString();
    void checkBool();
    void checkNumber();


public:
    JsonExamination(std::shared_ptr<char> value);
    void mainCheck();
};

enum symbol{
    key,
    doublePoint,
    value,
    close,
};

#endif // CHECKJSON_H
