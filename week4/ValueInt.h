#ifndef OPDRACHTEN_VALUEINT_H
#define OPDRACHTEN_VALUEINT_H

#include <string>
#include <iostream>
#include "BaseValue.h"

class ValueInt : public BaseValue {

private:
    int m_value;

public:
    ValueInt(std::string name, int value=0) : BaseValue(name), m_value(value) {
        //TODO: what if name is null?
    }

    void Update(int value) {
        m_value = value;
    }

    void Get(std::ostream &out) const {
        out << GetName() << "=" << m_value << " (int)";
    }

};


#endif //OPDRACHTEN_VALUEINT_H
