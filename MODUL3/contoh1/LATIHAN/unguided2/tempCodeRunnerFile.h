#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

// Deklarasi struktur pelajaran
struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi
Pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(Pelajaran pel);

#endif
