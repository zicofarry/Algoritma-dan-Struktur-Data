/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 1 soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include library stdio.h

// declare macro
#define slv solve(); // macro to call solve procedure
/*macro to declare and scanf an integer*/
#define isc(n)              \
        int n;              \
        scanf("%d", &n);

// declare box that containing pixel color
typedef struct{
    int cyan; // cyan color
    int magen; // magenta color
    int yell; // yellow color
    int key; // key color
}box; // the name of the box

//declare solve procedure
void solve();