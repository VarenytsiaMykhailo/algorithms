#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack {
public:
    explicit Stack(int bufferSize);

    ~Stack();

    void push(int a);

    int pop();

    bool isEmpty() const {
        return top == -1;
    }

private:
    int *buffer;

    int bufferSize;

    int top; // Index of the top element
};


#endif //STACK_STACK_H
