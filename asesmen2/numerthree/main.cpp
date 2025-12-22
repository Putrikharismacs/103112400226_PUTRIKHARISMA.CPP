#include "graphKota.h"

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, alokasiNode("Jakarta"));
    insertNode(G, alokasiNode("Bogor"));
    insertNode(G, alokasiNode("Depok"));
    insertNode(G, alokasiNode("Tangerang"));
    insertNode(G, alokasiNode("Bekasi"));

    connectNode(G,"Jakarta","Tangerang",24);
    connectNode(G,"Jakarta","Depok",21);
    connectNode(G,"Jakarta","Bekasi",16);
    connectNode(G,"Jakarta","Bogor",42);
    connectNode(G,"Bogor","Bekasi",60);
    connectNode(G,"Bogor","Depok",22);
    connectNode(G,"Depok","Bekasi",25);
    connectNode(G,"Depok","Tangerang",30);
    connectNode(G,"Tangerang","Bekasi",45);

    printGraph(G);

    cout << endl << "DELETE NODE DEPOK" << endl;
    deleteNode(G, "Depok");
    printGraph(G);

    cout << endl << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");

    return 0;
}