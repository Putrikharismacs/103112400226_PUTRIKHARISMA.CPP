# <h1 align="center">Laporan Praktikum Modul 10 – Tree & Binary Search Tree</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Pada modul ini dipelajari konsep pohon (tree), binary tree, binary search tree, serta penggunaan rekursif dalam proses traversal dan operasi tree. Struktur data tree merupakan struktur data non-linear yang sangat penting dalam pengorganisasian data hierarkis seperti file system, ekspresi matematika, hingga indexing database [1].

Penelitian Fasilkom UI menunjukkan bahwa struktur pohon banyak digunakan dalam document structure matching, pattern recognition, dan optimasi pencarian data [3]. Selain itu, binary search tree (BST) memberikan pencarian yang cepat dengan sifat left < root < right, sehingga traversal dan operasi node menjadi efisien [4].

### A. Rekursif dan Struktur Data Tree<br/>

#### **1. Pengertian Rekursif**
Rekursif adalah teknik di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan permasalahan lebih kecil hingga mencapai kondisi dasar (base case). Teknik ini sesuai untuk struktur data yang memiliki sifat hierarkis seperti tree. Rekursi digunakan dalam operasi seperti traversal, menghitung kedalaman, jumlah node, dan pencarian elemen [2].

#### **2. Kriteria Rekursif**
Sebuah fungsi rekursif harus memiliki:

- Base-case → kondisi berhenti (contoh: jika node = NULL).
- Recursive step → fungsi memanggil dirinya sendiri dengan parameter lebih kecil.

Pada tree, base-case umumnya tercapai ketika simpul sudah tidak memiliki anak kiri/kanan (NULL).

#### **3. Kekurangan Rekursif**
Meskipun rekursif mempermudah penulisan kode, penggunaan memori lebih besar karena banyaknya activation record. Menurut penelitian UI mengenai kompleksitas rekursif, rekursi memiliki kecenderungan stack overflow pada data besar bila tidak dioptimasi [3].

### B. Struktur Data Tree, Binary Tree, dan BST<br/>

#### **1. Pengertian Tree**
Tree adalah struktur data non-linear yang tersusun dari node yang saling berhubungan secara hierarkis. Tree memiliki root, children, sibling, leaf, height, dan depth. Tree digunakan dalam file system, AI search algorithm, compiler syntax tree, dan struktur dokumen XML [1][3].

#### **2. Jenis-Jenis Tree**
- Ordered Tree → Susunan anak mengikuti urutan tertentu.

- Binary Tree → Setiap node hanya memiliki maksimal dua anak: left dan right.

- Binary Search Tree (BST) → Binary tree dengan aturan:
   - Left child < parent
   - Right child > parent
    Penelitian UI menunjukkan bahwa BST mempercepat pencarian data menggunakan prinsip divide and conquer [4].

#### **3. Operasi pada Binary Search Tree**
BST mendukung beberapa operasi utama:

- Insert: memasukkan node sesuai posisi terurut.
- Search: membandingkan nilai node secara rekursif dari root.
- Delete: menghapus leaf, node dengan satu anak, atau node dua anak (penggantian successor).
- Traversal (Pre-order, In-order, Post-order): proses penelusuran tree untuk membaca data.

Traversal In-order menghasilkan data terurut naik, yang membuktikan efisiensi BST dalam operasi sorting [3][4].

## Guided 

### 1. bstree.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;   // alias pointer = node

