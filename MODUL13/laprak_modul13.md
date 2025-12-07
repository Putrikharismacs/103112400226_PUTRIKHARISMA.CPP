# <h1 align="center">Laporan Praktikum Modul 13 – Multi Linked List</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Multi Linked List (MLL) adalah salah satu pengembangan dari struktur data linked list yang digunakan untuk merepresentasikan hubungan **hirarkis** antara data induk (parent) dan data anak (child). Dalam MLL, setiap elemen induk memiliki list anak tersendiri, sehingga membentuk struktur yang fleksibel dan dinamis. Struktur ini banyak digunakan dalam kasus nyata seperti: data pegawai–anak, kategori–subkategori, fakultas–jurusan–prodi, hingga graph bertingkat.

Penelitian dari **Universitas Gadjah Mada (UGM)** menyatakan bahwa struktur data bertingkat seperti Multi Linked List mampu mengurangi redundansi data dan meningkatkan efisiensi pencarian pada data relasional kompleks [1]. Selain itu, riset dari **Universitas Negeri Semarang (UNNES)** menunjukkan bahwa linked list memiliki keunggulan dalam manajemen memori karena alokasi dilakukan secara dinamis dan tidak menyebabkan pemborosan seperti array statis [2].

### A. Multi Linked List

#### 1. Pengertian

Multi Linked List adalah struktur data yang terdiri dari beberapa linked list yang saling terhubung. Biasanya terdapat **list induk**, yang setiap elemennya memiliki pointer menuju **list anak**. Hubungan ini membentuk struktur *one-to-many*, di mana satu induk dapat memiliki banyak anak.

Struktur ini mempermudah representasi data bertingkat, karena setiap node induk dapat menyimpan list-nya sendiri tanpa harus membuat struktur array dua dimensi yang kaku.

#### 2. Komponen Utama MLL

* **Node Induk** → menyimpan data utama serta memiliki pointer menuju awal list anak.
* **Node Anak** → menyimpan data yang terkait dengan node induk.
* **List Induk** → menyimpan seluruh elemen induk.
* **List Anak** → berada di dalam setiap elemen induk.
* **Pointer next/prev** → seperti pada singly/doubly linked list.

#### 3. Kelebihan MLL

* Dapat merepresentasikan data hierarki dengan sangat fleksibel.
* Tidak memerlukan ukuran tetap seperti array.
* Mudah dikembangkan – setiap node dapat memiliki list anak tanpa membatasi ukuran.
* Operasi insert/delete tidak membutuhkan shifting elemen.

#### 4. Kekurangan MLL

* Manajemen pointer lebih kompleks.
* Membutuhkan memori lebih besar karena setiap node membawa pointer tambahan.
* Debugging lebih sulit karena struktur bertingkat.

### B. Operasi pada Multi Linked List

Operasi pada Multi Linked List hampir sama dengan operasi pada linked list biasa, namun dengan tambahan proses yang harus memperhatikan hubungan induk–anak.

#### 1. Operasi Insert

Operasi insert terbagi menjadi dua:

* **Insert Induk** → dilakukan seperti insert pada singly/doubly linked list.
* **Insert Anak** → harus mengetahui node induk terlebih dahulu. Setelah induk ditemukan, anak baru disisipkan pada awal, tengah, atau akhir list anak.

Proses insert meliputi:

* Alokasi memori node baru
* Menentukan posisi disisipkan
* Mengatur pointer next/prev

Penelitian dari UGM menyebutkan bahwa model insert bertingkat seperti ini meningkatkan efisiensi organisasi data terutama pada sistem manajemen basis data kecil–menengah [1].

#### 2. Operasi Delete

Penghapusan pada MLL juga terbagi dua:

* **Delete Anak** → menghapus node anak tertentu dari list anak milik induk.
* **Delete Induk** → menghapus node induk sekaligus *seluruh list anak* yang dimilikinya.

Operasi delete harus memperhatikan pointer sebelum dan sesudah node yang dihapus. Jika induk dihapus, seluruh anak miliknya harus didealokasikan agar tidak terjadi memory leak.

#### 3. Traversal & Pencarian

Traversal MLL dilakukan dengan cara:

1. Mengiterasi semua node induk.
2. Untuk setiap induk, mengiterasi list anaknya.

Fungsi pencarian dilakukan pada induk untuk menemukan node berdasarkan informasi tertentu, lalu mencari anak pada list anak milik induk tersebut.

#### 4. Penggunaan MLL dalam Dunia Nyata

