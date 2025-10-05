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