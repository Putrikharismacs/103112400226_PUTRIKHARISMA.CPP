# <h1 align="center">Laporan Praktikum Modul 3 -  Abstract Data Type (ADT)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan salah satu konsep dasar dalam pemrograman terstruktur dan berorientasi objek. ADT mendefinisikan tipe data berdasarkan perilaku (operasi yang dapat dilakukan) tanpa menjelaskan detail implementasinya. Dengan menggunakan ADT, program menjadi lebih modular, mudah dikembangkan, dan tidak bergantung pada cara penyimpanan data [1].

Menurut penelitian yang dilakukan oleh Rahmawati (2022), penerapan konsep ADT membantu mahasiswa memahami cara kerja struktur data seperti stack, queue, dan linked list dengan lebih terarah karena menekankan pada definisi operasi daripada representasi data [2]. Selain itu, ADT berperan penting dalam pembentukan dasar pemrograman berorientasi objek (OOP), di mana setiap entitas (class) merupakan bentuk nyata dari tipe data abstrak yang memiliki atribut dan perilaku [3].

### A. Definisi dan Karakteristik ADT<br/>
Abstract Data Type (ADT) didefinisikan sebagai tipe data yang menyembunyikan detail implementasinya, hanya menampilkan operasi-operasi yang dapat dilakukan terhadap data tersebut.
Dengan konsep ini, pengguna ADT tidak perlu mengetahui bagaimana data disimpan di memori, tetapi cukup memahami fungsi atau prosedur apa yang tersedia untuk memanipulasi data tersebut.
Menurut Rahmawati (2022), ADT mempermudah proses pembelajaran struktur data karena mahasiswa dapat fokus pada fungsi logis sebelum memahami struktur internalnya [3].

#### 1. PDefinisi ADT
ADT mendeskripsikan tipe data yang memiliki kumpulan nilai (domain) dan kumpulan operasi yang dapat dilakukan terhadap nilai tersebut tanpa memperlihatkan bagaimana operasi tersebut diimplementasikan [4].
Sebagai contoh, ADT Stack hanya mendefinisikan operasi push, pop, dan top, tanpa menjelaskan apakah data disimpan dalam array atau linked list.

#### 2. Karakteristik ADT
Menurut Munir (2019), ADT memiliki empat karakteristik utama [5]:

Abstraksi: menyembunyikan detail implementasi dan hanya menampilkan antarmuka operasi.
Enkapsulasi: menggabungkan data dan operasi dalam satu unit agar data tidak diakses secara langsung.
Modularitas: memisahkan kode menjadi bagian-bagian yang lebih kecil untuk memudahkan pengembangan.
Independensi Representasi: memungkinkan perubahan implementasi internal tanpa mengubah antarmuka.

#### 3. Contoh ADT dalam Struktur Data

Beberapa contoh struktur data yang menggunakan konsep ADT adalah [6]:

- **Stack (Tumpukan)**: operasi push, pop, dan top.
- **Queue (Antrian)**: operasi enqueue, dequeue, dan front.
- **List (Daftar)**: operasi insert, remove, dan find.
- **Map/Set**: operasi add, delete, dan contains.
- **Tree/Graph**: operasi addNode, search, dan traverse.

### B. Implementasi ADT dalam Bahasa Pemrograman C++<br/>
Implementasi ADT dalam bahasa pemrograman C++ dilakukan melalui penggunaan struct, class, dan pemisahan file header (.h) serta file implementasi (.cpp).
Dengan cara ini, program menjadi lebih modular karena setiap bagian memiliki tanggung jawab yang spesifik.
Menurut Suwanto & Yuliana (2021), pendekatan ini membantu mahasiswa memahami hubungan antara konsep logis ADT dengan implementasi fisiknya di C++, sehingga lebih siap menghadapi proyek perangkat lunak berskala besar [7].

#### 1. Struct dan Class sebagai ADT
Dalam C++, tipe data seperti struct dan class sering digunakan untuk merepresentasikan ADT.

- `struct` digunakan untuk menyimpan kumpulan atribut yang terkait.
- `class`  memiliki tambahan konsep enkapsulasi, di mana atribut dapat dibuat private dan hanya diakses melalui fungsi public.

Contohnya, ADT Pelajaran memiliki atribut namaMapel dan kodeMapel, serta fungsi create_pelajaran() dan tampil_pelajaran() untuk mengelola data tersebut [8].

#### 2. Pemisahan File Header dan Implementasi
- File header (.h) berisi deklarasi fungsi, prosedur, dan tipe data.
- File implementasi (.cpp) berisi definisi dari fungsi-fungsi tersebut.

Pemisahan ini menjaga keamanan dan kebersihan kode, karena detail implementasi tidak langsung terlihat oleh pengguna ADT [9].