MLL sering digunakan untuk struktur data yang bersifat bertingkat, misalnya:

* Data keluarga → orang tua (induk) dan anak (child)
* Organisasi → departemen dan karyawan
* Fakultas → jurusan → program studi
* Aplikasi e-commerce → kategori dan subkategori produk
  . Multi Linked List

## Guided 

### 1. mll.h

```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```
Penjelasan: File **mll.h** berfungsi sebagai blueprint atau rancangan struktur data yang digunakan dalam program Multi Linked List. Di dalamnya terdapat deklarasi struct untuk *parent* (kategori makanan) dan *child* (makanan), beserta list ganda (double linked list) yang menghubungkan setiap elemen. Selain struktur data, file ini juga berisi deklarasi fungsi-fungsi penting seperti membuat list, pengecekan list kosong, alokasi dan dealokasi node, operasi insert, delete, update, pencarian data, serta prosedur untuk menampilkan isi list. Fungsi-fungsi ini belum memiliki isi, hanya berupa deklarasi agar dapat dipanggil oleh file `.cpp`. Dengan kata lain, file `mll.h` adalah peta konsep yang menjelaskan apa saja yang bisa dilakukan program, sehingga file lain mengetahui struktur dan fungsi yang digunakan.

### 2. mll.cpp

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```
Penjelasan: File **mll.cpp** merupakan tempat implementasi seluruh fungsi yang sebelumnya dideklarasikan di header `mll.h`. File ini memuat kode lengkap cara kerja setiap operasi MLL, seperti bagaimana menambahkan node parent atau child di awal, akhir, atau setelah node tertentu, bagaimana menghapus parent dan child beserta seluruh daftar anaknya, serta bagaimana melakukan pencarian dan perubahan data berdasarkan ID yang dimasukkan. Di bagian ini program benar-benar menjalankan logika untuk mengatur hubungan data parent–child menggunakan konsep double linked list. Selain itu, fungsi print disediakan untuk menampilkan struktur MLL dengan rapi dan lengkap. Secara keseluruhan, file `mll.cpp` merupakan “otak” program yang membuat semua fitur berjalan.

### 3. main.cpp

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Penjelasan: ile **main.cpp** adalah pusat eksekusi program yang memanggil semua fungsi dari MLL untuk melakukan simulasi nyata terkait data kategori dan menu makanan. Dalam file ini dibuat beberapa node parent (kategori makanan), kemudian setiap parent diisi beberapa node child (makanan). Program menampilkan struktur awal menu, melakukan pencarian data, melakukan update nama kategori dan data makanan, menghapus beberapa node child dan parent tertentu, serta menampilkan hasil akhir setelah proses penghapusan. Dengan kata lain, `main.cpp` menjadi demonstrasi lengkap cara menggunakan seluruh fungsi MLL sehingga dapat melihat hasil nyata seperti pada tugas atau modul. File ini juga membantu memahami alur kerja MLL dari tahap pembuatan, pengisian, pencarian, update, sampai penghapusan data.

## Unguided 

## **1**

Buatlah program *Multi Linked List* dengan ketentuan sebagai berikut:

1. Terdapat **List Parent** yang menyimpan data:

   * ID Golongan
   * Nama Golongan

2. Terdapat **List Child** yang menyimpan data:

   * ID Hewan
   * Nama Hewan
   * Habitat
   * Ekor (0 = tidak ada, 1 = ada)
   * Bobot

3. Implementasikan fungsi-fungsi berikut:

   * `createListParent()`
   * `createListChild()`
   * `allocNodeParent()`
   * `allocNodeChild()`
   * `insertFirstParent()` / `insertLastParent()`
   * `insertFirstChild()` / `insertLastChild()`
   * `deleteAfterParent()`
   * `deleteAfterChild()`
   * `deleteListChild()`
   * `printMLLStructure()`
   * `searchHewanByEkor()`

Buat struktur program sesuai **contoh format tampilan** di modul.


## **2**

Gunakan data berikut untuk mengisi Multi Linked List:

### **A. Data Parent (Golongan Hewan)**

| ID Golongan | Nama Golongan |
| ----------- | ------------- |
| G001        | Aves          |
| G002        | Mamalia       |
| G003        | Pisces        |
| G004        | Amfibi        |
| G005        | Reptil        |

### **B. Data Child**

#### **1. Parent G001 – Aves**

| ID Hewan | Nama Hewan  | Habitat | Ekor | Bobot |
| -------- | ----------- | ------- | ---- | ----- |
| AV001    | Cendrawasih | Hutan   | 1    | 0.3   |
| AV002    | Bebek       | Air     | 1    | 2     |

#### **2. Parent G002 – Mamalia**

| ID Hewan | Nama Hewan | Habitat | Ekor | Bobot |
| -------- | ---------- | ------- | ---- | ----- |
| M001     | Harimau    | Hutan   | 1    | 200   |
| M003     | Gorila     | Hutan   | 0    | 160   |
| M002     | Kucing     | Darat   | 1    | 4     |

#### **3. Parent G004 – Amfibi**

| ID Hewan | Nama Hewan | Habitat | Ekor | Bobot |
| -------- | ---------- | ------- | ---- | ----- |
| AM001    | Kodok      | Sawah   | 0    | 0.2   |

#### **4. Parent G003 – Pisces**

Tidak memiliki child.

#### **5. Parent G005 – Reptil**

Tidak memiliki child.

---

## **3**

Lakukan operasi berikut:

1. **Tampilkan seluruh struktur Multi Linked List**
   Gunakan fungsi `printMLLStructure()`
   Format tampilan **harus sama seperti contoh** di Modul Latihan:

   ```
   === Parent 1 ===
   ID Golongan : ...
   Nama Golongan : ...
   - Child 1 :
     ID Hewan : ...
     ... dst.
   -----------------------------
   ```

2. **Cari hewan dengan ekor = 0**
   Gunakan fungsi:

   ```
   searchHewanByEkor(false)
   ```

   Tampilkan data sesuai format modul:

   ```
   Data ditemukan pada list anak dari node parent ...
   --- Data Child ---
   ...
   --- Data Parent ---
   ...
   ```

3. **Hapus Parent dengan ID = G004 (Amfibi)**
   Gunakan `deleteAfterParent()` sesuai posisi parent G004.

4. **Tampilkan kembali struktur Multi Linked List** setelah penghapusan G004.


### 📄 File: `MultiLL.h`

```C++
#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED
#include <iostream>
using namespace std;

