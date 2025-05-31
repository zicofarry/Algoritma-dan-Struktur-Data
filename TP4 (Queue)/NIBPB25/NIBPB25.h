/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 4 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#include <malloc.h> // include library malloc.h

// define macro
#define slv solve(); // macro to call solve procedure

// declare typedef struct
typedef struct{
    // contents of the container 
    char name[51];
    char disease[51];
    int urgency;
}box;

typedef struct elm *alamatelmt;
typedef struct elm{
    box container;
    alamatelmt next;
}element;

typedef struct{
    element *first;
    element *last;
}queue;

// declare procedure and function
void createEmpty(queue *Q); // procedure to create empty queue
int isEmpty(queue Q); // function to check if its an empty queue
int countElement(queue Q); // function to count element of the queue
void addPriority(box tmp, queue *Q ); // procedure to add element based on priority
void moveTo(queue *Q, queue *Q2); // procedure to move element from queue 1 to queue 2
void printQueue(queue Q); // procedure to print queue
void solve(); // procedure to solve the problem