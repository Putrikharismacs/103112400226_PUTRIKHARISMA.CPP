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