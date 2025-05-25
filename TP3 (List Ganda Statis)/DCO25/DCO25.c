/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 3 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "DCO25.h" // include library "DCO25.h"

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
void addFirst(box new, list *L){
    if(countElement(*L) < 51){ // if list exceeds limit
        int baru = emptyElement(*L);
        (*L).data[baru].container = new;

        if((*L).first == -1){ // if list is empty
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }else{ // if list is not empty
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        
        (*L).first = baru;
    }else{
        /*process if array is full*/
        printf("can't be added anymore\n");
    }
}

// procedure to add element after element
void addAfter(int before, box new, list *L){
    if(countElement(*L) < 51){ // if list exceeds limit
        int baru = emptyElement(*L);
        (*L).data[baru].container = new;

        if((*L).data[before].next != -1){ // if element is not at the end
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        }else{ // if element at the end of list
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }else{
        /*process if array is full*/
        printf("can't be added anymore\n");
    }
}

// procedure to add element to the last place
void addLast(box new, list *L){
    if((*L).first == -1){ // if list is empty, call addFirst
        addFirst(new, L);
    }else{ // if list is not empty 
        addAfter((*L).tail, new, L);
    }
}

// procedure to search the previous element, before swap
void searchPrev(int *beforeX, int *x, list* L){
    // declare (p = pointer) and (prev = before pointer)
    int prev = -1; // prev start from -1
    int p = (*L).first; // point start from first
    while(p != -1 && p != *x){ // loop until find the x
        prev = p; // update prev
        p = (*L).data[p].next; // update point
    }
    *beforeX = prev; // save before x value
    *x = p; // save x value
}

// procedure for moving existing element to first place
void moveToFirst(int x, list* L){
    int beforeX; // declare beforeX
    searchPrev(&beforeX, &x, &(*L)); // update beforeX value by calling searchPrev procedure
    if(x != (*L).first){ // if x its not the first element
        (*L).data[beforeX].next = (*L).data[x].next; // beforeX (next) point to element after x
        if(x != (*L).tail){ // if x its not the tail
            (*L).data[(*L).data[beforeX].next].prev = (*L).data[x].prev; // after x (prev) point to before x 
        }else{ // if its not
            (*L).tail = beforeX; // update tail with beforeX
        }
        
        (*L).data[x].next = (*L).first; // x (next) point to first
        (*L).data[x].prev = -1; // x (prev) point to -1

        (*L).data[(*L).first].prev = x; // first (prev) point to x
        (*L).first = x; // update the first with x
    }
}

// procedure for moving existing element to after element called before
void moveToAfter(int before, int x, list* L){
    int beforeX; // declare beforeX
    searchPrev(&beforeX, &x, &(*L)); // update beforeX value by calling searchPrev procedure
    /*if before its not beforeX and before its not x,
    you have to do this, if its not you don't need to
    change anything*/
    if(before != beforeX && before != x){
        (*L).data[beforeX].next = (*L).data[x].next; // beforeX (next) point to element after x
        if(x != (*L).tail){ // if x its not the tail
            (*L).data[(*L).data[beforeX].next].prev = (*L).data[x].prev; // after x (prev) point to before x 
        }else{ // if its not
            (*L).tail = beforeX; // update tail with beforeX
        }
        
        (*L).data[x].next = (*L).data[before].next; // x (next) point to before next
        (*L).data[x].prev = before; // x (prev) point to before
        
        if(before == (*L).tail){ // if before is the tail
            (*L).tail = x; // update tail with x
        }else{ // if its not
            (*L).data[(*L).data[before].next].prev = x; // before next (prev) point to x
        }
        (*L).data[before].next = x; // before (next) point to x
    }
}

// procedure for moving existing element to the last place
void moveToLast(int x, list* L){
    if(x != (*L).tail){ // if x its not the tail
        moveToAfter((*L).tail, x, L); // call move after with before is the tail
    }
}

// procedure for sorting a list by urgency
void sortByUrgency(list *L){
    int point = (*L).first; // declare point, start from first
    while(point != -1){ // loop while its not -1
        int nextPoint = (*L).data[point].next; // save nextPoint value with point next
        if(strcmp((*L).data[point].container.urgency, "Mendesak") == 0){ // if urgency is "Mendesak"
            moveToFirst(point, &(*L)); // call procedure move to first
        }
        point = nextPoint; // update point with nextPoint to do increment
    }
}

// procedure for sorting a list by category
void sortByCategory(list* L){
    int before = (*L).tail; // declare before, start from tail
    // loop while urgency its not "Mendesak" and before its not -1
    while(strcmp((*L).data[before].container.urgency, "Mendesak") != 0 && before != -1){ 
        before = (*L).data[before].prev; // update before with before prev to do decrement
    }
    
    int point = (*L).first; // declare point, start from first
    int limit = -1; // declare limit, default limit is -1
    int mark = 0; // declare flag with mark is 0
    while(point != -1 && point != limit){ // loop while point its not -1 and point its not limit
        int nextPoint = (*L).data[point].next; // save nextPoint value with point next
        // if category is "Fragile" and urgency its not "Mendesak"
        if(strcmp((*L).data[point].container.category, "Fragile") == 0 &&
        strcmp((*L).data[point].container.urgency, "Mendesak") != 0){
            if(before != -1){ // if before its not -1
                moveToAfter(before, point, &(*L)); // call moveToAfter procedure
            }else{ // if its -1
                moveToFirst(point, &(*L)); // call moveToFirst procedure
            }
        // if category is "Heavy" and urgency its not "Mendesak"
        }else if(strcmp((*L).data[point].container.category, "Heavy") == 0 &&
        strcmp((*L).data[point].container.urgency, "Mendesak") != 0){
            if(!mark){ // if mark value its still 0
                limit = point; // update limit with point now
                mark = 1;
                // and then update mark value with 1,
                // so it will never enter this if again
            }
            moveToLast(point, &(*L)); // call moveToLast procedure
        }
        point = nextPoint; // update point with nextPoint to do increment
    }
}

// procedure to print element
void printElement(elemen point){
    printf("| %-16s| %-16s| %-16s|\n", point.container.name, point.container.category, point.container.urgency);
}

// procedure to print the list
void printList(list L){
    if(L.first != -1){ // if list its not empty
        printf("Data Paket dari Depan :\n");
        printf("+-----------------+-----------------+-----------------+\n");
        printf("|      Nama       |     Kategori    |     Urgensi     |\n");
        printf("+-----------------+-----------------+-----------------+\n");
        /*initialization*/
        int point = L.first;
        while(point != -1){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].next;
        }
        printf("+-----------------+-----------------+-----------------+\n");
        printReverse(L); // call printRevere procedure
    }else{ // if its not
        printf("empty list\n");
    }
}

void printReverse(list L){
    if(L.first != -1){ // if list its not empty
        printf("\nData Barang dari Belakang :\n");
        printf("+-----------------+-----------------+-----------------+\n");
        printf("|      Nama       |     Kategori    |     Urgensi     |\n");
        printf("+-----------------+-----------------+-----------------+\n");
        /*initialization*/
        int point = L.tail;
        while(point != -1){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].prev;
        }
        printf("+-----------------+-----------------+-----------------+\n");
    }else{ // if its not
        printf("empty list\n");
    }
}

// procedure to solve the problem
void solve(){
    list L; // declare list L
    createList(&L); // create list L
    int n; // declare n (number of elements of the list)
    scanf("%d", &n); // scan n value
    for(int i = 0; i < n; i++){ // loop until n
        box new; // declare box new
        scanf("%s %s %s", new.name, new.category, new.urgency); // scan container
        addLast(new, &L); // add container to the last of the list
    }
    sortByUrgency(&L); // call sortByUrgency procedure
    sortByCategory(&L); // call sortByCategory procedure
    printList(L); // call printList procedure
}