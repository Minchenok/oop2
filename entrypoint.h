#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include <iostream>
#include <memory> // в этой библиотеке содержатся классы умных указателей
#include "filework.h"
#include "checkjson.h"

class Entrypoint {
public:
    std::shared_ptr<char> fileExamination(std::shared_ptr<char> pathToFile);
    void Examination(std::shared_ptr<char> json);

};

std::shared_ptr<char> fileExamination(std::shared_ptr<char> pathToFile);

void Examination(std::shared_ptr<char> json);

#endif // ENTRYPOINT_H









//умные указатели: это объекты, которые хранят указатели на динамически аллоцированные участки памяти произвольного типа.
//Причем они автоматически очищают память по выходу из области видимости.
//auto_ptr
//unique_ptr
//shared_ptr //несколько указателей ссылаются на одни и те же данные в памяти
//weak_ptr
