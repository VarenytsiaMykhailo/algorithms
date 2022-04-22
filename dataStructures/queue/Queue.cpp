#include <cassert>
#include "Queue.h"

Queue::Queue(int bufferSize) : bufferSize(bufferSize), head(0), tail(0) {
    buffer = new int[bufferSize];
}

Queue::~Queue() {
    delete[] buffer;
}

void Queue::enqueue(int a) {
    assert((tail + 1) % bufferSize != head);
    buffer[tail] = a;
    tail = (tail + 1) % bufferSize;
}

int Queue::dequeue() {
    assert(head != tail);
    int result = buffer[head];
    head = (head + 1) % bufferSize;
    return result;
}
