# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman tingkat tinggi yang dikembangkan sebagai perluasan dari bahasa C. C++ mendukung konsep pemrograman prosedural dan berorientasi objek, sehingga sangat cocok untuk digunakan dalam pembelajaran dasar struktur data dan algoritma. Dalam dunia pendidikan, C++ sering digunakan sebagai bahasa pengantar untuk memahami konsep pemrograman karena memiliki struktur yang jelas dan efisien.

Menurut jurnal oleh Santoso (2020), C++ memiliki kemampuan manipulasi data yang kuat melalui penggunaan pointer dan array, yang memungkinkan efisiensi tinggi dalam pengolahan data [1]. Selain itu, Hasdyna dan Dinata (2020) menjelaskan bahwa penerapan struktur data dalam C++ membantu mahasiswa memahami bagaimana data disimpan, diakses, dan diolah secara sistematis [2].

Konsep penting dalam modul ini meliputi fungsi, array satu dimensi, pointer, dan operasi dasar menggunakan perulangan. Berikut penjelasan masing-masing konsep:

### A. Fungsi dalam C++<br/>
Fungsi adalah blok kode yang memiliki nama dan dapat dipanggil dari bagian lain program. Fungsi membantu memecah program menjadi bagian-bagian kecil yang lebih mudah dipahami, diuji, dan digunakan kembali.
#### 1. Jenis Fungsi
Fungsi dengan nilai balik (return type): mengembalikan hasil berupa nilai tertentu.
Fungsi tanpa nilai balik (void): menjalankan perintah tanpa mengembalikan nilai.
Fungsi dengan parameter: menerima input agar hasilnya bisa bervariasi.
#### 2. Keuntungan Penggunaan Fungsi
Meningkatkan keterbacaan program.
Mempermudah proses debugging.
Mendukung prinsip modularisasi dalam pemrograman.

### B. Array 1 Dimensi<br/>
Array 1 dimensi adalah kumpulan elemen data bertipe sama yang disimpan berurutan dalam memori komputer dan diakses melalui indeks tunggal [2]. Contoh penggunaannya antara lain untuk menyimpan daftar nilai, data siswa, atau elemen numerik.
#### 1. Pengertian Array 1 Dimensi
Array satu dimensi hanya memiliki satu indeks, misalnya arr[0], arr[1], dan seterusnya. Indeks dimulai dari 0 dan berakhir pada ukuran array - 1.
#### 2. Kelebihan Array 1 Dimensi
Akses data cepat dengan indeks langsung.
Memudahkan pengelolaan kumpulan data sejenis.
Dapat digunakan untuk membangun struktur data lain seperti stack dan queue
#### 3. Contoh Deklarasi Array
Deklarasi dan inisialisasi array dapat dilakukan sebagai berikut:
```C++
int nilai[5] = {10, 20, 30, 40, 50};
```
Untuk menampilkan isi array digunakan perulangan:
```C++
for(int i = 0; i < 5; i++){
cout << nilai[i] << " ";
}
```
Array 1 dimensi banyak dimanfaatkan untuk operasi matematis sederhana seperti mencari nilai maksimum, minimum, dan rata-rata dari sekumpulan data.

### C. Pointer<br/>
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dalam C++, pointer sering digunakan untuk mengakses dan memodifikasi nilai variabel dari fungsi lain tanpa menyalin data. Konsep ini sangat penting dalam efisiensi program [1].
#### 1. Deklarasi Pointer
```C++
int x = 10;
int *ptr = &x; // ptr menyimpan alamat memori dari x
```
#### 2. Kelebihan Pointer
Dapat menghemat memori.
Memungkinkan manipulasi data secara langsung.
Digunakan dalam struktur data dinamis seperti linked list.

## Guided 

### 1. Array

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5){
        cout << "isi indekss ke-" << j << " ; " << arr[j] << endl;
        j++;
    }

    return 0;
}
```
penjelasan singkat guided 1 : Program ini menggunakan array satu dimensi berukuran lima elemen untuk menyimpan input dari pengguna, lalu menampilkannya kembali menggunakan perulangan while. Tujuannya untuk memahami cara menyimpan dan menampilkan data menggunakan array satu dimensi di C++.

### 2. Array 2 dimensi

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
penjelasan singkat guided 2 : Program ini menunjukkan operasi dasar pada array dua dimensi berupa penjumlahan dan perkalian matriks 2x2. Hasilnya ditampilkan menggunakan fungsi tampilkanHasil(), sehingga pengguna dapat memahami cara mengolah data dalam bentuk matriks.

### 3. Function
```C++
#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumalahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali =  arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl
    ;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}
```
penjelasan singkat guided 3 : Program ini memanfaatkan fungsi untuk mengelola array, yaitu mencari nilai maksimum dan menghitung total penjumlahan serta perkalian elemen. Melalui fungsi cariMAX() dan operasiAritmetika(), pengguna belajar cara memisahkan logika program agar lebih terstruktur.

### 4. Pointer

```C++
#include<iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int  *ptr;

    ptr = &a;

    cout << "value of a : " << a  << endl;
    cout << "addres of a : " << &a  << endl;
    cout << "value stored in ptr (addres of a) : " << ptr  << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 4 : Program ini menjelaskan konsep pointer yang digunakan untuk menyimpan alamat memori suatu variabel dan mengakses nilainya secara tidak langsung. Selain itu, fungsi tukar() memperlihatkan cara menukar nilai dua variabel menggunakan pointer.

### 5. Referenc

