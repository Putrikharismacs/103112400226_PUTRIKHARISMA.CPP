#include <iostream>
using namespace std;

struct elm_jual {
    int info;
    elm_jual* next;
};

struct sales {
    string nama;
    string gol;
};

struct elm_sales {
    sales info;
    elm_sales* Next;
    elm_jual* nextJual;
};

struct mll {
    elm_sales* First;
};

void Create_list(mll &L) {
    L.First = NULL;
}

elm_sales* new_elm_sales(sales x) {
    elm_sales* S = new elm_sales;
    S->info = x;
    S->Next = NULL;
    S->nextJual = NULL;
    return S;
}

elm_jual* new_elm_jual(int x) {
    elm_jual* J = new elm_jual;
    J->info = x;
    J->next = NULL;
    return J;
}

void insert_last_Sales(mll &L, elm_sales* S) {
    if (L.First == NULL) L.First = S;
    else {
        elm_sales* P = L.First;
        while (P->Next) P = P->Next;
        P->Next = S;
    }
}

void Insert_new_Penjualan(elm_sales* S, elm_jual* J) {
    if (!S->nextJual) S->nextJual = J;
    else {
        elm_jual* P = S->nextJual;
        while (P->next) P = P->next;
        P->next = J;
    }
}

void Delete_First_Penjualan(elm_sales* S) {
    elm_jual* J = S->nextJual;
    if (J) {
        S->nextJual = J->next;
        delete J;
    }
}

void Delete_Last_Penjualan(elm_sales* S) {
    if (!S->nextJual) return;
    elm_jual* P = S->nextJual;

    if (!P->next) {
        delete P;
        S->nextJual = NULL;
        return;
    }

    while (P->next->next) P = P->next;
    delete P->next;
    P->next = NULL;
}

void Delete_after_Penjualan(elm_jual* prec) {
    elm_jual* J = prec->next;
    prec->next = J->next;
    delete J;
}

void Delete_Penjualan(mll &L) {
    elm_sales* S = L.First;

    while (S) {
        elm_jual* P = S->nextJual;
        elm_jual* prec = NULL;

        while (P) {
            if (P->info < 3) {
                if (!prec) Delete_First_Penjualan(S);
                else if (!P->next) Delete_Last_Penjualan(S);
                else Delete_after_Penjualan(prec);

                P = S->nextJual;
                prec = NULL;
            }
            else {
                prec = P;
                P = P->next;
            }
        }
        S = S->Next;
    }
}

void Show_data_sales(mll L) {
    elm_sales* S = L.First;

    while (S) {
        cout << S->info.nama << endl;

        elm_jual* J = S->nextJual;
        while (J) {
            cout << J->info << " ";
            J = J->next;
        }
        cout << endl;

        S = S->Next;
    }
}

int main() {
    mll L;
    Create_list(L);

    // Sales
    sales a = {"Siska",""}, b = {"Affan",""}, c = {"Cahya",""}, d = {"Lia",""}, e = {"Hafidz",""};

    insert_last_Sales(L, new_elm_sales(a));
    insert_last_Sales(L, new_elm_sales(b));
    insert_last_Sales(L, new_elm_sales(c));
    insert_last_Sales(L, new_elm_sales(d));
    insert_last_Sales(L, new_elm_sales(e));

    elm_sales* S1 = L.First;
    elm_sales* S2 = S1->Next;
    elm_sales* S3 = S2->Next;
    elm_sales* S4 = S3->Next;
    elm_sales* S5 = S4->Next;

    // Penjualan
    Insert_new_Penjualan(S1, new_elm_jual(5));
    Insert_new_Penjualan(S1, new_elm_jual(3));
    Insert_new_Penjualan(S1, new_elm_jual(4));
    Insert_new_Penjualan(S1, new_elm_jual(2));

    Insert_new_Penjualan(S2, new_elm_jual(4));
    Insert_new_Penjualan(S2, new_elm_jual(3));

    Insert_new_Penjualan(S3, new_elm_jual(5));
    Insert_new_Penjualan(S3, new_elm_jual(0));
    Insert_new_Penjualan(S3, new_elm_jual(2));

    Insert_new_Penjualan(S5, new_elm_jual(7));

    cout << "DATA AWAL:\n";
    Show_data_sales(L);

    Delete_Penjualan(L);

    cout << "\nDATA SETELAH HAPUS (<3):\n";
    Show_data_sales(L);

    return 0;
}
