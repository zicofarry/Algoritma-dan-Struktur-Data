/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 5 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#include <malloc.h> // include library malloc.h

// define macro
#define slv solve();

// declare typedef struct for n-er tree
typedef struct{
    // contens of the container
    int level;
    char name[200];
    char type;
    int size;
}box;

typedef struct nde* nodeAddress;
typedef struct nde {
    box container;
    nodeAddress sibling;
    nodeAddress child;
    nodeAddress parent;
}node;

typedef struct{
    node *root;
}tree;

// declare typedef struct for queue
typedef struct{
    // contents of the container 
    node *element;
}boxQue;

typedef struct elm *alamatelmt;
typedef struct elm{
    boxQue container;
    alamatelmt next;
}element;

typedef struct{
    element *first;
    element *last;
}queue;

// declare global variable
extern int space[15];          // to save space value per level            
extern int idx;                // Index of the last character in the word
extern int wlen;               // word length
extern char cc;                // current character
extern char cw[50];            // current word
extern char tape[501];         // input tape
extern tree T;                 // n-er tree

// declare procedure and function for queue
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(boxQue tmp, queue *Q );
void del(queue *Q);

// declare procedure and function for n-er tree
void createTree(box tmp, tree* T);
void addChild(box tmp, node* root);
void delAll(node* root);
void delChild(box tmp, node* root);
node* findNodeBFS(box find, node* root);
void printNode(node *root);
void printPreOrder(node* root);
void countSizeAndSpace(int down, node *root);

// declare procedure and function for word machine
int eop(char pita[]);
void start(char pita[]);
void inc(char pita[]);
char* getcw();
int str_to_int(char str[]);

// procedure to solve the problem
void solve();