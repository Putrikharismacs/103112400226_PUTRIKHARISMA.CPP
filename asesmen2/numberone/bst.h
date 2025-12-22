#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idProduk;
    string namaProduk;
    int stok;
    Node* left;
    Node* right;
};

/* Global root */
extern Node* root;

/* Function declarations */
Node* insertNode(Node* node, int id, string nama, int stok);
Node* searchById(Node* node, int id);
void searchByProduct(Node* node, string nama);

void inOrder(Node* node);
void preOrder(Node* node);
void postOrder(Node* node);

Node* findMin(Node* node);
Node* findMax(Node* node);

Node* deleteNode(Node* node, int id);
void deleteTree(Node* node);

#endif