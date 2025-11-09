# <h1 align="center">Laporan Praktikum Modul 7 – Stack</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Stack merupakan struktur data linear yang menggunakan prinsip **LIFO (Last In First Out)**, yaitu data yang terakhir dimasukkan (push) akan menjadi data pertama yang dikeluarkan (pop). Dalam dunia komputasi modern, struktur data ini digunakan pada manajemen memori (stack frame), proses *undo-redo*, kompilasi program, penyusunan ekspresi matematika, serta berbagai algoritma *backtracking* [1].

Stack hanya memiliki satu titik akses, yaitu **TOP**, yang menunjukkan elemen paling atas di dalam stack. Representasi stack dapat dibuat dengan dua cara, yaitu:

1. **Representasi Pointer (Linked List)**
2. **Representasi Array (Tabel)**

Masing-masing memiliki kelebihan:

* **Pointer** fleksibel dalam ukuran,
* **Array** lebih cepat diakses karena indeks stabil di memori.

### A. Konsep dan Karakteristik Doubly Linked List<br/>

Pada representasi pointer, setiap elemen stack direpresentasikan sebagai node yang memiliki:

* **info** → data yang disimpan
* **next** → pointer ke node berikutnya

Elemen paling atas ditunjukkan oleh variabel **Top**. Penambahan dan penghapusan data hanya dapat dilakukan melalui node Top, sehingga operasi lebih efisien dibandingkan operasi pada tengah list [2].

#### **1. Push (Penyisipan)**

Operasi *push* bertujuan menambahkan elemen baru ke paling atas.
Langkah-langkah:

1. Alokasi node baru
2. Isi nilai info
3. Hubungkan node baru ke Top sebelumnya
4. Perbarui Top ke node baru

#### **2. Pop (Penghapusan)**

Operasi *pop* menghapus elemen paling atas.
Langkah:

1. Simpan node Top ke variabel sementara
2. Geser Top ke next
3. Kembalikan node yang di-pop

### B. Stack Menggunakan Array<br/>

Pada representasi tabel (array), stack dideklarasikan menggunakan **array berindeks** dan integer **Top** untuk menunjukkan posisi elemen terakhir.

Contoh struktur dasar:

* info[20] → array berisi elemen stack
* Top → penunjuk indeks elemen paling atas

Keunggulan cara ini adalah akses cepat, namun ukuran stack bersifat **statis** (fixed size) [3].

#### **1. Push**

Operasi push dilakukan dengan:

* Menaikkan nilai Top
* Menempatkan elemen pada info[Top]

#### **2. Pop**

Operasi pop dilakukan dengan:

* Menyimpan nilai info[Top]
* Mengurangi nilai Top

### C. Primitif-primitif pada Stack<br/>

Baik pada representasi pointer maupun array, stack memiliki beberapa operasi dasar:

#### **1. createStack()**

Digunakan untuk menginisialisasi stack awal.

* Pointer → Top = NULL
* Array → Top = 0

#### **2. isEmpty()**

Mengecek apakah stack kosong.
Mengembalikan true jika Top tidak berisi elemen.

#### **3. push()**

Menambahkan elemen baru ke atas stack.

#### **4. pop()**

Menghapus elemen paling atas dan mengembalikannya.

#### **5. printInfo()**

Menampilkan seluruh isi stack dari elemen paling atas ke paling bawah.

#### **6. balikStack()**

Prosedur tambahan yang membalik urutan elemen stack.
Biasanya dilakukan dengan membuat stack sementara, mem-pop semua data, lalu mem-push ulang ke stack baru.

---

### D. Penerapan Stack dalam Dunia Nyata<br/>

Beberapa implementasi nyata stack meliputi:

* **Undo/Redo** pada aplikasi
* **Penyusunan ekspresi aritmatika (postfix/prefix)**
* **Backtracking (DFS, pencarian labirin)**
* **Pemanggilan fungsi (Call Stack)**
* **Kompiler (penyocokan tanda kurung)** [4][5]


## Guided 

### Guided 1

