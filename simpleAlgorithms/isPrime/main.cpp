#include <iostream>

// T(n) = O(n), memory: 8 byte const, M(n) = O(1)
bool isPrime(int n) {
    if (n == 1) {
        return false; // 1 is not prime?
    }
    for (int i = 2; i * i <= n; ++i) { // operation '*' faster than sqrt
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << isPrime(5) << std::endl;
    return 0;
}


