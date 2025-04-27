/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 1 soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

// include library that necessary
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// declare macro
#define slv solve(); // macro to call solve procedure
/*macro to declare and scan an integer*/
#define isc(n)              \
        int n;              \
        scanf("%d", &n);

// declare typedef struct
typedef struct{
    // contents of the container
    char name[51];
    int year;
    long long tax;
    char status[51];
}value;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    value container;
    alamatelmt next;
} element;

typedef struct{
    element* first;
}list;

/*declare procedure and function*/
void createList(list *L);
int countelement(list L);
void addFirst(value temp, list *L);
void addAfter(element* prev, value temp, list *L);
void addLast(value temp, list *L);
void printElement(list L);
element* getLastElement(list L);
void moveToLast(element* beforeA, element* a, list* L);
void Pemutihan(int limitYear, list* L);
void solve();