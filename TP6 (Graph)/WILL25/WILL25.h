/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 6 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

// declare library that needed
#include <stdio.h>
#include <string.h>
#include <malloc.h>
// declare macro
#define slv solve();

// declare typedef struct
typedef struct{
    // contents of the container 
    char str[51];
}box;

typedef struct nde *nodeAddress;
typedef struct edg *edgeAddress;
typedef struct nde{
    box container;
    nodeAddress next;
    edgeAddress arc;
}node;

typedef struct edg{
    int container_edg;
    edgeAddress next_edg;
    node *dest;
}edge;

typedef struct{
    node* first;
}graph;

// declare procedure and function
void createEmpty(graph *G);
void addNode(box tmp, graph *G);
void addEdge(node *begin, node *dest, int weight);
node* findNode(box tmp, graph G);
void dfs(node *now, node *dest, char path[][51], int depth, int pathWeight, char result[][51], int *resDepth, int *resWeight, int vstIdx, node *visited[]);
void solve();