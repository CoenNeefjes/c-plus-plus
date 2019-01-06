#include <iostream>

void printArray(int *values, int values_count) {
    for (int i = 0; i < values_count; i++) {
        std::cout << values[i];
        if (i != values_count-1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}

int searchArray(int const *values, int values_count, int value) {
    if (values_count == 0 || value < values[0]) {
        return 0;
    }
    if (value > values[values_count-1]) {
        return values_count;
    }
    for (int i = 0; i < values_count; i++) {
        if (values[i] == value) {
            return i;
        } else if (values[i] < value && value < values[i+1]) {
            return i+1;
        }
    }
    std::cout << "this should not happen" << std::endl;
    return -1;
}

int *insertArray(int *values, int *values_count, int value) {
    // Create new array
    int *newValues = new int[*values_count+1];
    // Copy old array into new one
    for (int i = 0; i < *values_count; i++) {
        newValues[i] = values[i];
    }
    // Get index where the new number should go
    int insertOnIndex = searchArray(values, *values_count, value);
    std::cout << "Inserting " << value << " at index " << insertOnIndex << std::endl;

    // Replace items so we can fit the number in the right index
    for (int i = *values_count; i > insertOnIndex; i--) {
        newValues[i] = newValues[i-1];
    }
    // Set the number ont the index
    newValues[insertOnIndex] = value;
    // Print the array
    printArray(newValues, *values_count+1);
    // Deallocate old array
    delete [] values;
    // Set the new values count
    *values_count = *values_count+1;
    return newValues;
}

int main() {

//    the commented part is for the practice exercises

//    int values[100] = {0,1,2,3,4,7,8,9,10,11};
//    int values_count = 10;

//    printArray(values, values_count);
//    values[3] = 12;
//    values[5] = 15;
//    printArray(values, values_count);

//    int *ptr_1 = &values[3];
//    int *ptr_2 = &values[5];
//    std::cout << *ptr_1 << std::endl;
//    std::cout << *ptr_2 << std::endl;
//    std::cout << &values[3] << std::endl;
//    std::cout << &values[5] << std::endl;
//    printArray(values, values_count);
//    *ptr_1 = 12;
//    *ptr_2 = 15;
//    printArray(values, values_count);

//    int *ptr_1 = &values[3];
//    int *ptr_2 = &values[4];
//    std::cout << "Size of int: " << sizeof(int) << std::endl;
//    std::cout << ptr_1 << " " << ptr_2 << std::endl;

    int search_values[] = {1,2,3,4,5};

    if (searchArray(search_values, sizeof(search_values)/ sizeof(int), 3) != 2) {
        std::cout << "You done fucked up son";
        return 0;
    }

    if (searchArray(search_values, sizeof(search_values)/ sizeof(int), 4) != 3) {
        std::cout << "You done fucked up son";
        return 0;
    }

    std::cout << "All good" << std::endl;

    int *values = new int[0];
    int *values_count = new int;

    *values_count = 0;

    values = insertArray(values, values_count, 8);
    values = insertArray(values, values_count, 3);
    values = insertArray(values, values_count, 1);
    values = insertArray(values, values_count, 6);
    values = insertArray(values, values_count, 5);
    values = insertArray(values, values_count, 10);
    values = insertArray(values, values_count, 4);
    values = insertArray(values, values_count, 7);
    values = insertArray(values, values_count, 2);

    return 0;
}

