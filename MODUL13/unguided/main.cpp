#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    // INSERT PARENT
    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    // INSERT CHILD
    NodeParent P = LP.first; // G001
    insertLastChild(P->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    P = P->next; // G002
    insertLastChild(P->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(P->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(P->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    P = P->next->next; // G004
    insertLastChild(P->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // PRINT SEBELUM DELETE
    printMLLStructure(LP);

    // SEARCH EKOR = FALSE
    searchHewanByEkor(LP, false);

    // DELETE G004
    NodeParent deleteNode = LP.first->next->next->next; // G004
    deleteAfterParent(LP, deleteNode->prev);

    // PRINT SETELAH DELETE
    printMLLStructure(LP);

    return 0;
}
