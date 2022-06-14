#include "checkjson.h"

JsonExamination::JsonExamination(std::shared_ptr<char> value){
    this->json = value;
    this->index = 0;
}

void JsonExamination::mainCheck(){
    missSpace();
    if (json.get()[index] == '['){
        checkArr();
    }
    else if (json.get()[index] == '{'){
        checkObject();
    }
    else {
        throw JsonException("json");
    }
    missSpace();

    if (json.get()[index]){ //проверка всего, что после jsona
        throw JsonException("json");
    }
}


void JsonExamination::missSpace(){
    while (json.get()[index] == ' ' || json.get()[index] == '\n')
        index++;
}


void JsonExamination::checkArr(){
   index++;
   std::string valueNum = "0123456789-";
   std::string valueBool = "tfn";
   bool needValue = true;
   while (json.get()[index]){
       missSpace();
       if (needValue && valueNum.find(json.get()[index]) != std::string::npos){
            checkNumber();
            needValue = false;
       }
       else if (needValue && valueBool.find(json.get()[index]) != std::string::npos){
           checkBool();
           needValue = false;
       }
       else if (needValue && json.get()[index] == '['){
           checkArr();
           needValue = false;
       }
       else if (needValue && json.get()[index] == '{'){
           checkObject();
           needValue = false;
       }
       else if (needValue && json.get()[index] == '"'){
           checkString();
           needValue = false;
       }
       else if (!needValue && json.get()[index] == ','){
           index++;
           needValue = true;
       }
       else if (json.get()[index] == ']'){
           break;
       }
       else {
           throw JsonException("arr");
       }
   }
   index++;
}


void JsonExamination::checkObject(){
    index++;
    symbol need = key;

    missSpace();
    if (json.get()[index] == '}'){
        index++;
        return;
    }

    while (json.get()[index]){
        missSpace();
        if (json.get()[index] == '"' && need == key){
            checkString();
            need = doublePoint;
        }
        else if (json.get()[index] == ':' && need == doublePoint){
            index++;
            need = value;
        }
        else if (need == value && valueNum.find(json.get()[index]) != std::string::npos){
            checkNumber();
            need = close;
        }

        else if (need == value && valueBool.find(json.get()[index]) != std::string::npos){
            checkBool();
            need = close;
        }
        else if (need == value && json.get()[index] == '['){
            checkArr();
            need = close;
        }
        else if (need == value && json.get()[index] == '{'){
            checkObject();
            need = close;
        }
        else if (need == value && json.get()[index] == '"'){
            checkString();
            need = close;
        }
        else if (need == close && json.get()[index] == ','){
            index++;
            need = key;
        }
        else if (need == close && json.get()[index] == '}'){
            break;
        }
        else {
            throw JsonException("obj");
        }
    }
    index++;
}


void JsonExamination::checkString(){
    index++;
    while (json.get()[index] != '"'){
        if (!json.get()[index]){
            throw JsonException("string");
        }
        index++;
    }
    index++;
}

// Проверка на закрытие кавычки

//ffgfgfgfdg

void JsonExamination::checkBool(){
    if (json.get()[index] == 't' or json.get()[index] == 'f' or json.get()[index] == 'n'){
        std::string symbol;
        if (json.get()[index] == 't')
            symbol = "true";
        else if (json.get()[index] == 'f')
            symbol = "false";
        else
            symbol = "null";
        for (int i = 0; symbol[i]; i++){
            if (symbol[i] != json.get()[index])
                throw JsonException(symbol);
            index++;
        }
    }
}



void JsonExamination::checkNumber(){
    int countPoint = 0;
    while (valueNum.find(json.get()[index]) != std::string::npos){
        if (json.get()[index] == '.')
            countPoint++;
        if (countPoint > 1){
            throw JsonException("number");
        }
        index++;
    }
}

// find возвращает npos


