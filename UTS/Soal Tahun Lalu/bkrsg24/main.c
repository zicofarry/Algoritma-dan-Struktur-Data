#include <stdio.h>
#include <string.h>

#define slv solve();

/*Overall, this program mostly uses O(n) or linear,
but in one process it uses O(n^2) or exponential,
namely when calling addlast in the n loop.*/

// declare typedef struct
typedef struct{
    // contents of the container 
    char row[4];
    char name[51];
    char condition[51];
}box;

typedef struct{
    box container;
    int prev;
    int next;
}elemen;

typedef struct{
    int first;
    int tail;
    elemen data[51];
}list;

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

// procedure to add element after element
void addAfter(int before, box temp, list *L){
    if(countElement(*L) < 51){ // if list exceeds limit
        int new = emptyElement(*L);
        (*L).data[new].container = temp;

        if((*L).data[before].next != -1){ // if element is not at the end
            (*L).data[new].prev = before;
            (*L).data[new].next = (*L).data[before].next;
            (*L).data[before].next = new;
            (*L).data[(*L).data[new].next].prev = new;
        }else{ // if element at the end of list
            (*L).data[new].prev = before;
            (*L).data[before].next = new;
            (*L).data[new].next = -1;
            (*L).tail = new;
        }
    }else{
        /*process if array is full*/
        printf("can't be added anymore\n");
    }
}

// procedure to add element before element
void addBefore(int after, box temp, list *L){
    if(countElement(*L) < 51){ // if list exceeds limit
        int new = emptyElement(*L);
        (*L).data[new].container = temp;

        if((*L).data[after].prev != -1){ // if element is not at the end
            (*L).data[new].next = after;
            (*L).data[new].prev = (*L).data[after].prev;
            (*L).data[after].prev = new;
            (*L).data[(*L).data[new].prev].next = new;
        }else{ // if element at the end of list
            (*L).data[new].next = after;
            (*L).data[after].prev = new;
            (*L).data[new].prev = -1;
            (*L).first = new;
        }
    }else{
        /*process if array is full*/
        printf("can't be added anymore\n");
    }
}

// procedure to add element to the last place
void addLast(box temp, list *L){
    if((*L).first == -1){ // if list is empty, call addFirst
        addFirst(temp, L);
    }else{ // if list is not empty 
        addAfter((*L).tail, temp, L);
    }
}

// procedure for moving existing element to after element called before
void moveToAfter(int before, int x, list* L){
    int beforeX = (*L).data[x].prev; // declare beforeX
    /*if before its not beforeX and before its not x,
    you have to do this, if its not you don't need to
    change anything*/
    if(before != beforeX && before != x){
        if(x != (*L).first){
            (*L).data[beforeX].next = (*L).data[x].next; // beforeX (next) point to element after x
        }else{
            (*L).first = (*L).data[x].next; // update first with afterX
        }

        if(x != (*L).tail){ // if x its not the tail
            (*L).data[(*L).data[x].next].prev = beforeX; // after x (prev) point to before x 
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

// procedures for selecting flowers based on conditions
void selection(list* L){
    int point = (*L).first;
    int mark = 0;
    int last = -1;
    while(point != last){
        int nextPoint = (*L).data[point].next;
        if(strcmp((*L).data[point].container.condition, "kering") == 0){
            if(!mark){
                last = point;
                mark = 1;
            }
            moveToLast(point, &(*L));
        }
        point = nextPoint;
    }
}

// procedure to print element
void printElement(elemen point){
    printf("%s %s %s\n", point.container.row, point.container.name, point.container.condition);
}

// procedure to print the list
void printList(list L){
    printf("\nBunga Segar:\n");
    if(L.first != -1){ // if list its not empty
        
        /*initialization*/
        int point = L.first;
        while(point != -1 && strcmp(L.data[point].container.condition, "segar") == 0){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].next;
        }
    }else{ // if its not
        printf("empty list\n");
    }
}

void printReverse(list L){
    printf("Bunga Kering:\n");
    if(L.first != -1){ // if list its not empty
        
        /*initialization*/
        int point = L.tail;
        while(point != -1 && strcmp(L.data[point].container.condition, "kering") == 0){
            /*process*/
            printElement(L.data[point]);
            /*iteration*/
            point = L.data[point].prev;
        }
    }else{ // if its not
        printf("empty list\n");
    }
}

void solve(){
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        box new;
        scanf("%s %s %s", new.row, new.name, new.condition);
        addLast(new, &L);   
    }
    selection(&L);
    printReverse(L);
    printList(L);
}

int main(){slv return 0;}