//độ phức tạp thời gian O(n)
//độ phức tạp về bộ nhớ O(1)
#include <iostream>
using namespace std;

int main() {
    int N;
    float a[100];
    float tong = 0, trungBinh;

    cout << "Nhap N: ";
    cin >> N;

    cout << "Nhap day so:\n";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        tong += a[i];
    }

    trungBinh = tong / N;

    cout << "Gia tri trung binh = " << trungBinh << endl;

    cout << "Cac gia tri lon hon hoac bang gia tri trung binh:\n";
    for (int i = 0; i < N; i++) {
        if (a[i] >= trungBinh) {
            cout << a[i] << " ";
        }
    }

    return 0;
}