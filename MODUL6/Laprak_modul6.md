# <h1 align="center">Laporan Praktikum Modul 6 – Doubly Linked List (Bagian Pertama)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
### A. Konsep dan Karakteristik Doubly Linked List<br/>
#### 1. Pengertian Doubly Linked List
Doubly Linked List (DLL) adalah salah satu struktur data berantai yang setiap elemennya (disebut *node*) memiliki dua penunjuk atau pointer, yaitu `next` yang menunjuk ke elemen berikutnya dan `prev` yang menunjuk ke elemen sebelumnya. Dengan dua arah hubungan ini, Doubly Linked List memungkinkan proses traversal dilakukan baik dari depan ke belakang maupun sebaliknya [1].
Berbeda dengan *Singly Linked List* yang hanya memiliki satu pointer menuju elemen berikutnya, Doubly Linked List memberikan fleksibilitas lebih besar dalam pengelolaan data, terutama pada proses penambahan dan penghapusan elemen di tengah list.

#### 2. Struktur Node pada Doubly Linked List
Setiap node pada Doubly Linked List umumnya terdiri dari tiga bagian utama, yaitu:

   * **Info/Data Field**: Menyimpan informasi yang dibutuhkan (misalnya angka, string, atau data kompleks seperti objek kendaraan).
   * **Pointer Next**: Menunjuk ke node berikutnya dalam urutan list.
   * **Pointer Prev**: Menunjuk ke node sebelumnya dalam urutan list.
     Selain itu, struktur list memiliki dua pointer penting yaitu `first` (menunjuk node pertama) dan `last` (menunjuk node terakhir). Hubungan dua arah antar-node membuat Doubly Linked List lebih efisien dalam proses navigasi data [2].

#### 3. Ciri-ciri Doubly Linked List
Beberapa karakteristik yang membedakan Doubly Linked List dengan struktur data lainnya adalah:

   * Mempunyai dua pointer di setiap node (`next` dan `prev`).
   * Dapat ditelusuri ke dua arah (maju dan mundur).
   * Tidak memiliki batasan ukuran karena menggunakan memori dinamis.
   * Akses data membutuhkan traversal dari salah satu ujung list (karena tidak bersifat *random access* seperti array).
     Dengan sifat ini, Doubly Linked List cocok untuk situasi di mana data sering diubah, ditambah, atau dihapus tanpa perlu menggeser elemen-elemen lain di memori [3].

#### 4. Perbandingan dengan Singly Linked List
Dalam Singly Linked List, untuk menghapus atau menambah data di tengah, program harus mengetahui node sebelumnya, sehingga traversal dari awal list menjadi wajib. Sebaliknya, Doubly Linked List sudah memiliki pointer `prev`, sehingga operasi tersebut dapat dilakukan lebih cepat tanpa traversal penuh.
Namun, kekurangannya adalah kebutuhan memori yang lebih besar karena adanya dua pointer per node, serta potensi kesalahan manajemen pointer yang dapat menyebabkan *dangling pointer* atau *memory leak* jika tidak dihapus dengan benar [4].


### B. Operasi Dasar pada Doubly Linked List<br/>
#### 1. Create List dan Inisialisasi
Operasi *CreateList()* digunakan untuk membuat list kosong. Dalam proses ini, pointer `first` dan `last` diatur bernilai `NULL` sebagai penanda bahwa belum ada node di dalam list. Tahapan ini menjadi dasar sebelum dilakukan operasi lainnya seperti penambahan, penghapusan, atau pencarian data.

#### 2. Alokasi dan Dealokasi Node
* **Alokasi**: Operasi ini membuat node baru di memori secara dinamis menggunakan operator `new` (dalam C++). Node tersebut diisi dengan data yang dimasukkan pengguna, dan pointer `next` serta `prev` diinisialisasi dengan `NULL`.
   * **Dealokasi**: Operasi ini dilakukan untuk menghapus node dari memori setelah tidak lagi digunakan. Tujuannya adalah untuk menghindari kebocoran memori (*memory leak*). Dalam praktiknya, pointer ke node dihapus menggunakan operator `delete`, dan nilai `next` serta `prev` diatur kembali menjadi `NULL`.

