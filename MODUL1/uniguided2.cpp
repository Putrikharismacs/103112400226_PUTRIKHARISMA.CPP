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
