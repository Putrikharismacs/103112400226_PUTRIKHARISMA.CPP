#include "graphKota.h"

/* ===== CREATE ===== */
void createGraph(GraphKota &G) {
    G.first = NULL;
}

/* ===== ALOKASI ===== */
adrKota alokasiNode(string nama) {
    adrKota p = new ElmKota;
    p->namaKota = nama;
    p->visited = 0;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge e = new ElmEdge;
    e->kotaTujuan = tujuan;
    e->jarak = jarak;
    e->next = NULL;
    return e;
}

/* ===== INSERT NODE ===== */
void insertNode(GraphKota &G, adrKota p) {
    if (G.first == NULL) {
        G.first = p;
    } else {
        adrKota q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

/* ===== FIND NODE ===== */
adrKota findNode(GraphKota G, string nama) {
    adrKota p = G.first;
    while (p != NULL) {
        if (p->namaKota == nama)
            return p;
        p = p->next;
    }
    return NULL;
}

/* ===== CONNECT (UNDIRECTED) ===== */
void connectNode(GraphKota &G, string kota1, string kota2, int jarak) {
    adrKota p = findNode(G, kota1);
    adrKota q = findNode(G, kota2);

    if (p != NULL && q != NULL) {
        adrEdge e1 = alokasiEdge(q, jarak);
        e1->next = p->firstEdge;
        p->firstEdge = e1;

        adrEdge e2 = alokasiEdge(p, jarak);
        e2->next = q->firstEdge;
        q->firstEdge = e2;
    }
}

/* ===== DISCONNECT ===== */
void disconnectNode(adrKota p, string tujuan) {
    adrEdge e = p->firstEdge;
    adrEdge prev = NULL;

    while (e != NULL) {
        if (e->kotaTujuan->namaKota == tujuan) {
            if (prev == NULL)
                p->firstEdge = e->next;
            else
                prev->next = e->next;
            delete e;
            return;
        }
        prev = e;
        e = e->next;
    }
}

/* ===== DELETE NODE ===== */
void deleteNode(GraphKota &G, string nama) {
    adrKota p = G.first;
    adrKota prev = NULL;

    while (p != NULL && p->namaKota != nama) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        adrKota q = G.first;
        while (q != NULL) {
            disconnectNode(q, nama);
            q = q->next;
        }

        if (prev == NULL)
            G.first = p->next;
        else
            prev->next = p->next;

        delete p;
    }
}

/* ===== PRINT GRAPH ===== */
void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota p = G.first;

    while (p != NULL) {
        cout << "Node " << p->namaKota << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->kotaTujuan->namaKota
                 << "(" << e->jarak << " KM), ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}

/* ===== RESET VISITED ===== */
void resetVisited(GraphKota &G) {
    adrKota p = G.first;
    while (p != NULL) {
        p->visited = 0;
        p = p->next;
    }
}

/* ===== BFS ===== */
void printBFS(GraphKota G, string start) {
    resetVisited(G);
    queue<adrKota> Q;

    adrKota s = findNode(G, start);
    s->visited = 1;
    Q.push(s);

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrKota p = Q.front(); Q.pop();
        cout << p->namaKota << " - ";

        adrEdge e = p->firstEdge;
        while (e != NULL) {
            if (e->kotaTujuan->visited == 0) {
                e->kotaTujuan->visited = 1;
                Q.push(e->kotaTujuan);
            }
            e = e->next;
        }
    }
    cout << endl;
}

/* ===== DFS ===== */
void printDFS(GraphKota G, string start) {
    resetVisited(G);
    stack<adrKota> S;

    adrKota s = findNode(G, start);
    S.push(s);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrKota p = S.top(); S.pop();
        if (p->visited == 0) {
            p->visited = 1;
            cout << p->namaKota << " - ";

            adrEdge e = p->firstEdge;
            while (e != NULL) {
                if (e->kotaTujuan->visited == 0)
                    S.push(e->kotaTujuan);
                e = e->next;
            }
        }
    }
    cout << endl;
}