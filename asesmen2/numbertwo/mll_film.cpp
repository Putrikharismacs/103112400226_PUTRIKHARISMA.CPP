#include "MLL_Film.h"

/* ===== INIT ===== */
void initGenreList(GenreList &GL) {
    GL.first = NULL;
    GL.last = NULL;
}

void initFilmList(FilmList &FL) {
    FL.first = NULL;
    FL.last = NULL;
}

/* ===== ALOKASI ===== */
GenreNode* newGenre(string kode, string nama) {
    GenreNode* G = new GenreNode;
    G->kodeGenre = kode;
    G->namaGenre = nama;
    G->next = NULL;
    G->prev = NULL;
    initFilmList(G->film);
    return G;
}

FilmNode* newFilm(string kode, string judul, int durasi, int tahun, float rating) {
    FilmNode* F = new FilmNode;
    F->kodeFilm = kode;
    F->judul = judul;
    F->durasi = durasi;
    F->tahun = tahun;
    F->rating = rating;
    F->next = NULL;
    F->prev = NULL;
    return F;
}

/* ===== DEALOKASI ===== */
void deleteGenreNode(GenreNode* G) {
    delete G;
}

void deleteFilmNode(FilmNode* F) {
    delete F;
}

/* ===== INSERT ===== */
void insertLastGenre(GenreList &GL, GenreNode* G) {
    if (GL.first == NULL) {
        GL.first = GL.last = G;
    } else {
        GL.last->next = G;
        G->prev = GL.last;
        GL.last = G;
    }
}

void insertFirstFilm(FilmList &FL, FilmNode* F) {
    if (FL.first == NULL) {
        FL.first = FL.last = F;
    } else {
        F->next = FL.first;
        FL.first->prev = F;
        FL.first = F;
    }
}

/* ===== DELETE FILM ===== */
void clearFilm(FilmList &FL) {
    FilmNode* temp;
    while (FL.first != NULL) {
        temp = FL.first;
        FL.first = FL.first->next;
        deleteFilmNode(temp);
    }
    FL.last = NULL;
}

/* ===== DELETE AFTER GENRE ===== */
void removeAfterGenre(GenreList &GL, GenreNode* prec) {
    GenreNode* del = prec->next;
    clearFilm(del->film);

    prec->next = del->next;
    if (del->next != NULL)
        del->next->prev = prec;
    else
        GL.last = prec;

    deleteGenreNode(del);
}

/* ===== SEARCH ===== */
void findFilmByRating(GenreList GL, float low, float high) {
    GenreNode* G = GL.first;
    int idxG = 1;

    while (G != NULL) {
        FilmNode* F = G->film.first;
        int idxF = 1;

        while (F != NULL) {
            if (F->rating >= low && F->rating <= high) {
                cout << "Film ditemukan di Genre "
                     << G->namaGenre << " posisi film ke-" << idxF << endl;
                cout << "Kode Film : " << F->kodeFilm << endl;
                cout << "Judul : " << F->judul << endl;
                cout << "Durasi : " << F->durasi << " menit" << endl;
                cout << "Tahun : " << F->tahun << endl;
                cout << "Rating : " << F->rating << endl;
                cout << "---------------------------" << endl;
            }
            F = F->next;
            idxF++;
        }
        G = G->next;
        idxG++;
    }
}

/* ===== PRINT ===== */
void showAll(GenreList GL) {
    GenreNode* G = GL.first;
    int i = 1;

    while (G != NULL) {
        cout << "GENRE " << i << endl;
        cout << "Kode : " << G->kodeGenre << endl;
        cout << "Nama : " << G->namaGenre << endl;

        FilmNode* F = G->film.first;
        int j = 1;
        while (F != NULL) {
            cout << "  Film " << j << endl;
            cout << "  Judul : " << F->judul << endl;
            cout << "  Rating : " << F->rating << endl;
            F = F->next;
            j++;
        }
        cout << "======================" << endl;
        G = G->next;
        i++;
    }
}