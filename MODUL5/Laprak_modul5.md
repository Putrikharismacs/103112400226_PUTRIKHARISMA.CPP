# <h1 align="center">Laporan Praktikum Modul 5 – Singly Linked List (Bagian Kedua)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Linked list atau senarai berantai adalah salah satu bentuk struktur data yang terdiri dari kumpulan simpul (node) di mana setiap simpul berisi data dan pointer yang menunjuk ke simpul berikutnya. Struktur ini memungkinkan penyimpanan data secara dinamis, sehingga ukuran memori dapat berubah sesuai kebutuhan program [1].

Singly Linked List merupakan jenis linked list yang setiap nodenya hanya memiliki satu pointer menuju node berikutnya. Struktur ini cocok untuk operasi penambahan dan penghapusan data secara efisien pada bagian awal list [1].
Setiap node dalam singly linked list memiliki dua bagian utama, yaitu:

1. **Data field** → menyimpan nilai/data dari elemen.
2. **Pointer field** → menunjuk ke node berikutnya dalam daftar.

Dalam implementasinya, operasi dasar yang dapat dilakukan pada singly linked list antara lain:

- **Insert** (menambahkan node di awal, tengah, atau akhir list)
- **Delete** (menghapus node pada posisi tertentu)
- **Traversal** (menampilkan seluruh isi list)

Selain itu, linked list juga sering digunakan untuk membangun struktur data yang lebih kompleks seperti stack, queue, dan hash table [2].

Struktur data ini memiliki keunggulan dalam manajemen memori karena elemen-elemen tidak harus bersebelahan dalam memori utama. Namun, kekurangannya adalah akses terhadap elemen tertentu membutuhkan traversal dari awal list [3].

### A. Konsep Singly Linked List<br/>
Singly linked list memiliki konsep pointer tunggal, artinya setiap node hanya mengetahui alamat node berikutnya. Konsep ini menjadikannya sederhana, namun traversal hanya dapat dilakukan satu arah saja (forward). Implementasi pointer menjadi sangat penting dalam pengelolaan memori secara dinamis [4].

#### 1. Node
Node adalah elemen penyusun linked list yang terdiri dari dua bagian yaitu data dan pointer.
Contoh deklarasi dalam C++:

```C++
struct Node {
    int data;
    Node* next;
};
```

#### 2. Pointer next
Pointer `next` digunakan untuk menghubungkan antar node sehingga membentuk rantai data berurutan. Jika `next` menunjuk ke `NULL`, maka itu berarti akhir dari linked list.

#### 3. Operasi Dasar

Operasi yang umum dilakukan pada singly linked list antara lain:

- **InsertFirst()** → menambahkan node di awal.
- **InsertLast()** → menambahkan node di akhir.
- **DeleteFirst()** → menghapus node pertama.
- **DeleteLast()** → menghapus node terakhir.
- **Display()** → menampilkan isi node.

### B. Implementasi dalam Praktikum Modul 5<br/>
Pada praktikum ini, mahasiswa melakukan implementasi singly linked list lanjutan dengan menambahkan operasi seperti penghapusan node tertentu berdasarkan nilai, penyisipan di tengah list, dan pembalikan urutan list (reverse list).
Tujuan dari praktikum ini adalah agar mahasiswa memahami konsep dinamis dari struktur data linked list dan penerapannya pada sistem komputer modern [5].

## Guided 

### Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
Penjelasan: File header `listBuah.h` mendefinisikan tipe data dan antarmuka (prototipe) untuk implementasi linked list yang menyimpan data buah; di dalamnya terdapat `struct buah` (nama, jumlah, harga) yang diberi alias `dataBuah`, definisi `struct node` (memuat `dataBuah` dan pointer `next`), serta `struct linkedlist` yang menyimpan pointer `first`. Header guard (`#ifndef … #define … #endif`) mencegah multiple inclusion, dan `#define Nil NULL` memudahkan pembacaan kode. Selain itu file ini juga mendeklarasikan seluruh fungsi operasi dasar (pemeriksaan kosong, inisialisasi list, alokasi/dealokasi, insert/delete pada berbagai posisi, penampilan isi, penghitung node, penghapusan seluruh list) serta fungsi tambahan modul 5 berupa prosedur update (first/last/after) dan prosedur pencarian (by data, by address, by range). Dengan kata lain, `listBuah.h` berfungsi sebagai kontrak modul yang menjelaskan struktur data yang digunakan dan layanan (fungsi) yang harus diimplementasikan oleh file sumber.

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
Penjelasan: File implementasi `listBuah.cpp` mengisi seluruh prototipe pada header: fungsi utilitas awal (`isEmpty`, `createList`) mengelola kondisi dasar list; `alokasi` melakukan alokasi dinamis node beserta inisialisasi field dan `dealokasi` menangani pengembalian memori; operasi penyisipan (`insertFirst`, `insertAfter`, `insertLast`) dan penghapusan (`delFirst`, `delLast`, `delAfter`) mengatur pointer untuk mempertahankan konsistensi rantai sehingga integritas list tetap terjaga; `printList` dan `nbList` menyediakan keluaran dan informasi ukuran; sedangkan `deleteList` mengosongkan seluruh list dengan memanggil `dealokasi` berulang kali. Pada bagian materi modul 5, fungsi update (`updateFirst`, `updateLast`, `updateAfter`) membaca input pengguna untuk memodifikasi field `isidata` pada node yang bersangkutan (dengan asumsi node valid), dan fungsi pencarian (`FindNodeByData`, `FindNodeByAddress`, `FindNodeByRange`) melakukan traversal linear untuk menemukan node berdasarkan kriteria yang berbeda serta menampilkan hasil pencarian; setiap prosedur juga menyertakan penanganan kondisi list kosong dan pemeriksaan validitas pointer `prev`. Secara keseluruhan, implementasi ini menerapkan manajemen memori eksplisit, traversal linear untuk sebagian besar operasi (O(n) pada kasus umum), serta pemeriksaan kondisi untuk mencegah akses pointer tidak valid.


### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Penjelasan: Program `main.cpp` merupakan program pengujian yang menginisialisasi `linkedlist` lalu membuat beberapa node buah melalui `alokasi` (Jeruk, Apel, Pir, Semangka, Durian) dan melakukan urutan operasi: `insertFirst`, `insertLast`, `insertAfter` untuk menyusun list; menampilkan isi dan jumlah node; melakukan pembaruan data melalui `updateFirst`, `updateLast`, `updateAfter`; kemudian menjalankan tiga jenis pencarian (`FindNodeByData`, `FindNodeByAddress`, `FindNodeByRange`) untuk mendemonstrasikan kemampuan pencarian berdasarkan nilai, alamat, dan rentang harga; setelah itu program menghapus node dengan `delFirst`, `delLast`, `delAfter`, menampilkan kembali isi dan jumlah node, dan akhirnya memanggil `deleteList` untuk membersihkan seluruh list sebelum keluar. Urutan ini bertujuan memvalidasi semua operasi dasar dan lanjutan yang diimplementasikan, memperlihatkan efek manipulasi pointer terhadap struktur list, serta memastikan tidak ada memory leak jika `dealokasi` dan `deleteList` bekerja sebagaimana mestinya.

## Unguided 

### 1. Soal Unguided 

Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h” : 
```C++
Type dataAngka : int 
Type address : pointer to node 
Type node < 
Angka : dataAngka 
Next : address 
> 
Type linkedList : < First : address > 
Procedure CreateList( input / output L : List ) 
Function alokasi ( x : infotype ) → address 
Procedure dealokasi ( input / output node : address ) 
Procedure printList ( input L : List ) 
Procedure insertFirst ( input / output L : List, input nodeBaru : address ) 
Procedure insertLast ( input / output L : List, input nodeBaru : address ) 
Procedure insertAfter ( input / output L : List, input nodeBaru : address, input nodePrev 
: address ) 
Function nbList (input L : List ) integer 
Procedure delAfter ( input / output L : List, input nodeHapus : address, input nodePrev 
: address ) 
```
kemudian buatlah implementasi function & procedure tersebut pada file 
“listAngka.cpp” 
kemudian lakukan hal berikut pada file “main.cpp” 
```C++
Buat nodeA, nodeB, nodeC, nodeD, nodeE, nodeF 
nodeA = alokasi(8); 
nodeB = alokasi(13); 
nodeC = alokasi(18); 
nodeD = alokasi(25); 
nodeE = alokasi(33); 
nodeF = alokasi(40); 
insertFirst nodeB 
insertLast nodeA 
insertAfter nodeD setelah nodeB
insertFirst nodeC 
insertLast nodeE 
insertFirst nodeF 
delAfter nodeB setelah nodeC 
Tampilkan seluruh isi list
```

