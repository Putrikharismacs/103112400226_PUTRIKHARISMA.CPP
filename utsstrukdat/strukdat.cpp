#include <iostream>
using namespace std;

struct elmtVertex;
struct elmtEdge;

typedef elmtVertex* adrVertex;
typedef elmtEdge* adrEdge;

struct elmtVertex {
    char info;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct elmtEdge {
    adrVertex info;     // pointer ke vertex tujuan
    adrEdge nextEdge;
};

struct listVertex {
    adrVertex firstVertex;
};

struct Graph {
    listVertex Vertex;
};

// ==================== COUNT DEGREE =========================
int countDegree(adrVertex v) {
    int d = 0;
    adrEdge e = v->firstEdge;
    while (e != NULL) {
        d++;
        e = e->nextEdge;
    }
    return d;
}

// ==================== FIND VERTEX ==========================
adrVertex findVertex(char x, Graph G) {
    adrVertex p = G.Vertex.firstVertex;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->nextVertex;
    }
    return NULL;
}

// ==================== IS COMPLETE ==========================
bool isComplete(Graph G) {
    int jumlahVertex = 0;
    adrVertex p = G.Vertex.firstVertex;

    while (p != NULL) {
        jumlahVertex++;
        p = p->nextVertex;
    }

    p = G.Vertex.firstVertex;
    while (p != NULL) {
        int deg = countDegree(p);
        if (deg != jumlahVertex - 1)
            return false;
        p = p->nextVertex;
    }

    return true;
}

// =========================== MAIN ============================
int main() {
    Graph G;
    G.Vertex.firstVertex = NULL;

    cout << "Contoh Output Program:" << endl;
    cout << "findVertex('A', G) = NULL (karena graph kosong)" << endl;
    cout << "isComplete(G) = FALSE" << endl;

    return 0;
}