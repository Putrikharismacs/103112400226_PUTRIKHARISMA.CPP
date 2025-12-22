#ifndef MLL_FILM_H
#define MLL_FILM_H

#include <iostream>
using namespace std;

/* ===== CHILD (FILM) ===== */
struct FilmNode {
    string kodeFilm;
    string judul;
    int durasi;
    int tahun;
    float rating;
    FilmNode* next;
    FilmNode* prev;
};

struct FilmList {
    FilmNode* first;
    FilmNode* last;
};

/* ===== PARENT (GENRE) ===== */
struct GenreNode {
    string kodeGenre;
    string namaGenre;
    GenreNode* next;
    GenreNode* prev;
    FilmList film;
};

struct GenreList {
    GenreNode* first;
    GenreNode* last;
};

/* ===== PROTOTYPE ===== */
void initGenreList(GenreList &GL);
void initFilmList(FilmList &FL);

GenreNode* newGenre(string kode, string nama);
FilmNode* newFilm(string kode, string judul, int durasi, int tahun, float rating);

void deleteGenreNode(GenreNode* G);
void deleteFilmNode(FilmNode* F);

void insertLastGenre(GenreList &GL, GenreNode* G);
void insertFirstFilm(FilmList &FL, FilmNode* F);

void clearFilm(FilmList &FL);
void removeAfterGenre(GenreList &GL, GenreNode* prec);

void showAll(GenreList GL);
void findFilmByRating(GenreList GL, float low, float high);

#endif