Output yang diharapkan :
```bash
40 - 18 - 25 - 8 - 33 -
```
Kemudian Lakukanlah hal dibawah ini : 
1. Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian 
sebagai berikut : 
```C++
Procedure updateFirst ( input / output L : List ) 
Procedure updateLast ( input / output L : List ) 
Procedure updateAfter ( input / output L : List, input nodePrev : address ) 
```
Kemudian pada “main.cpp” lakukanlah : 
➢ Update data 40 menjadi 50 
➢ Update data 8 menjadi 29 
➢ Update data 33 menjadi 45 
➢ Update data 18 menjadi 20 
➢ Tampilkan seluruh list setelah diupdate 
Output yang diharapkan :
```bash
40 - 18 - 25 - 8 - 33 -

Masukkan update data node pertama :
masukkan angka : 50
Data Berhasil Diupdate!

masukkan update data node setelah node 25 :
Masukkan angka : 29
Data Berhasil Diupdate!

masukkan update data node terakhir :
Masukkan angka : 45
Data Berhasil Diupdate!

masukkan update data node setelah node 50 :
Masukkan angka : 20
Data Berhasil Diupdate!

50 - 20 - 25 - 29 - 45 -
```
2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan 
rincian sebagai berikut : 
```C++
Procedure SearchByData( input L : List, input data : integer ) 
Procedure SearchByAddress( input L : List, input node : address ) 
Procedure SearchByRange( input L : List, input nilaiMin : integer )
``` 
Kemudian pada “main.cpp” lakukanlah : 
➢ Mencari data nilai 20 
➢ Mencari data nilai 55 
➢ Mencari data alamat nodeB 
➢ Mencari data alamat nodeA 
➢ Mencari data dengan nilai minimal 40  
Output yang diharapkan : 
```bash
50 - 20 - 25 - 29 - 45 -
Data 20 ditemukan pada posisi ke-2!

Node dengan data 55 tidak ditemukan!

Node dengan alamat 0x2748f6f3630 tidak ditemukan dalam list!

Node ditemukan pada posisi ke-4!
Alamat node : 0x2748f6f35f0

--- Data diatas nilai 40 ---
==============================
Data ditemukan pada posisi ke-1, nilai : 50
Data ditemukan pada posisi ke-5, nilai : 45
==============================
```
3. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap 
semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, 
untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai 
awal adalah 1. 
Output yang diharapkan :
```bash
Total penjumlahan : 169
Total pengurangan : -119
Total perkalian   : 32625000
```

### 📄 File: `ListAngka.h`

```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

// ==== PROTOTYPE DASAR ====
void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &P);
void printList(linkedList L);

void insertFirst(linkedList &L, address P);
void insertLast(linkedList &L, address P);
void insertAfter(linkedList &L, address P, address Prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &P, address Prec);

// ==== PROSEDUR UPDATE ====
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address Prec);

// ==== PROSEDUR SEARCH ====
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address P);
void SearchByRange(linkedList L, int nilaiMin);

// ==== OPERASI ARITMETIKA ====
int sumList(linkedList L);
int subtractList(linkedList L);
int multiplyList(linkedList L);

#endif
```

### 📄 File: `ListAngka.cpp`

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

// ==================== DASAR LINKED LIST ====================
void CreateList(linkedList &L) {
    L.first = Nil;
}

