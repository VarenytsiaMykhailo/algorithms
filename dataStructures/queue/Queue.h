#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


class Queue {
public:
    explicit Queue(int bufferSize);

    ~Queue();

    void enqueue(int a);

    int dequeue();

    bool isEmpty() const {
        return head == tail;
    }

private:
    int *buffer;

    int bufferSize;

    int head; // Index of the first element in the queue

    int tail; // Index after the last element in the queue
};


#endif //QUEUE_QUEUE_H
