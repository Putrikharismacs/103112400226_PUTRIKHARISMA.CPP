# <h1 align="center">Laporan Praktikum Modul 8 – Queue</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Queue adalah struktur data linear yang menerapkan prinsip **FIFO (First In First Out)**, yaitu elemen yang pertama kali masuk akan menjadi elemen pertama yang dikeluarkan. Konsep ini dapat dianalogikan seperti antrean di kehidupan nyata, misalnya antrean pembelian tiket atau antrean pelayanan bank, sehingga elemen diproses sesuai urutan kedatangan.

Secara umum, queue memiliki dua posisi utama:

* **Head** → menunjuk ke elemen pertama (tempat elemen dikeluarkan / dequeue)
* **Tail** → menunjuk ke elemen terakhir (tempat elemen ditambahkan / enqueue)

Queue dapat diimplementasikan menggunakan:

1. **Array (representasi tabel)**
2. **Linked List (pointer)**

Dalam implementasi array, queue dapat dibuat dalam tiga alternatif:

* **Alternatif 1:** Head diam (selalu index 0 atau 1), Tail bergerak
* **Alternatif 2:** Head dan Tail keduanya bergerak maju
* **Alternatif 3 / Circular Queue:** Head dan Tail bergerak melingkar (circular buffer), paling efisien karena tidak perlu shifting elemen

Queue digunakan pada berbagai bidang, seperti:

* penjadwalan CPU,
* buffer I/O,
* sistem antrian layanan,
* simulasi proses,
* komunikasi data.

### **A. Struktur dan Operasi Queue**

#### **1. Enqueue (Insert)**

Operasi untuk memasukkan elemen baru ke bagian **tail** queue.
Jika queue masih memiliki ruang, elemen ditempatkan di posisi tail dan pointer tail digeser ke indeks berikutnya.

#### **2. Dequeue (Delete)**

Operasi untuk menghapus elemen dari bagian **head**.
Elemen yang pertama masuk akan menjadi elemen yang dikeluarkan pertama.

#### **3. IsEmpty**

Digunakan untuk mengecek apakah queue kosong.
Biasanya queue kosong jika:

* `head = -1` dan `tail = -1` (representasi array), atau
* `head = NIL` (representasi pointer).

#### **4. IsFull**

Digunakan untuk mengecek apakah queue penuh pada queue berbasis array.
Pada circular queue, kondisi full terjadi ketika:

```
(Tail + 1) mod Max == Head
```

#### **5. CreateQueue**

Inisialisasi struktur queue menjadi kondisi kosong.

#### **6. ViewQueue**

Menampilkan seluruh isi queue mulai dari head hingga tail.

### **B. Representasi Queue**

#### **1. Queue dengan Array**

* Jumlah elemen terbatas.
* Tidak perlu manajemen memori dinamis.
* Lebih sederhana namun kurang fleksibel.

Terdapat tiga alternatif utama:

* **Alternatif 1:** head tetap (diam), tail bergerak
* **Alternatif 2:** head & tail bergerak
* **Alternatif 3:** circular queue (paling efisien, tidak perlu shifting)

#### **2. Queue dengan Linked List**

* Elemen bersifat dinamis (tidak dibatasi ukuran array).
* Tidak perlu memindahkan elemen ketika enqueue/dequeue.
* Memerlukan alokasi dan dealokasi memori.

Struktur node dalam linked list:

```
info → data elemen
next → pointer ke elemen berikutnya
```

## Guided 

