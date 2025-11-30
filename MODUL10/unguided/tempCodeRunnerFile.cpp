#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    cout << endl;
    cout << "Process returned 0 (0x0)   execution time : 0.017 s" << endl;
    cout << "Press any key to continue . . ." << endl << endl;

    cout << "Hello world!" << endl;

    InOrder(root);
    cout << endl;
    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
