#include <iostream>

// Вернет индекс первого найденного element в отсортированном по возрастанию массиве (!!! не первого вхождения, см модификацию ниже от lower_bound)
// T(n) = O(log n), M(n) = O(1)
int binarySearch(const double *arr, int count, double element) {
    int first = 0;
    int last = count; // Элемент в last не учитывается. last - индекс после последнего элемента массива. Такая логика не требует проверки массива на пустоту
    while (first < last) {
        int mid = (first + last) / 2;
        if (arr[mid] < element) { // Выбираем правую часть массива
            first = mid + 1;
        } else { // Выбираем левую часть массива
            last = mid;
        }
    }
    // Все элементы слева от first трого меньше искомого
    return (first == count || arr[first] != element) ? -1 : first;
}

// Вернет индекс первого вхождения element в отсортированном по возрастанию массиве
// Возвращает позицию вставки элемента на отрезке [first, last)
// Равные элементы располагаются после (аналог std::lower_bound)
// T(n) = O(log n), M(n) = O(1)
int findInsertionPoint(const double* arr, int count, double element) {
    int first = 0;
    int last = count; // Элемент в last не учитывается
    while (first < last) {
        int mid = (first + last) / 2;
        if (arr[mid] < element) { // Выбираем правую часть массива
            first = mid + 1;
        } else { // Выбираем левую часть массива
            last = mid;
        }
    }
    return first;
}

int main() {
    int n = 4;
    double arr[] = {1.0, 2.0, 3.0, 3.0};
    std::cout << binarySearch(arr, n, 3.0) << std::endl;

    int n2 = 10;
    double arr2[] = {-40, -12, 0, 1, 2, 6, 22, 54, 343, 711};
    std::cout << binarySearch(arr2, n2, -12) << std::endl;

    int n3 = 10;
    double arr3[] = {10, 10, 10, 20, 20, 20, 30, 30};
    std::cout << binarySearch(arr3, n3, 20) << std::endl;
    return 0;
}
