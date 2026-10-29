
#include <iostream>
using namespace std;

const int SIZE = 11;

int table[SIZE];
bool used[SIZE];

void hashtable() {
    for (int i = 0; i < SIZE; i++) {
        used[i] = false;
    }
}

int hashFunction(int x) {
    return x % SIZE;
}

void insert(int x) {
    int index = hashFunction(x);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (used[pos] == false) {
            table[pos] = x;
            used[pos] = true;
            return;
        }
    }

    cout << "Bang bam da day!" << endl;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";

        if (used[i] == true) {
            cout << table[i];
        } else {
            cout << "Trong";
        }

        cout << endl;
    }
}

bool search(int x) {
    int index = hashFunction(x);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (used[pos] == false) {
            return false;
        }

        if (table[pos] == x) {
            return true;
        }
    }

    return false;
}

int main() {
    hashtable();

    int n, x;

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu: ";
        cin >> x;
        insert(x);
    }

    cout << "\nBang bam:\n";
    display();

    cout << "\nNhap so can tim: ";
    cin >> x;

    if (search(x)) {
        cout << "Tim thay " << x << endl;
    } else {
        cout << "Khong tim thay " << x << endl;
    }

    return 0;
}
