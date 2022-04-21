#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray dynamicArray = DynamicArray();
    std::cout << dynamicArray.size() << std::endl;
    //dynamicArray.getAt(0); // Assertion failed!
    std::cout << dynamicArray.size() << std::endl;
    dynamicArray.add(11);
    std::cout << dynamicArray.size() << std::endl;
    std::cout << dynamicArray.getAt(0) << std::endl;
    std::cout << dynamicArray[0] << std::endl;
    dynamicArray[0] = 22;
    std::cout << dynamicArray[0] << std::endl;
    double value = dynamicArray[0];
    value = 33;
    std::cout << dynamicArray[0] << std::endl;

    return 0;
}
