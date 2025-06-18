/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 5 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TMBT225.h"

int i;

void createTree(box tmp, tree *T){
    node *baru;
    baru = (node *) malloc (sizeof (node));
    baru->kontainer = tmp;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}
if(a){
    
}
void addRight(box tmp, node *root){
    if(root->right == NULL){
        /*jika sub pohon kanan kosong*/
        node *baru;
        baru = (node *) malloc (sizeof (node));
        baru->kontainer = tmp;
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }else{
        printf("sub pohon kanan telah terisi \n");
    }
}

void addLeft(box tmp, node *root){
    if(root->left == NULL){
        /*jika sub pohon kiri kosong*/
        node *baru;
        baru = (node *) malloc (sizeof
        (node));
        baru->kontainer = tmp;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }else{
        printf("sub pohon kiri telah terisi \n");
    }
}

void delAll(node *root){
    if(root != NULL){
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(node *root){
    if(root != NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(node *root){
    if(root != NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(node *root){
    if(root != NULL){
        if(i){
            printf("%c", root->kontainer.c);
            i = 0;
        }else printf("-%c", root->kontainer.c);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(node *root){
    if(root != NULL){
        printTreeInOrder(root->left);
        if(i){
            printf("%c", root->kontainer.c);
            i = 0;
        }else printf("-%c", root->kontainer.c);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(node *root){
    if(root != NULL){
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        if(i){
            printf("%c", root->kontainer.c);
            i = 0;
        }else printf("-%c", root->kontainer.c);
    }
}