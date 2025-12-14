#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    P->Next = G.first;
    G.first = P;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL && P->info != X) {
        P = P->Next;
    }
    return P;
}

/* Graph tidak berarah */
void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

/* DFS */
void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->Node);
            E = E->Next;
        }
    }
}

/* BFS */
void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        if (P->visited == 0) {
            cout << P->info << " ";
            P->visited = 1;

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                Q.push(E->Node);
                E = E->Next;
            }
        }
    }
}
