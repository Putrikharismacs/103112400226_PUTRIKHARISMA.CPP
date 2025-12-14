# <h1 align="center">Laporan Praktikum Modul 14 – GRAPH</h1>
<p align="center">Putri Kharisma Cahya Salsabillah - 103112400226</p>

## Dasar Teori
Graph merupakan salah satu struktur data non-linier yang terdiri dari sekumpulan simpul (vertex) dan sisi (edge) yang menghubungkan antar simpul. Graph banyak digunakan untuk merepresentasikan permasalahan nyata seperti jaringan komputer, peta jalan, relasi prasyarat mata kuliah, serta alur proses dalam sistem [1].

### A. Pengertian Graph

Graph didefinisikan sebagai pasangan himpunan (G = (V, E)) dengan (V) adalah himpunan vertex dan (E) adalah himpunan edge yang menghubungkan dua vertex. Edge dapat memiliki arah maupun tidak memiliki arah, tergantung jenis graph yang digunakan [2].

#### 1. Vertex (Node)

Vertex adalah simpul yang merepresentasikan objek atau entitas dalam graph.

#### 2. Edge

Edge merupakan penghubung antar vertex yang menunjukkan adanya relasi.

#### 3. Degree

Degree menyatakan jumlah edge yang terhubung dengan suatu vertex.

### B. Jenis-Jenis Graph

#### 1. Graph Berarah (Directed Graph)

Graph berarah adalah graph yang setiap edge-nya memiliki arah tertentu dari satu vertex ke vertex lain. Jenis graph ini banyak digunakan pada representasi alur proses dan ketergantungan (dependency).

#### 2. Graph Tidak Berarah (Undirected Graph)

Graph tidak berarah merupakan graph yang edge-nya tidak memiliki arah. Jika terdapat edge antara dua vertex, maka kedua vertex tersebut saling terhubung.

#### 3. Representasi Graph

Graph dapat direpresentasikan menggunakan adjacency matrix dan adjacency list (multilist). Pada modul ini digunakan multilist karena bersifat dinamis dan efisien dalam penggunaan memori.

### C. Penelusuran Graph

#### 1. Breadth First Search (BFS)

BFS melakukan penelusuran graph berdasarkan level, dimulai dari node awal kemudian ke node-node bertetangga.

#### 2. Depth First Search (DFS)

DFS melakukan penelusuran graph secara mendalam dengan menelusuri satu cabang hingga ke node terdalam sebelum berpindah ke cabang lain.

## Guided 

### 1. graph.h

```C++
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
```
Penjelasan: File `graph.h` berfungsi sebagai header yang mendefinisikan struktur data dan prototipe fungsi untuk ADT Graph tidak berarah. Pada file ini dideklarasikan tipe data `infoGraph` sebagai representasi informasi pada node, serta pointer `adrNode` dan `adrEdge` untuk menghubungkan node dan edge menggunakan konsep multilist. Struktur `ElmNode` menyimpan informasi node, penanda kunjungan (`visited`), pointer ke edge pertama, dan pointer ke node berikutnya, sedangkan struktur `ElmEdge` menyimpan pointer ke node tujuan dan edge berikutnya. Selain itu, struktur `Graph` memiliki pointer `First` sebagai penunjuk awal list node. File ini juga mendeklarasikan berbagai operasi dasar graph seperti pembuatan graph, penambahan node, pencarian node, penghubungan dan pemutusan node, penghapusan node, serta traversal BFS dan DFS, sehingga berperan sebagai antarmuka utama antara program utama dan implementasi graph.

### 2. graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->node = nodeTujuan;
    edgeBaru->next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->node->visited == 0) {
                edgeBantu->node->visited = 1;
                Qyu.push(edgeBantu->node);
            }
            edgeBantu = edgeBantu->next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->node->visited == 0) {
                    Stak.push(edgeBantu->node);
                }
                edgeBantu = edgeBantu->next;
            }
        }
    }
    cout << endl;
}
```
Penjelasan: File `graph.cpp` berisi implementasi seluruh fungsi yang telah dideklarasikan pada `graph.h`. Implementasi dimulai dengan prosedur `CreateGraph` untuk menginisialisasi graph kosong, dilanjutkan dengan fungsi alokasi node dan edge yang bertugas membuat elemen graph secara dinamis. Fungsi `InsertNode` digunakan untuk menambahkan node ke dalam graph dengan metode insert last, sedangkan `FindNode` berfungsi untuk mencari node berdasarkan informasi yang dimiliki. Prosedur `ConnectNode` menghubungkan dua node secara bolak-balik karena graph bersifat tidak berarah, sementara `DisconnectNode` dan `DeleteNode` menangani pemutusan hubungan serta penghapusan node beserta seluruh edge yang terhubung. Selain itu, file ini juga mengimplementasikan penampilan graph dalam bentuk adjacency list serta traversal Breadth First Search (BFS) menggunakan queue dan Depth First Search (DFS) menggunakan stack, yang keduanya memanfaatkan atribut `visited` untuk mencegah pengunjungan node yang sama secara berulang.

### 3. main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>  // library queue untuk BFS
#include <stack>  // library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');   //BFS
    PrintDFS(G, 'A');   //DFS

    return 0;
}
```

