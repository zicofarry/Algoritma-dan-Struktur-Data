/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tes Mesin 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to store student data (NIM, name, grade)
typedef struct{
    char merk[51];
    char tipe[50];
    int harga, stok;
} nilai;

// Element of the doubly linked list
typedef struct elmt *alametelmt;
typedef struct elmt{
    nilai kontainer;
    alametelmt prev;
    alametelmt next;
} elemen;

// Doubly linked list structure
typedef struct{
    elemen* head;
    elemen* tail;
} list;

// Function declarations for list operations
void initList(list *L);
int countElement(list L);
void addFirst(nilai value, list *L);
void addAfter(elemen* before, nilai value, list *L);
void addBefore(elemen* before, nilai value, list *L);
void addLast(nilai value, list *L);
void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void delAll(list *L);
void printList(list L);
void printReverse(list L);