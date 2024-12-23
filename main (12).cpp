
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Simple Queue Implementation
void simpleQueueDemo() {
    cout << "\n=== Simple Queue ===\n";
    queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    // Display and Dequeue
    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

// Circular Queue Implementation
class CircularQueue {
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) : capacity(cap), front(-1), rear(-1), size(0) {
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return false;
        }
        if (front == rear) {
            front = rear = -1; // Reset the queue
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Circular Queue contents: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << "\n";
    }
};

void circularQueueDemo() {
    cout << "\n=== Circular Queue ===\n";
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.display();
}

// Priority Queue Implementation
void priorityQueueDemo() {
    cout << "\n=== Priority Queue ===\n";
    priority_queue<int> pq; // Max-heap by default

    pq.push(40);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Priority Queue contents (Max-Heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    // Min-heap using custom comparator
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(40);
    minPq.push(10);
    minPq.push(30);
    minPq.push(20);

    cout << "Priority Queue contents (Min-Heap): ";
    while (!minPq.empty()) {
        cout << minPq.top() << " ";
        minPq.pop();
    }
    cout << "\n";
}

int main() {
    simpleQueueDemo();
    circularQueueDemo();
    priorityQueueDemo();
    return 0;
}

