# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Struktur data merupakan cara mengorganisasi dan menyimpan data agar dapat digunakan secara efisien dalam proses komputasi. Salah satu struktur data yang sering digunakan dalam pemrograman adalah **Linked List**.

Berbeda dengan array yang bersifat statis dan dialokasikan secara berurutan di memori, *Linked List* bersifat **dinamis**, artinya dapat bertambah atau berkurang sesuai kebutuhan. Setiap elemen pada *Linked List* disebut **node**, dan setiap node minimal memiliki dua komponen utama: **data field** dan **pointer field (next)** yang menunjuk ke node berikutnya [1].

Struktur *Linked List* banyak digunakan pada berbagai aplikasi seperti implementasi *stack, queue, hash table, dan graph,* karena kemampuannya dalam melakukan operasi penyisipan serta penghapusan data dengan efisien [2].

### A. Pengertian dan Karakteristik Linked List<br/>
Bagian ini menjelaskan definisi, sifat, serta komponen dasar dari Linked List yang menjadi pondasi pemrograman struktur data dinamis.

#### 1. Pengertian Linked List
*Linked List* adalah struktur data linear yang terdiri dari kumpulan elemen (node) yang saling terhubung melalui pointer. Setiap node menyimpan satu nilai data dan satu pointer ke node berikutnya. Tidak seperti array, lokasi penyimpanan node tidak harus berurutan di memori karena hubungan antar-node ditentukan oleh pointer [1].

Keunggulan utama *Linked List* adalah kemampuannya untuk melakukan operasi penambahan *(insert)* dan penghapusan *(delete)* data tanpa harus menggeser elemen lain di dalam list [3].

#### 2. Karakteristik Linked List
Beberapa karakteristik utama dari *Linked List* antara lain:

- Bersifat **dinamis**, sehingga ukurannya dapat berubah sesuai kebutuhan program.
- Setiap node memiliki alamat memori yang berbeda dan dihubungkan oleh pointer.
- Akses elemen bersifat **sekuensial,** dimulai dari node pertama *(head).*
- Memori dialokasikan hanya ketika dibutuhkan, membuatnya lebih efisien dibandingkan array pada data yang sering berubah.
- Memerlukan pointer tambahan untuk menghubungkan setiap node [2].

#### 3. Komponen Linked List

Setiap node dalam Linked List memiliki dua komponen utama:

- **Data field,** berfungsi untuk menyimpan nilai atau informasi yang akan digunakan.
- **Pointer field,** menyimpan alamat memori node berikutnya.
Selain itu, terdapat dua pointer penting:
- **Head** → menunjuk ke node pertama.
- **Tail** → menunjuk ke node terakhir yang biasanya mengarah ke `NULL` [3].

#### 4. Jenis-Jenis Linked List

a. **Singly Linked List** – setiap node hanya memiliki satu pointer ke node berikutnya.
b. **Doubly Linked List** – setiap node memiliki dua pointer, yaitu ke node sebelumnya dan node sesudahnya.
c. **Circular Linked List** – node terakhir menunjuk kembali ke node pertama, membentuk struktur melingkar [1].

Setiap jenis memiliki fungsi dan efisiensi yang berbeda tergantung kebutuhan aplikasi.

#### 5. Kelebihan dan Kekurangan Linked List

**Kelebihan:**
- Penambahan dan penghapusan data lebih cepat dibandingkan array.
- Tidak perlu menentukan ukuran list di awal.
- Memori dialokasikan sesuai kebutuhan (dynamic memory allocation).

**Kekurangan:**
- Akses data lambat karena harus dilakukan secara berurutan.
- Menggunakan memori tambahan untuk pointer.
- Implementasinya lebih kompleks dibanding array [2].

### B. Operasi Dasar pada Linked List<br/>
Operasi dasar adalah fungsi-fungsi utama yang digunakan untuk memanipulasi data pada *Linked List.*

#### 1. Create List
Digunakan untuk membuat list kosong dengan menginisialisasi pointer `head` dan `tail` menjadi `NULL`. Hal ini menandakan list belum berisi data apa pun.

#### 2. Insert (Penyisipan Data)
Operasi ini berfungsi untuk menambahkan node baru ke dalam list, dengan tiga variasi utama:

