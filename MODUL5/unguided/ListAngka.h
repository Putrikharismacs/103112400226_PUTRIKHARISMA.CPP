#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

// ==== PROTOTYPE DASAR ====
void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &P);
void printList(linkedList L);

void insertFirst(linkedList &L, address P);
void insertLast(linkedList &L, address P);
void insertAfter(linkedList &L, address P, address Prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &P, address Prec);

// ==== PROSEDUR UPDATE ====
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address Prec);

// ==== PROSEDUR SEARCH ====
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address P);
void SearchByRange(linkedList L, int nilaiMin);

// ==== OPERASI ARITMETIKA ====
int sumList(linkedList L);
int subtractList(linkedList L);
int multiplyList(linkedList L);

#endif
