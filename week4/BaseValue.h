#ifndef OPDRACHTEN_BASEVALUE_H
#define OPDRACHTEN_BASEVALUE_H

#include <string>

class BaseValue {

private:
    std::string m_name;

public:
    BaseValue(std::string name) : m_name(name) {}

    std::string const &GetName() const {
        return m_name;
    }

    virtual void Get(std::ostream &out) const = 0;

};


#endif //OPDRACHTEN_BASEVALUE_H
