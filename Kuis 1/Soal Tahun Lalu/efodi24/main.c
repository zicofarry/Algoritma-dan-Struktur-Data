#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define DEBUG(str, var) printf("%s = %d\n", str, var);
#define DEBAR(arr, n)                        \
    for(int i = 0; i < n; i++){              \
        printf("arr[%d] = %d\n", i, arr[i]);   \
    }
#define slv solve();
#define nl printf("\n");
#define isc(n)              \
        int n;              \
        scanf("%d", &n);


typedef struct{
    char photo[101];
    int date;
    int month;
    int year;
}nilai;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilai kontainer;
    alamatelmt next;
} elemen;

typedef struct{
    elemen* first;
}list;

int i = 1;


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

void addFirst(nilai temp, list *L){
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;

    // jika list kosong    
    if((*L).first == NULL){
        baru->next = NULL;
    // jika bukan list kosong
    }else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, nilai temp, list *L){
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;
    // jika elemen di akhir (prev next null)
    if(prev->next == NULL){
        baru->next = NULL;
    }
    // jika elemen bukan di akhir
    else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;  
}

void addLast(nilai temp, list *L){
    // jika list kosong gunakan addFirst
    if((*L).first == NULL){
      addFirst(temp, L);
    }
    // jika list tidak kosong 
    else{
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        // gunakan addAfter setelah ketemu prev di akhir
        addAfter(prev, temp, L);
    }
}

void delFirst(list *L){
    // jika list tidak kosong
    if((*L).first != NULL){   
        elemen* hapus = (*L).first;
        // jika elemen hanya 1
        if(countElement(*L) == 1){
            (*L).first = NULL;
        }
        // jika elemen lebih dari 1
        else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        // hapus di free kan
        free(hapus);
    }  
}

