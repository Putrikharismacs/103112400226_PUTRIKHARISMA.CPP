#include "mahasiswa.h"

// Fungsi untuk menambah data mahasiswa
void tambahMahasiswa(Mahasiswa data[], int &n) {
    cout << "\nMasukkan data mahasiswa ke-" << n + 1 << endl;
    cout << "Nama     : ";
    cin >> ws;
    getline(cin, data[n].nama);
    cout << "NIM      : ";
    getline(cin, data[n].nim);
    cout << "Jurusan  : ";
    getline(cin, data[n].jurusan);
    cout << "IPK      : ";
    cin >> data[n].ipk;
    n++;
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilMahasiswa(Mahasiswa data[], int n) {
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << data[i].nama 
             << " | " << data[i].nim 
             << " | " << data[i].jurusan 
             << " | IPK: " << data[i].ipk << endl;
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(Mahasiswa data[], int n, string cariNIM) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (data[i].nim == cariNIM) {
            cout << "\nData ditemukan!" << endl;
            cout << "Nama    : " << data[i].nama << endl;
            cout << "NIM     : " << data[i].nim << endl;
            cout << "Jurusan : " << data[i].jurusan << endl;
            cout << "IPK     : " << data[i].ipk << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan.\n";
}
