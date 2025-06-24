/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tes Mesin 6 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <malloc.h>

typedef struct{
    char c;
}boxSmp;

typedef struct{
    int n;
}boxJlr;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp{
    boxSmp kontainer;
    alamatsimpul next;
    alamatjalur arc;
}simpul;

typedef struct jlr{
    boxJlr kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
}jalur;

typedef struct{
    simpul* first;
}graph;

void createEmpty(graph *G);
void addSimpul(boxSmp tmp, graph *G);
void addJalur(simpul *awal, simpul *tujuan, boxJlr tmp);
simpul* findSimpul(boxSmp tmp, graph G);
void delJalur(boxSmp tmp, simpul *awal);
void delAll(simpul *awal);
void delSimpul(boxSmp tmp, graph *G);
void printGraph(graph G);