- **Insert First** → menambahkan node baru di awal list.
- **Insert Last** → menambahkan node di akhir list.
- **Insert After** → menambahkan node setelah node tertentu.

#### 3. Delete (Penghapusan Data)
Digunakan untuk menghapus node dari list. Terdapat tiga jenis penghapusan:

- **Delete First** → menghapus node pertama.
- **Delete Last** → menghapus node terakhir.
- **Delete After** → menghapus node setelah node tertentu.

Setelah node dihapus, memori dialokasikan kembali agar tidak terjadi kebocoran memori *(memory leak)* [1][3].

#### 4. Traversal (Display)
Proses menelusuri seluruh elemen dari `head` hingga `NULL` untuk menampilkan isi list. Traversal juga digunakan untuk menghitung jumlah node atau mencari data tertentu.

#### 5. nbList() (Count Node)
Fungsi untuk menghitung jumlah node dalam list. Dengan menelusuri semua node satu per satu, fungsi ini dapat mengetahui ukuran list secara dinamis.

## Guided 

### Guided 1

### 1. list.h

```C++
// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

// Ini struct untuk linked list-nya
struct linkedList {
    address first;
};

// Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif
```
Penjelasan: Pada file `list.h`, kode dimulai dengan penggunaan *header guard* `#ifndef LIST_H` dan `#define LIST_H` yang berfungsi untuk mencegah agar file header tidak di-*include* lebih dari satu kali dalam satu program. Selanjutnya, `#define Nil NULL` digunakan untuk membuat alias agar penulisan `NULL` menjadi lebih singkat. Library `<iostream>` di-*include* karena program akan menggunakan operasi input dan output dengan `cout` dan `cin`. Kemudian, dideklarasikan `struct mahasiswa` yang berfungsi sebagai wadah data setiap mahasiswa dengan tiga atribut, yaitu `nama`, `nim`, dan `umur`. Selanjutnya dibuat `typedef mahasiswa dataMahasiswa;` untuk memudahkan penulisan tipe data mahasiswa. Baris `typedef struct node* address;` mendefinisikan `address` sebagai pointer yang menunjuk ke struct `node`. Struktur `node` didefinisikan dengan dua elemen utama, yakni `isiData` bertipe `dataMahasiswa` dan `next` bertipe `address` yang menunjuk ke node berikutnya. Setelah itu, `struct linkedList` dibuat untuk merepresentasikan keseluruhan list dengan satu atribut `first` yang menunjuk ke node pertama dalam list. Di bagian bawah file, terdapat deklarasi fungsi-fungsi seperti `isEmpty`, `createList`, `alokasi`, `dealokasi`, `printList`, `insertFirst`, `insertAfter`, dan `insertLast` yang nantinya diimplementasikan di `list.cpp`. Secara keseluruhan, kode pada `list.h` ini bertujuan membentuk kerangka dasar untuk struktur *Singly Linked List* agar program utama dapat memanggil fungsi-fungsi yang sudah dideklarasikan tanpa harus menuliskannya ulang.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim 
            << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Penjelasan: Pada file `list.cpp`, bagian awal program menggunakan `#include "list.h"` agar fungsi-fungsi dan struktur data dari file header bisa digunakan. Fungsi `isEmpty(linkedList List)` digunakan untuk memeriksa apakah list kosong dengan cara memeriksa apakah `List.first` bernilai `Nil`; jika ya, fungsi mengembalikan `true`. Fungsi `createList(linkedList &List)` digunakan untuk menginisialisasi list kosong dengan mengatur `List.first = Nil`. Fungsi `alokasi` bertugas membuat node baru dengan `new node`, lalu mengisi atribut `nama`, `nim`, dan `umur` sesuai parameter yang diterima. Pointer `next` diset ke `Nil`, lalu node baru dikembalikan ke pemanggil. Fungsi `dealokasi` digunakan untuk menghapus node yang sudah tidak digunakan agar memori tidak bocor, yaitu dengan menyetel `next` ke `Nil` dan menghapusnya menggunakan `delete`. Fungsi `insertFirst` akan menempatkan node baru di bagian awal list dengan cara mengarahkan `nodeBaru->next` ke `List.first`, lalu `List.first` diarahkan ke `nodeBaru`. Fungsi `insertAfter` digunakan untuk menyisipkan node baru setelah node tertentu, yaitu dengan mengatur `nodeBaru->next` menunjuk ke `Prev->next`, lalu `Prev->next` diarahkan ke node baru. Fungsi `insertLast` menambahkan node baru di akhir list dengan menelusuri list dari `first` hingga `next` bernilai `Nil`, lalu node terakhir diarahkan ke node baru. Fungsi `printList` berfungsi untuk menampilkan seluruh isi list; jika list kosong, maka menampilkan pesan "List kosong", tetapi jika tidak, maka program akan menelusuri setiap node menggunakan pointer bantu (`nodeBantu`) dan mencetak data mahasiswa (`nama`, `NIM`, dan `umur`) dari setiap node hingga `Nil`. Secara keseluruhan, file ini berfungsi mengimplementasikan proses pembuatan, penambahan, dan penampilan isi list secara dinamis.

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Penjelasan: Pada file `main.cpp`, bagian awal meng-*include* file `list.h` agar struktur data dan fungsi yang sudah dibuat bisa digunakan. Program dimulai dengan membuat variabel `linkedList List` sebagai wadah list kosong, kemudian memanggil `createList(List)` untuk menginisialisasinya. Lima node mahasiswa (`nodeA` sampai `nodeE`) dibuat menggunakan fungsi `alokasi`, masing-masing berisi data mahasiswa berupa nama, NIM, dan umur. Setelah node terbentuk, fungsi `insertFirst(List, nodeA)` digunakan untuk menambahkan node pertama ke awal list, diikuti oleh `insertLast(List, nodeB)` untuk menambah node di akhir list, serta `insertAfter` untuk menambahkan node setelah node tertentu, misalnya `insertAfter(List, nodeC, nodeA)` menambahkan node C setelah node A. Urutan node akhirnya membentuk rantai data mahasiswa secara berurutan. Setelah seluruh node dimasukkan, perintah `cout` mencetak teks “--- ISI LIST SETELAH DILAKUKAN INSERT ---” lalu fungsi `printList(List)` menampilkan semua isi node dalam list. Program ini menunjukkan bagaimana data mahasiswa dapat dimasukkan ke dalam *Singly Linked List* dan ditampilkan menggunakan konsep pointer.

