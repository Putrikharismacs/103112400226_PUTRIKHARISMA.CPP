#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat node
    address A = alokasi(9);
    address B = alokasi(12);
    address C = alokasi(8);
    address D = alokasi(0);
    address E = alokasi(2);

    // Menyusun urutan sesuai soal
    insertFirst(L, A);        // 9
    insertLast(L, B);         // 9 -> 12
    insertLast(L, C);         // 9 -> 12 -> 8
    insertLast(L, D);         // 9 -> 12 -> 8 -> 0
    insertLast(L, E);         // 9 -> 12 -> 8 -> 0 -> 2

    // Cetak hasil akhir
    printList(L);

    return 0;
}
