#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// Deklarasi struct ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi function & procedure
pelajaran create_pelajaran(string namaMapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
