#ifndef OPDRACHTEN_VALUESTRING_H
#define OPDRACHTEN_VALUESTRING_H


#include <iostream>
#include "BaseValue.h"

class ValueString: public BaseValue {

private:
    std::string m_value;

public:
    ValueString(std::string name, std::string value) : BaseValue(name), m_value(value) {}

    void Update(std::string value) {
        m_value = value;
    }

    void Get(std::ostream &out) const {
        out << GetName() << "=" << m_value << " (string)";
    }

};


#endif //OPDRACHTEN_VALUESTRING_H
