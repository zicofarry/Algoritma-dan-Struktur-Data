/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan .... dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include <stdio.h>
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
    char owner[51];
    char plant[51];
    char type[51];
}box;

void solve(){
    isc(n);
    isc(m);
    box field[n*m];
    for(int i = 0; i < n*m; i++){
        scanf("%s %s %s", field[i].owner, field[i].plant, field[i].type);
    }
    char own[51];
    scanf("%s", own);

    box result[n*m];
    int r = 0, s = 0, l = 0;
    for(int i = 0; i < n*m; i++){
        if(strcmp(field[i].owner, own) == 0){
            result[r++] = field[i];
            if(strcmp(field[i].type, "sawah") == 0){
                s++;
            }else if(strcmp(field[i].type, "ladang") == 0){
                l++;
            }
        }
    }

    printf("nama pemilik: %s\n", own);
    printf("sawah: %d petak\n", s);
    printf("ladang: %d petak\n", l);
    if(r > 0){
        nl
        for(int i = 0; i < r; i++){
            printf("%s %s %s\n", result[i].owner, result[i].plant, result[i].type);   
        }
    }
}

int main(){slv return 0;}