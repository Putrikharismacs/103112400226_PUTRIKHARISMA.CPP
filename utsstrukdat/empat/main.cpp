#include <iostream>
#include <limits>
#include "QueuePengiriman.h"
using namespace std;

void clearStdin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Paket makePaket(string kode, string nama, int berat, string tujuan) {
    Paket p;
    p.KodeResi = kode;
    p.NamaPengirim = nama;
    p.BeratBarang = berat;
    p.Tujuan = tujuan;
    return p;
}

void tampilMenu() {
    cout << "\n--- Menu Komaniya Ekspress ---\n";
    cout << "1. Input Data Paket (enQueue)\n";
    cout << "2. Hapus Data Paket (deQueue)\n";
    cout << "3. Tampilkan queue paket\n";
    cout << "4. Hitung Total Biaya Pengiriman\n"; // Bagian B
    cout << "5. Isi contoh data otomatis (5 paket)\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    QueueEks Q;
    createQueue(Q);

    cout << "Program Queue Pengiriman (Head diam, Tail bergerak)\n";

    bool running = true;
    while (running) {
        tampilMenu();
        int pilihan;
        cin >> pilihan;
        clearStdin();

        switch (pilihan) {

        
            // >>> BAGIAN A <<<
           
            case 1: {
                if (isFull(Q)) {
                    cout << "Queue sudah penuh.\n";
                    break;
                }
                Paket p;
                cout << "Masukkan KodeResi: ";
                getline(cin, p.KodeResi);

                cout << "Masukkan Nama Pengirim: ";
                getline(cin, p.NamaPengirim);

                cout << "Masukkan Berat (kg): ";
                cin >> p.BeratBarang;
                clearStdin();

                cout << "Masukkan Tujuan: ";
                getline(cin, p.Tujuan);

                enQueue(Q, p);
                break;
            }

            case 2:
                deQueue(Q);
                break;

            case 3:
                viewQueue(Q);
                break;

           
            // >>> BAGIAN B <<<
            // Hitung total biaya semua paket
           
            case 4: {
                long long total = TotalBiayaPengiriman(Q);
                cout << "Total Biaya Pengiriman = Rp " << total << "\n";
                break;
            }

            case 5: {
                // contoh data sesuai soal
                enQueue(Q, makePaket("123456", "Hutao", 14, "Sumeru"));
                enQueue(Q, makePaket("234567", "Ayaka", 10, "Fontaine"));
                enQueue(Q, makePaket("345678", "Bennet", 7, "Natlan"));
                enQueue(Q, makePaket("456789", "Furina", 16, "Liyue"));
                enQueue(Q, makePaket("567890", "Nefer", 6, "Inazuma"));
                break;
            }

            case 6:
                running = false;
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak ada.\n";
        }
    }

    return 0;
}