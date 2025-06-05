/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tes Mesin 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "LGDC225.h"

void initList(list *L){
    (*L).head = NULL;
    (*L).tail = NULL;
}

int countElement(list L){
    int hasil = 0;

    if(L.head != NULL){
        elemen* tunjuk;
        tunjuk = L.head;
        while(tunjuk != NULL){
            hasil++;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(nilai value, list *L){
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = value;

    // jika list kosong
    if((*L).head == NULL){
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    
    // jika list tidak kosong
    }else{
        baru->prev = NULL;
        baru->next = (*L).head;
        (*L).head->prev = baru;
    }
    (*L).head = baru;
    baru = NULL;
}

void addAfter(elemen* before, nilai value, list *L){
    if(before != NULL){
        elemen* baru;
        baru = (elemen*) malloc(sizeof(elemen));
        baru->kontainer = value;

        // jika elemen terakhir
        if(before == (*L).tail){
            (*L).tail = baru;
            baru->next = NULL;

        // jika bukan elemen terakhir
        }else{
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen* after, nilai value, list *L){
    if(after != NULL){
        elemen* baru;
        baru = (elemen*) malloc(sizeof(elemen));
        baru->kontainer = value;

        // jika elemen pertama
        if(after == (*L).head){
            (*L).head = baru;
            baru->prev = NULL;

        // jika bukan elemen pertama
        }else{
            baru->prev = after->prev;
            baru->prev->next = baru;
        }
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

void addLast(nilai value, list *L){
    // kalo list kosong
    if((*L).head == NULL){
        addFirst(value, L);

    // kalo list ga kosong
    }else{
        addAfter((*L).tail, value, L);
    }
}

void delFirst(list *L){
    if((*L).head != NULL){
        elemen* hapus = (*L).head;

        // jika hanya ada satu elemen
        if(countElement(*L) == 1){
            (*L).head = NULL;
            (*L).tail = NULL;
        
        // jika tidak hanya ada satu elemen
        }else{
            (*L).head = (*L).head->next;
            (*L).head->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* before, list *L){
    if(before != NULL){
        elemen* hapus = before->next;

        // jika elemen terakhir yang mau dihapus
        if(hapus->next == NULL){
            before->next = NULL;
            (*L).tail = before;

        // jika bukan elemen terakhir yang mau dihapus
        }else{
            before->next = hapus->next;
            hapus->next->prev = before;
            hapus->next = NULL;
        }
        hapus->prev = NULL;
        free(hapus);
    }
}

void delLast(list *L){
    if((*L).head != NULL){

        // jika hanya ada satu elemen
        if(countElement(*L) == 1){
            delFirst(L);

        // jika ada lebih dari 1 elemen
        }else{
            delAfter((*L).tail->prev, L);
        }
    }
}

void delAll(list *L){
    if(countElement(*L) != 0){
        int i;
        for(i = countElement(*L); i>= 1; i--){
            delLast(L);
        }
    }
}

void printList(list L){
    printf("+-------------------------------------+\n");
    printf("|         List Katalog Laptop         |\n");
    printf("+-------------------------------------+\n");
    if(L.head != NULL){
        elemen* tunjuk = L.head;
        int i = 1;
        while(tunjuk != NULL){
            printf("| %d. %s %s %d %d\n", i, tunjuk->kontainer.merk, tunjuk->kontainer.tipe, tunjuk->kontainer.stok, tunjuk->kontainer.harga);
            tunjuk = tunjuk->next;
            i++;
        }
    }else{
        printf("| - Katalog lagi kosong\n");
    }
    printf("+-------------------------------------+\n");
}

void printReverse(list L){
    printf("+-------------------------------------+\n");
    printf("|         List Katalog Laptop         |\n");
    printf("+-------------------------------------+\n");
    if(L.tail != NULL){
        elemen* tunjuk = L.tail;
        int i = 1;
        while(tunjuk != NULL){
            printf("| %d. %s %s %d %d\n", i, tunjuk->kontainer.merk, tunjuk->kontainer.tipe, tunjuk->kontainer.stok, tunjuk->kontainer.harga);
            tunjuk = tunjuk->prev;
            i++;
        }
    }else{
        printf("| - Katalog lagi kosong\n");
    }
    printf("+-------------------------------------+\n");
}