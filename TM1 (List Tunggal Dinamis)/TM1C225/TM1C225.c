/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TM1C225.h"

void createList(list *L){
    (*L).first = NULL;    
}

int countElement(list L){
    int hasil = 0;
    
    if(L.first !=NULL){
        /*list tidak kosong*/

        elemen* tunjuk;
        
        /*inisialisasi*/
        tunjuk = L.first;
        while(tunjuk != NULL){
            /*proses*/
            hasil = hasil + 1;
            
            /*iterasi*/
            tunjuk = tunjuk->next;
        }
    }
    
    return hasil;
}

void addFirst(char merk[], char tipe[], int tahun, char status[], list *L){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.tipe, tipe);
    baru->kontainer.tahun = tahun;
    strcpy(baru->kontainer.status, status);
    if((*L).first == NULL){
        baru->next = NULL;
    }else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, char merk[], char tipe[], int tahun, char status[], list *L){
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.tipe, tipe);
    baru->kontainer.tahun = tahun;
    strcpy(baru->kontainer.status, status);
    if(prev->next == NULL){
        baru->next = NULL;
    }else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char merk[], char tipe[], int tahun, char status[], list *L){
    if((*L).first == NULL){
        /*jika list adalah list kosong*/
        addFirst(merk, tipe, tahun, status, L);
    }else{
        /*jika list tidak kosong
        mencari elemen terakhir list*/
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            /*iterasi*/
            prev = prev->next;
        }
        addAfter(prev, merk, tipe, tahun, status, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
        /*jika list bukan list kosong*/
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1){
            (*L).first = NULL;    
        }else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* prev, list *L){
    if(prev != NULL){ // so it doesnt leak
        elemen* hapus = prev->next;
        if(hapus != NULL){
            if(hapus->next == NULL){
                prev->next = NULL;
            }else{
                prev->next = hapus->next;
                hapus->next = NULL;
            }
        free(hapus);
        }
    }
}

void delLast(list *L){
    if((*L).first != NULL){
        /*jika list tidak kosong*/
        if(countElement(*L) == 1){
            /*list terdiri dari satu elemen*/        
            delFirst(L);
        }else{
            /*mencari elemen terakhir list*/
            elemen* last = (*L).first;
            elemen* prev;
            while(last->next != NULL){
                /*iterasi*/
                prev = last;
                last = last->next;
            }
        delAfter(prev, L);
        }
    }
}

void printElement(list L){
    printf("----------------------------------------\n");
    printf("Data Armada TalRental :\n");
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* tunjuk = L.first;
        int i = 1;
        while(tunjuk != NULL){
            /*proses*/
            printf("- %d %s %s %s\n", tunjuk->kontainer.tahun, tunjuk->kontainer.merk, tunjuk->kontainer.tipe,tunjuk->kontainer.status);
            /*iterasi*/
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    }else{
        /*proses jika list kosong*/
        printf("TalRental tanpa mobil anjay.\n");
    }
}

void delAll(list *L){
    if(countElement(*L) != 0){
        int i;    
        for(i=countElement(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}