void delAfter(elemen* prev, list *L){
    // jika prev bukan NULL
    if(prev != NULL){
        // declare pointer hapus dan diisi prev next
        elemen* hapus = prev->next;
        // jika elemen di akhir
        if(hapus->next == NULL){
            prev->next = NULL;
        // jika elemen bukan di akhir
        }else{
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        // hapus di free kan
        free(hapus);
    }
}

void delLast(list *L){
    // jika list tidak kosong
    if((*L).first != NULL){
        // jika elemen hanya 1 gunakan delFirst
        if(countElement(*L) == 1){
            delFirst(L);
        }
        // jika elemen lebih dari 1
        else{
            // declare pointer last dan prev
    
            elemen* last = (*L).first;
    
            elemen* prev;
            // loop untuk mencari posisi last dan prev
            while(last->next != NULL){
                // iterasi
                prev = last;
                last = last->next;
            }
        delAfter(prev, L);
        }
    }
}


void printElement(list L){
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* tunjuk = L.first;
        int i = 1;
        while(tunjuk != NULL){
            /*proses*/
            printf("%s %d %d %d\n", tunjuk->kontainer.photo, tunjuk->kontainer.date, tunjuk->kontainer.month, tunjuk->kontainer.year);
            /*iterasi*/
            tunjuk = tunjuk->next;
            i++;
        }
    }else{
        /*proses jika list kosong*/
        printf("list kosong\n");
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

// Fungsi mendapatkan elemen terakhir
elemen* getLastElement(list L) {
    elemen *temp = L.first;
    while (temp != NULL && temp->next != NULL)
    temp = temp->next;
    return temp;
}

void moveToFirst(elemen* beforeX, elemen* x, list* L){
    // before next diganti dulu
    beforeX->next = x->next;

    // x next jadi first
    x->next = (*L).first;

    // first jadi x
    (*L).first = x;
}

void moveToLast(elemen* beforeA, elemen* a, list* L){
    if(a->next != NULL){ // Jika a belum di posisi terakhir
        if(beforeA == NULL){
            // Jika a adalah elemen pertama
            (*L).first = a->next; // Perbarui first
        } else {
            // Jika a bukan elemen pertama
            beforeA->next = a->next;
        }
        // printf("masok i = %d\n", i);

        // Temukan elemen terakhir
        elemen* last = getLastElement(*L);
        last->next = a; // Sambungkan a ke akhir list
        a->next = NULL; // Pastikan a jadi elemen terakhir
    }
}



// void moveToLast(elemen* beforeA, elemen* a, list* L){
//     if(a->next != NULL){
//         if(beforeA == NULL){
//             //a next jadi first
//             elemen* afterA = a->next;
//             afterA = (*L).first;
    
//             // last jadi a
//             getLastElement(*L)->next = a;
    
//             // a next jadi NULL
//             a->next = NULL;
            
//         }else{
//             // before next diganti dulu
//             beforeA->next = a->next;
            
//             // a next jadi NULL
//             a->next = NULL;

//             // last jadi a
//             getLastElement(*L)->next = a;
//         }
//     }
// }

// void movePhoto(int limitMonth, int limitYear, list* L){
//     // declare pointer elemen
//     elemen* beforeTunjuk = NULL;
//     elemen* tunjuk = (*L).first;

//     // loop untuk setiap elemen
//     while(tunjuk != NULL){
//         // declare save untuk menyimpan beforeTunjuk (jika diswap)
//         elemen* save = beforeTunjuk;

//         //declare elemen beforeTemp dan temp buat iterasi
//         elemen* beforeTemp = tunjuk;
//         elemen* temp = tunjuk->next;

//         // jika bulan dan tahun lebih besar atau sama
//         if(tunjuk->kontainer.month >= limitMonth && tunjuk->kontainer.year >= limitYear){
//             // panggil moveToFirst
//             // moveToFirst(beforeTunjuk, tunjuk, L);
//             moveToLast(beforeTunjuk, tunjuk, L);
//             //beforeTunjuk jadi temp
//             beforeTunjuk = save;
//         }else{ // jika tidak swap
//             beforeTunjuk = beforeTemp;
//         }
//         //tunjuk jadi temp
//         tunjuk = temp;
        
//     }
// }

void movePhoto(int limitMonth, int limitYear, list* L){
    elemen* beforeTunjuk = NULL;
    elemen* tunjuk = (*L).first;

    while(tunjuk != NULL){
        elemen* temp = tunjuk->next; // Simpan next sebelum mengubah posisi
        
        if(tunjuk->kontainer.month >= limitMonth && tunjuk->kontainer.year >= limitYear){
            moveToLast(beforeTunjuk, tunjuk, L);
            // moveToFirst(beforeTunjuk, tunjuk, L);
            
            // Jika elemen pertama yang dipindah, first sudah berubah, perlu reset pointer
            if(beforeTunjuk == NULL) {
                tunjuk = (*L).first;
            } else {
                tunjuk = temp;
            }
        } else {
            beforeTunjuk = tunjuk;
            tunjuk = temp;
        }
    }
}

void movePhotoToLast(int limitMonth, int limitYear, list* L) {
    elemen* beforeTunjuk = NULL;
    elemen* tunjuk = (*L).first;
    elemen* last = NULL;
    int i = 0;
    int stop = 0;
    while (tunjuk != NULL && tunjuk->next != last) {
        // printf("%d ", i);
        elemen* beforeTemp = tunjuk; // Simpan next sebelum mengubah posisi
        elemen* temp = tunjuk->next; // Simpan next sebelum mengubah posisi

        if (tunjuk->kontainer.month >= limitMonth && tunjuk->kontainer.year >= limitYear) {
            printf("masok1\n");
            // Cek sebelum akses beforeTunjuk untuk menghindari segmentation fault
            //     printf("%s %d %d %d\n", beforeTunjuk->kontainer.photo, beforeTunjuk->kontainer.date, beforeTunjuk->kontainer.month, beforeTunjuk->kontainer.year);
            // printf("%s %d %d %d\n", tunjuk->kontainer.photo, tunjuk->kontainer.date, tunjuk->kontainer.month, tunjuk->kontainer.year);
            if(!stop){
                last = getLastElement(*L);
                stop = 1;
            }
            moveToLast(beforeTunjuk, tunjuk, L);
            // printf("masok3\n");
            
            
            beforeTunjuk = beforeTemp;
            tunjuk = temp;
        } else {
            // printf("masok2\n");
            beforeTunjuk = tunjuk;
            tunjuk = temp;
        }
        // printf("%d\n", tunjuk);
        i++;
    }
}


void movePhotoToLast(int limitMonth, int limitYear, list* L) {
    if ((*L).first == NULL) return; // Jika list kosong, langsung return

    elemen* beforeTunjuk = NULL;
    elemen* tunjuk = (*L).first;
    elemen* last = getLastElement(*L); // Ambil elemen terakhir sebelum mulai

    while (tunjuk != NULL && tunjuk != last) { // Loop sampai sebelum last
        elemen* temp = tunjuk->next; // Simpan next sebelum mengubah posisi

        if (tunjuk->kontainer.month >= limitMonth && tunjuk->kontainer.year >= limitYear) {
            // printf("masok1\n");
            
            moveToLast(beforeTunjuk, tunjuk, L);
            
            // **Update last hanya jika tunjuk adalah last sebelum dipindah**
            if (tunjuk == last) {
                last = getLastElement(*L);
            }

            // **Reset pointer setelah pindah**
            if (beforeTunjuk == NULL) {
                tunjuk = (*L).first; // Jika elemen pertama yang dipindah
            } else {
                beforeTunjuk->next = temp; // Hubungkan ulang list
                tunjuk = temp; // Lanjutkan ke elemen berikutnya
            }
        } else {
            beforeTunjuk = tunjuk;
            tunjuk = temp;
        }
    }
    
    if(tunjuk == last){
        elemen* temp = tunjuk->next; // Simpan next sebelum mengubah posisi
        
        if (tunjuk->kontainer.month >= limitMonth && tunjuk->kontainer.year >= limitYear) {
            // printf("masok2\n");
            moveToLast(beforeTunjuk, tunjuk, L);
        } else {
            beforeTunjuk = tunjuk;
            tunjuk = temp;
        }
    }
}


void solve(){
    list L;
    createList(&L);
    int n, limitMonth, limitYear;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        nilai new;
        scanf("%s %d %d %d", new.photo, &new.date, &new.month, &new.year);   
        addLast(new, &L);
    }
    scanf("%d %d", &limitMonth, &limitYear);
    // printf("%s %d %d %d\n", getLastElement(L)->kontainer.photo, getLastElement(L)->kontainer.date, getLastElement(L)->kontainer.month, getLastElement(L)->kontainer.year);
    //move photo
    movePhotoToLast(limitMonth, limitYear, &L);
    
    //print list
    printElement(L);
}

int main(){slv return 0;}