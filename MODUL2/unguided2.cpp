#include<iostream>
using namespace std;

// Fungsi menukar 3 variabel menggunakan pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi menukar 3 variabel menggunakan reference
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== SEBELUM PERTUKARAN ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar dengan POINTER
    tukarPointer(&a, &b, &c);
    cout << "\n=== SETELAH PERTUKARAN DENGAN POINTER ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar kembali dengan REFERENCE
    tukarReference(a, b, c);
    cout << "\n=== SETELAH PERTUKARAN DENGAN REFERENCE ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