#### 3. Operasi Penyisipan (Insert)
Doubly Linked List memiliki tiga jenis operasi penyisipan utama, yaitu:

   * **Insert First**: Menambahkan node baru di awal list. Jika list kosong, node baru menjadi elemen pertama dan terakhir sekaligus. Jika tidak kosong, pointer `next` node baru menunjuk ke `first`, dan `first.prev` menunjuk ke node baru.
   * **Insert Last**: Menambahkan node di akhir list. Pointer `prev` node baru menunjuk ke `last`, dan `last.next` menunjuk ke node baru. Setelah itu, pointer `last` diperbarui agar menunjuk ke node baru.
   * **Insert After**: Menambahkan node di tengah list setelah node tertentu. Pointer `next` dan `prev` diatur agar node baru terhubung dengan node sebelum dan sesudahnya secara konsisten.
     Semua operasi insert memiliki kompleksitas waktu O(1) jika posisi penyisipan sudah diketahui [5].

#### 4. Operasi Penghapusan (Delete)
 Operasi penghapusan juga memiliki tiga variasi utama:

   * **Delete First**: Menghapus node pertama dengan menggeser pointer `first` ke node berikutnya dan mengatur `prev` node baru pertama menjadi `NULL`.
   * **Delete Last**: Menghapus node terakhir dengan memindahkan pointer `last` ke node sebelumnya, lalu mengatur `next` node baru terakhir menjadi `NULL`.
   * **Delete After**: Menghapus node tertentu di tengah list dengan menyesuaikan pointer `next` dan `prev` dari node sebelum dan sesudah node yang dihapus.
     Semua operasi delete ini perlu hati-hati agar tidak meninggalkan pointer menggantung (*dangling pointer*).

#### 5. Operasi Pencarian (Searching)
Operasi pencarian dilakukan dengan menelusuri list mulai dari `first` hingga `last` untuk mencari node dengan data tertentu. Karena Doubly Linked List bersifat dua arah, pencarian juga bisa dilakukan dari arah `last` jika lebih efisien.
Contohnya, fungsi `findElm(L, x)` mencari node dengan nilai tertentu (misalnya `nopol` kendaraan) dan mengembalikan alamat node jika ditemukan.

#### 6. Traversal atau Penelusuran
Traversal merupakan proses menampilkan atau membaca seluruh isi list secara berurutan. Dalam Doubly Linked List, traversal dapat dilakukan dengan dua cara:

   * **Forward Traversal**: Menelusuri node dari `first` hingga `last`.
   * **Backward Traversal**: Menelusuri node dari `last` ke `first`.
     Kemampuan dua arah ini menjadi keunggulan utama Doubly Linked List dibanding Singly Linked List.

## Guided 

### Guided 1

### 1. listMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
Penjelasan: File **`listMakanan.h`** merupakan file header yang berisi deklarasi struktur dan fungsi yang digunakan untuk mengelola data pada Doubly Linked List. Di dalamnya terdapat definisi struktur `makanan` yang memiliki beberapa atribut, yaitu `nama`, `jenis`, `harga`, dan `rating`. Struktur `node` digunakan untuk membentuk setiap simpul (node) pada list, yang berisi data makanan dan dua pointer (`next` dan `prev`) agar setiap node bisa saling terhubung dua arah. Kemudian terdapat struktur `linkedlist` yang menyimpan pointer `first` dan `last` sebagai penanda elemen pertama dan terakhir dari list. Selain struktur, file ini juga berisi deklarasi fungsi-fungsi dasar seperti `createList`, `alokasi`, `dealokasi`, serta beberapa prosedur untuk menambahkan data (`insertFirst`, `insertLast`, `insertAfter`, `insertBefore`), menampilkan data (`printList`), dan memperbarui data (`updateFirst`, `updateLast`, `updateAfter`, `updateBefore`). Secara keseluruhan, file ini berfungsi sebagai rancangan awal atau *blueprint* yang mengatur hubungan antarbagian program agar dapat berjalan secara modular dan terstruktur.

