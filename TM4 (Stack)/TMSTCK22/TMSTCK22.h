/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 4 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char baju[51];
    char size[51];
}box;

typedef struct elmt *alamatelmt;
typedef struct elmt{
    box kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen* top;
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(box tmp, stack *S);
void pop(stack *S);
void popto(stack* S, stack* S2);
void printStack(stack S, stack S2);