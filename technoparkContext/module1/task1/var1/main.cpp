#include <iostream>

unsigned int calcNumOfBitsInEvenPositions(unsigned int);

int main() {
    unsigned int num = 0;
    std::cin >> num;

    std::cout << calcNumOfBitsInEvenPositions(num) << std::endl;

    return 0;
}

unsigned int calcNumOfBitsInEvenPositions(unsigned int num) {
    unsigned int count = 0;
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num = num >> 2;
    }
    return count;
}