### Guided 2

### 1. list.h

```C++
// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

struct linkedList { // Ini linked list-nya
    address first;
};

// semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```
Penjelasan: Pada file `list.h`, bagian awal program menggunakan *header guard* `#ifndef LIST_H`, `#define LIST_H`, dan `#endif` untuk mencegah file di-*include* lebih dari sekali. Lalu, `#define Nil NULL` membuat alias agar lebih mudah menuliskan `NULL`. Library `<iostream>` di-*include* karena digunakan untuk menampilkan data ke layar dengan `cout`. Struktur data `struct mahasiswa` masih sama seperti pada Guided 1, menyimpan tiga informasi utama: `nama`, `nim`, dan `umur`. Selanjutnya, `typedef mahasiswa dataMahasiswa;` digunakan agar tipe data lebih ringkas, dan `typedef struct node* address;` mendefinisikan `address` sebagai pointer ke struct `node`. Struktur `node` berfungsi sebagai elemen utama dalam list, berisi dua atribut: `isiData` (data mahasiswa) dan `next` (penunjuk ke node berikutnya). Struktur `linkedList` menyimpan satu pointer `first` sebagai penanda node awal. Setelah struktur selesai didefinisikan, fungsi-fungsi dideklarasikan agar dapat digunakan di file implementasi `list.cpp`. Fungsi yang ada diantaranya `isEmpty`, `createList`, `alokasi`, `dealokasi`, `printList`, `insertFirst`, `insertAfter`, `insertLast`, serta fungsi tambahan `delFirst`, `delLast`, `delAfter`, `nbList`, dan `deleteList` yang digunakan untuk menghapus node di posisi tertentu, menghitung jumlah node, serta menghapus seluruh isi list. Secara keseluruhan, file ini berfungsi sebagai cetak biru (*blueprint*) dari *Singly Linked List* yang sudah dilengkapi fungsi insert, delete, dan traversal agar dapat digunakan dengan fleksibel dalam program utama.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
Penjelasan: Pada file `list.cpp`, implementasi dari seluruh fungsi dalam `list.h` ditulis secara lengkap. Fungsi `isEmpty` digunakan untuk memeriksa apakah list kosong dengan memeriksa apakah `List.first == Nil`. Fungsi `createList` menginisialisasi list kosong dengan mengatur `List.first = Nil`. Fungsi `alokasi` digunakan untuk membuat node baru menggunakan `new node`, kemudian mengisi data mahasiswa berupa `nama`, `nim`, dan `umur`, serta mengatur pointer `next` bernilai `Nil`. Fungsi `dealokasi` digunakan untuk menghapus node dari memori agar tidak terjadi *memory leak*. Fungsi `insertFirst`, `insertAfter`, dan `insertLast` digunakan untuk menambahkan node baru di awal, tengah, atau akhir list. Pada `insertFirst`, pointer `next` dari node baru diarahkan ke `List.first`, kemudian `List.first` diperbarui ke node baru. Pada `insertAfter`, pointer `nodeBaru->next` diarahkan ke `Prev->next`, dan `Prev->next` diarahkan ke node baru. Sedangkan `insertLast` akan menelusuri list hingga node terakhir (`next == Nil`) lalu menautkan node terakhir dengan node baru. Selanjutnya, fungsi `delFirst` menghapus node pertama dengan cara memindahkan pointer `List.first` ke `List.first->next` dan menghapus node sebelumnya. Fungsi `delLast` menghapus node terakhir dengan menelusuri node hingga akhir, menyimpan node sebelumnya (`nodePrev`), kemudian menghapus node terakhir dan mengatur pointer `nodePrev->next` ke `Nil`. Fungsi `delAfter` digunakan untuk menghapus node yang berada setelah node tertentu dengan mengatur ulang pointer `Prev->next` agar langsung menunjuk ke node setelahnya. Fungsi `printList` menampilkan seluruh isi list dengan cara menelusuri setiap node dan mencetak data mahasiswa (`nama`, `nim`, `umur`) hingga pointer `next` bernilai `Nil`. Fungsi `nbList` menghitung jumlah node dengan melakukan penelusuran dari node pertama hingga terakhir sambil menambah nilai penghitung setiap kali node ditemukan. Terakhir, fungsi `deleteList` menghapus seluruh node dalam list dengan menelusuri satu per satu dan memanggil fungsi `dealokasi` untuk setiap node yang dihapus, kemudian mengatur `List.first` ke `Nil`. Secara keseluruhan, file ini menunjukkan implementasi lengkap operasi dasar pada *Singly Linked List*, meliputi pembuatan list, penambahan node, penghapusan node, penghitungan jumlah data, dan penghapusan seluruh isi list dengan manajemen memori dinamis.


### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

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

Penjelasan: Pada file `main.cpp`, bagian awal program meng-*include* file `list.h` agar seluruh struktur dan fungsi yang telah dibuat dapat digunakan. Program dimulai dengan mendeklarasikan variabel `linkedList List` untuk membuat list kosong dan beberapa variabel `address` (`nodeA` hingga `nodeE`) untuk menampung node-node baru. Fungsi `createList(List)` digunakan untuk menginisialisasi list kosong. Selanjutnya, lima node mahasiswa dibuat menggunakan fungsi `alokasi` dengan data nama, NIM, dan umur berbeda, seperti "Dhimas", "Arvin", "Rizal", "Satrio", dan "Joshua". Node-node ini kemudian dimasukkan ke dalam list menggunakan `insertFirst`, `insertAfter`, dan `insertLast` untuk membentuk rantai data berurutan. Setelah semua node dimasukkan, fungsi `printList` digunakan untuk menampilkan seluruh isi list, sementara fungsi `nbList` menghitung jumlah node yang ada dan menampilkannya ke layar. Program lalu menghapus beberapa node menggunakan `delFirst` (menghapus node pertama), `delLast` (menghapus node terakhir), dan `delAfter` (menghapus node setelah node tertentu), kemudian hasil list setelah penghapusan kembali ditampilkan untuk menunjukkan perubahan data. Terakhir, fungsi `deleteList` digunakan untuk menghapus seluruh isi list dan memastikan memori kembali kosong, lalu hasil akhir ditampilkan untuk memastikan list benar-benar sudah terhapus. Secara keseluruhan, isi `main.cpp` menunjukkan bagaimana seluruh operasi yang dibuat di file sebelumnya dapat digunakan secara berurutan — mulai dari pembuatan list, penambahan node, penghapusan node, hingga penghapusan seluruh list dengan hasil yang sesuai di layar.

