/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tes Mesin 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "LGDC225.h"

int main(){
    list L;
    initList(&L);
    nilai new[7];
    for(int i = 0; i < 7; i++){
        scanf("%s %s %d %d", new[i].merk, new[i].tipe, &new[i].harga, &new[i].stok);
    }
    addLast(new[0], &L);
    addFirst(new[1], &L);
    addLast(new[2], &L);
    addBefore(L.head, new[3], &L);
    printList(L);

    addAfter(L.head, new[4], &L);
    delLast(&L);
    delAfter(L.head, &L);
    addBefore(L.tail, new[5], &L);
    delFirst(&L);
    printReverse(L);

    delAll(&L);
    printList(L);

    addLast(new[6], &L);
    printList(L);

    delLast(&L);
    printList(L);

    return 0;
}