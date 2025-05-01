/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UTS soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "prtk25.h" // include header "prtk25.h"

// procedure to create the list
void createList(list *L){
    (*L).first = -1;
    (*L).tail = -1;

    for(int i = 0; i < 51; i++){
        /*the process of initializing the contents of an array*/
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

// procedure to count the element
int countElement(list L){
    int result = 0;
    if(L.first != -1){
        /*list is not empty*/
        int point;

        /*initialization*/
        point = L.first;

        while(point != -1){
            /*process*/
            result = result + 1;

            /*iteration*/
            point = L.data[point].next;
        }
    }

    return result;
}

// procedure to create a new empty element
int emptyElement(list L){
    int result = -1;

    if(countElement(L) < 51){
        int find = 0;

        int i = 0;
        while((find == 0) && (i < 51)){
            if(L.data[i].next == -2){
                result = i;
                find = 1;
            }else{
                i = i + 1;
            }
        }
    }
    return result;
}

// procedure to add element to the first place
void addFirst(box temp, list *L){
    if(countElement(*L) < 51){ // if list exceeds limit
        int new = emptyElement(*L);
        (*L).data[new].container = temp;

        if((*L).first == -1){ // if list is empty
            (*L).data[new].prev = -1;
            (*L).data[new].next = -1;
            (*L).tail = new;
        }else{ // if list is not empty
            (*L).data[new].prev = -1;
            (*L).data[new].next = (*L).first;
            (*L).data[(*L).first].prev = new;
        }
        
        (*L).first = new;
    }else{
        /*process if array is full*/
        printf("can't be added anymore\n");
    }
}

// procedure to print element
void printElement(elemen point){
    printf("%s %d %d\n", point.container.name, point.container.price, point.container.year);
}

// procedure to print the list from middle to last
void printList(list L){
    if(L.first != -1){ // if list its not empty
        
        printf("\ntengah belakang:\n");
        /*initialization*/
        int point = countElement(L)/2 - 1;
        while(point != -1){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].next;
        }
    }else{ // if its not
        printf("empty list\n");
    }
}

// procedure to print the list from middle to first
void printReverse(list L){
    if(L.first != -1){ // if list its not empty
        printf("tengah depan:\n");
        /*initialization*/
        int point = countElement(L)/2;
        while(point != -1){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].prev;
        }
    }else{ // if its not
        printf("empty list\n");
    }
}

// procedure to solve the problem
void solve(){
    list L; // declare list L
    createList(&L); // call procedure createList
    int n; // declare n to save the number of elements of the list
    scanf("%d", &n); // input the number of n
    for(int i = 0; i < n; i++){ // loop until n
        box new; // declare box new
        scanf("%s %d %d", new.name, &new.price, &new.year); // scanf value for container new
        addFirst(new, &L); // add container new to the first place, by calling addFirst procedure
    }
    // print the list
    printReverse(L);
    printList(L);
}