#### 3. Kelebihan Penggunaan ADT di C++
Penggunaan ADT memberikan berbagai keuntungan, antara lain [10]:

- Kode program lebih terstruktur dan mudah dibaca.
- Perawatan (maintenance) menjadi lebih mudah karena implementasi dapat diubah tanpa mengganggu program utama.
- Dapat digunakan kembali (reusable) di berbagai proyek.
- Mendukung konsep OOP (Object-Oriented Programming) seperti enkapsulasi dan abstraksi.

## Guided 

### 1. Program pelaran.h

```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```
Penjelasan: Program Guided 1 ini digunakan untuk mendefinisikan **ADT (Abstract Data Type)** bernama `pelajaran` di dalam file header `pelajaran.h`. Kode `#ifndef`, `#define`, dan `#endif` disebut **header guard**, berfungsi untuk mencegah file header di-include lebih dari sekali dalam satu program. Struktur `pelajaran` memiliki dua atribut, yaitu `namaMapel` dan `kodeMapel`, sedangkan fungsi `create_pelajaran()` digunakan untuk membuat data pelajaran baru dan prosedur `tampil_pelajaran()` untuk menampilkannya. Program ini menunjukkan penerapan konsep **abstraksi dan modularisasi** pada ADT di C++.

### 2. pelajaran.cpp

```C++
#include "pelajaran.h"

//Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Penjelasan: Program Guided 2 ini merupakan implementasi dari file header `pelajaran.h` yang ditulis dalam file `pelajaran.cpp`. Pada bagian ini, fungsi `create_pelajaran()` digunakan untuk membuat dan mengembalikan data bertipe `pelajaran` dengan mengisi atribut `namaMapel` dan `kodeMapel`. Sedangkan prosedur `tampil_pelajaran()` digunakan untuk menampilkan data pelajaran ke layar. Program ini memperlihatkan bagaimana **implementasi fungsi dan prosedur ADT** dipisahkan dari deklarasinya agar kode menjadi lebih **modular, terstruktur, dan mudah dipelihara**.

### 3. Struct.cpp

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa m){
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa &m){
    return (m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata rata ; " << rata2(mhs);
    return 0;
}
```

Penjelasan: Program Guided 3 ini digunakan untuk menghitung **rata-rata nilai mahasiswa** dengan menerapkan konsep **ADT dan parameter fungsi**. Struktur `mahasiswa` menyimpan data berupa nama dan dua nilai. Fungsi `inputMhs()` digunakan untuk menerima input dari pengguna, sedangkan fungsi `rata2()` menghitung nilai rata-rata dengan menggunakan **parameter referensi (&)** agar data yang dikirim bisa langsung digunakan tanpa membuat salinan baru. Program ini menunjukkan penerapan konsep **abstraksi dan efisiensi memori** melalui penggunaan struct dan parameter referensi dalam fungsi di C++.


## Unguided 

### 1. Soal Unguided 1

Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3" uts+0.4*uas+0.3*tugas

### 📄 File: `main.cpp`

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

// fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah melebihi batas maksimum!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> ws;
        getline(cin, data[i].nama);
        cout << "NIM    : ";
        getline(cin, data[i].nim);
        cout << "Nilai UTS   : ";
        cin >> data[i].uts;
        cout << "Nilai UAS   : ";
        cin >> data[i].uas;
        cout << "Nilai Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << data[i].nama << endl;
        cout << "NIM : " << data[i].nim << endl;
        cout << "Nilai Akhir: " << data[i].nilaiAkhir << endl;
        cout << "-----------------------------\n";
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output1_unguided1_modul3.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output2_unguided1_modul3.png)


penjelasan unguided 1 yaitu Program ini menggunakan struct Mahasiswa untuk menyimpan data nama, NIM, dan nilai (UTS, UAS, Tugas).
Fungsi hitungNilaiAkhir() menghitung nilai akhir berdasarkan bobot tertentu.
Konsep ADT diterapkan melalui fungsi terpisah yang menangani perhitungan, sehingga kode menjadi modular dan mudah dipelihara.

### 2. soal unguided 2

Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":

Type pelajaran <
namaMape :string
kodemapel:string
>
Function create pelajaran (namapel: string, 
kodepel: string) pelajaran 
procedure tampil_pelajaran (input pel pelajaran)

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

using namespace std;
int main(){
string namapel = "Struktur Data":
string kodepel = "STD";
 pelajaran pel = create_pelajaran (namapel, kodepel); tampil_pelajaran (pel);

return 0;
}

Contoh output hasil:
nama pelajaran: Struktur Data
nilai: STD

#### 📄 File: `pelajaran.h`

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

// Deklarasi struktur pelajaran
struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi
Pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(Pelajaran pel);

#endif
```
### 📄 File: `pelajaran.cpp`

```C++
#include "pelajaran.h"

