#include <iostream>
#include <cmath>

/*
Ограничение времени	1 секунда
Ограничение памяти	5Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt

Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
n ≤ 110000, m ≤ 1000. Время работы поиска для каждого элемента B[i]: O(log(k)).

Требования: Время работы поиска для каждого элемента B[i]: O(log(k)).
Внимание! В этой задаче для каждого B[i] сначала нужно определить диапазон для бинарного поиска размером порядка k
с помощью экспоненциального поиска, а потом уже в нем делать бинарный поиск.

Пример входных данных:
in:
3
10 20 30
3
9 15 35

out:
0 0 2

in:
3
10 20 30
4
8 9 10 32

out:
0 0 0 2
*/

struct Interval;

std::size_t *calcIndices(const int[], const std::size_t, const int[], const std::size_t, std::size_t[]);

Interval getInterval(const int[], const std::size_t, const int);

std::size_t binarySearch(const int[],
                         const std::size_t,
                         const std::size_t,
                         const std::size_t,
                         const int);

int main() {
    std::size_t n = 0;
    std::cin >> n;
    int *A = new int[n];
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::size_t m = 0;
    std::cin >> m;
    int *B = new int[m];
    for (std::size_t i = 0; i < m; ++i) {
        std::cin >> B[i];
    }

    std::size_t *resultArray = new std::size_t[m];
    resultArray = calcIndices(A, n, B, m, resultArray);

    for (std::size_t i = 0; i < m; ++i) {
        std::cout << resultArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] resultArray;

    return 0;
}

struct Interval {
    std::size_t a = 0;

    std::size_t b = 0;
};

std::size_t *calcIndices(const int A[],
                         const std::size_t n,
                         const int B[],
                         const std::size_t m,
                         std::size_t resultArray[]) {

    for (std::size_t i = 0; i < m; ++i) {
        Interval interval = getInterval(A, n, B[i]);
        //std::cout << "for elem = " << B[i] << " a = " << interval.a << " b = " << interval.b << std::endl;
        std::size_t index = binarySearch(A, n, interval.a, interval.b, B[i]);
        resultArray[i] = index;
        //std::cout << "for elem = " << B[i] << " indexInA = " << index << std::endl;
    }

    return resultArray;
}

Interval getInterval(const int array[], const std::size_t n, const int element) {
    if (n == 1) {
        return Interval{0, 0};
    } else if (element <= array[1]) {
        return Interval{0, 1};
    }

    std::size_t intervalStart = 1;
    std::size_t intervalEnd = intervalStart << 1;

    while (intervalStart <= n) {
        if (intervalEnd > n - 1) {
            intervalEnd = n - 1;
        }
        if ((element >= array[intervalStart]) && (element <= array[intervalEnd])) {
            return Interval{intervalStart, intervalEnd};
        }

        intervalStart = intervalStart << 1;
        intervalEnd = intervalEnd << 1;
    }

    return Interval{n - 1, n - 1}; // Если элемент не содержится в массиве, возвращаем интервал из последнего индекса
}

std::size_t binarySearch(const int array[],
                         const std::size_t n,
                         const std::size_t intervalStart,
                         const std::size_t intervalEnd,
                         const int element) {
    std::size_t first = intervalStart;
    std::size_t last = intervalEnd; // Элемент в last не учитывается. last - индекс после последнего элемента массива. Такая логика не требует проверки массива на пустоту
    while (first < last) {
        std::size_t mid = (first + last) / 2;
        if (array[mid] < element) { // Выбираем правую часть массива
            first = mid + 1;
        } else { // Выбираем левую часть массива
            last = mid;
        }
    }
    // После работы цикла все элементы слева от first строго меньше искомого, array[last] >= elem

    //std::cout << "___for elem = " << element << " first = " << first << " last = " << last << std::endl;
    if ((first == n) || (array[first] != element)) {
        if (first == 0) {
            return first;
        } else {
            return (abs(array[first - 1] - element) <= abs(array[first] - element)) ? first - 1 : first;
        }
    } else {
        return first;
    }
}
