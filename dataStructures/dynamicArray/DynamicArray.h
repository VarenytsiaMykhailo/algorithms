#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H


class DynamicArray {
public:
    DynamicArray() : buffer(0), bufferSize(0), realSize(0) {
    }

    ~DynamicArray() {
        delete[] buffer;
    }

    // Get real size
    int size() const {
        return realSize;
    }

    double getAt(int index) const; // O(1)

    // Add new element
    void add(double element); // Best O(1), worse O(n), AC(n) = O(1) - average

    double operator[](int index) const { // O(1)
        return getAt(index);
    }

    double &operator[](int index); // O(1)

private:
    double *buffer; // Buffer

    int bufferSize; // Size of buffer

    int realSize; // Num of elements in the buffer

    int defaultInitialSize = 10;

    void grow();
};


#endif //DYNAMICARRAY_DYNAMICARRAY_H