// Fungsi untuk membuat data pelajaran baru
Pelajaran create_pelajaran(string namaPel, string kodePel) {
    Pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

// Prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```
### 📄 File: `main.cpp`

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string nama, kode;

    cout << "Masukkan nama mata pelajaran: ";
    getline(cin, nama);
    cout << "Masukkan kode mata pelajaran: ";
    getline(cin, kode);

    // Membuat objek pelajaran menggunakan fungsi ADT
    Pelajaran p1 = create_pelajaran(nama, kode);

    cout << "\n=== Data Pelajaran ===\n";
    tampil_pelajaran(p1);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output1_unguided2_modul3.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output2_unguided2_modul3.png)

penjelasan unguided 2 yaitu Program ini menerapkan ADT Pelajaran menggunakan tiga file: pelajaran.h, pelajaran.cpp, dan main.cpp.
Struktur Pelajaran dideklarasikan di header, implementasi fungsinya dipisah di file .cpp, dan penggunaannya dilakukan di main.cpp.
Hal ini menunjukkan penerapan abstraksi dan enkapsulasi sesuai konsep ADT pada C++.

### 3. Soal unguided 3

Buatlah program dengan ketentuan:

- 2 buah crray 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi 2 array 2D pada posisi tertentu
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar isi variabel melalui pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *ptr1, *ptr2;
    int x = 10, y = 20;

    cout << "=== Array A ===" << endl;
    tampilArray(A);
    cout << "=== Array B ===" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan baris dan kolom yang ingin ditukar (0-2): ";
    cin >> baris >> kolom;

    tukarElemen(A, B, baris, kolom);

    cout << "\n=== Setelah Penukaran Elemen ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    ptr1 = &x;
    ptr2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output1_unguided3_modul3.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL3/imagesmodul3/output2_unguided3_modul3.png)

penjelasan unguided 3 yaitu Program ini menggunakan dua array 2 dimensi berukuran 3x3 dan dua pointer integer untuk mendemonstrasikan konsep dasar pointer dan manipulasi data array. Fungsi tampilArray() menampilkan isi array 2D ke layar, tukarElemen() menukar elemen antara dua array pada posisi baris dan kolom yang ditentukan pengguna, sedangkan tukarPointer() menukar nilai dua variabel melalui pointer. Dengan program ini, kamu bisa melihat bagaimana array dan pointer saling berinteraksi dalam pengelolaan data di memori menggunakan fungsi dan prosedur terpisah.

## Kesimpulan
Pada praktikum Modul 3 ini, saya belajar bagaimana konsep Abstract Data Type (ADT) digunakan dalam pemrograman C++ untuk membuat program yang lebih terstruktur dan rapi.
Dengan memisahkan antara data dan fungsi pengolah datanya, program jadi lebih mudah dipahami dan dikembangkan.

Melalui latihan membuat ADT Mahasiswa dan Pelajaran, saya jadi paham bahwa ADT tidak hanya menyimpan data, tetapi juga cara mengatur bagaimana data tersebut digunakan.
Konsep ini juga mengajarkan pentingnya modularisasi, abstraksi, dan enkapsulasi supaya kode bisa dipakai ulang tanpa harus mengubah seluruh program.

Secara keseluruhan, penerapan ADT membantu saya memahami dasar dari pembuatan program yang efisien, mudah dirawat, dan terstruktur dengan baik.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Universitas Islam Negeri Sumatera Utara.
[2] Rahmawati, R. (2022). Penerapan Konsep Abstract Data Type (ADT) dalam Pembelajaran Struktur Data Menggunakan Bahasa C++. Jurnal Teknologi Informasi dan Komputer (JTIK), Vol. 8 No. 3.
[3] Suwanto, D., & Yuliana, D. (2021). Implementasi Struktur Data dan ADT dalam Pemrograman C++. Jurnal Teknologi dan Sistem Informasi (JTSI).
[4] Munir, R. (2019). Struktur Data dan Algoritma. Informatika Bandung.
[5] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th Edition). Pearson.
[6] Nugroho, S. (2020). Analisis Penggunaan Konsep ADT dalam Pemrograman Berorientasi Objek. Jurnal Teknologi dan Sistem Informasi, 5(2), 45–53.
[7] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman Dalam Bahasa C++. Umsida Press.
[8] Malik, D. (2018). C++ Programming: From Problem Analysis to Program Design. Cengage Learning.
[9] Suhartono, T. (2023). Analisis Modularisasi dan Efisiensi Penggunaan ADT pada Bahasa C++. Jurnal Sistem Informasi Nasional, 4(2), 60–68.
[10] Wahyudi, Y., dkk. (2013). Instruksi Bahasa Pemrograman ADT (Abstract Data Type) pada Virus dan Loop Batch. Jurnal Media Infotama, 9(2), 44–50.
<br>...