### 1. stack.h

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
Penjelasan: File *stack.h* berfungsi sebagai deklarasi struktur data dan fungsi-fungsi yang digunakan dalam implementasi stack berbasis *linked list*. Pada bagian awal, tipe data `address` didefinisikan sebagai pointer yang menunjuk ke struktur `node`, yang menyimpan data bilangan bulat serta pointer ke elemen berikutnya. Struktur `stack` hanya memiliki satu elemen penting yaitu `top`, yang menunjuk elemen paling atas dari stack. Selain itu, diberikan pula deklarasi fungsi-fungsi dasar seperti `createStack`, `isEmpty`, `alokasi`, dan `dealokasi` yang menangani manajemen memori, serta fungsi-fungsi utama yaitu `push`, `pop`, `update`, `view`, dan `searchData`. Berkas ini memastikan bahwa seluruh operasi yang berkaitan dengan stack memiliki antarmuka yang seragam sebelum diimplementasikan secara lebih detail dalam file *stack.cpp*.

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
Penjelasan: File *stack.cpp* berisi implementasi seluruh fungsi yang telah dideklarasikan dalam *stack.h*. Fungsi `isEmpty` memeriksa apakah stack kosong dengan melihat nilai pointer `top`, sedangkan `createStack` menginisialisasi stack baru. Fungsi `alokasi` dan `dealokasi` bertanggung jawab mengelola memori dinamis untuk node baru. Operasi `push` menambahkan node baru pada bagian paling atas, sedangkan `pop` menghapus node teratas dan melepaskan memorinya. Fungsi `update` memberikan kemampuan untuk memperbarui nilai elemen pada posisi tertentu, sementara `view` digunakan untuk menampilkan seluruh isi stack dari atas ke bawah. Terakhir, fungsi `searchData` memungkinkan pencarian nilai tertentu pada seluruh elemen stack. Implementasi ini menunjukkan bagaimana stack dapat dikelola menggunakan struktur *linked list* dengan operasi yang efisien.

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Penjelasan: File *main.cpp* berfungsi sebagai program utama yang menguji seluruh fungsi stack berbasis *linked list* yang telah dibuat. Program diawali dengan membuat stack baru dan mengalokasikan lima node, masing-masing berisi nilai 1 hingga 5, kemudian mendorongnya (push) ke dalam stack. Setelah itu, program menampilkan isi stack, menghapus dua elemen teratas dengan operasi pop, dan kembali menampilkan kondisi stack setelah perubahan terjadi. Program juga menguji fungsi update untuk beberapa posisi berbeda, termasuk posisi yang valid dan tidak valid, sehingga terlihat bagaimana fungsi menangani kedua kondisi tersebut. Terakhir, dilakukan pencarian nilai tertentu di dalam stack untuk melihat apakah data tersebut ditemukan atau tidak. Melalui pengujian lengkap di dalam fungsi main, pengguna dapat memahami secara menyeluruh cara kerja operasi-operasi stack menggunakan *linked list*.

### Guided 2

### 1. stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
Penjelasan: File *stack.h* pada Guided 2 mendefinisikan struktur stack menggunakan pendekatan berbasis array atau *representasi tabel*. Stack direpresentasikan dengan array `data[MAX]` dengan kapasitas tertentu dan variabel `top` yang menyimpan indeks elemen paling atas. Selain struktur, file ini juga memuat deklarasi fungsi-fungsi untuk memeriksa kondisi stack (`isEmpty` dan `isFull`), menginisialisasi stack (`createStack`), serta operasi-operasi utama seperti `push`, `pop`, `update`, `view`, dan `searchData`. Dengan pendekatan array ini, seluruh elemen berada pada lokasi memori berurutan, sehingga akses data lebih cepat dibandingkan metode pointer. File header ini memastikan semua operasi memiliki definisi yang jelas sebelum diimplementasikan pada file *stack.cpp*.

### 2. stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    if(s.top == -1){
        return true;
    } else {
        return false;
    }
    //return s.top == -1;
}

bool isFull(stackTable s){
    if(s.top == MAX - 1){
        return true;
    } else {
        return false;
    }
    //return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s) == true){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    
    }
    if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
            return;
    }

    //indek = top - (posisi + 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << "tidak valid!" << endl;
        return;
    }

    cout << "update data pposisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << "Posisi " << (s.top - i + 1) << " : " << s.data[i] << endl;
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << " dalam stack..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
         if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << (s.top - i + 1) << endl;
            found = true;
            break;
            }
            posisi++;
        }

        if(!found){
            cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
            cout << endl;
        }
    }
