/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TM1C225.h"

int main(){
    list L;
    createList(&L);
    value baru[6];
    for(int i = 0; i < 6; i++){
        scanf("%s %s %d %s", baru[i].merk, baru[i].tipe, &baru[i].tahun, baru[i].status);
    }
    addFirst(baru[0].merk, baru[0].tipe, baru[0].tahun, baru[0].status, &L);
    addAfter(L.first, baru[1].merk, baru[1].tipe, baru[1].tahun, baru[1].status, &L);
    addLast(baru[2].merk, baru[2].tipe, baru[2].tahun, baru[2].status, &L);
    addAfter(L.first, baru[3].merk, baru[3].tipe, baru[3].tahun, baru[3].status, &L);
    
    printElement(L);
    
    delLast(&L);
    addAfter(L.first->next, baru[4].merk, baru[4].tipe, baru[4].tahun, baru[4].status, &L);
    delFirst(&L);
    
    printElement(L);
    
    delAfter(L.first, &L);
    addLast(baru[5].merk, baru[5].tipe, baru[5].tahun, baru[5].status, &L);

    printElement(L);

    delAll(&L);

    printElement(L);
    printf("----------------------------------------\n");

    return 0;
}