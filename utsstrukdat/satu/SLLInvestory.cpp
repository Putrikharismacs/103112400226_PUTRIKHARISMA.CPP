#include "SLLInvestory.h"

void createList(List &L){
    L.first = nullptr;
}

Node* createElement(infotype x){
    Node* P = new Node;
    x.HargaAkhir = hitungHargaAkhir(x.HargaSatuan, x.DiskonPersen);
    P->info = x;
    P->next = nullptr;
    return P;
}

bool isEmpty(List L){
    return L.first == nullptr;
}

void insertFirst(List &L, Node* P){
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, Node* P){
    if(isEmpty(L)){
        insertFirst(L, P);
    } else {
        Node* Q = L.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(List &L, Node* Prec, Node* P){
    if(Prec != nullptr){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, Node* &P){
    if(!isEmpty(L)){
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLast(List &L, Node* &P){
    if(!isEmpty(L)){
        Node* Q = L.first;

        if(Q->next == nullptr){
            deleteFirst(L, P);
        } else {
            while(Q->next->next != nullptr){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfter(List &L, Node* Prec, Node* &P){
    if(Prec != nullptr && Prec->next != nullptr){
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

float hitungHargaAkhir(float harga, float diskon){
    return harga * (1 - (diskon / 100));
}

void show(List L){
    Node* P = L.first;
    int i = 1;

    while(P != nullptr){
        cout << i << ". " << P->info.Nama
             << " | SKU: " << P->info.SKU
             << " | Jumlah: " << P->info.Jumlah
             << " | Harga Satuan: " << P->info.HargaSatuan
             << " | Diskon: " << P->info.DiskonPersen
             << " | Harga Akhir: " << P->info.HargaAkhir
             << endl;

        P = P->next;
        i++;
    }
}

void updateAtPosition(List &L, int pos, infotype dataBaru){
    Node* P = L.first;
    int idx = 1;

    while(P != nullptr && idx < pos){
        P = P->next;
        idx++;
    }

    if(P != nullptr){
        dataBaru.HargaAkhir = hitungHargaAkhir(dataBaru.HargaSatuan, dataBaru.DiskonPersen);
        P->info = dataBaru;
    }
}

void searchHargaAkhir(List L, float min, float max){
    Node* P = L.first;

    while(P != nullptr){
        if(P->info.HargaAkhir >= min && P->info.HargaAkhir <= max){
            cout << P->info.Nama
                 << " | Harga Setelah Diskon: "
                 << P->info.HargaAkhir << endl;
        }
        P = P->next;
    }
}
