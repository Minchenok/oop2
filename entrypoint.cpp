#include "entrypoint.h"


std::shared_ptr<char> Entrypoint::fileExamination(std::shared_ptr<char> pathToFile){
    WorkWithFile file;
    return file.readingFile(pathToFile);
}


void Entrypoint::Examination(std::shared_ptr<char> json){
    JsonExamination checkJson(json);
    checkJson.mainCheck();
}
