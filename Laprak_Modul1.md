# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Pemrograman berorientasi prosedur seperti C++ merupakan dasar penting dalam pembelajaran algoritma dan struktur data. C++ mendukung konsep low-level programming seperti pointer, alokasi memori, serta mendukung implementasi struktur data dinamis seperti linked list, stack, dan queue. IDE (Integrated Development Environment) seperti Code::Blocks digunakan untuk mempermudah pengembangan, karena menyediakan editor, compiler, serta debugger dalam satu kesatuan [1].

### A. Bahasa Pemrograman C++<br/> 
Bahasa pemrograman C++ adalah pengembangan dari C yang mendukung paradigma prosedural maupun berorientasi objek. Dengan fitur pointer, C++ dapat digunakan untuk mengimplementasikan struktur data dinamis. Menurut penelitian, C++ masih menjadi bahasa populer untuk pendidikan dasar pemrograman karena sintaksnya dekat dengan sistem dan mudah dihubungkan dengan konsep struktur data [2].
#### 1. Paradigma Pemrograman
Prosedural: menyelesaikan masalah melalui fungsi dan prosedur.
Objek: menggunakan kelas (class) dan objek untuk modularisasi kode.
#### 2. Pointer dan Memori
Pointer digunakan untuk mengakses alamat memori secara langsung. Hal ini penting dalam implementasi linked list.
#### 3. Kompiler
C++ dikompilasi menjadi machine code menggunakan kompiler, misalnya GCC.
### B. Integrated Development Environment (IDE)<br/>
IDE merupakan perangkat lunak yang mengintegrasikan editor, compiler, dan debugger. Code::Blocks adalah salah satu IDE open-source yang banyak digunakan di dunia akademik di Indonesia karena ringan dan kompatibel di berbagai sistem operasi [3].
#### 1. Fitur Utama Code::Blocks
Editor dengan syntax highlighting
Integrasi dengan GCC compiler
Debugger untuk melacak error
#### 2. Keunggulan
Gratis dan open-source
Mendukung multi-platform
Ringan dan mudah digunakan oleh mahasiswa
#### 3. Peran di Pendidikan
Dalam penelitian lokal, penggunaan Code::Blocks terbukti mempermudah mahasiswa memahami konsep dasar pemrograman C++ serta debugging program [4].

## Guided 

### 1. Program Hello World

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```
Penjelasan: guided 1 membahas tentang cara membuat progam hello world. Fungsinya adalah untuk memperkenalkan sintaks dasar C++.

### 2. Input dan Output

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Penjelasan: guided 2 program ini membaca input dari user (cin) dan menampilkannya kembali ke layar.

### 3. Struktur Kontrol If-Else

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Lulus" << endl;
    } else {
        cout << "Tidak Lulus" << endl;
    }
    return 0;
}
```

Penjelasan: guided 3 program ini menggunakan percabangan if-else untuk menentukan apakah nilai lulus atau tidak.

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    // Input
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    // Proses & Output
    cout << "\n=== Hasil Operasi Aritmatika ===" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian  : Tidak dapat dilakukan (pembagi nol)" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output-Unguided1-Modul1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output2-Unguided1-Modul1.png)

penjelasan unguided 1 yaitu Program ini menerima dua bilangan float lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dengan operator aritmatika dasar.

### 2. soal unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                    "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

string terjemah(int n){
    if(n == 0) return "nol";
    else if(n == 100) return "seratus";
    else if(n < 10) return satuan[n];
    else if(n < 20) return belasan[n-10];
    else {
        int p = n/10;   // puluhan
        int s = n%10;   // satuan
        if(s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    }
}

int main(){
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if(angka < 0 || angka > 100){
        cout << "Di luar jangkauan!";
    } else {
        cout << angka << " : " << terjemah(angka);
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output-Uniguided2-Modul1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output2-Uniguided2-Modul1.png)

penjelasan unguided 2 yaitu Program ini mengubah input angka 0–100 menjadi tulisan bahasa Indonesia dengan percabangan if-else untuk kasus khusus serta pemisahan puluhan dan satuan.

### 3. Soal unguided 3

Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for(int i=n; i>=1; i--){
        for(int j=i; j>=1; j--) cout << j << " ";
        cout << "* ";
        for(int j=1; j<=i; j++) cout << j << " ";
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output-Unguided3-Modul1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/103112400226_PUTRIKHARISMA.CPP/images/Output2-Unguided3-Modul1.png)

penjelasan unguided 3 yaitu Program ini mencetak segitiga bintang rata kanan dengan perulangan: baris, spasi, dan bintang sesuai tinggi yang dimasukkan.

## Kesimpulan
Pada praktikum ini, dipelajari dasar-dasar penggunaan bahasa pemrograman C++ menggunakan IDE Code::Blocks. Materi meliputi input-output, percabangan, serta penerapan pada soal mandiri. Dengan IDE, mahasiswa dapat lebih mudah menulis, mengompilasi, dan mengecek kesalahan program.

## Referensi
[1] Hidayat, Rahmat, dkk. (2019). “Implementasi IDE Code::Blocks dalam Praktikum Algoritma dan Pemrograman.” Jurnal Nasional Komputasi dan Teknologi Informasi, 2(1), 45–53.
[2] Tamba, R. A., & Naibaho, P. (2021). “Pembelajaran Bahasa Pemrograman C++ pada Mahasiswa Informatika.” Jurnal Teknologi dan Sistem Informasi, 9(2), 112–118.
[3] Nugroho, S. (2020). “Analisis Penggunaan IDE dalam Pembelajaran Pemrograman Dasar.” Jurnal Pendidikan Teknologi Informasi dan Komunikasi, 4(1), 23–29.
[4] Pratama, A. (2022). “Studi Efektivitas Code::Blocks Sebagai IDE Open Source untuk Pemrograman C++ di Lingkungan Akademik.” Jurnal Ilmu Komputer Indonesia, 7(3), 77–85.
<br>...
