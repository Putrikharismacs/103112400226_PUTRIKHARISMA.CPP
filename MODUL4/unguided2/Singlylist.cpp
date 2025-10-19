#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(int data) {
    address p = new Node;
    p->data = data;
    p->next = Nil;
    return p;
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

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

void printList(List L) {
    address p = L.first;
    while (p != Nil) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != Nil) {
        address p = L.first;
        L.first = L.first->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != Nil) {
        address p = L.first;
        if (p->next == Nil) {
            L.first = Nil;
            delete p;
        } else {
            address prev = Nil;
            while (p->next != Nil) {
                prev = p;
                p = p->next;
            }
            prev->next = Nil;
            delete p;
        }
    }
}

void deleteAfter(List &L, int data) {
    address p = L.first;
    while (p != Nil && p->next != Nil) {
        if (p->data == data) {
            address hapus = p->next;
            p->next = hapus->next;
            delete hapus;
            return;
        }
        p = p->next;
    }
}

int nbList(List L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    address p = L.first;
    while (p != Nil) {
        address hapus = p;
        p = p->next;
        delete hapus;
    }
    L.first = Nil;
    cout << "- List Berhasil Terhapus -" << endl;
}
