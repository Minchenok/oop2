#ifndef FILEWORK_H
#define FILEWORK_H
#include <iostream>
#include <memory>
#include "fileexception.h"

class WorkWithFile {
public:
    WorkWithFile() {};
    std::shared_ptr<char> readingFile(std::shared_ptr<char> path);
private:
    const int sizeLine = 250;
    FILE* openingFile(std::shared_ptr<char> fileName);
    void closingFile(FILE* file);
    int countLines(FILE* file);
};

#endif // FILEWORK_H