// ======================= STRUCT =======================

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

// ======================= DEKLARASI =======================

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```

### 📄 File: `MultiLL.cpp`

```C++
#include "MultiLL.h"

// ===================== LIST CHECK ==========================

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

// ===================== CREATE LIST ==========================

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

// ===================== ALOKASI ===============================

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent N = new nodeParent;
    N->isidata.idGolongan = idGol;
    N->isidata.namaGolongan = namaGol;
    N->next = NULL;
    N->prev = NULL;
    createListChild(N->L_Child);
    return N;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

// ===================== DEALOKASI =============================

void deallocNodeParent(NodeParent &NParent) { delete NParent; }
void deallocNodeChild(NodeChild &NChild) { delete NChild; }

// ===================== INSERT PARENT =========================

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNParent);
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

// ===================== DELETE PARENT =========================

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = del->next;
            LParent.first->prev = NULL;
        }
        deleteListChild(del->L_Child);
        delete del;
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;

        NPrev->next = del->next;

        if (del == LParent.last) {
            LParent.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        deleteListChild(del->L_Child);
        delete del;
    }
}

// ===================== INSERT CHILD ==========================

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNChild);
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

// ===================== DELETE CHILD ==========================

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = del->next;
            LChild.first->prev = NULL;
        }
        delete del;
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;
        NPrev->next = del->next;

        if (del == LChild.last) {
            LChild.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        delete del;
    }
}

// ===================== DELETE ALL CHILD ======================

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

// ===================== PRINT MLL ==============================
// 🟢 FORMAT 100% SAMA PERSIS DENGAN MODUL
void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int parentIndex = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentIndex << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int childIndex = 1;
            while (C != NULL) {
                cout << "- Child " << childIndex << " :" << endl;
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "  Habitat : " << C->isidata.habitat << endl;
                cout << "  Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "  Bobot : " << C->isidata.bobot << endl;
                childIndex++;
                C = C->next;
            }
        }

        cout << "-----------------------------" << endl;
        parentIndex++;
        P = P->next;
    }
}

