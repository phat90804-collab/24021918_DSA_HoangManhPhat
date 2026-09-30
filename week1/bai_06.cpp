//độ phức tạp về thời gian xóa phần tử O(n)
//độ phức tạp về bộ nhớ xóa phần tử O(1)
//độ phức tạp về thời gian chèn phần tử O(n)
//độ phức tạp về bộ nhớ chèn phần tử O(1)

#include <iostream>
using namespace std;

void xoaPhanTu(int a[], int &n, int k) {
    for (int i = k - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void chenPhanTu(int a[], int &n, int y, int m) {
    for (int i = n; i >= m; i--) {
        a[i] = a[i - 1];
    }

    a[m - 1] = y;
    n++;
}

int main() {
    int a[100];
    int n, k, m, y;

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap day so:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Nhap vi tri k can xoa: ";
    cin >> k;

    if (k >= 1 && k <= n) {
        xoaPhanTu(a, n, k);
    } else {
        cout << "Vi tri k khong hop le!\n";
    }

    cout << "Day sau khi xoa: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nNhap gia tri y: ";
    cin >> y;

    cout << "Nhap vi tri m can chen: ";
    cin >> m;

    if (m >= 1 && m <= n + 1) {
        chenPhanTu(a, n, y, m);
    } else {
        cout << "Vi tri m khong hop le!\n";
    }

    cout << "Day sau khi chen: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}