### 2. listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
Penjelasan: File **`listMakanan.cpp`** berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan pada file header. Di dalamnya dijelaskan secara detail bagaimana setiap fungsi bekerja untuk mengelola data dalam Doubly Linked List. Fungsi `isEmpty` digunakan untuk memeriksa apakah list kosong, sedangkan `createList` bertugas menginisialisasi list baru. Prosedur `alokasi` berfungsi membuat node baru di memori dengan mengisi data yang diberikan, sementara `dealokasi` menghapus node agar memori dapat digunakan kembali. Proses penambahan data dilakukan melalui `insertFirst`, `insertLast`, `insertAfter`, dan `insertBefore`, yang mengatur posisi node baru sesuai kebutuhan. Selain itu, `printList` digunakan untuk menampilkan isi list dengan menelusuri setiap node secara berurutan. Program ini juga menyediakan fitur pembaruan data melalui `updateFirst`, `updateLast`, `updateAfter`, dan `updateBefore`, di mana pengguna dapat mengganti data makanan tertentu. File ini memperlihatkan penerapan konsep *dynamic memory management* dan keterkaitan dua arah antar-node yang menjadi ciri utama Doubly Linked List.


### 3. main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Penjelasan: File **`main.cpp`** berfungsi sebagai program utama yang digunakan untuk menjalankan dan menguji seluruh fungsi yang telah dibuat dalam file header dan implementasinya. Pada awal program, list diinisialisasi dengan `createList`, kemudian dibuat beberapa node makanan menggunakan fungsi `alokasi`. Setelah itu, beberapa fungsi penyisipan digunakan untuk menempatkan node pada posisi yang diinginkan, seperti `insertFirst`, `insertLast`, `insertAfter`, dan `insertBefore`, hingga terbentuk urutan data sesuai contoh pada modul. Setelah penyisipan, program menampilkan isi list menggunakan `printList`, lalu dilakukan pembaruan data pada beberapa node menggunakan fungsi `updateFirst`, `updateLast`, `updateBefore`, dan `updateAfter`. Hasil dari setiap proses pembaruan kembali ditampilkan agar pengguna dapat melihat perubahan yang terjadi. File ini secara keseluruhan menjadi tempat pengujian seluruh proses dasar Doubly Linked List mulai dari pembuatan, penambahan, pembaruan, hingga penampilan data.

### Guided 2

### 1. listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
Penjelasan: File **`listMakanan.h`** pada Guided 2 memiliki struktur dasar yang sama dengan versi sebelumnya, namun telah ditambahkan beberapa deklarasi fungsi baru yang digunakan untuk melakukan pencarian dan penghapusan data. Struktur `makanan`, `node`, dan `linkedlist` tetap digunakan sebagai dasar penyimpanan data dan hubungan antar-node. Tambahan fungsi seperti `findByName`, `findByJenis`, dan `findByMinRating` digunakan untuk mencari data berdasarkan nama, jenis, atau nilai minimum rating makanan. Selain itu, terdapat pula deklarasi fungsi untuk proses penghapusan data, seperti `deleteFirst`, `deleteLast`, `deleteAfter`, `deleteBefore`, `deleteNode`, dan `deleteByName`. Dengan adanya fungsi-fungsi ini, pengelolaan data pada list menjadi lebih lengkap karena pengguna tidak hanya dapat menambah dan memperbarui data, tetapi juga bisa mencari dan menghapus data dengan mudah. File header ini berfungsi sebagai panduan agar seluruh operasi Doubly Linked List tetap terstruktur dan mudah dipelihara.

