/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char merk[101];
    char tipe[101];
    int tahun;
    char status[11];
}value;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    value kontainer;
    alamatelmt next;
} elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char merk[], char tipe[], int tahun, char status[], list *L);
void addAfter(elemen* prev, char merk[], char tipe[], int tahun, char status[], list *L);
void addLast(char merk[], char tipe[], int tahun, char status[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);