#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat node (sama seperti latihan 1)
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));
    insertLast(L, alokasi(2));

    // Penghapusan sesuai soal
    deleteFirst(L);    // hapus node 9
    deleteLast(L);     // hapus node 2
    deleteAfter(L, 12); // hapus node setelah 12 (node 8)

    // Tampilkan hasil & jumlah node
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // Hapus seluruh list
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