### Guided 1

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```
Penjelasan: Pada file *queue.h*, didefinisikan struktur data queue berbasis *linked list* menggunakan pointer. Struktur `Node` berfungsi sebagai elemen tunggal yang menyimpan sebuah string `nama` dan pointer `next` untuk menghubungkan elemen berikutnya. Struktur `queue` memiliki dua pointer, yaitu `head` untuk menunjuk elemen pertama dan `tail` untuk menunjuk elemen terakhir, sesuai prinsip FIFO (First In First Out). File ini juga memuat deklarasi fungsi seperti `createQueue`, `enQueue`, `deQueue`, `viewQueue`, dan `clearQueue` sebagai operasi dasar queue, serta fungsi `isEmpty` dan `isFull` untuk memeriksa kondisi queue. Seluruh deklarasi ini memastikan queue dapat dibangun, diperiksa, ditambah, dihapus, ditampilkan, dan dibersihkan secara efisien.

### 2. queue.cpp

```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```
Penjelasan: File *queue.cpp* berisi implementasi dari seluruh fungsi yang dideklarasikan pada header. Fungsi `createQueue` menginisialisasi queue kosong dengan null pada head dan tail. Fungsi `enQueue` membuat node baru dan menambahkannya pada bagian belakang queue, sesuai sifat FIFO. Fungsi `deQueue` menghapus node pertama yang berada di head dan memastikan pointer diperbarui dengan benar. `viewQueue` digunakan untuk menampilkan seluruh elemen secara berurutan mulai dari head hingga tail. Fungsi `clearQueue` menghapus semua elemen queue dengan memanggil `deQueue` berulang–ulang sampai queue benar-benar kosong. Implementasi ini membentuk sistem antrian dinamis yang fleksibel karena ukuran tidak dibatasi oleh array statis.

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Penjelasan: Pada file *main.cpp*, queue dibuat dan diuji melalui serangkaian operasi. Program pertama-tama memanggil `createQueue` untuk menyiapkan queue kosong. Selanjutnya, beberapa nama dimasukkan ke dalam queue menggunakan `enQueue`, kemudian isi queue ditampilkan menggunakan `viewQueue`. Setelah itu, beberapa operasi `deQueue` dilakukan untuk menghapus elemen dari antrian sesuai urutan kedatangan. Program kemudian menampilkan isi queue setelah elemen dihapus, sehingga terlihat perubahan struktur queue. Terakhir, fungsi `clearQueue` membersihkan seluruh sisa elemen. File ini berfungsi sebagai pengujian langsung dari semua fungsi queue yang sudah dibuat.

### Guided 2

### 1. queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); // terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
Penjelasan: Pada file *queue.h* ini, queue diimplementasikan menggunakan array statis berukuran tetap `MAKSIMAL = 5`. Struktur queue menyimpan array `nama[]` untuk menampung elemen, serta dua variabel `head` dan `tail` sebagai penanda posisi awal dan akhir queue. Serangkaian fungsi juga dideklarasikan, seperti `isFull` dan `isEmpty` yang digunakan untuk mengecek kondisi queue, kemudian `createQueue` untuk inisialisasi, `enQueue` untuk menambah elemen, `deQueue` untuk menghapus elemen, dan `viewQueue` untuk menampilkan isi queue. Berbeda dari Guided 1 yang memakai linked list, Guided 2 berfokus pada implementasi queue statis berbasis array agar lebih mudah memahami pergerakan indeks head dan tail.

### 2. queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```
Penjelasan: File *queue.cpp* memuat implementasi lengkap dari queue berbasis array. Fungsi `createQueue` mengatur head dan tail bernilai -1 sebagai tanda queue kosong. Fungsi `enQueue` menambahkan elemen ke posisi `tail`, dengan memperbarui head jika queue sebelumnya kosong; implementasi ini sesuai dengan mekanisme queue linear Alternatif 1 maupun 2 (head diam atau head bergerak). Fungsi `deQueue` menghapus elemen pada posisi `head`; pada implementasi Alternatif 1, seluruh elemen digeser ke kiri untuk mempertahankan head tetap pada indeks awal. Terdapat pula komentar tambahan untuk Alternatif 2 dan 3 yang menggerakkan head atau menerapkan sistem melingkar (circular). Implementasi `viewQueue` mencetak isi antrian dari head ke tail. File ini menampilkan bagaimana queue statis bekerja pada berbagai mekanisme head–tail.

### 3. main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Penjelasan: Pada *main.cpp* Guided 2, queue diuji menggunakan operasi statis berbasis array. Program dimulai dengan memanggil `createQueue` untuk inisialisasi, diikuti serangkaian operasi `enQueue` untuk memasukkan beberapa nama hingga queue penuh. Setelah itu, isi queue ditampilkan melalui `viewQueue` untuk menunjukkan urutan elemen. Program kemudian menjalankan beberapa operasi `deQueue` untuk menghapus elemen dari depan queue sesuai aturan FIFO. Akhirnya, isi queue kembali ditampilkan untuk memperlihatkan kondisi antrian setelah penghapusan elemen. File ini menunjukkan bagaimana queue statis berperilaku dengan pergerakan head dan tail, serta bagaimana kapasitas array memengaruhi operasi.

## Unguided 

### 1. Soal Unguided 

### **1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:**

```
Type infotype : integer
Type Queue :
    info : array [5] of infotype {index array dalam C++ dimulai dari 0}
    head, tail : integer

procedure CreateQueue (input/output Q : Queue)
function isEmptyQueue (Q : Queue) → boolean
function isFullQueue (Q : Queue) → boolean
procedure enqueue (input/output Q : Queue, input x : infotype)
function dequeue (input/output Q : Queue) → infotype
procedure printInfo (input Q : Queue)
```

---

### **Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).**

---

### **Program main (sesuai gambar):**

```
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T \t | Queue info" << endl;
    cout << "------------------------" << endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    enqueue(Q,9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### **2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).**


### **3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).**

# **Output Program (SALINAN DARI GAMBAR)**

```
Hello world!
------------------------
H - T    | Queue Info
------------------------
-1  -1   | empty queue
0   0    | 5
0   1    | 5 2
0   2    | 5 2 7
0   3    | 5 2 7 9
0   2    | 2 7 9
0   3    | 2 7 9 4
0   2    | 7 9 4
0   1    | 9 4
```


### 📄 File: `queue.h`

```C++
#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T \t| Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### 📄 File: `queue.cpp`

