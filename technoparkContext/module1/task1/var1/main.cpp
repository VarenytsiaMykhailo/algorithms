#include <iostream>

/*
Подсчитать кол-во единичных бит в входном числе , стоящих на четных позициях.
Позиции битов нумеруются с 0.

Необходимо использование битовых операций.
Использование арифметических операций запрещено.

Формат ввода:
Входное число лежит в диапазоне 0..2^32-1 и вводится в десятичном виде.

Формат вывода:
Целое число - количество бит

Примеры ввода in/out:
1/1
5/2
25/2
*/

unsigned int calcNumOfBitsInEvenPositions(unsigned int);

int main() {
    unsigned int num = 0;
    std::cin >> num;

    std::cout << calcNumOfBitsInEvenPositions(num) << std::endl;

    return 0;
}

unsigned int calcNumOfBitsInEvenPositions(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        count += num & 1;
        num = num >> 2;
    }
    return count;
}
