/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 3 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h

// define macro
#define slv solve(); // macro to call solve procedure

// declare typedef struct
typedef struct{
    // contents of the container 
    char name[51];
    char category[51];
    char urgency[51];
}box;

typedef struct{
    box container;
    int prev;
    int next;
}elemen;

typedef struct{
    int first;
    int tail;
    elemen data[51];
}list;

// declare procedure and function
void createList(list *L); // procedure to create the list
int countElement(list L); // function to count the number of elements in a list
int emptyElement(list L); // function to create a new empty element
void addFirst(box new, list *L); // procedure to add element to the first place
void addAfter(int prev, box new, list *L); // procedure to add element after element
void addLast(box new, list *L); // procedure to add element to the last place
void searchPrev(int *beforeX, int *x, list* L); // procedure to search the previous element
void moveToFirst(int x, list* L); // procedure for moving existing element to first place
void moveToAfter(int before, int x, list* L); // procedure for moving existing element to after element called before
void moveToLast(int x, list* L); // procedure for moving existing element to the last place
void sortByUrgency(list *L); // procedure for sorting a list by urgency
void sortByCategory(list* L); // procedure for sorting a list by category
void printElement(elemen point); // procedure to print element
void printList(list L); // procedure to print the list
void printReverse(list L); // procedure to print reverse the list
void solve(); // procedure to solve the problem