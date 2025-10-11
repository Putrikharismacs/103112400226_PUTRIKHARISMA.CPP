#ifndef MAHASISWA_H
#define MAHASISWA_H
#include <iostream>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    string jurusan;
    float ipk;
};

// Deklarasi fungsi-fungsi ADT
void tambahMahasiswa(Mahasiswa data[], int &n);
void tampilMahasiswa(Mahasiswa data[], int n);
void cariMahasiswa(Mahasiswa data[], int n, string cariNIM);

#endif
