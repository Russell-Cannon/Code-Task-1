#include <iostream>
#include "Stack.h"
#include "Queue.h"

void ReverseCString(char* str) {
    Stack<char> stack;
    int i = 0;
    // ends at the delimeter character of the c-string
    while (str[i] != '\0') {
        // pushes each char from the c-string onto the stack
        stack.Push(str[i]);
        i++;
    }

    // resets i back to 0
    i = 0;

    // empties the stack, reversing the c-string in the process
    while (!stack.IsEmpty()) {
        str[i++] = stack.Pop();
    }
}

class StackQueue {
private:
    Stack<int> stack1, stack2;

public:
    // loads stack1 with the values for the queue
    void Enqueue(int value) {
        stack1.Push(value);
    }

    // 
    int Dequeue() {
        if (stack2.IsEmpty()) {
            while (!stack1.IsEmpty()) {
                stack2.Push(stack1.Pop());
            }
        }
        return stack2.Pop();
    }
};

int main() {
    // Demonstrates the stack and queue
    Stack<int> stack;
    Queue<int> queue;

    stack.Push(1);
    std::cout << "Stack Push: 1" << std::endl;
    stack.Push(2);
    std::cout << "Stack Push: 2" << std::endl;
    stack.Push(3);
    std::cout << "Stack Push: 3" << std::endl << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << "Stack Pop: " << stack.Pop() << std::endl;
    }

    std::cout << std::endl;

    queue.Enqueue(10);
    std::cout << "Queue Enqueue: 10" << std::endl;
    queue.Enqueue(20);
    std::cout << "Queue Enqueue: 20" << std::endl;
    queue.Enqueue(30);
    std::cout << "Queue Enqueue: 30" << std::endl << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << "Queue Dequeue: " << queue.Dequeue() << std::endl;
    }

    std::cout << std::endl;

    char str[] = "Hello, World!";
    std::cout << "C-string: ";
    // change the 13 here to match the c-string length when needed
    for(int i = 0; i < 13; i++){
        std::cout << str[i];
    }
    std::cout << std::endl;
    ReverseCString(str);
    std::cout << "Reversed C-string: " << str << std::endl << std::endl;

    StackQueue stackQueue;
    Queue<int> testQueue;
    stackQueue.Enqueue(100);
    testQueue.Enqueue(100);
    std::cout << "Simulated Queue and Test Enqueue: 100" << std::endl;
    stackQueue.Enqueue(200);
    testQueue.Enqueue(200);
    std::cout << "Simulated Queue and Test Enqueue: 200" << std::endl;
    stackQueue.Enqueue(300);
    testQueue.Enqueue(300);
    std::cout << "Simulated Queue and Test Enqueue: 300" << std::endl << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << "Simulated Queue Dequeue: " << stackQueue.Dequeue() << '\n';
        std::cout << "Standard Queue Dequeue: " << testQueue.Dequeue() << '\n';
    }

    return 0;
}