#include "Doublylist.h"
#include <iomanip>  // untuk setw()
using namespace std;

// Mengecek apakah nomor polisi sudah ada
bool isExist(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    createList(L);
    infotype x;
    address P;
    int n = 4;

    // NOMOR 1: Input data kendaraan
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (!isExist(L, x.nopol)) {
            P = alokasi(x);
            insertLast(L, P);
        } else {
            cout << "Nomor polisi sudah terdaftar." << endl;
        }
        cout << endl;
    }

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    // NOMOR 2: Mencari elemen berdasarkan nomor polisi
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    string cari;
    cin >> cari;

    address hasil = findElm(L, cari);
    cout << endl;

    if (hasil != Nil) {
        cout << left << setw(15) << "Nomor Polisi" << ": " << hasil->info.nopol << endl;
        cout << left << setw(15) << "Warna"        << ": " << hasil->info.warna << endl;
        cout << left << setw(15) << "Tahun"        << ": " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    // NOMOR 3: Menghapus elemen berdasarkan nomor polisi
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    string hapus;
    cin >> hapus;
    address target = findElm(L, hapus);
    address Pdel;

    if (target != Nil) {
        if (target == L.first) {
            deleteFirst(L, Pdel);
        } else if (target == L.last) {
            deleteLast(L, Pdel);
        } else {
            deleteAfter(L, target->prev, Pdel);
        }
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus." << endl;
        dealokasi(Pdel);
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl << "DATA LIST 1 (SETELAH DIHAPUS)" << endl;
    printInfo(L);

    return 0;
}
