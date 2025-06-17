/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 5 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TMBT225.h"

int i;

int main(){
    tree T;
    box new[8];
    for(int i = 0; i < 8; i++) scanf(" %c", &new[i].c);
    createTree(new[0], &T);
    addLeft(new[1], T.root);    
    addRight(new[2], T.root);
    addLeft(new[3], T.root->left);
    addRight(new[4], T.root->left);
    addLeft(new[5], T.root->right);
    addRight(new[6], T.root->right);
    addLeft(new[7], T.root->right->left);

    printf("Pre Order => ");
    i = 1;
    printTreePreOrder(T.root);
    printf("\nIn Order => ");
    i = 1;
    printTreeInOrder(T.root);
    printf("\nPost Order => ");
    i = 1;
    printTreePostOrder(T.root);
    printf("\n");
    
    delLeft(T.root->right->left);
    printf("\nPre Order => ");
    i = 1;
    printTreePreOrder(T.root);
    printf("\nIn Order => ");
    i = 1;
    printTreeInOrder(T.root);
    printf("\nPost Order => ");
    i = 1;
    printTreePostOrder(T.root);
    printf("\n");
    
    delRight(T.root->right);
    printf("\nPre Order => ");
    i = 1;
    printTreePreOrder(T.root);
    printf("\nIn Order => ");
    i = 1;
    printTreeInOrder(T.root);
    printf("\nPost Order => ");
    i = 1;
    printTreePostOrder(T.root);
    printf("\n");

    return 0;
}