/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 1 soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "mtbps25.h" // include my header -> mtbps25.h

void solve(){ // make solve algorithm
    // declare and scanf int n and m
    isc(n); 
    isc(m); 

    // declare package matrix n x m
    box mat[n][m];

    // declare kcolor to count the tendency color for every pixel
    int kcyan = 0, kmagen = 0, kyell = 0, kkey = 0;

    // declare lcolor to count total tendency for every color
    int lcyan = 0, lmagen = 0, lyell = 0, lkey = 0;

    for(int i = 0; i < n; i++){ // loop for the row
        for(int j = 0; j < m; j++){ // loop for the column
            // scan each color pixel at each index of the matrix
            scanf("%d %d %d %d", &mat[i][j].cyan, &mat[i][j].magen, &mat[i][j].yell, &mat[i][j].key);

            // make condition to check the tendency color
            if(mat[i][j].cyan > mat[i][j].magen && mat[i][j].cyan > mat[i][j].yell && mat[i][j].cyan > mat[i][j].key){
                // if it tends to cyan
                lcyan += mat[i][j].cyan; // count up the total of cyan that tendency color
                kcyan++; // count up cyan color that tendeny
            }else if(mat[i][j].magen > mat[i][j].cyan && mat[i][j].magen > mat[i][j].yell && mat[i][j].magen > mat[i][j].key){
                // if it tends to magenta
                lmagen += mat[i][j].magen; // count up the total of magenta that tendency color
                kmagen++; // count up magenta color that tendeny
            }else if(mat[i][j].yell > mat[i][j].cyan && mat[i][j].yell > mat[i][j].magen && mat[i][j].yell > mat[i][j].key){
                // if it tends to yellow
                lyell += mat[i][j].yell; // count up the total of yellow that tendency color
                kyell++; // count up yellow color that tendeny
            }else if(mat[i][j].key > mat[i][j].cyan && mat[i][j].key > mat[i][j].magen && mat[i][j].key > mat[i][j].yell){
                // if it tends to key
                lkey += mat[i][j].key; // count up the total of key that tendency color
                kkey++; // count up key color that tendeny
            }
        }
    }

/*print output according to the input that has been processed*/
    // print total tendency color for every pixel
    printf("cenderung cyan: %d - total: %d\n", kcyan, lcyan);
    printf("cenderung magenta: %d - total: %d\n", kmagen, lmagen);
    printf("cenderung yellow: %d - total: %d\n",kyell, lyell);
    printf("cenderung key: %d - total: %d\n", kkey, lkey);
    printf("\n");

    // print the conclusion the most likely tendency color
    if(lcyan > lmagen && lcyan > lyell && lcyan > lkey){
        printf("kesimpulan: cyan\n");
    }else if(lmagen > lcyan && lmagen > lyell && lmagen > lkey){
        printf("kesimpulan: magenta\n");
    }else if(lyell > lcyan && lyell > lmagen && lyell > lkey){
        printf("kesimpulan: yellow\n");
    }else if(lkey > lcyan && lkey > lmagen && lkey > lyell){
        printf("kesimpulan: key\n");
    }
}