## Unguided 

### 1. Soal Unguided 1

Buatlah ADT Singly Linked List dengan ketentuan seperti di bawah ini :

- File header : Singlylist.h
- File implementasi : Singlylist.cpp
- File utama : main.cpp

Di dalam ADT tersebut, minimal harus terdapat beberapa fungsi berikut :

- createList()
- alokasi()
- insertFirst()
- insertLast()
- printList()

Output yang diharapkan :
```bash
Isi Linked List : 9 12 8 0 2
```


### 📄 File: `Singlylist.h`

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

typedef Node* address;

// Struktur list
struct List {
    address first;
};

// Deklarasi fungsi dasar
void createList(List &L);
address alokasi(int data);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void insertAfter(List &L, address prec, address p);
void printList(List L);

#endif
```

### 📄 File: `Singlylist.cpp`

```C++
#include "Singlylist.h"

// Membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

// Alokasi node baru
address alokasi(int data) {
    address p = new Node;
    p->data = data;
    p->next = Nil;
    return p;
}

// Menambah node di depan
void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

// Menambah node di akhir
void insertLast(List &L, address p) {
    if (L.first == Nil) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != Nil) {
            q = q->next;
        }
        q->next = p;
    }
}

// Menambah node setelah node tertentu
void insertAfter(List &L, address prec, address p) {
    if (prec != Nil) {
        p->next = prec->next;
        prec->next = p;
    }
}

// Menampilkan isi list
void printList(List L) {
    address p = L.first;
    while (p != Nil) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
```

### 📄 File: `main.cpp`

```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat node
    address A = alokasi(9);
    address B = alokasi(12);
    address C = alokasi(8);
    address D = alokasi(0);
    address E = alokasi(2);

    // Menyusun urutan sesuai soal
    insertFirst(L, A);        // 9
    insertLast(L, B);         // 9 -> 12
    insertLast(L, C);         // 9 -> 12 -> 8
    insertLast(L, D);         // 9 -> 12 -> 8 -> 0
    insertLast(L, E);         // 9 -> 12 -> 8 -> 0 -> 2

    // Cetak hasil akhir
    printList(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output1_unguided1_modul4.png)

penjelasan unguided 1 yaitu Program ini membuat *Singly Linked List* menggunakan tiga file utama, yaitu `Singlylist.h` untuk deklarasi fungsi dan struktur data, `Singlylist.cpp` untuk implementasi fungsi, dan `main.cpp` untuk program utama. Struktur node terdiri dari dua bagian, yaitu data dan pointer `next` yang menghubungkan antar node. Program dimulai dengan membuat list kosong menggunakan `createList()`, kemudian menambahkan node dengan nilai 9, 12, 8, 0, dan 2 secara berurutan menggunakan fungsi `insertFirst()` dan `insertLast()`. Setelah semua node berhasil ditambahkan, fungsi `printList()` digunakan untuk menampilkan isi list. Hasil akhir menunjukkan urutan node `9 12 8 0 2`, yang menandakan bahwa operasi penyisipan berhasil dilakukan dengan benar sesuai dengan konsep *Singly Linked List*.

### 2. soal unguided 2

Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan 
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh 
node menggunakan deleteList(). 
Output yang diharapkan :
```bash
12 9
Jumlah node : 2 - List Berhasil Terhapus -
Jumlah node : 0
```

#### 📄 File: `Singlylist.h`

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;

struct List {
    address first;
};

// Fungsi dasar
void createList(List &L);
address alokasi(int data);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void printList(List L);

// Fungsi penghapusan & utility
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, int data);
int nbList(List L);
void deleteList(List &L);

