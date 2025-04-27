/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 1 soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "lumwp25.h" // include my header -> lumwp25.h

// procedure to create the list
void createList(list *L){
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
            /*proses*/
            result++;
            
            /*iterasi*/
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
    // is list is empty, call addFirst
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

// procedure to print the list
void printElement(list L){
    if(L.first != NULL){
        /*if list is not empty*/
        /*initialization*/
        element* point = L.first;
        int i = 1;
        while(point != NULL){
            /*process*/    
            printf("%s %d %lld %s\n", point->container.name, point->container.year, point->container.tax, point->container.status);

            /*iteration*/
            point = point->next;
            i++;
        }
    }else{
        /*process is list if empty*/
        printf("empty list\n");
    }
}

// function to get the last element
element* getLastElement(list L) {
    element *temp = L.first;
    while (temp != NULL && temp->next != NULL)
    temp = temp->next;
    return temp;
}

// procedure to move element to the last place (breakdown concept)
void moveToLast(element* beforeA, element* a, list* L){
    if(a->next != NULL){ // if a is not in the last position
        if(beforeA == NULL){
            // if a is the first element
            (*L).first = a->next; // update first
        } else {
            // if a is not the first element
            beforeA->next = a->next;
        }

        // get last element
        element* last = getLastElement(*L);
        last->next = a; // connect a to the end of the list
        a->next = NULL; // make sure a is the last element

        // update tax and status value if payment is not past due
        a->container.tax = 0; // tax becomes 0
        strcpy(a->container.status, "diputihkan"); // status becomes "diputihkan"
    }
}

// procedure to check the list
void Pemutihan(int limitYear, list* L) {
    if ((*L).first == NULL) return; // if the list is empty, return

    element* beforePoint = NULL;
    element* point = (*L).first;
    element* last = getLastElement(*L); // take the last element before starting

    while (point != NULL && point != last) { // Loop until before last
        element* temp = point->next; // save next before change potition

        if (point->container.year <= limitYear) {
            moveToLast(beforePoint, point, L);
            
            // update last if point equal to last
            if (point == last) {
                last = getLastElement(*L);
            }

            // Reset pointer after moving
            if (beforePoint == NULL) {
                point = (*L).first; // if the first element is moved
            } else {
                beforePoint->next = temp; // Reconnect the list
                point = temp; // Continue to the next element
            }
        } else {
            beforePoint = point;
            point = temp;
        }
    }
    
    // to process the last element
    if(point == last){
        element* temp = point->next; // save next before change potition
        
        if (point->container.year <= limitYear) {
            moveToLast(beforePoint, point, L);
        } else {
            beforePoint = point;
            point = temp;
        }
    }
}

// procedure to solve the program
void solve(){
    // declare the list
    list L;
    createList(&L);

    // declare and scan amount of data
    isc(n);
    for(int i = 0; i < n; i++){ // loop as many as the number of data
        value new; // declare new
        scanf("%s %d %lld %s", new.name, &new.year, &new.tax, new.status); // scan new
        addLast(new, &L); // input new to list with addLast
    }
    // declare limitYear
    int limitYear;
    scanf("%d", &limitYear); // scan limit year

    // call pemutihan algorithm
    Pemutihan(limitYear, &L);

    // print the list
    printElement(L);
}