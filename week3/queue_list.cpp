#include <iostream>
using namespace std;

struct ListQueue {
    int arr[1000];
    int headIndex;
    int tailIndex;

    ListQueue() {
        headIndex = 0;
        tailIndex = 0;
    }

    bool isEmpty() {
        return headIndex == tailIndex;
    }

    int size() {
        return tailIndex - headIndex;
    }

    void enqueue(int item) {
        arr[tailIndex] = item;
        tailIndex++;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[headIndex];
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int popItem = arr[headIndex];
        headIndex++;
        return popItem;
    }
};

int main() {
    ListQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Kich thuoc: " << q.size() << endl;
    cout << "Gia tri dau: " << q.front() << endl;

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}