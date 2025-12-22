#include "MLL_Film.h"

int main() {
    GenreList GL;
    initGenreList(GL);

    GenreNode* A = newGenre("GN01","Action");
    GenreNode* C = newGenre("GN02","Comedy");
    GenreNode* H = newGenre("GN03","Horror");
    GenreNode* R = newGenre("GN04","Romance");

    insertLastGenre(GL, A);
    insertLastGenre(GL, C);
    insertLastGenre(GL, H);
    insertLastGenre(GL, R);

    insertFirstFilm(A->film, newFilm("F01","The Raid",101,2011,7.6));
    insertFirstFilm(C->film, newFilm("F02","Agak Laen",119,2024,8.0));
    insertFirstFilm(C->film, newFilm("F03","My Stupid Boss",108,2016,6.8));
    insertFirstFilm(H->film, newFilm("F04","Pengabdi Setan",107,2017,8.4));
    insertFirstFilm(R->film, newFilm("F05","Habibie & Ainun",118,2012,7.6));
    insertFirstFilm(R->film, newFilm("F06","Dilan 1990",110,2018,6.6));

    showAll(GL);

    cout << endl << "FILTER RATING 8.0 - 8.5" << endl;
    findFilmByRating(GL, 8.0, 8.5);

    removeAfterGenre(GL, A);

    cout << endl << "SETELAH HAPUS GENRE KE-2" << endl;
    showAll(GL);

    return 0;
}