```
Penjelasan: Pada *stack.cpp*, seluruh fungsi terkait stack berbasis array diimplementasikan secara rinci. Fungsi `isEmpty` dan `isFull` mengevaluasi kondisi stack berdasarkan nilai indeks `top`. Fungsi `createStack` menginisialisasi stack dalam kondisi kosong dengan menetapkan `top = -1`. Operasi `push` menambahkan data pada indeks teratas apabila kapasitas masih tersedia, sedangkan `pop` menghapus elemen paling atas dan menurunkan nilai `top`. Fungsi `update` memberikan kemampuan untuk mengganti data pada posisi tertentu yang dihitung dari posisi teratas (1-based), memastikan validasi indeks dilakukan dengan tepat. Fungsi `view` menampilkan isi stack beserta posisi setiap datanya, sedangkan `searchData` mencari keberadaan elemen dalam stack dengan mengiterasi seluruh data dari atas ke bawah. Implementasi ini memperlihatkan bagaimana stack dapat dibangun secara efisien menggunakan array dengan batas kapasitas tetap.

### 3. main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //posisi dihitung dari Top (1-based)

    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Penjelasan: File *main.cpp* digunakan sebagai bagian pengujian fungsi-fungsi stack berbasis array. Program dimulai dengan inisialisasi stack, dilanjutkan dengan memasukkan lima elemen menggunakan operasi push. Kondisi stack kemudian ditampilkan untuk menunjukkan susunan awal elemen. Dua operasi pop dijalankan untuk menghapus elemen teratas dan memastikan perubahan tersebut tercermin pada tampilan stack berikutnya. Program juga menguji operasi update pada beberapa posisi, baik posisi yang valid maupun yang tidak valid, sehingga terlihat bagaimana fungsi menolak atau menerima perubahan data berdasarkan validitas indeks. Terakhir, fungsi searchData diuji untuk mengetahui apakah suatu nilai dapat ditemukan dalam stack. Pengujian menyeluruh dalam main ini memberikan gambaran jelas mengenai proses manipulasi data pada stack berbasis array.

## Unguided 

### 1. Soal Unguided 

1.  Buatlah ADT Stack menggunakan ARRAY sebagai berikut didalam file “stack.h”:
```C++
  Typeinfotype: integer
 TypeStack<
 info: array [20]ofinteger
 top: integer
 >
 procedure CreateStack( input/outputS :Stack)
 procedure push(input/output S: Stack,
 inputx: infotype)
 functionpop(input/output tS: Stack)
 →infotype
 procedure printInfo(inputS :Stack)
 procedure balikStack(input/outputS:
 Stack)
```
Buatlah implementasi ADT Stack menggunakan Array pada ile “stack.cpp” dan “main.cpp”
 ```C++
  intmain()
 {
 cout <<"Hello world!"<<
 endl;
 StackS;
 createStack(S);
 Push(S,3);
 Push(S,4);
 Push(S,8);
 pop(S)
 Push(S,2);
 Push(S,3);
 pop(S);
 Push(S,9);
 printInfo(S);
 cout<<"balikstack"<<endl;
 balikStack(S);
 printInfo(S);
 return0;
 }
 ```

CONTOH OUTPUT :
```bash
Hello world!
[TOP] 9 2 4 3 
balik stack
[TOP] 3 4 2 9
```
2. Tambahkan prosedur pushAscending (in/out S:Stack,in x:integer)
```C++
 intmain()
 {
 cout << "Hello world!" << endl;
 Stack S;
 createStack(S);
 pushAscending(S,3);
 pushAscending(S,4);
 pushAscending(S,8);
 pushAscending(S,2);
 pushAscending(S,3);
 pushAscending(S,9);
 printInfo(S);
 cout<<"balik stack"<<endl;
 balikStack(S);
 printInfo(S);
 return 0;
 }
```

CONTOH OUTPUT: 
```bash
--- PUSH ASCENDING ---
[TOP] 9 8 4 3 3 2 
balik stack
[TOP] 2 3 3 4 8 9
```
3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user
```C++
 int main()
 {
 cout << "Hello world!" << endl;
 Stack S;
 createStack(S);
 getInputStream(S);
 printInfo(S);
 cout<<"balik stack"<<endl;
 balikStack(S);
 printInfo(S);
 return 0;
 }
```

CONTOH OUTPUT :
```bash
Hello World!
4729601
[TOP] 1 0 6 9 2 7 4 
balik stack
[TOP] 4 7 2 9 6 0 1
```

### 📄 File: `stack.h`

```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    int info[20];  // tetap int, tapi bisa menampung char
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
void pushChar(Stack &S, char c);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

### 📄 File: `stack.cpp`

```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top] = x;
    }
}

void pushChar(Stack &S, char c) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top] = c - '0';   // agar char '4' disimpan sebagai angka 4
    }
}

int pop(Stack &S) {
    if (S.top > 0) {
        int val = S.info[S.top];
        S.top--;
        return val;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top > 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    createStack(temp);

    while (S.top > 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top > 0) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan karakter (ENTER untuk berhenti): ";
    char c;

    while (true) {
        c = cin.get();
        if (c == '\n') break;
        pushChar(S, c);
    }
}
```

