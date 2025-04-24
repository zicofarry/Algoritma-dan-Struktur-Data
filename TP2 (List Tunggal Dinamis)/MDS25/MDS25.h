/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include the library stdio.h
#include <string.h> // include the library string.h
#include <malloc.h> // include the library malloc.h

// define macro
#define slv solve(); // macro to call solve function

// declare typedef struct
typedef struct {
    char name[101];
    char position[101];
    int salary;
} value;

typedef struct elmt* alamatelmt;
typedef struct elmt {
    value container;
    alamatelmt next;
} element;

typedef struct {
    element* first;
} list;

// declare procedure and function
void createList(list *L); // procedure to create the list
int countelement(list L); // procedure to count the element
void addFirst(value temp, list *L); // procedure to add element to the first place
void addAfter(element* prev, value temp, list *L); // procedure to add element after element
void addLast(value temp, list *L); // procedure to add element to the last place
void printList(list L); // procedure to print the content list
element* getLastElement(list L); // function to get the last element
void searchPrev(element **prevX, element **x, element **prevY, element **y, list *L); // procedure to search the previous element, before swap
void swap(element *x, element *y, list *L); // procedure to swap 2 element (without swapping the data)
void bubbleSortList(list *L, char sortBy[], char sortOrder[]); // procedure to sort the list with bubble sort algorithm
void mergeElement(list *L1, list *L2, element *prev); // procedure to merge element to the main list
void mergeSortList(list *L1, list *L2, char sortBy[], char sortOrder[]); // procedure to merge list with sort condition
void solve(); // procedure to solve the problem