// ===================== SEARCH EKOR ============================
// 🟢 FORMAT 100% SAMA PERSIS DENGAN MODUL
void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int parentIndex = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childIndex = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << parentIndex << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childIndex << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "-----------------------------" << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentIndex << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "-----------------------------" << endl;
            }
            childIndex++;
            C = C->next;
        }

        parentIndex++;
        P = P->next;
    }
}
```

### 📄 File: `main.cpp`

```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    // INSERT PARENT
    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    // INSERT CHILD
    NodeParent P = LP.first; // G001
    insertLastChild(P->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    P = P->next; // G002
    insertLastChild(P->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    P = P->next->next; // G004
    insertLastChild(P->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // PRINT SEBELUM DELETE
    printMLLStructure(LP);

    // SEARCH EKOR = FALSE
    searchHewanByEkor(LP, false);

    // DELETE G004
    NodeParent deleteNode = LP.first->next->next->next; // G004
    deleteAfterParent(LP, deleteNode->prev);

    // PRINT SETELAH DELETE
    printMLLStructure(LP);

    return 0;
}
```

### Output Unguided  :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL13/imagesmodul13/output1_unguided_modul13.png)

![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL13/imagesmodul13/output2_unguided_modul13.png)

![Screenshot Output Unguided 1_3](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL13/imagesmodul13/output3_unguided_modul13.png)

Penjelasan : Program Multi Linked List ini dibangun menggunakan tiga file utama, yaitu `MultiLL.h`, `MultiLL.cpp`, dan `main.cpp`. Pada `MultiLL.h`, didefinisikan seluruh struktur data yang diperlukan untuk membuat hubungan antara *parent* (golongan hewan) dan *child* (data hewan), lengkap dengan atribut masing-masing serta deklarasi fungsi-fungsi pengelolaan list, seperti pembuatan list, pengecekan kondisi kosong, alokasi, dealokasi, insert, delete, hingga pencarian dan pencetakan struktur multi list. File `MultiLL.cpp` menjadi tempat implementasi semua fungsi tersebut, di mana setiap operasi dijalankan secara detail—misalnya proses menambah parent atau child di awal/akhir list, menghapus node beserta seluruh child di dalamnya, menampilkan isi struktur secara rapi sesuai format modul praktik, serta melakukan pencarian hewan berdasarkan kondisi ekor (true/false). Sementara itu, `main.cpp` berfungsi sebagai penggerak utama program yang memanfaatkan semua fungsi dalam MLL untuk membuat data nyata: mulai dari membuat lima golongan hewan sebagai parent, mengisi masing-masing dengan data hewan sesuai kategori, menampilkan struktur MLL sebelum dan sesudah penghapusan data, melakukan pencarian berdasarkan atribut ekor, serta mempraktikkan operasi delete pada salah satu parent. Secara keseluruhan, ketiga file bekerja bersama membentuk sistem Multi Linked List yang menggambarkan hubungan hierarki golongan hewan dan data hewan secara terstruktur, dinamis, dan sesuai format modul.

## Kesimpulan
Multi Linked List merupakan struktur data yang dirancang untuk merepresentasikan hubungan bertingkat antara data induk dan data anak secara efisien. Melalui struktur ini, penyimpanan data menjadi lebih fleksibel karena setiap elemen induk dapat memiliki list anak sendiri tanpa batasan ukuran yang kaku. Operasi dasar seperti penyisipan, penghapusan, dan pencarian tetap dapat dilakukan dengan efektif selama pengelolaan pointer dilakukan secara tepat. Praktikum ini menunjukkan bahwa Multi Linked List mampu menangani data kompleks yang memiliki relasi hirarkis, sekaligus menjaga efisiensi memori melalui alokasi dinamis. Struktur ini relevan digunakan dalam berbagai konteks nyata seperti sistem organisasi, data keluarga, maupun representasi kategori–subkategori. Dengan memahami implementasi MLL, mahasiswa dapat mengembangkan kemampuan dalam merancang struktur data yang lebih adaptif dan sesuai kebutuhan aplikasi modern.

## Referensi
[1] IJEIS – Indonesian Journal of Electronics and Instrumentation Systems, Universitas Gadjah Mada (UGM). "Hierarchical Data Structure Optimization", 2022.

[2] IJCETS – Indonesian Journal of Curriculum and Educational Technology Studies, Universitas Negeri Semarang (UNNES). "Efficiency Analysis of Dynamic Linked Structure", 2021.

[3] Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), Universitas Brawijaya. "Analisis Struktur Data Linked List dalam Pengelolaan Data Hierarkis", 2020.

[4] Jurnal Sistem dan Informatika, Institut Teknologi Sepuluh Nopember (ITS). "Penggunaan Multi-Linked List pada Representasi Data Kompleks", 2021.

[5] Jurnal Ilmu Komputer dan Agri-Informatika (JIKA), Institut Pertanian Bogor (IPB). "Optimasi Struktur Data Dinamis Berbasis Pointer", 2019.
<br>...
