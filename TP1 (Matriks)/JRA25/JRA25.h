/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h> // include the library stdio.h

// defining macro
#define slv solve(); // to call the solve function 
#define loopMat(act) /*declare macro to act matrix(2x2) per index*/     \
        for(int i = 0; i < n; i++){ /*loop for the row*/                \
            for(int j = 0; j < m; j++){ /*loop for the column*/         \
                act /*action according to input*/                       \
            }                                                           \
        }
#define SWAPMAT(a, b)  /*declare macro to swap the matrix per index*/   \
        for(int i = 0; i < *n; i++){ /*loop for the row*/               \
            for(int j = 0; j < *m; j++){ /*loop for the column*/        \
                a = b; /*swapping value a with b per index*/            \
            }                                                           \
        }
#define LIMIT(a, b) if(i+a >= 0 && j+b >= 0 && i+a <= n-1 && j+b <= m-1) // macro to check if the index has not exceeded the limit
#define SPREAD(a, b) if(mat[i+a][j+b] != -1) mat[i+a][j+b]++; // macro to count up around mines
#define MINE /*calling macro LIMIT and SPREAD*/       \
        /*if it is still within the limits then   \   \
        it is affected by the effects of the mine*/   \
        /*checking around the mine every single one*/ \
        LIMIT(-1,0) {SPREAD(-1,0)}    /*North*/       \
        LIMIT(-1,1) {SPREAD(-1,1)}    /*Northeast*/   \
        LIMIT(0,1) {SPREAD(0,1)}      /*East*/        \
        LIMIT(1,1) {SPREAD(1,1)}      /*Southeast*/   \
        LIMIT(1,0) {SPREAD(1,0)}      /*South*/       \
        LIMIT(1,-1) {SPREAD(1,-1)}    /*Southwest*/   \
        LIMIT(0,-1) {SPREAD(0,-1)}    /*West*/        \
        LIMIT(-1,-1) {SPREAD(-1,-1)}  /*Northwest*/    

// declare procedure and function
void mine(int n, int m, int mat[n][m]); // procedure for calculating mines
void rotate(int *n, int *m, int mat[*n][*m], char direc); // procedure for rotating the matrix
void print(int n, int m, int mat[n][m]); // procedure for print the matrix
void solve(); // procedure for solving the problem