/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 5 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <malloc.h>

typedef struct{
    // contens of the container
    char c;
}box;

typedef struct smp *alamatnode;
typedef struct smp{
    box kontainer;
    alamatnode right;
    alamatnode left;
}node;

typedef struct{
    node* root;
}tree;

extern int i;

// declare procedure and function
void createTree(box tmp, tree *T);
void addRight(box tmp, node *root);
void addLeft(box tmp, node *root);
void delAll(node *root);
void delRight(node *root);
void delLeft(node *root);
void printTreePreOrder(node *root);
void printTreeInOrder(node *root);
void printTreePostOrder(node *root);