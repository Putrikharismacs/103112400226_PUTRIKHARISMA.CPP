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


