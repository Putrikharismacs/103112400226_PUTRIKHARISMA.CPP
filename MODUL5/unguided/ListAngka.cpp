#include "ListAngka.h"
#include <iostream>
using namespace std;

// ==================== DASAR LINKED LIST ====================
void CreateList(linkedList &L) {
    L.first = Nil;
}

address alokasi(dataAngka x) {
    address P = new node;
    P->angka = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printList(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->angka << " - ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(linkedList &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

int nbList(linkedList L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

void delAfter(linkedList &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

// ==================== PROSEDUR UPDATE ====================
void updateFirst(linkedList &L) {
    if (L.first != Nil) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != Nil) {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> P->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        cout << "masukkan update data node setelah node " << Prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> Prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// ==================== PROSEDUR SEARCH ====================
void SearchByData(linkedList L, int data) {
    address P = L.first;
    int pos = 1;
    bool found = false;
    while (P != Nil) {
        if (P->angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl << endl;
            found = true;
            break;
        }
        pos++;
        P = P->next;
    }
    if (!found) cout << "Node dengan data " << data << " tidak ditemukan!" << endl << endl;
}

void SearchByAddress(linkedList L, address P) {
    address Q = L.first;
    int pos = 1;
    bool found = false;
    while (Q != Nil) {
        if (Q == P) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << Q << endl << endl;
            found = true;
            break;
        }
        pos++;
        Q = Q->next;
    }
    if (!found) cout << "Node dengan alamat " << P << " tidak ditemukan dalam list!" << endl << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    address P = L.first;
    int pos = 1;
    bool found = false;

    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    cout << "==============================" << endl;
    while (P != Nil) {
        if (P->angka > nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << P->angka << endl;
            found = true;
        }
        P = P->next;
        pos++;
    }
    cout << "==============================" << endl;
    if (!found) cout << "Tidak ada data yang memenuhi." << endl;
}

// ==================== OPERASI ARITMETIKA ====================
int sumList(linkedList L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->angka;
        P = P->next;
    }
    return total;
}

int subtractList(linkedList L) {
    if (L.first == Nil) return 0;
    int total = L.first->angka;
    address P = L.first->next;
    while (P != Nil) {
        total -= P->angka;
        P = P->next;
    }
    return total;
}

int multiplyList(linkedList L) {
    if (L.first == Nil) return 0;
    int total = 1;
    address P = L.first;
    while (P != Nil) {
        total *= P->angka;
        P = P->next;
    }
    return total;
}
