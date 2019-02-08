#include <sstream>
#include <chrono>
#include "KeyValue.h"

std::string IntToString(int value) {
    std::ostringstream output;
    output << value;
    return output.str();
}

int main(int argc, char* argv[]) {
    KeyValue key_value;

    std::chrono::time_point<std::chrono::system_clock> p1;
    p1 = std::chrono::system_clock::now();

    constexpr size_t number_of_keys = 10000;

    // Create elements with names int_1..number_of_keys 
    // and values 1..number_of_keys
    for (size_t i = 1; i < number_of_keys; ++i) {
        key_value.Create(new ValueInt("int_" + IntToString(i), i));
    }

    for (size_t i = 1; i < number_of_keys; ++i) {
        std::string key = "int_" + IntToString(i);
        ValueInt const &value = key_value.Get(key);
        
        std::ostringstream value_check;
        value.Get(value_check);
        std::string expected_get = (key + "=" + IntToString(i) + " (int)");
        if (value_check.str() != expected_get) {
            std::cout << "Wrong value returned for key: " << key << "," << std::endl
                << "value was: " << value_check.str() << "," << std::endl
                << "expected: " << expected_get << std::endl;
        }
        
    }

    for (size_t i = 1; i < number_of_keys; ++i) {
        std::string key = "int_" + IntToString(i);
        key_value.Delete(key);
    }

    std::chrono::time_point<std::chrono::system_clock> p2;
    p2 = std::chrono::system_clock::now();

    std::cout << "Duration: " <<
        std::chrono::duration_cast<std::chrono::milliseconds>(p2 - p1).count()
        << " milliseconds " << std::endl;


    return 0;
}
