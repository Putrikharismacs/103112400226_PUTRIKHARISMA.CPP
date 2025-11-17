#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

bool isEmpty(ListSong L) {
    return L.head == nullptr;
}

void createList(ListSong &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

NodeSong* allocateSong(const Song &S) {
    NodeSong* P = new NodeSong;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocateSong(NodeSong* P) {
    delete P;
}

void insertFirst(ListSong &L, NodeSong* P) {
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(ListSong &L, NodeSong* P) {
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

void insertBefore(ListSong &L, NodeSong* Q, NodeSong* P) {
    if (Q == nullptr) return;
    P->next = Q;
    P->prev = Q->prev;
    if (Q->prev != nullptr)
        Q->prev->next = P;
    else
        L.head = P;
    Q->prev = P;
}

void updateAtPosition(ListSong &L, int pos, const Song &newData) {
    if (pos < 1) return;
    NodeSong* cur = L.head;
    int i = 1;
    while (cur != nullptr && i < pos) {
        cur = cur->next;
        i++;
    }
    if (cur != nullptr)
        cur->info = newData;
}

void updateBefore(ListSong &L, NodeSong* Q, const Song &newData) {
    if (Q != nullptr && Q->prev != nullptr) {
        Q->prev->info = newData;
    }
}

void deleteBefore(ListSong &L, NodeSong* Q, Song &out) {
    if (Q != nullptr && Q->prev != nullptr) {
        NodeSong* del = Q->prev;
        out = del->info;

        Q->prev = del->prev;
        if (del->prev != nullptr)
            del->prev->next = Q;
        else
            L.head = Q;

        deallocateSong(del);
    }
}

float PopularityScore(const Song &s) {
    return 0.8f * s.PlayCount + 20 * s.Rating;
}

void viewList(const ListSong &L) {
    NodeSong* cur = L.head;
    int i = 1;
    while (cur != nullptr) {
        cout << i << ") " << cur->info.Title
             << " | Artist: " << cur->info.Artist
             << " | PlayCount: " << cur->info.PlayCount
             << " | Rating: " << cur->info.Rating
             << " | Popularity: " << PopularityScore(cur->info)
             << "\n";
        cur = cur->next;
        i++;
    }
}

void searchByPopularityRange(const ListSong &L, float minScore, float maxScore) {
    NodeSong* cur = L.head;
    while (cur != nullptr) {
        float p = PopularityScore(cur->info);
        if (p >= minScore && p <= maxScore) {
            cout << cur->info.Title << " | Popularity: " << p << "\n";
        }
        cur = cur->next;
    }
}
