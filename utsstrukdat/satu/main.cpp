#include "SLLInvestory.h"

int main(){
    List L;
    createList(L);

    // 1. Menambahkan 3 produk awal
    infotype A = {"Pulpen", "A001", 20, 2500, 0};
    infotype B = {"Buku Tulis", "A002", 15, 5000, 10};
    infotype C = {"Penghapus", "A003", 30, 1500, 0};

    insertLast(L, createElement(A));
    insertLast(L, createElement(B));
    insertLast(L, createElement(C));

    // 2. Menampilkan data awal
    cout << "\nDaftar Produk Awal:\n";
    show(L);

    // 3. Menghapus elemen pertama
    Node* X;
    deleteFirst(L, X);

    cout << "\nSetelah Menghapus Elemen Pertama:\n";
    show(L);

    // 4. Memperbarui item pada posisi kedua
    infotype baru = {"Stabilo", "A010", 40, 8000, 5};
    updateAtPosition(L, 2, baru);

    cout << "\nSetelah Update Posisi ke-2:\n";
    show(L);

    // 5. Menampilkan produk dengan harga akhir di rentang tertentu
    cout << "\nProduk dengan Harga Akhir antara 2000–7000:\n";
    searchHargaAkhir(L, 2000, 7000);

    return 0;
}
