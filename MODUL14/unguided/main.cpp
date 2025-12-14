#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    /* Insert Node */
    InsertNode(G, 'H');
    InsertNode(G, 'G');
    InsertNode(G, 'F');
    InsertNode(G, 'E');
    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');

    /* Cari Node */
    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    /* Hubungan sesuai gambar */
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List Graph\n";
    PrintInfoGraph(G);

    cout << "\nDFS Traversal : ";
    PrintDFS(G, A);

    /* Reset visited */
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "\nBFS Traversal : ";
    PrintBFS(G, A);

    return 0;
}
