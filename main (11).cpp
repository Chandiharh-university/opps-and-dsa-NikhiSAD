#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack.\n";
    }

    // Peek operation
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Display stack contents
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    // Demonstrate stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Peek: " << stack.peek() << "\n";

    stack.pop();
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop(); // Attempt to pop from empty stack

    return 0;
}
