/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UTS soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h
#include <string.h> // include library string.h
#define slv solve(); // define macro slv

// declare typedef struct
typedef struct{
    // contents of the container 
    char name[51]; // name of the product
    int price; // price of the product
    int year; // year of entering the shop
}box;

typedef struct{
    box container; // box of container
    int prev; // to save prev index
    int next; // to save next index
}elemen;

typedef struct{
    int first; // to save first element of the list
    int tail; // to save the last element of the list
    elemen data[51]; // the capacity of the list is static (51)
}list;

// declare procedure and function
void createList(list *L); // procedure to create the list
int countElement(list L); // procedure to count the element
int emptyElement(list L); // procedure to create a new empty element
void addFirst(box temp, list *L); // procedure to add element to the first place
void printElement(elemen point); // procedure to print element
void printList(list L); // procedure to print the list from middle to the last
void printReverse(list L); // procedure to print the list from middle to first
void solve(); // procedure to solve the problem