#endif
```
### 📄 File: `Singlylist.cpp`

```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(int data) {
    address p = new Node;
    p->data = data;
    p->next = Nil;
    return p;
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(List &L, address p) {
    if (L.first == Nil) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != Nil) {
            q = q->next;
        }
        q->next = p;
    }
}

void printList(List L) {
    address p = L.first;
    while (p != Nil) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != Nil) {
        address p = L.first;
        L.first = L.first->next;
        delete p;
    }
}

void deleteLast(List &L) {
    if (L.first != Nil) {
        address p = L.first;
        if (p->next == Nil) {
            L.first = Nil;
            delete p;
        } else {
            address prev = Nil;
            while (p->next != Nil) {
                prev = p;
                p = p->next;
            }
            prev->next = Nil;
            delete p;
        }
    }
}

void deleteAfter(List &L, int data) {
    address p = L.first;
    while (p != Nil && p->next != Nil) {
        if (p->data == data) {
            address hapus = p->next;
            p->next = hapus->next;
            delete hapus;
            return;
        }
        p = p->next;
    }
}

int nbList(List L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    address p = L.first;
    while (p != Nil) {
        address hapus = p;
        p = p->next;
        delete hapus;
    }
    L.first = Nil;
    cout << "- List Berhasil Terhapus -" << endl;
}
```
### 📄 File: `main.cpp`

```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat node (sama seperti latihan 1)
    insertLast(L, alokasi(9));
    insertLast(L, alokasi(12));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(0));
    insertLast(L, alokasi(2));

    // Penghapusan sesuai soal
    deleteFirst(L);    // hapus node 9
    deleteLast(L);     // hapus node 2
    deleteAfter(L, 12); // hapus node setelah 12 (node 8)

    // Tampilkan hasil & jumlah node
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // Hapus seluruh list
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output1_unguided2_modul4.png)

penjelasan unguided 2 yaitu Program ini merupakan lanjutan dari latihan pertama yang menambahkan fitur penghapusan data pada *Singly Linked List* menggunakan fungsi `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`. Pertama, list dibuat dengan node berisi 9, 12, 8, 0, dan 2. Kemudian, `deleteFirst()` digunakan untuk menghapus node pertama (9), `deleteLast()` untuk menghapus node terakhir (2), dan `deleteAfter(12)` untuk menghapus node setelah 12, yaitu node 8. Setelah penghapusan, fungsi `nbList()` digunakan untuk menghitung jumlah node yang tersisa, dan hasilnya adalah 2 node, yaitu `12` dan `0`. Terakhir, `deleteList()` digunakan untuk menghapus seluruh node dalam list hingga kosong. Hasil program menampilkan output `12 0`, diikuti dengan pesan `List Berhasil Terhapus`, yang membuktikan bahwa seluruh operasi penghapusan berjalan dengan benar.


## Kesimpulan
Berdasarkan hasil praktikum yang telah dilakukan, dapat disimpulkan bahwa *Singly Linked List* merupakan struktur data yang memungkinkan penyimpanan data secara dinamis menggunakan node yang saling terhubung melalui pointer. Pada latihan pertama, berhasil dibuat program yang menampilkan data dalam urutan yang benar melalui proses penambahan elemen dengan fungsi `insertFirst()` dan `insertLast()`. Sementara itu, pada latihan kedua berhasil dilakukan penghapusan elemen menggunakan fungsi `deleteFirst()`, `deleteLast()`, dan `deleteAfter()` serta perhitungan jumlah node dengan `nbList()`. Secara keseluruhan, praktikum ini menunjukkan bahwa *Singly Linked List* mampu mengelola data dengan efisien melalui operasi penambahan dan penghapusan tanpa harus memindahkan seluruh elemen seperti pada array.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara.
[2] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press.
[3] Fauziddin, M., Adha, T. R., Arifiyanti, N., Indriyani, F., Rizki, L. M., Wulandary, V., & Reddy, V. S. V. (2025). The Impact of AI on the Future of Education in Indonesia. Educative: Jurnal Ilmiah Pendidikan, Vol. 3 No. 1, Hal. 11–16. DOI: 10.70437/educative.v3i1.828
<br>...
