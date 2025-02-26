#ifndef STACK_H
#define STACK_H

#include "ResizingArray.h"

template <typename T>
class Stack {
private:
    ResizingArray<T> data;

public:
    // uses ResizingArray's Push
    void Push(T value) {
        data.Push(value);
    }

    T Pop() {
        if (IsEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        // uses ResizingArray's Pop
        return data.Pop();
    }

    T Top() {
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        // returns the value of the top value on the stack
        return data[data.getSize() - 1];
    }

    bool IsEmpty() {
        return data.getSize() == 0;
    }
};

#endif