/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 4 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TMSTCK22.h"

int main(){
    stack S1;
    createEmpty(&S1);
    stack S2;
    createEmpty(&S2);
    box new[8];
    for(int i = 0; i < 8; i++){
        scanf("%s %s", new[i].baju, new[i].size);
    }
    printStack(S1, S2);
    push(new[0], &S1);
    push(new[1], &S1);
    push(new[2], &S1);
    push(new[3], &S2);
    printStack(S1, S2);
    popto(&S1, &S2);
    popto(&S1, &S2);
    printStack(S1, S2);
    push(new[4], &S2);
    push(new[5], &S2);
    popto(&S1, &S2);
    push(new[6], &S1);
    push(new[7], &S1);
    pop(&S2);
    pop(&S1);
    popto(&S2, &S1);
    popto(&S2, &S1);
    printStack(S1, S2);
    printf("---------------------------\n");
    return 0;
}
