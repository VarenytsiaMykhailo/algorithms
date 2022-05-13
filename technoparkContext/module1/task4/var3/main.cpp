#include <iostream>
#include <cassert>

/*
В операционной системе Technux есть планировщик процессов.
Каждый процесс характеризуется:
приоритетом P
временем, которое он уже отработал t
временем, которое необходимо для завершения работы процесса T
Планировщик процессов выбирает процесс с минимальным значением P * (t + 1), выполняет его время P и кладет обратно в очередь процессов.
Если выполняется условие t >= T, то процесс считается завершенным и удаляется из очереди.
Требуется посчитать кол-во переключений процессора.
Формат входных данных:  Сначала вводится кол-во процессов. После этого процессы в формате P T
Формат выходных данных: Кол-во переключений процессора.

Пример входных данных:
in:
3
1 10
1 5
2 5

out:
18

*/

struct ProcessStatus {
    int P;

    int t;

    int T;

    ProcessStatus();
};

ProcessStatus::ProcessStatus() : P(0), t(0), T(0) {
}


struct ProcessStatusComparator {
    bool operator()(const ProcessStatus &l, const ProcessStatus &r) const {
        return l.P * (l.t + 1) < r.P * (r.t + 1);
    }
};

template<typename T>
struct DefaultComparator {
    bool operator()(const T &l, const T &r) const {
        return l < r;
    }
};

template<typename T, typename Comparator>
class Heap {
public:
    Heap(T *data, std::size_t bufferSize, Comparator comparator) : buffer(data),
                                                                   bufferSize(bufferSize),
                                                                   comparator(comparator) {
        makeHeapOnBasedArray();
    }

    Heap(const Heap &) = delete;

    Heap(Heap &&) = delete;

    Heap &operator=(const Heap &) = delete;

    Heap &operator=(Heap &&) = delete;

    ~Heap() {
        delete[] buffer;
    }

    T &top() const {
        assert(!isEmpty());

        return buffer[0];
    }

    T pop() {
        assert(!isEmpty());
        T extractedTop = buffer[0];
        buffer[0] = buffer[bufferSize - 1];
        bufferSize--;
        if (!isEmpty()) {
            siftDown(0);
        }

        return extractedTop;
    }

    bool isEmpty() const {
        return bufferSize == 0;
    }

    std::size_t size() const {
        return bufferSize;
    }


private:
    T *buffer;

    std::size_t bufferSize;

    Comparator comparator;

    void makeHeapOnBasedArray() {
        for (long int i = bufferSize / 2; i >= 0; --i) {
            siftDown(i);
        }
    }

    void siftDown(std::size_t index) {
        std::size_t leftChildIndex = index * 2 + 1;
        std::size_t rightChildIndex = index * 2 + 2;
        std::size_t minimumElemIndex = index;
        if ((leftChildIndex < bufferSize) && comparator(buffer[leftChildIndex], buffer[index])) {
            minimumElemIndex = leftChildIndex;
        }
        if ((rightChildIndex < bufferSize) && comparator(buffer[rightChildIndex], buffer[minimumElemIndex])) {
            minimumElemIndex = rightChildIndex;
        }
        if (minimumElemIndex != index) {
            T tmp = buffer[minimumElemIndex];
            buffer[minimumElemIndex] = buffer[index];
            buffer[index] = tmp;

            siftDown(minimumElemIndex);
        }
    }
};

void processesModeling(ProcessStatus *const processes, std::size_t processCount) {
    auto *heap = new Heap<ProcessStatus, ProcessStatusComparator>(processes,
                                                                                                          processCount,
                                                                                                          ProcessStatusComparator());
    std::size_t switchCount = 0;

    //for (std::size_t i = heap->size(); i > 0; --i)
    while (!heap->isEmpty()) {
        ProcessStatus &processStatusOnTop = heap->top();
        processStatusOnTop.t += processStatusOnTop.P;
        if (processStatusOnTop.t >= processStatusOnTop.T) {
            ProcessStatus popped = heap->pop();
        }

        switchCount++;
    }

    std::cout << switchCount;

    delete heap;
}

int main() {
    std::size_t processCount = 0;
    std::cin >> processCount;

    auto *processes = new ProcessStatus[processCount];

    for (std::size_t i = 0; i < processCount; ++i) {
        std::cin >> processes[i].P;
        processes[i].t = 0;
        std::cin >> processes[i].T;
    }

    processesModeling(processes, processCount);

    //delete[] processes;

    return 0;
}
