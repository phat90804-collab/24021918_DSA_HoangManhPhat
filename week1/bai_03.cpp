//độ phức tạp thời gian O(n)
//độ phức tạp bộ nhớ O(1)
#include <iostream>
using namespace std;

int main() {
    int n;
    long long gt = 1;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        gt = gt * i;
    }

    cout << n << "! = " << gt;

    return 0;
}