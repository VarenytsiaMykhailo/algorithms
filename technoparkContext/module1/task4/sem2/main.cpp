#include <iostream>
#include <cmath>

struct Point {
    Point() : x(0), y(0) {
    }

    Point(int x, int y) : x(x), y(y) {
    }

    int x;

    int y;
};

bool operator<(const Point &l, const Point &r) {
    return l.x < r.x;
}

bool pointXLessComparator(const Point &l, const Point &r) {
    return l.x < r.x;
}

bool pointYLessComparator(const Point &l, const Point &r) {
    return l.y < r.y;
}

template<typename T>
bool defaultLess(const T &l, const T &r) {
    return l < r;
}

class PointComparator {
public:
    PointComparator(const Point &p0) : p0(p0) {

    }

    bool operator()(const Point &l, const Point &r) {
        auto distance1 = std::sqrt((p0.x - l.x) * (p0.x - l.x) + (p0.y - l.y) * (p0.y - l.y));
        auto distance2 = std::sqrt((p0.x - r.x) * (p0.x - r.x) + (p0.y - r.y) * (p0.y - r.y));

        return distance1 < distance2;
    }

private:
    Point p0;
};

std::istream &operator>>(std::istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

template<typename T>
void mySort(T *arr, int l, int r, bool (*cmp)(const T &l, const T &r) = defaultLess) {
    for (int i = l; i < r; ++i) {
        for (int j = l; j < r; ++j) {
            if (cmp(arr[j + 1], arr[j])) {
                std::swap(arr[j + 1], arr[j]);
            }
        }
    }
}

template<typename T, typename Comparator>
void mySort2(T *arr, int l, int r, Comparator cmp) {
    for (int i = l; i < r; ++i) {
        for (int j = l; j < r; ++j) {
            if (cmp(arr[j + 1], arr[j])) {
                std::swap(arr[j + 1], arr[j]);
            }
        }
    }
}

template<typename T, typename Comparator>
class Heap {
public:
    Heap(Comparator cmp): cmp(cmp) {
        T t;
    }
private:
    Comparator cmp;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 0;
    std::cin >> n;
    Point *arr = new Point[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    Heap<Point, PointComparator> heap(PointComparator());

    //mySort(arr, 0, n - 1, pointYLessComparator);
    Point p0;
    std::cin >> p0;
    mySort2(arr, 0, n - 1, PointComparator(p0));

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
