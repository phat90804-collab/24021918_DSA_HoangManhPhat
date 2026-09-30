//độ phức tạp thời gian O(n)
//độ phức tạp bộ nhớ O(1)
#include<iostream>
using namespace std;
int main(){
int n;
int a[100];
cout<<"Nhap so phan tu trong day ";
cin>>n;
cout<<"Nhap cac phan tu trong day ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
int sum=0;
for(int i=0;i<n;i++){
    sum = sum + a[i];
}
cout<<"Tong cac phan tu trong day "<<sum;

    return 0;
}
