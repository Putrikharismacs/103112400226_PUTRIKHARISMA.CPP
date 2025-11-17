#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

const int MAX = 5;
const int BIAYA_PER_KG = 8250;

// =========================
// >>> BAGIAN A <<<
// ADT Queue menggunakan Array
// =========================
struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; // kg
    string Tujuan;
};

struct QueueEks {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

// Prototipe fungsi untuk Bagian A
bool isEmpty(const QueueEks &Q);
bool isFull(const QueueEks &Q);
void createQueue(QueueEks &Q);
void enQueue(QueueEks &Q, const Paket &P);
Paket deQueue(QueueEks &Q);
void viewQueue(const QueueEks &Q);

// >>> BAGIAN B <<<
// Tambahan fungsi total biaya pengiriman

long long TotalBiayaPengiriman(const QueueEks &Q);

#endif