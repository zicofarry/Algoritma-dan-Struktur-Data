/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UTS soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#include <malloc.h> // include library malloc.h
#define slv solve(); // define macro slv

// declare typdef struct
typedef struct{
    // contents of the row container
    char nusery[51];
}row;

typedef struct{
    // contents of the column container
    char name[51];
    int regis;
    int remake;
    char status[51];
}column;

typedef struct eClm *alamateColumn;
typedef struct eClm{
    column container_col;
    alamateColumn next_col;
}eColumn;

typedef struct ebr *alamateRow;
typedef struct ebr{
    row container;
    eColumn *col;
    alamateRow next;
}eRow;

typedef struct{
    eRow *first;
}list;

// declare procedure and function
void createList(list *L); // procedure to create the list
void addFirstR(row tmp, list *L); // procedure to add row element to the first place
void addAfterR(eRow* prev, row tmp); // procedure to add row element after element
void addLastR(row tmp, list *L); // procedure to add row element to the last place
void addFirstC(column tmp, eRow *L); // procedure to add column element to the first place
void addAfterC(eColumn* prev, column tmp); // procedure to add column element after element
void addLastC(column tmp, eRow *L); // procedure to add column element to the last place
void printColElm(eColumn *eCol); // procedure to print the column element
void printRowElm(eRow *point); // procedure to print the row element
void printListofList(list L); // procedure to print the list of list
void solve(); // procedure to solve the problem