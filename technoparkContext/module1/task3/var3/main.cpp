/*
Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды push* и pop*.
Формат входных данных.
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.
a = 1 - push front
a = 2 - pop front
a = 3 - push back
a = 4 - pop back
Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.
Формат выходных данных.
Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

3_3. Реализовать очередь с помощью двух стеков.
Требования: Очередь должна быть реализована в виде класса. Стек тоже должен быть реализован в виде класса.

Примеры входных данных:
in:
3
3 44
3 50
2 44

out:
YES

in:
2
2 -1
3 10

out:
YES

in:
2
3 44
2 66

out:
NO
*/

#include <iostream>
#include <cassert>

// ---------------- DynamicArray

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

    int pop();

    double operator[](int index) const { // O(1)
        return getAt(index);
    }

    double &operator[](int index); // O(1)

private:
    double *buffer; // Buffer

    int bufferSize; // Size of addBuffer

    int realSize; // Num of elements in the addBuffer

    int defaultInitialSize = 10;

    void grow();
};

// Get alement
double DynamicArray::getAt(int index) const {
    assert(index >= 0 && index < realSize && buffer != 0);
    return buffer[index];
}

// Grow addBuffer
void DynamicArray::grow() {
    int newBufferSize = std::max(bufferSize * 2, defaultInitialSize);
    double *newBuffer = new double[newBufferSize];
    /*
    for (int i = 0; i < realSize; ++i) { // Copy elements. Better is using std::copy
        newBuffer[i] = addBuffer[i];
    }
    */
    std::copy(buffer, buffer + realSize, newBuffer);

    delete[] buffer;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

int DynamicArray::pop() {
    assert(realSize > 0 && buffer != 0);
    return buffer[--realSize];
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

// ---------------- Stack

class Stack {
public:
    explicit Stack();

    ~Stack();

    void push(int a);

    int pop();

    bool isEmpty() const {
        return top == -1;
    }

private:
    DynamicArray *buffer;

    int top; // Index of the top element
};

Stack::Stack() : top(-1) {
    buffer = new DynamicArray();
}

Stack::~Stack() {
    delete buffer;
}

void Stack::push(int a) {
    buffer->add(a);
    ++top;
}

int Stack::pop() {
    assert(top != -1);
    --top;
    return buffer->pop();
}

// ---------------- Queue

class Queue {
public:
    explicit Queue();

    ~Queue();

    void enqueue(int a);

    int dequeue();

    bool isEmpty() const {
        return addBuffer->isEmpty() && readBuffer->isEmpty();
    }

private:
    Stack *addBuffer;

    Stack *readBuffer;

    void moveDataFromAddBufferToReadBuffer();
};

Queue::Queue() {
    addBuffer = new Stack();
    readBuffer = new Stack();
}

Queue::~Queue() {
    delete addBuffer;
    delete readBuffer;
}

void Queue::enqueue(int a) {
    addBuffer->push(a);
}

int Queue::dequeue() {
    if (readBuffer->isEmpty()) {
        moveDataFromAddBufferToReadBuffer();
    }

    return readBuffer->pop();
}

void Queue::moveDataFromAddBufferToReadBuffer() {
    while (!addBuffer->isEmpty()) {
        readBuffer->push(addBuffer->pop());
    }
}

void process() {
    int n = 0;
    std::cin >> n;
    Queue *queue = new Queue();
    bool allValuesExpected = true;
    while (n--) {
        int command = 0;
        int value = 0;
        std::cin >> command;
        std::cin >> value;
        switch (command) {
            case 2: {// Dequeue (pop front)
                if (queue->isEmpty()) {
                    if (value != -1) {
                        allValuesExpected = false;
                    }
                } else if (queue->dequeue() != value) {
                    allValuesExpected = false;
                }
                break;
            }
            case 3: { // Enqueue (push back)
                queue->enqueue(value);

                break;
            }
            default: {
                assert(false);
            }
        }
    }
    std::cout << (allValuesExpected ? "YES" : "NO") << std::endl;
    delete queue;
}

int main() {
    process();

    return 0;
}