### 📄 File: `main.cpp`

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    // UNGUIDED 1
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    // UNGUIDED 2
    cout << endl << "--- PUSH ASCENDING ---" << endl;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    // UNGUIDED 3
    cout << endl << "--- INPUT STREAM ---" << endl;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided  :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL7/imagesmodul7/output1_unguided_modul7.png)

![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL7/imagesmodul7/output2_unguided_modul7.png)

![Screenshot Output Unguided 1_3](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL7/imagesmodul7/output3_unguided_modul7.png)

Penjelasan : Pada bagian unguided ini, implementasi stack menggunakan representasi array dilakukan secara menyeluruh dengan menambahkan beberapa variasi operasi yang memperluas fungsionalitas dasar stack. Struktur stack disusun dengan menggunakan array berukuran tetap dan variabel `top` sebagai penunjuk elemen teratas. Pada tahap awal, fungsi `createStack` dipakai untuk menginisialisasi stack dalam keadaan kosong, sementara fungsi `push`, `pop`, dan `printInfo` mengelola penambahan elemen, penghapusan elemen, dan penampilan isi stack. Untuk memperkaya operasi dasar, ditambahkan prosedur `balikStack` yang membalik urutan elemen menggunakan stack sementara. Pada pengembangan selanjutnya, prosedur `pushAscending` diterapkan untuk memastikan elemen-elemen dalam stack disisipkan dalam urutan menaik. Prosedur ini bekerja dengan memindahkan elemen yang lebih besar ke stack sementara hingga ditemukan posisi yang tepat, kemudian mengembalikan semua elemen ke stack utama sehingga susunan tetap terurut. Selain itu, ditambahkan pula prosedur `getInputStream`, yang berfungsi membaca setiap karakter yang dimasukkan pengguna hingga tombol ENTER ditekan, mengonversinya menjadi angka, dan menyimpannya ke dalam stack menggunakan metode LIFO. Seluruh serangkaian pengujian yang dilakukan pada program utama menunjukkan bahwa operasi-operasi dasar stack dapat digabungkan dengan fungsi tambahan untuk menghasilkan perilaku yang lebih fleksibel, seperti penyimpanan terurut dan pengolahan input beruntun, tanpa menghilangkan prinsip utama stack sebagai struktur data dengan konsep Last In First Out.

## Kesimpulan
Pada praktikum ini, stack berhasil diimplementasikan menggunakan dua pendekatan, yaitu representasi array dan representasi linked list. Melalui berbagai operasi seperti `push`, `pop`, `update`, `searchData`, hingga variasi tambahan seperti `pushAscending`, `balikStack`, dan `getInputStream`, dapat dipahami bahwa stack merupakan struktur data yang sederhana namun sangat fleksibel dalam menangani proses yang membutuhkan mekanisme LIFO (Last In First Out). Implementasi dengan array memberikan akses yang cepat dan terstruktur, sementara representasi linked list menawarkan fleksibilitas dalam penambahan elemen tanpa batasan kapasitas. Pengujian pada program utama menunjukkan bahwa setiap fungsi dapat berjalan sesuai tujuan, baik untuk manipulasi data, penyusunan ulang elemen, maupun penanganan input berurutan dari pengguna. Secara keseluruhan, praktikum ini memperkuat pemahaman mengenai konsep dasar stack, karakteristik operasinya, serta penerapannya dalam pemrograman untuk menyelesaikan berbagai permasalahan komputasi.

## Referensi
[1] Santoso, S. & Wibowo, A. (2021). *Implementasi Struktur Data Stack pada Pemrosesan Ekspresi Aritmatika*. Jurnal Ilmu Komputer dan Informatika, Universitas Gadjah Mada (UGM).

[2] Setiadi, D. (2020). *Analisis Kinerja Struktur Data Stack dan Queue dalam Pengembangan Sistem*. Jurnal Teknologi dan Sistem Komputer, Universitas Indonesia (UI).

[3] Firmansyah, M., & Rustamaji, H. (2019). *Perancangan Stack Menggunakan Representasi Linked List*. Jurnal Sistem Informasi, Telkom University.

[4] Sutrisno, B. (2022). *Implementasi Representasi Array pada Struktur Data Stack untuk Optimasi Memori*. Jurnal Teknik Informatika, Institut Teknologi Bandung (ITB).

[5] Fauziah, L. (2021). *Pemanfaatan Stack dalam Algoritma Backtracking*. Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), Universitas Brawijaya.
<br>...

