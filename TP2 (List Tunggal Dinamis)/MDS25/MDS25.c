/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "MDS25.h" // include library "MDS25.h"

// procedure to create the list
void createList(list *L) {
    (*L).first = NULL;
}

// procedure to count the element
int countelement(list L){
    int result = 0;
    
    if(L.first !=NULL){
        /*list is not empty*/
        
        element* point;
        
        /*initialization*/
        point = L.first;
        while(point != NULL){
            /*process*/
            result++;
            
            /*iteration*/
            point = point->next;
        }
    }
    
    return result;
}

// procedure to add element to the first place
void addFirst(value temp, list *L){
    element* new;
    new = (element*) malloc(sizeof(element));
    new->container = temp;
    
    // if list is empty    
    if((*L).first == NULL){
        new->next = NULL;
        // if list is not empty
    }else{
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// procedure to add element after element
void addAfter(element* prev, value temp, list *L){
    element* new;
    new = (element*) malloc(sizeof(element));
    new->container = temp;
    // if element at the end of list (prev next null)
    if(prev->next == NULL){
        new->next = NULL;
    }
    // if element is not at the end
    else{
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;  
}

// procedure to add element to the last place
void addLast(value temp, list *L){
    // if list is empty, call addFirst
    if((*L).first == NULL){
        addFirst(temp, L);
    }
    // if list is not empty 
    else{
        element* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        // call addAfter after finding prev at the end
        addAfter(prev, temp, L);
    }
}

// procedure to print the content list
void printList(list L) {
    if (L.first != NULL) {
        printf("+-----------+------------------+-----------------+\n");
        printf("| Nama      | Jabatan          | Gaji            |\n");
        printf("+-----------+------------------+-----------------+\n");
        
        element* temp = L.first;
        while (temp != NULL) {
            printf("| %-10s| %-17s| %-16d|\n", temp->container.name, temp->container.position, temp->container.salary);
            temp = temp->next;
        }
        
        printf("+-----------+------------------+-----------------+\n");
    } else {
        printf("empty list\n");
    }
}
        
// function to get the last element
element* getLastElement(list L) {
    element *point = L.first; // declare point, start from first
    while(point != NULL && point->next != NULL){ // loop until NULL
        point = point->next; // increment to next element
    }
    return point; // return the last element
}

// procedure to search the previous element, before swap
void searchPrev(element **prevX, element **x, element **prevY, element **y, list *L){
    element *p, *prev; // declare (p = pointer) and (prev = before pointer)
    prev = NULL; // prev start from NULL
    p = (*L).first; // point start from first
    while(p != NULL && p != *x){ // loop until find the x
        prev = p; // update prev
        p = p->next; // update point
    }
    *prevX = prev; // save before x value
    *x = p; // save x value

    prev = NULL; // prev start from NULL
    p = (*L).first; // point start from first
    while (p != NULL && p != *y){ // loop until find the y
        prev = p; // update prev
        p = p->next; // update point
    }
    *prevY = prev; // save before y value
    *y = p; // save y value
}

// procedure to swap 2 element (without swapping the data)
void swap(element *x, element *y, list *L){
    element *prevX, *prevY; // declare (prevX = element before x) and (prevY = element before y)
    searchPrev(&prevX, &x, &prevY, &y, L); // call func searcPrev to get the previous element
    if(x->next == y){ // case when the elements are adjacent
        if(x == (*L).first){ // case if x is the first element
            (*L).first = (*L).first->next; // the first element is the second element
            x->next = (*L).first->next; // after x element is the third element
            (*L).first->next = x; // after the first element is x
        }else{ // case if its not
            prevX->next = x->next; // prevX point to after x
            x->next = y->next; // x point to after y
            y->next = x; // y point to x
        }
    }else{ // case when the elements are not adjacent
        if(x == (*L).first || y == (*L).first){ // case if one of the element is the first element
            element* afterY; // declare element after y
            afterY = y->next; // save after y value
            y->next = x->next; // y point to element after x
            x->next = afterY; // now x point to element afterY
            afterY = NULL; // make afterY to be a NULL, to kill the zombie

            if(prevX == NULL){ // if before x is NULL (so in that case x is the first)
                (*L).first = y; // so now y is the first
            }else{ // if its not
                prevX->next = y; // prevX point to y
            }
            
            if(prevY == NULL){ // if berfore y is NULL (so in that case y is the first)
                (*L).first = x; // so now x is the first
            }else{ // if its not
                prevY->next = x; // prevY point to x
            }
        }else{ // case when the element is not in the first
            element* afterY; // declare element after y
            afterY = y->next; // save after y value
            y->next = x->next; // y point to element after x
            x->next = afterY; // now x point to element afterY
            afterY = NULL; // make afterY to be a NULL, to kill the zombie
            if(prevX != NULL && prevY != NULL){  // if prevX and prevY is not NULL
                prevX->next = y; // so prevX point to y
                prevY->next = x; // and prevY point to x
            }
        }
    }
}

// procedure to sort the list with bubble sort algorithm
void bubbleSortList(list *L, char sortBy[], char sortOrder[]){
    int switched = 1; // declare switched to mark if its switched or not
    while(switched){ // loop when switched value is true
        switched = 0; // make switched is false, cuz we'll check the condition if its still need to switch
        element* beforeX = NULL; // declare beforeX, start from NULL
        element* x = (*L).first; // declare x, start from first
        element* afterX = (*L).first->next; // declare afterX, start from second element
        
        while(x->next != NULL){ // loop until x point to NULL
            element* tmp = x; // save element x, it'll be use for an increment
            element* afterTmp = x->next; // save element after x, it'll be use for an increment
            afterX = x->next; // afterX is element that x is pointed to
            int condition = 0; // declare condition, to mark if its true or false
            if(strcmp(sortBy, "gaji") == 0){ // if sort by gaji
                if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
                    condition = (x->container.salary > afterX->container.salary); // thats true condition
                }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
                    condition = (x->container.salary < afterX->container.salary); // thats true condition
                }
            }else if(strcmp(sortBy, "nama") == 0){ // if sort by nama
                if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
                    condition = (strcmp(x->container.name, afterX->container.name) > 0); // thats true condition
                }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
                    condition = (strcmp(x->container.name, afterX->container.name) < 0); // thats true condition
                }
            }
            
            if(condition){ // if condition value is true
                swap(x, afterX, L); // call swap procedure
                switched = 1; // and mark if its switched
            }
            
            beforeX = tmp; // update beforeX value
            x = afterTmp; // update x value
            tmp = NULL; // make tmp to be a NULL, to kill the zombie
            afterTmp = NULL; // make afterTmp to be a NULL, to kill the zombie
        }
    }
}

// procedure to merge element to the main list
void mergeElement(list *L1, list *L2, element *prev){
    element *x = (*L2).first; // declare x is the first element of the second list
    (*L2).first = (*L2).first->next; // now the first element is the second element
    x->next = prev->next; // x points to what prev pointed to
    prev->next = x; // prev points to x
    x = NULL; // make x to be a NULL, to kill the zombie
}

// procedure to merge list with sort condition
void mergeSortList(list *L1, list *L2, char sortBy[], char sortOrder[]){
    int condition = 0; // declare condition, to mark if its true or false
    if(strcmp(sortBy, "gaji") == 0){ // if sort by gaji
        if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
            condition = ((*L1).first->container.salary > (*L2).first->container.salary); // thats true condition
        }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
            condition = ((*L1).first->container.salary < (*L2).first->container.salary); // thats true condition
        }
    }else if(strcmp(sortBy, "nama") == 0){ // if sort by nama
        if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
            condition = (strcmp((*L1).first->container.name, (*L2).first->container.name) > 0); // thats true condition
        }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
            condition = (strcmp((*L1).first->container.name, (*L2).first->container.name) < 0); // thats true condition
        }
    }
    
    if(condition){ // if condition value is true
        element *tmp = (*L2).first; // save the first element of the second list
        (*L2).first = (*L2).first->next; // now the first element is the second element
        tmp->next = (*L1).first; // tmp points to the first element of the first list
        (*L1).first = tmp; // now the first element is tmp
        tmp = NULL; // make tmp to be a NULL, to kill the zombie
    }
    
    element *point = (*L1).first; // declare point, start from first
    while(point->next != NULL && (*L2).first != NULL){ // loop until point points to NULL or second list is NULL
        int condition = 0; // declare condition, to mark if its true or false
        if(strcmp(sortBy, "gaji") == 0){
            if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
                condition = (point->next->container.salary > (*L2).first->container.salary); // thats true condition
            }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
                condition = (point->next->container.salary < (*L2).first->container.salary); // thats true condition
            }
        }else if(strcmp(sortBy, "nama") == 0){ // if sort by nama
            if(strcmp(sortOrder, "ascending") == 0){ // if sort order is ascending
                condition = (strcmp(point->next->container.name, (*L2).first->container.name) > 0); // thats true condition
            }else if(strcmp(sortOrder, "descending") == 0){ // if sort order is descending
                condition = (strcmp(point->next->container.name, (*L2).first->container.name) < 0); // thats true condition
            }
        }

        if(condition){ // if condition value is true
            mergeElement(L1, L2, point); // merge element to the first list
        }
        point = point->next; // point is the next point (increment)
    }
    if((*L2).first != NULL){ // make a condition if second list is not NULL
        point = (*L1).first; // point start from first element of the first list
        if(point != NULL){ // if point its not NULL
            while(point->next != NULL){ // loop until point points to NULL
                point = point->next; // increment
            }
            point->next = (*L2).first; // now point points to first element of the first list
        }else{ // if its not
            point = (*L2).first; // save first element of the second list to the point
        }
        (*L2).first = NULL; // make L2.first to be a NULL, to kill the zombie
    }
    point = NULL; // make point to be a NULL, to kill the zombie
}

// procedure to solve the problem
void solve() {
    list L1, L2; // declare list 1 and list 2
    createList(&L1); // create list 1
    createList(&L2); // create list 2
    
    int n, m; // declare (n = number of elements of the first list) and (m = number of elements of the second list)
    char sortBy[5], sortOrder[11]; // declare sortBy and sortOrder
    
    // enter the number of Gojek employees
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        value temp; // declare temp to save a container value
        scanf("%s %s %d", temp.name, temp.position, &temp.salary); // scan container
        addLast(temp, &L1); // add container to the last of the first list
    }
    
    // enter the number of Tokopedia employees
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        value temp; // declare temp to save a container value
        scanf("%s %s %d", temp.name, temp.position, &temp.salary); // scan container
        addLast(temp, &L2); // add container to the last of the second list
    }
    
    // input sort method
    scanf("%s %s", sortBy, sortOrder);
    
    // sort both lists before merging (with bubble sort algorithm)
    bubbleSortList(&L1, sortBy, sortOrder);
    bubbleSortList(&L2, sortBy, sortOrder);

    // merge both lists
    mergeSortList(&L1, &L2, sortBy, sortOrder);
    
    // print the list
    printList(L1);
}