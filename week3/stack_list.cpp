#include <iostream>
using namespace std;
struct ListStack {
    int arr[1000];
    int n;

    ListStack() {
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void push(int item) {
        arr[n] = item;
        n++;
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[n - 1];
    }

    int pop() {
        if (isEmpty()) return -1;
        int popItem = arr[n - 1];
        n--;
        return popItem;
    }
};

int main() {
    ListStack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Size: " << s.size() << endl;
    cout << "Gia tri top: " << s.top() << endl;

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}