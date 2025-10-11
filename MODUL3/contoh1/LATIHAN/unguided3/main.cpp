#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa data[10];
    int jumlah = 0;
    int pilihan;
    string cari;

    do {
        cout << "\n=== MENU DATA MAHASISWA ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Semua Data" << endl;
        cout << "3. Cari Mahasiswa Berdasarkan NIM" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlah < 10)
                    tambahMahasiswa(data, jumlah);
                else
                    cout << "Data sudah penuh!" << endl;
                break;
            case 2:
                tampilMahasiswa(data, jumlah);
                break;
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> ws;
                getline(cin, cari);
                cariMahasiswa(data, jumlah, cari);
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
