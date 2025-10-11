#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string nama, kode;

    cout << "Masukkan nama mata pelajaran: ";
    getline(cin, nama);
    cout << "Masukkan kode mata pelajaran: ";
    getline(cin, kode);

    // Membuat objek pelajaran menggunakan fungsi ADT
    Pelajaran p1 = create_pelajaran(nama, kode);

    cout << "\n=== Data Pelajaran ===\n";
    tampil_pelajaran(p1);

    return 0;
}