Penjelasan: File `main.cpp` merupakan program utama yang digunakan untuk menguji dan menjalankan ADT Graph yang telah dibuat. Pada file ini dilakukan pembuatan graph kosong, penambahan beberapa node, serta penghubungan antar node sesuai dengan ilustrasi graph yang diberikan pada modul. Program kemudian menampilkan representasi graph dalam bentuk adjacency list dan melakukan traversal BFS dan DFS yang dimulai dari node tertentu untuk melihat urutan penelusuran graph. Selanjutnya, dilakukan penghapusan salah satu node beserta seluruh hubungan yang terkait untuk memastikan fungsi `DeleteNode` berjalan dengan benar. Setelah penghapusan, graph kembali ditampilkan dan traversal diulang untuk menunjukkan perubahan struktur graph. Dengan demikian, file `main.cpp` berfungsi sebagai media pengujian seluruh operasi dasar dan traversal pada ADT Graph.

## Unguided 

1. **Buatlah ADT Graph tidak berarah** pada file **`graph.h`** dengan ketentuan sebagai berikut:

   * Type `infoGraph` : `char`
   * Type `adrNode` : pointer to `ElmNode`
   * Type `adrEdge` : pointer to `ElmEdge`

   **Type `ElmNode`** berisi:

   * `info` : `infoGraph`
   * `visited` : integer
   * `firstEdge` : `adrEdge`
   * `Next` : `adrNode`

   **Type `ElmEdge`** berisi:

   * `Node` : `adrNode`
   * `Next` : `adrEdge`

   **Type `Graph`** berisi:

   * `first` : `adrNode`

   Lengkapi pula primitive berikut:

   * `procedure CreateGraph (input/output G : Graph)`
   * `procedure InsertNode (input/output G : Graph, input X : infoGraph)`
   * `procedure ConnectNode (input/output N1, N2 : adrNode)`
   * `procedure PrintInfoGraph (input G : Graph)`

   Setelah itu, buatlah implementasi ADT Graph pada file **`graph.cpp`** dan lakukan pengujian program pada file **`main.cpp`** sesuai dengan ilustrasi graph yang diberikan.

2. **Buatlah prosedur untuk menampilkan hasil penelusuran Depth First Search (DFS)** pada graph yang telah dibuat dengan prototype berikut:

   ```
   procedure PrintDFS (Graph G, adrNode N);
   ```

3. **Buatlah prosedur untuk menampilkan hasil penelusuran Breadth First Search (BFS)** pada graph yang telah dibuat dengan prototype berikut:

   ```
   procedure PrintBFS (Graph G, adrNode N);
   ```

### 📄 File: `graph.h`

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

/* Prototype */
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

### 📄 File: `graph.cpp`

```C++
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
```

### 📄 File: `main.cpp`

```C++
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
```

### Output Unguided  :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/Putrikharismacs/103112400226_Putri-Kharisma-Cahya-Salsabillah/blob/main/MODUL14/imagesmodul14/output1_unguided_modul14.png)

Penjelasan : Pada bagian unguided ini dilakukan implementasi ADT Graph tidak berarah menggunakan representasi multilist dengan pointer. Graph dibangun melalui tiga file utama, yaitu `graph.h` sebagai pendefinisian struktur data dan prototipe fungsi, `graph.cpp` sebagai implementasi seluruh operasi graph, serta `main.cpp` sebagai program pengujian. Node disimpan dalam bentuk linked list, sedangkan hubungan antar node direpresentasikan melalui edge yang juga disimpan dalam linked list pada setiap node. Program mampu melakukan penambahan node, penghubungan node secara bolak-balik sesuai konsep graph tidak berarah, serta pencarian node berdasarkan informasi yang dimiliki. Selain itu, graph ditampilkan dalam bentuk adjacency list untuk menunjukkan keterhubungan antar node. Penelusuran graph dilakukan menggunakan dua metode, yaitu Depth First Search (DFS) yang menelusuri graph secara mendalam dengan pendekatan rekursif, dan Breadth First Search (BFS) yang menelusuri graph berdasarkan level menggunakan struktur data queue. Atribut `visited` digunakan untuk mencegah pengunjungan node yang sama secara berulang. Hasil keluaran program menunjukkan bahwa struktur graph, adjacency list, serta urutan traversal DFS dan BFS telah berjalan sesuai dengan konsep yang dipelajari pada Modul 14.

## Kesimpulan
Berdasarkan praktikum Modul 14, dapat disimpulkan bahwa graph merupakan struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar data dalam bentuk simpul (node) dan sisi (edge). Pada praktikum ini, graph tidak berarah diimplementasikan menggunakan struktur multilist yang bersifat dinamis sehingga memudahkan dalam penambahan node maupun edge.

Implementasi ADT Graph terdiri dari operasi dasar seperti pembuatan graph, penambahan node, penghubungan antar node, serta penampilan isi graph dalam bentuk adjacency list. Selain itu, dilakukan juga penelusuran graph menggunakan metode Depth First Search (DFS) dan Breadth First Search (BFS). DFS menelusuri graph secara mendalam hingga ke node terdalam sebelum berpindah ke cabang lain, sedangkan BFS menelusuri graph berdasarkan tingkat atau level dengan bantuan struktur data queue.

Dengan melakukan praktikum ini, pemahaman mengenai cara kerja graph, representasi graph menggunakan pointer, serta perbedaan karakteristik DFS dan BFS dapat dipahami dengan lebih baik dan dapat diterapkan untuk menyelesaikan permasalahan yang berkaitan dengan struktur data graph.

## Referensi
[1] Triase. (2020). **Diktat Edisi Revisi: Struktur Data**. Medan: Universitas Islam Negeri Sumatera Utara.

[2] Indahyati, U., & Rahmawati, Y. (2020). **Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++**. Sidoarjo: Umsida Press.

[3] Makara Journal of Science. (2018). **Graph Theory and Its Applications in Computer Science**. Depok: Universitas Indonesia.
<br>...