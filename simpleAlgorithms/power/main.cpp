#include <iostream>

// O(logN), M(n) = O(1)
double power(double a, int n) {
    double result = 1; // Для хранения результата
    double aInPowerOf2 = a; // Текущее значение (a^2)^2...)^2

    while (n > 0) { // Количество итераций цикла = степень двойки, не ппрвышающая n, т.е. log(n)
        // Добавляем нужную степень двойки к результату, если она есть в разложении n
        if ((n & 1) == 1) {
            result *= aInPowerOf2;
        }
        aInPowerOf2 *= aInPowerOf2;

        // Не стоит использовать битовый сдвиг со знаковыми числами
        n = n >> 1; // Можно написать n /= 2. Работает т.к. while (n > 0)
    }
    return result;
}

int main() {
    std::cout << power(4, 4) << std::endl;
    return 0;
}
