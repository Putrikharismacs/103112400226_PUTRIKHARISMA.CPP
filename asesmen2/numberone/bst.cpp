#include "BST.h"

Node* root = NULL;

/* ================= INSERT ================= */
Node* insertNode(Node* node, int id, string nama, int stok) {
    if (node == NULL) {
        Node* newNode = new Node;
        newNode->idProduk = id;
        newNode->namaProduk = nama;
        newNode->stok = stok;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (id < node->idProduk)
        node->left = insertNode(node->left, id, nama, stok);
    else
        node->right = insertNode(node->right, id, nama, stok);

    return node;
}

/* ================= SEARCH BY ID ================= */
Node* searchById(Node* node, int id) {
    if (node == NULL || node->idProduk == id)
        return node;

    if (id < node->idProduk)
        return searchById(node->left, id);
    else
        return searchById(node->right, id);
}

/* ================= SEARCH BY PRODUCT ================= */
void searchByProduct(Node* node, string nama) {
    if (node == NULL) return;

    searchByProduct(node->left, nama);
    if (node->namaProduk == nama) {
        cout << "Ditemukan: " << node->idProduk << " | "
             << node->namaProduk << " | Stok: " << node->stok << endl;
    }
    searchByProduct(node->right, nama);
}

/* ================= TRAVERSAL ================= */
void inOrder(Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->idProduk << " ";
    inOrder(node->right);
}

void preOrder(Node* node) {
    if (node == NULL) return;
    cout << node->idProduk << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->idProduk << " ";
}

/* ================= FIND MIN & MAX ================= */
Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* findMax(Node* node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

/* ================= DELETE NODE ================= */
Node* deleteNode(Node* node, int id) {
    if (node == NULL) return node;

    if (id < node->idProduk)
        node->left = deleteNode(node->left, id);
    else if (id > node->idProduk)
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->idProduk = temp->idProduk;
        node->namaProduk = temp->namaProduk;
        node->stok = temp->stok;
        node->right = deleteNode(node->right, temp->idProduk);
    }
    return node;
}

/* ================= DELETE TREE ================= */
void deleteTree(Node* node) {
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}