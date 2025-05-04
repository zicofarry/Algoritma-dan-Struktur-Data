/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UTS soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "orrr25.h" // include header "orrr25.h"

// procedure to create the list
void createList(list *L){
    (*L).first = NULL;
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

// procedure to print the column element
void printColElm(eColumn *eCol){
    printf("- %s %d %d %s\n", eCol->container_col.name, eCol->container_col.regis, eCol->container_col.remake, eCol->container_col.status);
}

// procedure to print the row element
void printRowElm(eRow *point){
    printf("%s\n", point->container.nusery);
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

// procedure to solve the problem
void solve(){
    list L; // declare list L
    createList(&L); // call procedure createList
    int n; // declare n
    scanf("%d", &n); // input the number of n
    column new[n]; // declare column element
    for(int i = 0; i < n; i++){ // loop until n
        row tmp; // declare row element
        scanf("%s %d %d %s", new[i].name, &new[i].regis, &new[i].remake, tmp.nusery); // scan the input
        eRow* point = L.first; // declare point start from first
        while(point != NULL && strcmp(point->container.nusery, tmp.nusery) != 0){
            point = point->next;
        }

        // if the raw is not founf
        if(point == NULL){
            addLastR(tmp, &L); // call orocedure addLastR
            point = L.first;
            while(strcmp(point->container.nusery, tmp.nusery) != 0){
                point = point->next;
            }
            // and get the row of the list
        }

        // loop to check if its found or not
        // to get the status registrant or remake
        int j = 0;
        int flag = 0;
        while(j < i && !flag){
            if(strcmp(new[i].name, new[j].name) == 0){
                flag = 1;
            }else{
                j++;
            }
        }

        if(flag){ // if theres found
            strcpy(new[i].status, "remake"); // status is remake
        }else{ //if its not
            strcpy(new[i].status, "registrant"); // status is registrant
        }
        addLastC(new[i], point); // call procedure addLastC
        point = NULL; // update point to be NULL, to kill the zombie
    }
    printListofList(L); // call procedure printListofList
}
