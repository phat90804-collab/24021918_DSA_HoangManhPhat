
#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
public:
    int arr[1000];
    int size;
};

void insertMax(Heap &h, int x) {
    int k = h.size;
    h.arr[k] = x;
    h.size++;

    while (k > 0) {
        int p = (k - 1) / 2;

        if (h.arr[k] <= h.arr[p])
            break;

        swap(h.arr[k], h.arr[p]);
        k = p;
    }
}

void deleteMax(Heap &h, int x) {
    int k = 0;

    while (k < h.size && h.arr[k] != x)
        k++;

    if (k == h.size)
        return;

    h.arr[k] = h.arr[h.size - 1];
    h.size--;

    while (k > 0) {
        int p = (k - 1) / 2;

        if (h.arr[k] <= h.arr[p])
            break;

        swap(h.arr[k], h.arr[p]);
        k = p;
    }

    while (2 * k + 1 < h.size) {
        int l = 2 * k + 1;
        int r = 2 * k + 2;
        int m = l;

        if (r < h.size && h.arr[r] > h.arr[l])
            m = r;

        if (h.arr[k] >= h.arr[m])
            break;

        swap(h.arr[k], h.arr[m]);
        k = m;
    }
}

void insertMin(Heap &h, int x) {
    int k = h.size;
    h.arr[k] = x;
    h.size++;

    while (k > 0) {
        int p = (k - 1) / 2;

        if (h.arr[k] >= h.arr[p])
            break;

        swap(h.arr[k], h.arr[p]);
        k = p;
    }
}

void deleteMin(Heap &h, int x) {
    int k = 0;

    while (k < h.size && h.arr[k] != x)
        k++;

    if (k == h.size)
        return;

    h.arr[k] = h.arr[h.size - 1];
    h.size--;

    while (k > 0) {
        int p = (k - 1) / 2;

        if (h.arr[k] >= h.arr[p])
            break;

        swap(h.arr[k], h.arr[p]);
        k = p;
    }

    while (2 * k + 1 < h.size) {
        int l = 2 * k + 1;
        int r = 2 * k + 2;
        int m = l;

        if (r < h.size && h.arr[r] < h.arr[l])
            m = r;

        if (h.arr[k] <= h.arr[m])
            break;

        swap(h.arr[k], h.arr[m]);
        k = m;
    }
}

void display(Heap h) {
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;
}

int main() {
    Heap maxH, minH;

    maxH.size = 0;
    minH.size = 0;

    int a[] = {15, 7, 20, 3, 12, 8};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        insertMax(maxH, a[i]);
        insertMin(minH, a[i]);
    }

    cout << "MAX HEAP: ";
    display(maxH);

    cout << "MIN HEAP: ";
    display(minH);

    int x;
    cout << "\nNhap phan tu can xoa: ";
    cin >> x;

    deleteMax(maxH, x);
    deleteMin(minH, x);

    cout << "\nMAX HEAP sau khi xoa: ";
    display(maxH);

    cout << "MIN HEAP sau khi xoa: ";
    display(minH);

    return 0;
}
