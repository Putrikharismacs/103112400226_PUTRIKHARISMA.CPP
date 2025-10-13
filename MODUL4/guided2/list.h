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

struct linkedList { // Ini linked list-nya
    address first;
};

// semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif