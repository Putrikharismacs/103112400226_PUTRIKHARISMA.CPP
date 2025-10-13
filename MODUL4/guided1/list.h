// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

// Ini struct untuk linked list-nya
struct linkedList {
    address first;
};

// Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif