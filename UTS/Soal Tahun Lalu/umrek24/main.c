#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define slv solve();

typedef struct{
    // contents of the row container
    char product[51];
    int price;
}row;

typedef struct{
    // contents of the column container
    char name[51];
    int year;
}column;

typedef struct eClm *alamateColumn;
typedef struct eClm{
    column container_col;
    alamateColumn next_col;
}eColumn;

typedef struct ebr *alamateRow;
typedef struct ebr{
    row container;
    eColumn *col;
    alamateRow next;
}eRow;

typedef struct{
    eRow *first;
}list;

// procedure to create the list
void createList(list *L){
    (*L).first = NULL;
}

// procedure to count the row element
int countRowElm(list L){
    int result = 0;
    if(L.first != NULL){
        /*list is not empty*/
        eRow* point;
        /*initialization*/
        point = L.first;
        while(point != NULL){
            /*process*/
            result = result + 1;
            
            /*iteration*/
            point = point->next;
        }
    }
    return result;
}

// procedure to count the column element
int countColElm(eRow L){
    int result = 0;
    if(L.col != NULL){
        /*list is not empty*/
        eColumn* point;
        /*initialization*/
        point = L.col;
        while(point != NULL){
            /*process*/
            result = result + 1;
            
            /*iteration*/
            point = point->next_col;
        }
    }
    return result;
}

// procedure to add row element to the first place
void addFirstR(row tmp, list *L){
    eRow* new;
    new = (eRow *) malloc (sizeof (eRow));
    new->container = tmp;
    new->col = NULL;

    // if list is empty    
    if((*L).first == NULL){
        new->next = NULL;
    }else{ // if list is not empty
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// procedure to add row element after element
void addAfterR(eRow* prev, row tmp){
    eRow* new;
    new = (eRow *) malloc (sizeof (eRow));
    new->container = tmp;
    new->col = NULL;
    // if element at the end of list (prev next null)
    if(prev->next == NULL){
        new->next = NULL;
    }else{ // if element is not at the end
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

// procedure to add row element to the last place
void addLastR(row tmp, list *L){
    if((*L).first == NULL){
        /*if list is empty, call addFirstR*/
        addFirstR(tmp, L);
    }else{
        /*if list is not empty*/
        /*find the last element*/
        eRow *last = (*L).first;
        while(last->next != NULL){
            /*iteration*/
            last = last->next;
        }
        addAfterR(last, tmp);
    }
}

// procedure to add column element to the first place
void addFirstC(column tmp, eRow *L){
    eColumn* new;
    new = (eColumn *) malloc (sizeof (eColumn));
    new->container_col = tmp;
    if((*L).col == NULL){// if row is empty
        new->next_col = NULL;
    }else{ // if row is not empty
        new->next_col = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

// procedure to add column element after element
void addAfterC(eColumn* prev, column tmp){
    eColumn* new;
    new = (eColumn *) malloc (sizeof (eColumn));
    new->container_col = tmp; 
    // if element at the end of row element (prev next null)
    if(prev->next_col == NULL){
        new->next_col = NULL;
    }else{ // if element is not at the end
        new->next_col = prev->next_col;
    }
    prev->next_col = new;
    new = NULL;
}

// procedure to add column element to the last place
void addLastC(column tmp, eRow *L){
    if((*L).col == NULL){
        /*if row element is empty, call addFirstC*/
        addFirstC(tmp, L);
    }else{
        /*if row element is not empty*/
        /*find the last element*/
        eColumn *last = (*L).col;
        while(last->next_col != NULL){
            /*iteration*/
            last = last->next_col;
        }
        addAfterC(last, tmp);
    }
}

// procedure to delete the first row element
void delFirstC(eRow *L){
    if((*L).col != NULL){
        /*if list is not empty*/
        eColumn* delete = (*L).col;
        if(countColElm(*L) == 1){
            (*L).col = NULL;
        }else{
            (*L).col = (*L).col->next_col;
            delete->next_col = NULL;
        }
        free(delete);
    }
}

// procedure to delete row element after element
void delAfterC(eColumn* prev){
    eColumn* delete = prev->next_col;
    if(delete != NULL){
        if(delete->next_col == NULL){
            prev->next_col = NULL; 
        }else{
            prev->next_col = delete->next_col;
            delete->next_col = NULL;
        }
        free(delete);
    }
}

// procedure to delete the last row element
void delLastC(eRow *L){
    if((*L).col != NULL){
        /*if list is not empty*/
        if(countColElm(*L) == 1){ //if element is only 1, call delFirstC
            delFirstC(L);
        }else{ // if element is more than 1
            /*find the last element*/
            eColumn *last = (*L).col;
            eColumn *before_last;

            while(last->next_col != NULL){
                /*iteration*/
                before_last = last;
                last = last->next_col;
            }
            delAfterC(before_last);
        }
    }
}

// procedure to delete all column element of the row element
void delAllC(eRow *L){
    if(countColElm(*L) != 0){
        for(int i = countColElm(*L); i >= 1; i--){
            /*process of deleting column element from row elements*/
            delLastC(L);
        }
    }
}

// procedure to delete the first row element
void delFirstR(list *L){
    if((*L).first != NULL){
        /*if list is not empty*/
        eRow *delete = (*L).first;
        if(delete->col != NULL){
            // delete every column elemen of this row element
            delAllC(delete);
        }
        if(countRowElm(*L) == 1){
            (*L).first = NULL;
        }else{
            (*L).first = (*L).first->next;
        }
        delete->next = NULL;
        free(delete);
    }else{
        printf("empty list\n");
    }
}

// procedure to delete row element after element
void delAfterR(eRow* prev){
    if(prev != NULL){
        eRow *delete = prev->next;
        if(delete != NULL){
            if(delete->col != NULL){
                // delete every column elemen of this row element
                delAllC(delete);
            }
            if(delete->next == NULL){
                prev->next = NULL;
            }else{
                prev->next = delete->next;
            }
            delete->next = NULL;
            free(delete);
        }
    }
}

// procedure to delete the last row element
void delLastR(list *L){
    if((*L).first != NULL){
        /*if list is not empty*/
        if(countRowElm(*L) == 1){ // if element is only 1, call delFirstR
            delFirstR(L);
        }else{ // if element is more than 1
            /*find the last row element*/
            eRow *last = (*L).first;
            eRow *before_last;
            while(last->next != NULL){
                /*iteration*/
                before_last = last;
                last = last->next;
            }
            delAfterR(before_last);
        }
    }
}

// procedure to delete all element of the list
void delAllB(list *L){
    if(countRowElm(*L) != 0){
        for(int i = countRowElm(*L); i >= 1; i--){
            /*process of deleting list elements*/
            delLastR(L);
        }
    }
}

// procedure to print the column element
void printColElm(eColumn *eCol){
    printf("- %s %d\n", eCol->container_col.name, eCol->container_col.year);
}

// procedure to print the row element
void printRowElm(eRow *point){
    printf("%s %d\n", point->container.product, point->container.price);
    eColumn* eCol = point->col;
    while(eCol != NULL){
        printColElm(eCol);    
        eCol = eCol->next_col;
    }
}

// procedure to print the list of list
void printListofList(list L){
    if(L.first != NULL){
        /*if list is not empty*/
        /*initialization*/
        eRow* point = L.first;
        while(point != NULL){
            /*process*/
            printRowElm(point);
            /*iteration*/
            point = point->next;
            if(point != NULL){
                printf("\n");
            }
        }
    }else{
        /*process is list if empty*/
        printf("empty list\n");
    }
}

// procedure to search the previous element, before swap
void searchPrevRow(eRow **prevX, eRow **x,  list *L){
    eRow *p, *prev; // declare (p = pointer) and (prev = before pointer)
    prev = NULL; // prev start from NULL
    p = (*L).first; // point start from first
    while(p != NULL && p != *x){ // loop until find the x
        prev = p; // update prev
        p = p->next; // update point
    }
    *prevX = prev; // save before x value
    *x = p; // save x value
}

// procedure to search the previous element, before swap
void searchPrevCol(eColumn **prevX, eColumn **x,  eRow *L){
    eColumn *p, *prev; // declare (p = pointer) and (prev = before pointer)
    prev = NULL; // prev start from NULL
    p = (*L).col; // point start from first
    while(p != NULL && p != *x){ // loop until find the x
        prev = p; // update prev
        p = p->next_col; // update point
    }
    *prevX = prev; // save before x value
    *x = p; // save x value
}

void moveToFirstCol_OnAnotherRow(eRow* old, eColumn* x, eRow* new){
    eColumn* prevX;
    if(x != old->col){
        searchPrevCol(&prevX, &x, old);
        prevX->next_col = x->next_col;
    }else{
        old->col = NULL;
    }

    eColumn* pointCol = new->col;
    x->next_col = new->col;
    new->col = x;
    // while(pointCol->next_col != NULL){
    //     pointCol = pointCol->next_col;
    // }
    // x->next_col = pointCol->next_col;
    // pointCol->next_col = x;
}

void findCol(char tmp1[], char tmp2[], column new, list *L){
    eRow* point = (*L).first;
    while(point != NULL && strcmp(point->container.product, tmp1) != 0){
        point = point->next;
    }
    eColumn* pointCol = point->col;
    while(pointCol != NULL && strcmp(pointCol->container_col.name, new.name) != 0){
        pointCol = pointCol->next_col;
    }
    eRow* point2 = (*L).first;
    while(point2 != NULL && strcmp(point2->container.product, tmp2) != 0){
        point2 = point2->next;
    }
    moveToFirstCol_OnAnotherRow(point, pointCol, point2);
    pointCol->container_col.year = new.year;
}

void delEmpty(list *L){
    eRow* prev = NULL;
    eRow* point = (*L).first;
    while(point != NULL){
        eRow* savepoint = point->next;
        searchPrevRow(&prev, &point, &(*L));

        if(countColElm(*point) == 0){
            delAfterR(&(*prev));
        }
        point = savepoint;
    }
}

void solve(){
    list L;
    createList(&L);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        row new;
        scanf("%s %d", new.product, &new.price);
        addLastR(new, &L);
    }

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        char tmp[51];
        column new;
        scanf("%s %s %d", tmp, new.name, &new.year);

        eRow* point = L.first;
        int mark = 0;
        while(point != NULL && !mark){
            /*process*/
            if(strcmp(tmp, point->container.product) == 0){
                mark = 1;
            }else{
                /*iteration*/
                point = point->next;
            }
        }
        addLastC(new, point);
    }

    int p;
    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        char oldProduct[51];
        char newProduct[51];
        column move;
        scanf("%s %s %s %d", oldProduct, newProduct, move.name, &move.year);
        findCol(oldProduct, newProduct, move, &L);
    }
    delEmpty(&L);
    printListofList(L);
}

int main(){slv return 0;}