### 2. listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```
Penjelasan: File **`listMakanan.cpp`** pada Guided 2 merupakan kelanjutan dari versi sebelumnya dengan penambahan fitur pencarian (*searching*) dan penghapusan (*deletion*). Semua fungsi dasar seperti pembuatan, penambahan, serta pembaruan data tetap ada, namun kini dilengkapi dengan logika tambahan untuk memudahkan pengguna dalam mengelola data. Fungsi pencarian seperti `findByName`, `findByJenis`, dan `findByMinRating` menggunakan metode penelusuran dari awal hingga akhir list untuk menemukan node yang sesuai dengan kriteria tertentu. Jika ditemukan, data akan ditampilkan; jika tidak, program akan memberikan pesan bahwa data tidak tersedia. Sementara itu, bagian penghapusan mencakup berbagai kondisi seperti menghapus node pertama, terakhir, atau node di tengah menggunakan fungsi `deleteFirst`, `deleteLast`, `deleteAfter`, `deleteBefore`, `deleteNode`, dan `deleteByName`. Setiap proses penghapusan dilakukan dengan memperhatikan keterhubungan antar-node agar tidak terjadi kesalahan pada struktur list. File ini menunjukkan penerapan konsep Doubly Linked List secara menyeluruh, mulai dari penyimpanan hingga penghapusan data, dengan pengelolaan memori yang aman dan efisien.

### 3. main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Penjelasan: File **`main.cpp`** pada Guided 2 berfungsi sebagai pengujian terhadap seluruh fungsi yang telah ditambahkan, khususnya untuk operasi pencarian dan penghapusan data. Pada awal program, list diinisialisasi dan diisi dengan beberapa node berisi data makanan yang berbeda menggunakan fungsi `alokasi` dan `insert`. Setelah itu, dilakukan beberapa operasi pembaruan data untuk memastikan fungsi update berjalan dengan benar. Selanjutnya, program menguji fungsi pencarian seperti `findByName` untuk mencari data berdasarkan nama makanan. Bagian akhir dari program menguji proses penghapusan data dengan menjalankan `deleteByName`, `deleteFirst`, dan `deleteBefore`, yang secara bertahap menghapus beberapa node dari list. Setelah semua operasi dilakukan, isi list kembali ditampilkan menggunakan `printList` untuk memperlihatkan hasil akhirnya. File ini menjadi bukti bahwa seluruh fungsi yang ada pada Doubly Linked List bekerja dengan baik, mulai dari pembuatan list, penambahan, pencarian, hingga penghapusan data secara dinamis dan teratur.

## Unguided 

### 1. Soal Unguided 

1. Buatlah ADT Doubly Linkedlist sebagai berikut didalam file “Doublylist.h” :
```C++
 Typeinfotype: kendaraan <
    nopol :string
    warna :string
    thnBuat:integer
 >
 Typeaddress :pointer to ElmList
 TypeElmList <
    info:infotype
    next:address
    prev:address
 >
 TypeList <
    First :address
    Last:address
 >
 procedure CreateList(input/outputL: List)
 function alokasi( x :infotype)→address
 procedure dealokasi(input/output P:address )
 procedure printInfo(inputL :List )
 procedure insertLast(input/outputL :List,
    inputP: address)
```
Buatlah implementasi ADTDoubly Linked list pada file “Doublylist.cpp” dan coba hasil
implementasi ADT pada file “main.cpp”

CONTOH OUTPUT :
```bash
Masukkan nomor polisi: D001
Masukkan warna kendaraan: hitam
Masukkan tahun kendaraan: 90

Masukkan nomor polisi: D003
Masukkan warna kendaraan: putih
Masukkan tahun kendaraan: 70

Masukkan nomor polisi: D001
Masukkan warna kendaraan: merah
Masukkan tahun kendaraan: 80
Nomor polisi sudah terdaftar.

Masukkan nomor polisi: D004
Masukkan warna kendaraan: kuning
Masukkan tahun kendaraan: 90

DATA LIST 1
no polisi : D004
warna     : kuning
tahun     : 90
no polisi : D003
warna     : putih
tahun     : 70
no polisi : D001
warna     : hitam
tahun     : 90
```
2.  Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
fungsi findElm( L : List, x : infotype ) : address

CONTOH OUTPUT: 
```bash
Masukkan Nomor Polisi yang dicari : D001

Nomor Polisi   : D001
Warna          : hitam
Tahun          : 90
```
3.  Hapus elemen dengan nomor polisi D003 dengan procedure delete.
- procedure deleteFirst( input/output L : List,
    P : address )--
- procedure deleteLast( input/output L : List,
    P : address )
- procedure deleteAfter( input Prec : address,
    input/output P : address )

