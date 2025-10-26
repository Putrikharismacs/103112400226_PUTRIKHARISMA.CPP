#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    CreateList(L);

    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC); // delete node setelah nodeC (hapus nodeB)

    printList(L);
    cout << endl;

    // ==== UPDATE SESUAI SOAL ====
    updateFirst(L);           // ubah 40 -> 50
    updateAfter(L, nodeD);    // ubah 8 -> 29
    updateLast(L);            // ubah 33 -> 45
    updateAfter(L, L.first);  // ubah 18 -> 20

    printList(L);
    cout << endl;

    // ==== SEARCH ====
    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);
    cout << endl;

    // ==== OPERASI ARITMETIKA ====
    cout << "Total penjumlahan : " << sumList(L) << endl;
    cout << "Total pengurangan : " << subtractList(L) << endl;
    cout << "Total perkalian   : " << multiplyList(L) << endl;

    return 0;
}
