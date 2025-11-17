#include <iostream>
#include "QueuePengiriman.h"
using namespace std;


// >>> BAGIAN A <<<
// Implementasi Queue ARRAY (Head diam, Tail bergerak)


bool isEmpty(const QueueEks &Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(const QueueEks &Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEks &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEks &Q, const Paket &P) {
    if (isFull(Q)) {
        cout << "Queue penuh. Tidak bisa menambah paket.\n";
        return;
    }
    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
        Q.dataPaket[Q.Tail] = P;
    } else {
        Q.Tail++;
        Q.dataPaket[Q.Tail] = P;
    }
    cout << "Paket dengan resi " << P.KodeResi << " berhasil ditambahkan.\n";
}

Paket deQueue(QueueEks &Q) {
    Paket dummy;
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return dummy;
    }

    Paket removed = Q.dataPaket[Q.Head];

    if (Q.Head == Q.Tail) {
        Q.Head = -1;
        Q.Tail = -1;
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
    }

    cout << "Paket dengan resi " << removed.KodeResi << " berhasil dihapus.\n";
    return removed;
}

void viewQueue(const QueueEks &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "Isi Queue:\n";
    cout << "-------------------------------------------------------------\n";
    cout << "| No | KodeResi | NamaPengirim | Berat(kg) | Tujuan |\n";
    cout << "-------------------------------------------------------------\n";

    int idx = 1;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "| " << idx << " | "
             << Q.dataPaket[i].KodeResi << " | "
             << Q.dataPaket[i].NamaPengirim << " | "
             << Q.dataPaket[i].BeratBarang << " | "
             << Q.dataPaket[i].Tujuan << " |\n";
        idx++;
    }

    cout << "-------------------------------------------------------------\n";
}


// >>> BAGIAN B <<<
// Hitung total biaya = berat * 8250 per paket


long long TotalBiayaPengiriman(const QueueEks &Q) {
    if (isEmpty(Q)) return 0;

    long long total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += (long long)Q.dataPaket[i].BeratBarang * BIAYA_PER_KG;
    }
    return total;
}