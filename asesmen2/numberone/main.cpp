#include "BST.h"

int main() {

    root = insertNode(root, 50, "Monitor LED", 10);
    root = insertNode(root, 30, "Keyboard RGB", 20);
    root = insertNode(root, 70, "Mouse Gaming", 15);
    root = insertNode(root, 20, "Kabel HDMI", 50);
    root = insertNode(root, 40, "Headset 7.1", 12);
    root = insertNode(root, 60, "Webcam HD", 8);
    root = insertNode(root, 80, "Speaker BT", 5);

    cout << "InOrder: ";
    inOrder(root); cout << endl;

    cout << "PreOrder: ";
    preOrder(root); cout << endl;

    cout << "PostOrder: ";
    postOrder(root); cout << endl;

    cout << "\nSearch ID 40:\n";
    Node* s = searchById(root, 40);
    if (s) cout << s->namaProduk << " ditemukan\n";
    else cout << "Tidak ditemukan\n";

    cout << "\nSearch ID 99:\n";
    s = searchById(root, 99);
    if (s) cout << s->namaProduk << " ditemukan\n";
    else cout << "Tidak ditemukan\n";

    cout << "\nSearch Product Webcam HD:\n";
    searchByProduct(root, "Webcam HD");

    cout << "\nSearch Product Printer:\n";
    searchByProduct(root, "Printer");

    cout << "\nMin ID: " << findMin(root)->idProduk << endl;
    cout << "Max ID: " << findMax(root)->idProduk << endl;

    root = deleteNode(root, 20);
    cout << "\nInOrder setelah delete 20: ";
    inOrder(root); cout << endl;

    root = deleteNode(root, 30);
    cout << "InOrder setelah delete 30: ";
    inOrder(root); cout << endl;

    root = deleteNode(root, 50);
    cout << "InOrder setelah delete 50: ";
    inOrder(root); cout << endl;

    deleteTree(root);
    root = NULL;

    cout << "InOrder setelah deleteTree: ";
    inOrder(root);

    return 0;
}