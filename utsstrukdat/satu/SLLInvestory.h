#ifndef SLLINVESTORY_H
#define SLLINVESTORY_H

#include <iostream>
using namespace std;

struct Product {
    string Nama;          // Nama barang
    string SKU;           // Kode barang
    int Jumlah;           // Jumlah stok
    float HargaSatuan;    // Harga sebelum diskon
    float DiskonPersen;   // Besar diskon (%)
    float HargaAkhir;     // Harga setelah diskon dihitung
};

typedef Product infotype;

struct Node {
    infotype info;
    Node* next;
};

struct List {
    Node* first;
};

// Prototipe fungsi
void createList(List &L);
Node* createElement(infotype x);
bool isEmpty(List L);

void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void insertAfter(List &L, Node* Prec, Node* P);

void deleteFirst(List &L, Node* &P);
void deleteLast(List &L, Node* &P);
void deleteAfter(List &L, Node* Prec, Node* &P);

void show(List L);

float hitungHargaAkhir(float harga, float diskon);
void updateAtPosition(List &L, int pos, infotype dataBaru);
void searchHargaAkhir(List L, float min, float max);

#endif
