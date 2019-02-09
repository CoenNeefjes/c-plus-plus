#ifndef OPDRACHTEN_KEYVALUE_H
#define OPDRACHTEN_KEYVALUE_H

#include <vector>
#include <iostream>
#include "BaseValue.h"

class KeyValue {
private:
    std::vector<BaseValue*> data;

    int getIndex(std::string name) const {
        for (int i=0; i < data.size(); i++) {
            if (data[i]->GetName() == name){
//                std::cout << data[i]->GetName() << " equals " << name << ", so returning " << i << std::endl;
                return i;
            }
        }
        Error("object not found");
    }

    [[noreturn]] void Error(std::string const &message) const {
        std::cerr << message << std::endl;
        exit(-1);
    }

public:
    void Create(BaseValue *value){
        data.push_back(value);
    }

    void Delete(std::string const &name){
        data.erase(data.begin() + getIndex(name));
    }

    BaseValue const &Get(std::string const &name) const {
        return *data[getIndex(name)];
    }

//    BaseValue $Get(std::string const &name) {
//        return *data[getIndex(name)];
//    }

};


#endif //OPDRACHTEN_KEYVALUE_H
