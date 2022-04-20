#include <iostream>

// T(n) = O(n)
// the best way: sort array and find elem with binary search algorithm
bool hasElement(const double *arr, int count, double element) {
    for (int i = 0; i < count; ++i) {
        if (arr[i] == element) { // Found
            return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    double arr[] = {1.0, 1.2, 1.3, 1.5};
    std::cout << hasElement(arr, n, 1.3) << std::endl;
    return 0;
}
