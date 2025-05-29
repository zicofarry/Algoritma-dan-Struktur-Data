/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 4 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "NIBPB25.h" // include header "NIBPB25.h"

// procedure to create empty queue
void createEmpty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// function to check if its an empty queue
int isEmpty(queue Q){
    int result = 0;
    if(Q.first == NULL) result = 1;
    return result;
}

// function to count element of the queue
int countElement(queue Q){
    int result = 0;
    if(Q.first != NULL){
        /*queue is not empty*/
        element* point;
        /*initialitazion*/
        point = Q.first;
        while(point != NULL){
            /*process*/
            result = result + 1;
            
            /*iteration*/
            point = point->next;
        }
    }
    return result;
}

// procedure to add element based on priority
void addPriority(box tmp, queue *Q ){
    element* new; // declare element new
    new = (element *) malloc (sizeof (element)); // malloc element new
    new->container = tmp; // fill container new with box tmp
    new->next = NULL; // new point (next) to NULL

    if((*Q).first == NULL){ // if the first queue is NULL
        (*Q).first = new; // update first with element new
        (*Q).last = new; //  update last with element new
    }else{ // if its not NULL
        element* before = NULL; // declare before, start from NULL
        element* point = (*Q).first; // declare point, start from first
        // loop while point its not NULL and tmp.urgency greater than
        // or equal to point->container.urgency
        while(point != NULL && tmp.urgency >= point->container.urgency){
            before = point; // update before with point
            point = point->next; // update point with element after point
        }

        if(point == (*Q).first){ // if point is the first queue
            new->next = (*Q).first; // new point (next) to first
            (*Q).first = new; // update first with element new
        }else if(before == (*Q).last){ // if before is the last element
            (*Q).last->next = new; // last point (next) to element new
            (*Q).last = new; // update last with the new element
        }else{ // if point in the middle of queue
            new->next = point; // new point (next) to element point
            before->next = new; // before point (next) to element new
        }
        before = NULL; // update before with NULL to kill the zombie
        point = NULL; // update point with NULL to kill the zombie
    }
    new = NULL; // update new with NULL to kill the zombie
}

// procedure to move element from queue 1 to queue 2
void moveTo(queue *Q, queue *Q2){
    if((*Q).first != NULL){ // if queue is not empty queue
        element *move = (*Q).first; // save Q.first in element move
        if(countElement(*Q) == 1){ // if queue is just one element
            (*Q).first = NULL; // update first with NULL
            (*Q).last = NULL; // update last with NULL
        }else{ // if its not
            (*Q).first = (*Q).first->next; // first point (next) to the next element
            move->next = NULL; // move point (next) to NULL
        }

        if((*Q2).first == NULL){ // if Q2.first is NULL
            (*Q2).first = move; // update Q2.first with element move
        }else{ // if its not NULL
            (*Q2).last->next = move; // Q2.last point (next) to move
        }
        (*Q2).last = move; // update Q2.last with element move
        move = NULL; // update move with NULL to kill the zombie
    }
}

// procedure to print queue
void printQueue(queue Q){
    printf("==================================\n");
    printf("|          ANTRIAN PASIEN         |\n");
    printf("==================================\n");
    if(Q.first != NULL){
        element* point = Q.first;
        int i = 1;
        while(point != NULL){
            printf("%s %s %d\n", point->container.name, point->container.disease, point->container.urgency);
            /* iteration */
            point = point->next;
            i++;
        }
    }
    else{
        /*process id queue is empty*/
        printf("Antrian kosong\n");
    }
    printf("==================================\n");
}

// procedure to solve the problem
void solve(){
    queue Q; // declare queue Q
    createEmpty(&Q); // call createEmpty procedure to create an empty queue
    int n; // declare n (number of elements of the queue)
    scanf("%d", &n); // input n value
    box new; // declare box now 
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", new.name, new.disease, &new.urgency); // scan new container
        addPriority(new, &Q); // add container to the queue based on priority, call addPriority procedure
    }
    /* no need to declare nanang container cuz it doesnt matter
    and to make the program more efficient, just use box new */
    scanf("%s %s %d", new.name, new.disease, &new.urgency); // scan container to save nanang container
    addPriority(new, &Q); // add container to the queue based on priority, call addPriority procedure

    int m; // declare m to save minute value
    scanf("%d", &m); // input m value

    // call printQueue procedur to print all the elements of the queue
    printf("Antrian lengkap:\n");
    printQueue(Q);

    queue Q2; // declare queue 2 to save element that move from queue 1
    createEmpty(&Q2); // call createEmpty procedure to create an empty queue
    while((m -= 15) >= 0) moveTo(&Q, &Q2); // loop while the minutes are not up
    
    // call printQueue procedur to print the rest elements of the queue
    printf("\nAntrian saat ini:\n");
    printQueue(Q);
    // call printQueue procedur to print the queued element
    printf("\nAntrian yang sudah dilayani:\n");
    printQueue(Q2);

    // lets search Nanang in Q2
    element* point = Q2.first; // declare point element, start from Q2.first
    int found = 0; // declare found to marking if Nanang is found or not
    while(point != NULL && !found){ // loop while point is not NULL and found is 0
        if(strcmp(point->container.name, "Nanang") == 0) found = 1; // if Nanang found, update found with 1
        else point = point->next; // if its not, lets next to the next element
    }
    point = NULL; // update point with NULL to kill the zombie

    if(found) printf("\nNanang Sudah Diperiksa, Silahkan Tebus Obat!\n"); // if Nanang found print this
    else printf("\nNanang Belum Diperiksa!\n"); // if its not, then print this

}