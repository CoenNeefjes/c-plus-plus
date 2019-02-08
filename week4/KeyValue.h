#ifndef OPDRACHTEN_KEYVALUE_H
#define OPDRACHTEN_KEYVALUE_H

#include "ValueInt.h"
#include <vector>

class KeyValue {
private:
    std::vector<ValueInt*> data;

    int getIndex(std::string name) const {
        for (int i=0; i != data.size(); i++) {
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
    void Create(ValueInt *value){
        data.push_back(value);
    }

    void Delete(std::string const &name){
        data.erase(data.begin() + getIndex(name));
    }

    ValueInt const &Get(std::string const &name) const {
        return *data[getIndex(name)];
    }

    ValueInt $Get(std::string const &name) {
        return *data[getIndex(name)];
    }

};


#endif //OPDRACHTEN_KEYVALUE_H
