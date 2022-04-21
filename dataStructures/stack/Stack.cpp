#include <cassert>
#include "Stack.h"


Stack::Stack(int bufferSize) : bufferSize(bufferSize), top(-1) {
    buffer = new int[bufferSize];
}

Stack::~Stack() {
    delete[] buffer;
}

void Stack::push(int a) {
    assert(top + 1 < bufferSize);
    buffer[++top] = a;
}

int Stack::pop() {
    assert(top != -1);
    return buffer[top--];
}
