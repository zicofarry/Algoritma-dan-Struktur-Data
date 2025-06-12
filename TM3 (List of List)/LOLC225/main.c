/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 3 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char genre[50];
}mahasiswa;

typedef struct{
    char nama[51];
    char artis[51];
    int detik;
}matkul;

typedef struct eklm *alamatekolom;
typedef struct eklm{
    matkul kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
    mahasiswa kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;

void createList(list *L){
    (*L).first = NULL;
}

int countElementB(list L){
    int hasil = 0;
    if(L.first !=NULL){
        /*list tidak kosong*/
        eBaris* bantu;
        /*inisialisasi*/
        bantu = L.first;
        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;
            
            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L){
    int hasil = 0;
    if(L.col !=NULL){
        /*list tidak kosong*/
        eKolom* bantu;
        /*inisialisasi*/
        bantu = L.col;
        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;
            
            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char genre[], list *L){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.genre, genre);
    baru->col = NULL;
    if((*L).first == NULL){
        baru->next = NULL;
    }else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char nama[], char artis[], int detik, eBaris *L){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.nama, nama);
    strcpy(baru->kontainer_kol.artis, artis);
    baru->kontainer_kol.detik = detik;
    if((*L).col == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris* prev, char genre[]){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.genre, genre);
    baru->col = NULL;
    if(prev->next == NULL){
        baru->next = NULL;
    }else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom* prev, char nama[], char artis[], int detik){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.nama, nama);
    strcpy(baru->kontainer_kol.artis, artis);
    baru->kontainer_kol.detik = detik;
    if(prev->next_kol == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char genre[], list *L){
    if((*L).first == NULL){
        /*jika list adalah list kosong*/
        addFirstB(genre, L);
    }else{
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;
        while(last->next != NULL){
            /*iterasi*/
            last = last->next;
        }
        addAfterB(last, genre);
    }
}

void addLastK(char nama[], char artis[], int detik, eBaris *L){
    if((*L).col == NULL){
        /*jika list adalah list kosong*/
        addFirstK(nama, artis, detik, L);
    }
    else{
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eKolom *last = (*L).col;
        while(last->next_kol != NULL){
            /*iterasi*/
            last = last->next_kol;
        }
        addAfterK(last, nama, artis, detik);
    }
}

void delFirstK(eBaris *L){
    if((*L).col != NULL){
        /*jika list bukan list kosong*/
        eKolom* hapus = (*L).col;
        if(countElementK(*L) == 1){
            (*L).col = NULL;
        }else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom* prev){
    eKolom* hapus = prev->next_kol;
    if(hapus != NULL){
        if(hapus->next_kol == NULL){
            prev->next_kol = NULL; 
        }else{
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L){
    if((*L).col != NULL){
        /*jika list tidak kosong*/
        if(countElementK(*L) == 1){
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }else{
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while(last->next_kol != NULL){
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L){
    if(countElementK(*L) != 0){
        int i;
        for(i=countElementK(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L){
    if((*L).first != NULL){
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;
        if(hapus->col != NULL){
            //menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }
        if(countElementB(*L) == 1){
            (*L).first = NULL;
        }else{
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        printf("list kosong");
    }
}

void delAfterB(eBaris* prev){
    if(prev != NULL){
        eBaris *hapus = prev->next;
        if(hapus != NULL){
            if(hapus->col != NULL){
                //menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
            if(hapus->next == NULL){
                prev->next = NULL;
            }else{
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L){
    if((*L).first != NULL){
        /*jika list tidak kosong*/
        if(countElementB(*L) == 1){
        /*list terdiri dari satu
        elemen*/
        delFirstB(L);
        }else{
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while(last->next != NULL){
                /*iterasi*/
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L){
    if(countElementB(*L) != 0){
        int i;
        for(i=countElementB(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L){
    printf("+==============================+\n");
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris* bantu = L.first;
        int i = 1;
        while(bantu != NULL){
            printf("%s:\n", bantu->kontainer.genre);
            /*proses*/
            eKolom* eCol = bantu->col;
            while(eCol != NULL){
                printf("| - %s : %s - %d menit %d detik\n",eCol->kontainer_kol.nama, eCol->kontainer_kol.artis, eCol->kontainer_kol.detik/60, eCol->kontainer_kol.detik%60);
                // printf("nama kuliah : %s\n", eCol->kontainer_kol.nama);
                // printf("artis : %s\n", eCol->kontainer_kol.artis);
                eCol = eCol->next_kol;
            }
            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
    }else{
        /*proses jika list kosong*/
        printf("List habis deh :(\n");
    }
}

int main(){
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        mahasiswa new;
        scanf("%s", new.genre);
        addLastB(new.genre, &L);
        matkul baru[5];
        for(int j = 0; j < 5; j++){
            scanf("%s %s %d", baru[j].nama, baru[j].artis, &baru[j].detik);
        }
        eBaris* bantu = L.first;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        addLastK(baru[0].nama, baru[0].artis, baru[0].detik, bantu);
        addLastK(baru[1].nama, baru[1].artis, baru[1].detik, bantu);
        addFirstK(baru[2].nama, baru[2].artis, baru[2].detik, bantu);
        addAfterK(bantu->col->next_kol, baru[3].nama, baru[3].artis, baru[3].detik);
        addFirstK(baru[4].nama, baru[4].artis, baru[4].detik, bantu);
    }


    printElement(L);
    delAfterK(L.first->next->col);//
    // delAfterK(L.first->next->col->next_kol);//
    delAfterB(L.first->next);
    // delLastB(&L);
    printElement(L);
    delLastK(L.first);
    delFirstK(L.first->next);
    printElement(L);
    // delAfterB(L.first);//
    delFirstB(&L);
    printElement(L);
    delAllB(&L);
    printElement(L);
    printf("+==============================+\n");

    // printElement(L);
    // printf("=================\n");
    // addFirstB("1", "Orang_1", &L);
    // addFirstK("IF40K1", "A", L.first);
    // addAfterK(L.first->col, "IF40Z1", "A");
    // addLastK("IF40Z2", "A", L.first);
    // addAfterB(L.first, "2", "Orang_2");
    // addFirstK("TI5141", "A", L.first->next);
    // addLastK("IF5021", "A", L.first->next);
    // addLastB("3", "Orang_3", &L);
    // addFirstK("IF5321", "A", L.first->next->next);
    // printElement(L);
    // printf("=================\n");
    // delAllB(&L);
    // printElement(L);
    // printf("=================\n");
    return 0;
}