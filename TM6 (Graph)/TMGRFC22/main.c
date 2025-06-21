/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tes Mesin 6 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TMGRFC22.h"

int main(){
    graph G;
    createEmpty(&G);
    int n;
    boxSmp x;
    boxSmp y;
    boxJlr z;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %c %c %d", &x.c, &y.c, &z.n);
        simpul *find = findSimpul(x, G);
        if(find == NULL){
            addSimpul(x, &G);
        }
        simpul *find2 = findSimpul(y, G);
        if(find2 == NULL){
            addSimpul(y, &G);
        }

        simpul *begin = findSimpul(x, G);
        simpul *end = findSimpul(y, G);
        if((begin != NULL) && (end != NULL)){
            addJalur(begin, end, z);
        }
    }
    scanf(" %c", &x.c);
    
    printf("~~~~~~~~~~~~~\n");
    printf("beF0r3:\n");
    printGraph(G);
    delSimpul(x, &G);
    printf("! ! !\n");
    printf("aFteR:\n");
    printGraph(G);
    printf("~~~~~~~~~~~~~\n");

    return 0;
}