```C++
#include<iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a  << endl;
    cout << "alamat a (&a) : " << &a  << endl;
    cout << "Nilai ref (alias a) : " << ref  << endl;
    cout << "Almat ref (&ref) : " << &ref << endl;

    //menukar nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << a  << endl;
    cout << "Nilai a : " << a  << endl;
    cout << "Nilai ref : " << ref  << endl;
    

    tukar(a, b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}
```
penjelasan singkat guided 5 : Program ini memperkenalkan konsep reference sebagai alias dari variabel, di mana perubahan pada reference juga mengubah nilai variabel aslinya. Fungsi tukar() menggunakan parameter by reference untuk menukar nilai tanpa pointer, sehingga lebih sederhana dan efisien.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;


int main(){
int A[3][3], B[3][3], C[3][3];
cout << "Masukkan elemen matriks A:\n";
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){
cin >> A[i][j];
}
}
cout << "Masukkan elemen matriks B:\n";
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){
cin >> B[i][j];
}
}
cout << "\nHasil Penjumlahan Matriks:\n";
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){
C[i][j] = A[i][j] + B[i][j];
cout << C[i][j] << " ";
}
cout << endl;
}
return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL2/imagesmodul2/output1_unguided1_modul2
.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL2/imagesmodul2/output2_unguided1_modul2.png)

penjelasan unguided 1 : Program ini berfungsi untuk menjumlahkan dua buah matriks berukuran 3x3. Nilai matriks dimasukkan melalui input pengguna, kemudian program menjumlahkan setiap elemen yang memiliki posisi sama. Hasil akhirnya ditampilkan dalam bentuk matriks baru di layar.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include<iostream>
using namespace std;

// Fungsi menukar 3 variabel menggunakan pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi menukar 3 variabel menggunakan reference
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== SEBELUM PERTUKARAN ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar dengan POINTER
    tukarPointer(&a, &b, &c);
    cout << "\n=== SETELAH PERTUKARAN DENGAN POINTER ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar kembali dengan REFERENCE
    tukarReference(a, b, c);
    cout << "\n=== SETELAH PERTUKARAN DENGAN REFERENCE ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL2/imagesmodul2/output1_unguided2_modul2.png)


penjelasan unguided 2 : Program ini berfungsi untuk menukar nilai tiga variabel menggunakan dua metode berbeda, yaitu pointer dan reference. Fungsi tukarPointer() menggunakan parameter pointer untuk mengakses dan menukar nilai variabel melalui alamat memori, sedangkan fungsi tukarReference() menggunakan parameter referensi agar nilai variabel dapat langsung diubah tanpa memerlukan operator dereference. Hasil eksekusi menunjukkan bahwa kedua metode sama-sama efektif dalam menukar nilai, hanya berbeda dalam cara pemanggilan dan akses terhadap variabel aslinya.

### 3. Program Array dengan Nilai Minimum, Maksimum, dan Rata-rata

```C++
#include <iostream>
using namespace std;


int cariMaks(int arr[], int n){
int maks = arr[0];
for(int i=1; i<n; i++){
if(arr[i] > maks) maks = arr[i];
}
return maks;
}


int cariMin(int arr[], int n){
int min = arr[0];
for(int i=1; i<n; i++){
if(arr[i] < min) min = arr[i];
}
return min;
}


float hitungRata(int arr[], int n){
float total = 0;
for(int i=0; i<n; i++) total += arr[i];
return total/n;
}


int main(){
int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
int pilih;
do{
cout << "\n--- Menu Program Array ---\n";
cout << "1. Tampilkan isi array\n2. Cari nilai maksimum\n3. Cari nilai minimum\n4. Hitung nilai rata-rata\n5. Keluar\n";
cout << "Pilih menu: ";
cin >> pilih;


switch(pilih){
case 1:
for(int i=0; i<10; i++) cout << arrA[i] << " ";
cout << endl;
break;
case 2:
cout << "Nilai maksimum: " << cariMaks(arrA, 10) << endl;
break;
case 3:
cout << "Nilai minimum: " << cariMin(arrA, 10) << endl;
break;
case 4:
cout << "Nilai rata-rata: " << hitungRata(arrA, 10) << endl;
break;
}
} while(pilih != 5);


return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL2/imagesmodul2/output1_unguided3_modul2.png)


##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL2/imagesmodul2/output2_unguided3_modul2.png)

penjelasan unguided 3 :Program ini menggunakan array satu dimensi berisi sepuluh angka. Pengguna dapat memilih menu untuk menampilkan isi array, mencari nilai maksimum, minimum, dan menghitung nilai rata-rata. Program memanfaatkan fungsi untuk modularisasi agar lebih rapi dan mudah dibaca.

## Kesimpulan
Pada praktikum ini mahasiswa belajar membuat program dengan fungsi, pointer, dan array satu dimensi. Melalui latihan guided dan unguided, mahasiswa memahami bagaimana modularisasi kode mempermudah pengembangan serta meningkatkan efisiensi program.

## Referensi
[1] Santoso, L. E. (2020). Standard Template Library C++ untuk Mengajarkan Struktur Data. Jurnal Teknologi Informasi dan Komunikasi, Universitas Esa Unggul. https://ejurnal.esaunggul.ac.id/index.php/JIK/article/view/397
<br>[2] Hasdyna, N., & Dinata, R. K. (2020). Pembelajaran Struktur Data dalam Pemrograman C++. Universitas Malikussaleh. https://repository.unimal.ac.id/6709/