#include <cassert>
#include <algorithm>
#include "DynamicArray.h"

// Get alement
double DynamicArray::getAt(int index) const {
    assert(index >= 0 && index < realSize && buffer != 0);
    return buffer[index];
}

// Grow buffer
void DynamicArray::grow() {
    int newBufferSize = std::max(bufferSize * 2, defaultInitialSize);
    double *newBuffer = new double[newBufferSize];
    /*
    for (int i = 0; i < realSize; ++i) { // Copy elements. Better is using std::copy
        newBuffer[i] = buffer[i];
    }
    */
    std::copy(buffer, buffer + realSize, newBuffer);

    delete[] buffer;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

// Add element
void DynamicArray::add(double element) {
    if (realSize == bufferSize) {
        grow();
    }
    assert(realSize < bufferSize && buffer != 0);
    buffer[realSize++] = element;
}

double &DynamicArray::operator[](int index) {
    assert(index >= 0 && index < realSize && buffer != 0);
    return buffer[index];
}