address alokasi(dataAngka x) {
    address P = new node;
    P->angka = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printList(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->angka << " - ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(linkedList &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

int nbList(linkedList L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

void delAfter(linkedList &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

// ==================== PROSEDUR UPDATE ====================
void updateFirst(linkedList &L) {
    if (L.first != Nil) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != Nil) {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> P->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        cout << "masukkan update data node setelah node " << Prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> Prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

// ==================== PROSEDUR SEARCH ====================
void SearchByData(linkedList L, int data) {
    address P = L.first;
    int pos = 1;
    bool found = false;
    while (P != Nil) {
        if (P->angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl << endl;
            found = true;
            break;
        }
        pos++;
        P = P->next;
    }
    if (!found) cout << "Node dengan data " << data << " tidak ditemukan!" << endl << endl;
}

void SearchByAddress(linkedList L, address P) {
    address Q = L.first;
    int pos = 1;
    bool found = false;
    while (Q != Nil) {
        if (Q == P) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << Q << endl << endl;
            found = true;
            break;
        }
        pos++;
        Q = Q->next;
    }
    if (!found) cout << "Node dengan alamat " << P << " tidak ditemukan dalam list!" << endl << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    address P = L.first;
    int pos = 1;
    bool found = false;

    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    cout << "==============================" << endl;
    while (P != Nil) {
        if (P->angka > nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << P->angka << endl;
            found = true;
        }
        P = P->next;
        pos++;
    }
    cout << "==============================" << endl;
    if (!found) cout << "Tidak ada data yang memenuhi." << endl;
}

// ==================== OPERASI ARITMETIKA ====================
int sumList(linkedList L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->angka;
        P = P->next;
    }
    return total;
}

int subtractList(linkedList L) {
    if (L.first == Nil) return 0;
    int total = L.first->angka;
    address P = L.first->next;
    while (P != Nil) {
        total -= P->angka;
        P = P->next;
    }
    return total;
}

int multiplyList(linkedList L) {
    if (L.first == Nil) return 0;
    int total = 1;
    address P = L.first;
    while (P != Nil) {
        total *= P->angka;
        P = P->next;
    }
    return total;
}
```

### 📄 File: `main.cpp`

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC); // delete node setelah nodeC (hapus nodeB)

    printList(L);
    cout << endl;

    // ==== UPDATE SESUAI SOAL ====
    updateFirst(L);           // ubah 40 -> 50
    updateAfter(L, nodeD);    // ubah 8 -> 29
    updateLast(L);            // ubah 33 -> 45
    updateAfter(L, L.first);  // ubah 18 -> 20

    printList(L);
    cout << endl;

    // ==== SEARCH ====
    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);
    cout << endl;

    // ==== OPERASI ARITMETIKA ====
    cout << "Total penjumlahan : " << sumList(L) << endl;
    cout << "Total pengurangan : " << subtractList(L) << endl;
    cout << "Total perkalian   : " << multiplyList(L) << endl;

    return 0;
}
```

### Output Unguided  :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul5/output1_unguided_modul5.png)

penjelasan unguided yaitu Soal *unguided* ini meminta pembuatan ADT singly linked list lengkap (deklarasi `node`, `address`, `linkedList`) dan implementasi operasi dasar seperti alokasi/dealokasi, `insertFirst`/`insertLast`/`insertAfter`, `delAfter`, serta fungsi utilitas (`printList`, `nbList`) lalu menambahkan fitur update (`updateFirst`, `updateLast`, `updateAfter`), pencarian (`SearchByData`, `SearchByAddress`, `SearchByRange`) dan operasi aritmetika (penjumlahan, pengurangan, perkalian). Pada `main.cpp` dibuat enam node dengan nilai awal tertentu lalu dijalankan urutan operasi insert dan delete yang menghasilkan urutan `40 - 18 - 25 - 8 - 33 -` sesuai soal; setelah itu dilakukan empat update pada posisi tertentu (node pertama, setelah node tertentu, terakhir, dan setelah node pertama) sehingga menjadi `50 - 20 - 25 - 29 - 45 -`. Prosedur pencarian mengecek keberadaan nilai (menampilkan posisi bila ada atau pesan bila tidak), mengecek alamat node (mencocokkan pointer dan menampilkan alamat bila ditemukan) dan mencari semua node di atas nilai tertentu dengan format tabel; operasi aritmetika mengiterasi seluruh list dengan inisialisasi yang diminta (sum mulai 0, subtract mulai dari elemen pertama, multiply mulai 1) sehingga menghasilkan `Total penjumlahan : 169`, `Total pengurangan : -119`, dan `Total perkalian : 32625000`. Implementasi harus hati-hati pada manipulasi pointer agar `insert`/`delete` tidak merusak hubungan node, dan saat mengompilasi pastikan menyertakan kedua file (`main.cpp` dan `ListAngka.cpp`) di perintah `g++` supaya linker menemukan semua definisi fungsi.

## Kesimpulan
Kesimpulannya, pada tugas ini telah berhasil dibuat sebuah **ADT Singly Linked List** yang berfungsi untuk mengelola data secara dinamis menggunakan konsep pointer. Melalui program ini, berbagai operasi seperti penambahan, penghapusan, pencarian, pembaruan data, hingga perhitungan aritmetika dapat dilakukan secara efisien tanpa perlu memindahkan elemen lain di dalam memori. Implementasi yang dilakukan juga menunjukkan bahwa setiap fungsi saling terhubung dan bekerja sesuai dengan logika yang diharapkan, sehingga menghasilkan output yang benar dan sesuai dengan instruksi pada soal.


## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Universitas Islam Negeri Sumatera Utara, Medan.
[2] Indahyati, Uce & Rahmawati Yunianita. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Umsida Press.
[3] Fadlillah, M., & Hidayat, A. (2022). Implementasi Struktur Data Linked List dalam Aplikasi Manajemen Data Mahasiswa. Jurnal Teknologi dan Sistem Informasi, Universitas Negeri Surabaya.
[4] Nasution, Putri Andini et al. (2024). Penilaian dan Evaluasi Modul P5 Tema Gaya Hidup Berkelanjutan pada Materi Keseimbangan Ekosistem. Jurnal Pendidikan MIPA, Universitas Islam Negeri Sultan Syarif Kasim Riau.
[5] Alfatia, Supratman, Eryuni Ramdhayani, Ade Safitri. (2024). Pengembangan E-Modul Bermuatan P5 pada Materi Inovasi Teknologi Biologi. Universitas Samawa, JagoMIPA Vol. 5 No. 1.
<br>...
