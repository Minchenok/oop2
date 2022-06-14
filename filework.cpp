#include "filework.h"

FILE* WorkWithFile::openingFile(std::shared_ptr<char> fileName){
    return fopen(fileName.get(), "r");
}

//get преобразовывает в char*

std::shared_ptr<char> WorkWithFile::readingFile(std::shared_ptr<char> path){
    FILE* file = openingFile(path);
    if (file){
        int len = countLines(file);
        std::unique_ptr<char> line (new char[len*sizeLine]);
        std::shared_ptr<char> json (new char[len*sizeLine]);
        int i = 0;
        while (fgets(line.get(),sizeLine, file)){
            for (int j = 0; line.get()[j]; j++){
                json.get()[i]= line.get()[j];
                i++;
            }
        }
        json.get()[i] = '\0';
        closingFile(file);
        return json;
    }
    else{
        throw FileException();
    }
}

//fgets только в обычные указатели

int WorkWithFile::countLines(FILE* file){
    int count = 0;
    char* testLine = new char[sizeLine];
    while (fgets(testLine,sizeLine, file)){
        count++;
    }
    delete[] testLine;
    rewind(file);
    return count;
}

void WorkWithFile::closingFile(FILE* file){
    fclose(file);
}
