#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }
    else if(x < root->info){
        insertNode(root->left, x);
    }
    else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if(root == NULL) return NULL;
    if(root->info == x) return root;
    if(x < root->info) return findNode(x, root->left);
    return findNode(x, root->right);
}

void InOrder(address root){
    if(root != NULL){
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungNode(address root){
    if(root == NULL) return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root){
    if(root == NULL) return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int level){
    if(root == NULL) return level;
    int L = hitungKedalaman(root->left, level + 1);
    int R = hitungKedalaman(root->right, level + 1);
    return (L > R ? L : R);
}

void PreOrder(address root){
    if(root != NULL){
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}
