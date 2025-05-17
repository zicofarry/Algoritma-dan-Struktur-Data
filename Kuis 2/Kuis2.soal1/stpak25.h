/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#include <malloc.h> // include library malloc.h

#define slv solve();

// declare typedef struct
typedef struct{
    // contents of the container 
    char resi[51];
    int date;
    int month;
    int year;
}box;

typedef struct elmt *alamatelmt;
typedef struct elmt{
    box container;
    alamatelmt next;
}element;

typedef struct {
    element* top;
}stack;

// declare procedure and function
void createEmpty(stack *S); // procedure to create empty stack
int isEmpty(stack S); // function to check if its an empty stack
int countElement(stack S); // function to count element of the stack
void push(box tmp, stack *S); // procedure to push element to the stack
void moveTo(stack* S, stack* S2); // procedure to move element to the another stack (breakdown concept)
void printElement(element* point); // procedure to print the element
void printStack(stack S); // procedure to print the stack
void solve(); // procedure to solve the problem