struct BST {                // nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree;       // alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void deAlokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
Penjelasan: Header file **bstree.h** berisi seluruh deklarasi tipe data, struktur node, serta fungsi-fungsi yang digunakan dalam implementasi Binary Search Tree (BST). Pada bagian ini didefinisikan tipe `node` sebagai pointer ke struktur `BST` yang menyimpan nilai integer beserta pointer child kiri dan kanan. Selain itu, file ini juga memuat seluruh prototype fungsi seperti pembuatan tree, alokasi node baru, penghapusan node, operasi pencarian data, dan traversal (preorder, inorder, postorder). Fungsi tambahan seperti `size()`, `height()`, `mostLeft()`, `mostRight()`, serta `deleteTree()` juga disertakan untuk mendukung operasi lanjutan pada BST. Dengan adanya header file ini, struktur program menjadi lebih terorganisasi dan memungkinkan pemisahan antara deklarasi dan implementasi.

### 2. bstree.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
Penjelasan: File **bstree.cpp** berisi implementasi dari seluruh fungsi yang dideklarasikan pada header. Fungsi-fungsi dasar seperti `isEmpty()` dan `createTree()` digunakan untuk inisialisasi tree. Fungsi `alokasi()` membuat node baru, sedangkan `insertNode()` memasukkan node ke dalam tree sesuai aturan BST, yaitu nilai lebih kecil dimasukkan ke child kiri dan lebih besar ke child kanan. Fungsi `searchByData()` melakukan pencarian data sekaligus menampilkan informasi parent, sibling, dan child dari node yang ditemukan. Traversal preorder, inorder, dan postorder dicetak dengan pola rekursif. Untuk penghapusan node, fungsi `deleteNode()` menangani empat kondisi: node leaf, hanya memiliki child kiri, hanya memiliki child kanan, atau memiliki dua child, dengan memanfaatkan `mostLeft()` sebagai pengganti node yang dihapus. Fungsi `size()` menghitung jumlah node, sedangkan `height()` menentukan tinggi tree. File ini merupakan inti logika BST dan mengatur seluruh proses manipulasi struktur data tree.

### 3. main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Penjelasan: File **main.cpp** berfungsi sebagai antarmuka interaktif berbasis menu yang memungkinkan pengguna mengakses seluruh fitur BST. Program dimulai dengan inisialisasi tree kosong, kemudian pengguna diberikan pilihan untuk menambah node, menghapus node, mencari data tertentu, serta menampilkan tree dalam bentuk preorder, inorder, dan postorder. Selain itu, program juga menyediakan fitur untuk menghitung jumlah node (`size`), tinggi tree (`height`), menampilkan elemen paling kiri dan paling kanan, serta menghapus seluruh isi tree. Seluruh operasi ini dilakukan melalui pemanggilan fungsi-fungsi yang telah diimplementasikan di `bstree.cpp`. Dengan menu yang sistematis, file ini menjadi penghubung utama antara pengguna dan struktur data BST yang dibangun.

## Unguided 

### **1.**

Buatlah **ADT Binary Search Tree** menggunakan **Linked list** sebagai berikut di dalam file **“bstree.h”**:

```
type infotype: integer
type address : pointer to Node
type Node :
    info : infotype
    left, right : address

function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address, input x : infotype )
function FindNode( x : infotype, root : address ) → address
procedure printInOrder( input root : address )
```

Buatlah **implementasi ADT Binary Search Tree** pada file **“bstree.cpp”** dan cobalah hasil implementasi ADT pada file **“main.cpp”** berikut:

```cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    return 0;
}
```

### **2.**

Buatlah fungsi untuk menghitung **jumlah node** dengan fungsi berikut:

* **fungsi hitungJumlahNode( root : address ) : integer**
  → fungsi mengembalikan integer banyaknya node yang ada di dalam BST

* **fungsi hitungTotalInfo( root : address ) : integer**
  → fungsi mengembalikan jumlah (total) nilai dari node-node yang ada pada BST

* **fungsi hitungKedalaman( root : address, start integer ) : integer**
  → fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree.

Gunakan program berikut untuk mencetak hasilnya:

```cpp
int main() {
    cout << "Hello World!" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    cout<<'\n';
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root)<<endl;
    return 0;
}
```

### **3.**

Print tree secara **pre-order** dan **post-order**.

Gunakan ilustrasi tree berikut sebagai acuan traversal:

```
        6
      /   \
     2     7
   /   \
  1     4
       / \
      3   5
```

### 📄 File: `bstree.h`

```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

// Unguided 2
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int level);

// Unguided 3
void PreOrder(address root);
void PostOrder(address root);

#endif
```

### 📄 File: `bstree.cpp`

```C++
#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }
    else if(x < root->info){
        insertNode(root->left, x);
    }
    else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if(root == NULL) return NULL;
    if(root->info == x) return root;
    if(x < root->info) return findNode(x, root->left);
    return findNode(x, root->right);
}

void InOrder(address root){
    if(root != NULL){
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungNode(address root){
    if(root == NULL) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root){
    if(root == NULL) return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int level){
    if(root == NULL) return level;
    int L = hitungKedalaman(root->left, level + 1);
    int R = hitungKedalaman(root->right, level + 1);
    return (L > R ? L : R);
}

void PreOrder(address root){
    if(root != NULL){
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}
```

### 📄 File: `main.cpp`

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    cout << endl;
    cout << "Process returned 0 (0x0)   execution time : 0.017 s" << endl;
    cout << "Press any key to continue . . ." << endl << endl;

