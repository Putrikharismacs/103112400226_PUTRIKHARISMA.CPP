#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

typedef Node* address;

// Struktur list
struct List {
    address first;
};

// Deklarasi fungsi dasar
void createList(List &L);
address alokasi(int data);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void insertAfter(List &L, address prec, address p);
void printList(List L);

#endif
