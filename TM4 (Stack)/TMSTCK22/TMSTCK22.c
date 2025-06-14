/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tes mesin 4 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "TMSTCK22.h"

void createEmpty(stack *S){
    (*S).top = NULL;
}
    
int isEmpty(stack S){
    int hasil = 0;
    if(S.top == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S){
    int hasil = 0;

    if(S.top != NULL){
        /* stack tidak kosong */
        elemen* bantu;
        
        /* inisialisasi */
        bantu = S.top;
        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;
            
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(box tmp, stack *S){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));

    baru->kontainer = tmp;
    if((*S).top == NULL){
        //jika stack kosong
        baru->next = NULL;
    }else{
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S){
    if((*S).top != NULL){
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if(countElement(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        printf("stack kosong");
    }
}

// procedure to move element to the first place (breakdown concept)
void popto(stack* S, stack* S2){
    elemen* x = (*S).top;
    (*S).top = (*S).top->next;
    
    // x next update with first element
    x->next = (*S2).top;
    
    // first update with x
    (*S2).top = x;
    x = NULL;
}

void printStack(stack S, stack S2){
    printf("---------------------------\n");
    if(S.top != NULL){
        printf("Baju di Lemari A:\n");
        elemen* bantu = S.top;
        int i = 1;
        while(bantu != NULL){
            printf("%d. %s %s\n", i, bantu->kontainer.baju, bantu->kontainer.size);
            
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }else{
        /* proses jika stack kosong */
        printf("Baju Lemari a:\n");
        printf("- KoShong!!!l\n");
    }
    if(S2.top != NULL){
        printf("\nBaju di Lemari B:\n");
        elemen* bantu = S2.top;
        int i = 1;
        while(bantu != NULL){
            printf("%d. %s %s\n", i, bantu->kontainer.baju, bantu->kontainer.size);
            
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }else{
        /* proses jika stack kosong */
        printf("\nBaju di lemari b:\n");
        printf("- KoShongg!!!\n");
    }
}