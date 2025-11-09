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
