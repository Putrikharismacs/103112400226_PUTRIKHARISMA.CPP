#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

struct Mahasiswa {
    string Nama;
    int NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
};

const int MAX = 8;

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int Top;
};

// === PROTOTYPE FUNGSI ===
void createStack(StackMahasiswa &S);
bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void push(StackMahasiswa &S, Mahasiswa x);
void pop(StackMahasiswa &S, Mahasiswa &x);
void printStack(StackMahasiswa S);

float hitungNilaiAkhir(Mahasiswa M);
Mahasiswa getAtPosition(StackMahasiswa S, int pos);
void updateAtPosition(StackMahasiswa &S, int pos, Mahasiswa M);
void searchNilaiAkhir(StackMahasiswa S, float minVal, float maxVal);

#endif
