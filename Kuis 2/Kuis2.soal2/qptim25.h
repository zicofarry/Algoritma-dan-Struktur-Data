/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h

// declare macro
#define slv solve(); // define slv to call solve procedure

typedef struct{
    // contents of the container
    char name[51];
    char leaf[11];
    char root[11];
    int priority;
}box;

typedef struct{
    int first;
    int last;
    box data[50];
}queue;

// declare procedure and function
void createEmpty(queue *Q); // procedure to create empty queue
int isEmpty(queue Q); // function to check if its an empty queue
int isFull(queue Q); // function to check if its a full stack
void addPriority(int priority, box tmp, queue *Q); // procedure to add element based on priority
void moveTo(queue *Q, queue *Q2); // procedure to move element from queue 1 to queue 2
void printQueue(queue Q); // procedure to print queue
void solve(); // procedure to solve the problem