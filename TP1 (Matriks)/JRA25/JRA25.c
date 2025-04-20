/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "JRA25.h" // include library "JRA25.h"

// procedure for calculating mines
void mine(int n, int m, int mat[n][m]){
    // looping matrix per index
    loopMat(if(mat[i][j] == -1){MINE}) // if value is -1, call macro MINE
}

// procedure for rotating the matrix
void rotate(int *n, int *m, int mat[*n][*m], char direc){
    if(direc == 'U'){// if direc equal to 'U'
        // nothing's change
        print(*n, *m, mat); // print the matrix
    }else if(direc == 'S'){// if direc equal to 'S'
        int temp[*n][*m]; // declare temp to saving matrix rotation
        SWAPMAT(temp[*n - 1 - i][*m - 1 - j], mat[i][j]) // rotate the matrix 180 degrees
        print(*n, *m, temp); // print the matrix after rotation
    }else if(direc == 'T'){// if direc equal to 'T'
        int temp[*m][*n]; // declare temp to saving matrix rotation
        SWAPMAT(temp[j][*n - i - 1], mat[i][j]) // rotate the matrix 90 degrees clockwise
        print(*m, *n, temp); // print the matrix after rotation
    }else if(direc == 'B'){// if direc equal to 'B'
        int temp[*m][*n]; // declare temp to saving matrix rotation
        SWAPMAT(temp[*m - j - 1][i], mat[i][j]) // rotate the matrix 90 degrees counterclockwise
        print(*m, *n, temp); // print the matrix after rotation
    }
}
    
// procedure for print the matrix
void print(int n, int m, int mat[n][m]){
    printf("Peta Zona Aman:\n");
    for(int i = 0; i < n; i++){ // loop for the row
        printf("|");
        for(int j = 0; j < m; j++){ // loop for the column
            printf("%3d", mat[i][j]); // print matrix per index
        }
        printf(" |\n");
    }   
}

// procedure for solving the problem
void solve(){
    int n, m; // declare int (n -> row) and (m -> column)
    char direc; // declare char to saving value of direction
    scanf("%d %d %c", &n, &m, &direc); // scan value for n, m, and direc
    int mat[n][m]; // declare matrix integer
    loopMat(scanf("%d", &mat[i][j]);) // loop to scan value per index matrix
    mine(n, m, mat); // call procedure algorithm of mine
    rotate(&n, &m, mat, direc); // call procedure rotate to rorate and print the matrix
}