#ifndef OPDRACHTEN_VALUEINT_H
#define OPDRACHTEN_VALUEINT_H

#include <string>
#include <iostream>

class ValueInt {

private:
    int m_value;
    std::string m_name;

public:
    ValueInt(std::string name, int value) {
        //TODO: what if name is null?
        m_name = name;
        m_value = value;
    }

    void Update(int value) {
        m_value = value;
    }

    void Get(std::ostream &out) const {
        out << m_name << "=" << m_value << " (int)";
    }

    std::string const &GetName() const {
        return m_name;
    }

};


#endif //OPDRACHTEN_VALUEINT_H
