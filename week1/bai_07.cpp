//độ phức tạp về thời gian O(N*M)
//độ phức tạp về bộ nhớ O(1)
#include <iostream>
using namespace std;

int tinhTong(int a[][100], int n, int m) {
    int tong = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tong += a[i][j];
        }
    }

    return tong;
}

void xoaDong(int a[][100], int &n, int m, int i) {
    for (int dong = i; dong < n - 1; dong++) {
        for (int cot = 0; cot < m; cot++) {
            a[dong][cot] = a[dong + 1][cot];
        }
    }

    n--;
}

int main() {
    int a[100][100];
    int n, m;

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap M: ";
    cin >> m;

    cout << "Nhap mang:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Tong cac phan tu = "
         << tinhTong(a, n, m) << endl;

    int i;
    cout << "Nhap dong can xoa (0 -> " << n - 1 << "): ";
    cin >> i;

    if (i >= 0 && i < n) {
        xoaDong(a, n, m, i);
    } else {
        cout << "Vi tri dong khong hop le!";
        return 0;
    }

    cout << "Mang sau khi xoa dong " << i << ":\n";

    for (int dong = 0; dong < n; dong++) {
        for (int cot = 0; cot < m; cot++) {
            cout << a[dong][cot] << " ";
        }
        cout << endl;
    }

    return 0;
}