#include "Singlylist.h"

// Membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(int data) {
    address p = new Node;
    p->data = data;
    p->next = Nil;
    return p;
}

// Menambah node di depan
void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

// Menambah node di akhir
void insertLast(List &L, address p) {
    if (L.first == Nil) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != Nil) {
            q = q->next;
        }
        q->next = p;
    }
}

// Menambah node setelah node tertentu
void insertAfter(List &L, address prec, address p) {
    if (prec != Nil) {
        p->next = prec->next;
        prec->next = p;
    }
}

// Menampilkan isi list
void printList(List L) {
    address p = L.first;
    while (p != Nil) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
