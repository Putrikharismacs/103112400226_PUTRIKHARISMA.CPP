#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

float hitungNilaiAkhir(Mahasiswa M) {
    return 0.2*M.NilaiTugas + 0.4*M.NilaiUTS + 0.4*M.NilaiUAS;
}

void push(StackMahasiswa &S, Mahasiswa x) {
    if (!isFull(S)) {
        S.Top++;
        x.NilaiAkhir = hitungNilaiAkhir(x);
        S.data[S.Top] = x;
    }
}

void pop(StackMahasiswa &S, Mahasiswa &x) {
    if (!isEmpty(S)) {
        x = S.data[S.Top];
        S.Top--;
    }
}

void printStack(StackMahasiswa S) {
    cout << "\n===== Daftar Mahasiswa di Stack =====\n";
    for (int i = S.Top; i >= 0; i--) {
        cout << (i+1) << ". " << S.data[i].Nama 
             << " | NIM: " << S.data[i].NIM
             << " | Nilai Akhir: " << S.data[i].NilaiAkhir << endl;
    }
}

Mahasiswa getAtPosition(StackMahasiswa S, int pos) {
    return S.data[pos - 1];
}

void updateAtPosition(StackMahasiswa &S, int pos, Mahasiswa M) {
    int idx = pos - 1;
    M.NilaiAkhir = hitungNilaiAkhir(M);
    S.data[idx] = M;
}

void searchNilaiAkhir(StackMahasiswa S, float minVal, float maxVal) {
    cout << "\n=== Pencarian Mahasiswa dengan Nilai Akhir " << minVal 
         << " - " << maxVal << " ===\n";

    for (int i = S.Top; i >= 0; i--) {
        if (S.data[i].NilaiAkhir >= minVal && S.data[i].NilaiAkhir <= maxVal) {
            cout << "- " << S.data[i].Nama 
                 << " | Nilai Akhir: " << S.data[i].NilaiAkhir 
                 << " | Posisi di Stack: " << (i+1) << endl;
        }
    }
}
