#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;

struct List {
    address first;
};

// Fungsi dasar
void createList(List &L);
address alokasi(int data);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void printList(List L);

// Fungsi penghapusan & utility
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, int data);
int nbList(List L);
void deleteList(List &L);

#endif
