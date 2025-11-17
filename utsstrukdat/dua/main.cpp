#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main() {
    ListSong L;
    createList(L);

    Song s1 = {"Senja", "Nona", 210, 150, 4.2};
    Song s2 = {"Langkah", "Delta", 185, 320, 4.8};
    Song s3 = {"Hujan", "Arka", 240, 90, 3.9};

    insertLast(L, allocateSong(s1));
    insertLast(L, allocateSong(s2));
    insertLast(L, allocateSong(s3));

    cout << "Daftar Lagu:\n";
    viewList(L);

    cout << "\nUpdate lagu posisi 2...\n";
    updateAtPosition(L, 2, {"Pelita", "Luna", 200, 260, 4.5});
    viewList(L);

    cout << "\nInsert sebelum lagu posisi 2...\n";
    NodeSong* pos2 = L.head->next;
    insertBefore(L, pos2, allocateSong({"Senandung", "Mira", 175, 120, 4.0}));
    viewList(L);

    cout << "\nUpdate Before posisi 2...\n";
    updateBefore(L, pos2, {"Updated", "AX", 100, 10, 3.5});
    viewList(L);

    cout << "\nDelete Before posisi 3...\n";
    Song deleted;
    deleteBefore(L, pos2->next, deleted);
    viewList(L);

    cout << "\nCari Popularity 150–300:\n";
    searchByPopularityRange(L, 150, 300);

    return 0;
}