```C++
#include <iostream>
using namespace std;
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        createQueue(Q);
    } else {
        // SHIFT semua elemen ke kiri (karena head diam)
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
    }

    return x;
}

// Output harus mirip modul
void printInfo(Queue Q) {
    cout << Q.head << "  " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
```

### 📄 File: `main.cpp`

```C++
#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T \t| Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### Output Unguided  :

##### Output
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL8/imagesmodul8/output1_unguided_modul8.png)


Penjelasan : Pada bagian unguided ini, ADT Queue diimplementasikan menggunakan array statis dengan kapasitas lima elemen sesuai ketentuan modul, menggunakan mekanisme *Alternatif 1* yaitu head tetap pada posisi awal dan tail bergerak mengikuti penambahan elemen. Pada file `queue.h`, didefinisikan struktur queue yang terdiri dari array `info[]` untuk menyimpan elemen bertipe integer serta indeks `head` dan `tail` sebagai penanda awal dan akhir antrian, disertai deklarasi fungsi-fungsi dasar seperti `createQueue`, `isEmptyQueue`, `isFullQueue`, `enqueue`, `dequeue`, dan `printInfo` yang akan digunakan untuk mengelola proses antrian. Selanjutnya, pada file `queue.cpp` seluruh fungsi tersebut diimplementasikan, di mana `createQueue` menginisialisasi queue dalam keadaan kosong, `isEmptyQueue` dan `isFullQueue` memeriksa kondisi antrian, `enqueue` menempatkan elemen baru pada posisi tail dengan memperbarui indeks sesuai kebutuhan, dan `dequeue` menghapus elemen dari head dengan melakukan shifting seluruh elemen ke kiri agar head tetap berada pada indeks yang sama. Fungsi `printInfo` digunakan untuk menampilkan posisi head, tail, serta seluruh elemen queue dalam format yang identik dengan contoh output pada modul, sehingga hasil pengujian dapat diverifikasi dengan mudah. File `main.cpp` berperan sebagai program utama yang menguji seluruh fungsi queue melalui serangkaian operasi, dimulai dari inisialisasi queue, memasukkan beberapa nilai melalui `enqueue`, melakukan beberapa penghapusan menggunakan `dequeue`, dan menampilkan kondisi queue setelah setiap perubahan sehingga alur keluar-masuk elemen terlihat secara jelas. Keseluruhan implementasi ini memperlihatkan bagaimana queue berbasis array bekerja mengikuti prinsip FIFO dan menunjukkan dampak mekanisme shifting ketika elemen dihapus, sekaligus memastikan bahwa perilaku program sudah sesuai dengan ilustrasi output yang diberikan dalam modul.

## Kesimpulan
Queue merupakan salah satu struktur data linear yang bekerja dengan prinsip First In First Out (FIFO), yaitu setiap elemen diproses berdasarkan urutan kedatangannya. Struktur ini memiliki dua titik utama, yaitu head sebagai posisi penghapusan elemen dan tail sebagai posisi penambahan elemen. Queue dapat diimplementasikan menggunakan array maupun linked list, masing-masing dengan karakteristik dan keunggulannya.

Pada representasi array, queue dapat dibangun melalui beberapa pendekatan seperti alternatif head tetap, head–tail bergerak, maupun circular queue yang lebih efisien karena tidak memerlukan pergeseran elemen. Sementara itu, implementasi menggunakan linked list memberikan fleksibilitas lebih besar karena jumlah elemen tidak dibatasi ukuran statis.

Secara keseluruhan, queue berperan penting dalam berbagai aplikasi pemrograman dan sistem komputer, seperti pengelolaan buffer, penjadwalan proses, serta simulasi antrean. Pemahaman terhadap operasi-operasi dasar seperti enqueue, dequeue, isEmpty, dan isFull menjadi kunci dalam merancang struktur data yang efektif dan sesuai kebutuhan.

## Referensi
[1] Putra, R. R., & Wirawan, S. S. (2021). *Analisis Implementasi Struktur Data Queue untuk Sistem Antrian Pelayanan Publik*. **Jurnal Teknologi dan Sistem Informasi Universitas Brawijaya**.

[2] Lestari, D., & Kurniawan, A. (2020). *Penerapan Circular Queue pada Sistem Antrian Poliklinik Menggunakan C++*. **Jurnal Informatika Universitas Dian Nuswantoro (UDINUS)**.

[3] Sari, M., & Widodo, T. (2019). *Optimasi Struktur Data Antrian Menggunakan Representasi Linked List*. **Jurnal Ilmu Komputer Universitas Gadjah Mada (UGM)**.

[4] Firmansyah, A., & Prasetyo, H. (2018). *Implementasi Queue dengan Alternatif Head-Tail Bergerak pada Sistem Buffer*. **Jurnal Teknik Informatika Universitas Telkom**.

[5] Nugroho, A. S. (2020). *Struktur Data dan Algoritma dalam Pengembangan Sistem*. **Universitas Negeri Yogyakarta Press**
<br>...
