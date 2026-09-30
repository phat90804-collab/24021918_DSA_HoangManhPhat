//độ phức tạp về thời gian O(logn)
//độ phức tạp về bộ nhớ O(1)
#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void rutGon(int &a, int &b) {
    int u = UCLN(a, b);

    a = a / u;
    b = b / u;
}

int main() {
    int a, b;

    cout << "Nhap tu so a: ";
    cin >> a;

    cout << "Nhap mau so b: ";
    cin >> b;

    if (b == 0) {
        cout << "Mau so phai khac 0!";
        return 0;
    }

    rutGon(a, b);

    cout << "Phan so sau khi rut gon: " << a << "/" << b;

    return 0;
}