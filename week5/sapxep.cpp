#include<iostream>
using namespace std;

void Bubble_sort(int a[], int n){
for(int i=0; i<n-1; i++){
    for(int j=0;j<n-i-1;j++ ){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
}
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        swap(a[i], a[min]);
    }
}


void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}


void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}


void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}


int main() {
    int n;
    int a[100];

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Bubble_sort(a, n);
    cout << "\nBubble Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    selectionSort(a, n);
    cout << "\nSelection Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    insertionSort(a, n);
    cout << "\nInsertion Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    mergeSort(a, 0, n - 1);
    cout << "\nMerge Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    quickSort(a, 0, n - 1);
    cout << "\nQuick Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}