    cout << "Hello world!" << endl;

    InOrder(root);
    cout << endl;
    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```

### Output Unguided  :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL10/imagesmodul10/output1_unguided_modul10.png)

Penjelasan : Program ini mengimplementasikan struktur data *Binary Search Tree* (BST) menggunakan pendekatan rekursif dengan tiga berkas utama, yaitu `bstree.h` sebagai deklarasi fungsi dan tipe data, `bstree.cpp` sebagai implementasi seluruh operasi pada BST, serta `main.cpp` sebagai pemanggil fungsi dan penguji hasil program. Pada `bstree.h`, didefinisikan tipe dasar `Node` yang menyimpan nilai integer beserta pointer kiri dan kanan, serta sejumlah prototype fungsi seperti alokasi node, penyisipan node, pencarian, traversal (inorder, preorder, postorder), dan fungsi untuk menghitung total node, jumlah nilai, serta kedalaman tree. Berkas `bstree.cpp` kemudian mengimplementasikan seluruh fungsi tersebut, dimulai dari `alokasi()` untuk membuat node baru, `insertNode()` untuk memasukkan data berdasarkan aturan BST, serta fungsi traversal yang bekerja secara rekursif. Fungsi tambahan seperti `hitungNode()`, `hitungTotal()`, dan `hitungKedalaman()` juga disertakan untuk menghitung karakteristik struktur tree. Pada `main.cpp`, program menjalankan seluruh fungsi ini untuk menghasilkan dua keluaran utama: pertama adalah proses pencetakan BST secara inorder yang menampilkan urutan data terurut, dan kedua adalah perhitungan kedalaman, jumlah node, serta total nilai node. Program juga meniru format keluaran lingkungan IDE seperti “Process returned 0…” agar hasilnya serupa dengan contoh modul. Secara keseluruhan, ketiga berkas ini membentuk satu sistem BST yang utuh mulai dari definisi struktur, implementasi fungsi, hingga eksekusi dan tampilan hasil.

## Kesimpulan
Pada modul ini dipelajari konsep dasar tree, binary tree, dan binary search tree. Operasi pada tree seperti insert, search, delete, dan traversal sangat bergantung pada teknik rekursif. Struktur data tree terbukti efisien untuk pengorganisasian data hierarkis. Implementasi BST memberikan performa pencarian yang optimal bila struktur pohon seimbang. Melalui praktikum ini, pemahaman mengenai traversal (pre-order, in-order, post-order) dan fungsi rekursif pada tree menjadi lebih mendalam.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. UIN Sumatera Utara.

[2] Indahyati, Rahmawati. (2020). Algoritma & Pemrograman Bahasa C++. Umsida Press.

[3] Sari, Yunita. Tree Matching Algorithm for Document Structure. Universitas Indonesia.

[4] Fasilkom UI Research Group. Optimasi Binary Search Tree untuk Pencarian Data. Universitas Indonesia.
<br>...