CONTOH OUTPUT :
```bash
Masukkan Nomor Polisi yang akan dihapus : D003
Data dengan nomor polisi D003 berhasil dihapus.

DATA LIST 1 (SETELAH DIHAPUS)
no polisi : D004
warna     : kuning
tahun     : 90
no polisi : D001
warna     : hitam
tahun     : 90
```

### 📄 File: `Doublylist.h`

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

#endif
```

### 📄 File: `Doublylist.cpp`

```C++
#include "Doublylist.h"
using namespace std;

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong!" << endl;
    } else {
        address P = L.last;
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->prev;
        }
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}
```

### 📄 File: `main.cpp`

```C++
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
```

### Output Unguided  :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL6/imagesmodul6/output1_unguided_modul6.png)

![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL6/imagesmodul6/output2_unguided_modul6.png)

![Screenshot Output Unguided 1_3](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL6/imagesmodul6/output3_unguided_modul6.png)

Penjelasan : Pada bagian **Unguided** ini, dilakukan penerapan konsep **Doubly Linked List** untuk mengelola data kendaraan secara dinamis, di mana setiap data kendaraan terdiri dari atribut *nomor polisi*, *warna*, dan *tahun pembuatan*. Struktur data ini dibangun dengan tiga file utama yaitu `Doublylist.h`, `Doublylist.cpp`, dan `main.cpp`. File `Doublylist.h` digunakan untuk mendefinisikan tipe data dan deklarasi fungsi, seperti `createList`, `alokasi`, `dealokasi`, `insertLast`, `printInfo`, `findElm`, serta prosedur penghapusan data. File `Doublylist.cpp` berisi implementasi fungsi-fungsi tersebut, yang memungkinkan pembentukan list dua arah, penambahan elemen di akhir list, pencarian elemen berdasarkan nomor polisi, serta penghapusan elemen baik di awal, akhir, maupun di tengah list menggunakan pointer penghubung `next` dan `prev`. Pada `main.cpp`, pengguna diberikan interaksi langsung untuk memasukkan data kendaraan, menampilkan isi list, mencari data tertentu berdasarkan nomor polisi, dan menghapus data tertentu sesuai kebutuhan. Program juga dilengkapi dengan validasi agar nomor polisi yang sama tidak dapat dimasukkan dua kali. Hasil dari implementasi ini menunjukkan bahwa Doubly Linked List mampu menyimpan dan memanipulasi data secara fleksibel, efisien, serta mendukung navigasi maju dan mundur di dalam struktur data yang saling terhubung.

## Kesimpulan
Dari praktikum Modul 6 ini dapat disimpulkan bahwa Doubly Linked List adalah struktur data dinamis yang memungkinkan setiap elemen saling terhubung dua arah melalui pointer `next` dan `prev`. Dengan dua arah hubungan ini, proses seperti penambahan, penghapusan, pencarian, dan penelusuran data menjadi lebih fleksibel dibandingkan Singly Linked List.
Latihan 6.2 memberikan pemahaman mengenai cara implementasi Doubly Linked List untuk menyimpan data kompleks (seperti data kendaraan), melakukan pencarian berdasarkan atribut tertentu, serta menghapus node dengan aman tanpa merusak struktur rantai data. Struktur ini banyak digunakan pada sistem yang memerlukan navigasi dua arah dan efisiensi tinggi dalam pengelolaan data dinamis.


## Referensi
[1] Ginting, F. (2022). Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++. Jurnal Ilmiah Teknologi Informasi, Universitas Medan Area.
[2] Handayani, R. (2021). Analisis Kinerja Doubly Linked List dalam Penyimpanan Dinamis. Jurnal Teknologi dan Sistem Informasi, Universitas Diponegoro.
[3] Triase. (2020). Struktur Data (Edisi Revisi). Universitas Islam Negeri Sumatera Utara.
[4] Indahyati, U., & Rahmawati, Y. (2020). Algoritma dan Pemrograman dalam Bahasa C++. Umsida Press.
[5] Suryani, L. (2023). Optimasi Pengelolaan Data Dinamis Menggunakan Doubly Linked List. Jurnal Informatika Nusantara, Universitas Negeri Surabaya.
<br>...








