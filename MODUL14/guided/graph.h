#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;       // Menyimpan data node (misal: char/int)
    int visited;          // Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge;    // Pointer ke edge pertama yang terhubung
    adrNode Next;         // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode node;         // Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge next;         // Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First;        // Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); // Prosedur untuk mengeset First dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data); // alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); // alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); // Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); // function untuk mencari alamat Node berdasarkan info
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); // prosedur untuk menghubungkan dua Node
void DisconnectNode(Graph &G, adrNode node1, adrNode node2); // prosedur untuk memutuskan hubungan dua Node
void DeleteNode(Graph &G, infoGraph X); // prosedur untuk menghapus Node X beserta semua edge yang terhubung

void PrintInfoGraph(Graph G); // Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); // Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); // Traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); // Traversal Depth First Search / DFS (Menggunakan Stack atau Rekursif)

#endif