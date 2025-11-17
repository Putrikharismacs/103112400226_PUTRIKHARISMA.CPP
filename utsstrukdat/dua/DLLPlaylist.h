#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <string>

struct Song {
    std::string Title;
    std::string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct NodeSong {
    Song info;
    NodeSong* prev;
    NodeSong* next;
};

struct ListSong {
    NodeSong* head;
    NodeSong* tail;
};

bool isEmpty(ListSong L);
void createList(ListSong &L);
NodeSong* allocateSong(const Song &S);
void deallocateSong(NodeSong* P);
void insertFirst(ListSong &L, NodeSong* P);
void insertLast(ListSong &L, NodeSong* P);
void insertBefore(ListSong &L, NodeSong* Q, NodeSong* P);
void updateAtPosition(ListSong &L, int pos, const Song &newData);
void updateBefore(ListSong &L, NodeSong* Q, const Song &newData);
void deleteBefore(ListSong &L, NodeSong* Q, Song &out);
float PopularityScore(const Song &s);
void viewList(const ListSong &L);
void searchByPopularityRange(const ListSong &L, float minScore, float maxScore);

#endif
