/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 2 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "qptim25.h" // include header "qptim25.h"

// procedure to create empty queue
void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

// function to check if its an empty queue
int isEmpty(queue Q){
    int result = 0;
    if(Q.first == -1) result = 1;
    return result;
}

// function to check if its a full stack
int isFull(queue Q){
    int result = 0;
    if(Q.last == 50) result = 1;
    return result;
}

// procedure to add element based on priority
void addPriority(int priority, box tmp, queue *Q){
    if(isEmpty(*Q)){ // if queue is empty
        (*Q).first = 0; // update first with 0
        (*Q).last = 0; // update last with 0
        (*Q).data[0] = tmp; // fill data index 0 with container tmp
    }else{ // if its not empty
        if(!isFull(*Q)){ // if queue is not full
            if(priority == 0){ // if priority is index 0
                for(int i = (*Q).last; i >= (*Q).first; i--){ // shift elements back 
                    (*Q).data[i+1] = (*Q).data[i];
                }
                (*Q).data[0] = tmp; // fill index 0 with container tmp
                (*Q).last = (*Q).last + 1; // update last with last + 1
            }else if(priority > (*Q).last){ // if priority is greater than last
                (*Q).last = (*Q).last + 1; // update last with last + 1
                (*Q).data[(*Q).last] = tmp; // fill data index last with container tmp
            }else{ // if index priority is in the middle of queue
                for(int i = (*Q).last; i >= priority; i--){ // shift element after index priority to the back
                    (*Q).data[i+1] = (*Q).data[i];
                }
                (*Q).data[priority] = tmp; // fill data index priority with container tmp
                (*Q).last = (*Q).last + 1; // update last with last + 1
            }
        }else{ // if its full
            printf("queue full\n");
        }
    }
}

// procedure to move element from queue 1 to queue 2
void moveTo(queue *Q, queue *Q2){
    if((*Q).first != -1){ // if the first queue is not empty
        int move = (*Q).first; // save the first element of first queue in move variable
        if((*Q2).first == -1){  // if queue 2 is empty
            (*Q2).first = 0; // update first with 0
        }

        if(!isFull(*Q2)){ // if queue 2 is not full
            (*Q2).last = (*Q2).last + 1; // update last with last + 1
        }else{ // if its not
            printf("queue full\n"); // print queue full
        }
        (*Q2).data[(*Q2).last] = (*Q).data[move]; // update last queue 2 with queue 1 index move

        if((*Q).last == 0){ // if queue 1 just have 1 element
            (*Q).first = -1; // update first with -1
            (*Q).last = -1; // update last with -1
        }else{ // if its not
            /*shift elements to the front*/
            for(int i = ((*Q).first + 1); i <= (*Q).last; i++){
                (*Q).data[i-1] = (*Q).data[i];
            }
            (*Q).last = (*Q).last - 1; // update last with last - 1
        }
    }
}

// procedure to print queue
void printQueue(queue Q){
    if(Q.first != -1){
        for(int i = Q.first; i <= Q.last; i++){
            printf("%s %s %s %d\n", Q.data[i].name, Q.data[i].leaf, Q.data[i].root, Q.data[i].priority);
        }
    }
    else{
        /* process if queue is empty */
        printf("kosong\n");
    }
}

// procedure to solve the problem
void solve(){
    queue Q; // declare queue Q
    createEmpty(&Q); // call createEmpty procedure to create empty queue
    int n; // declare n to save the number of element of the queue
    scanf("%d", &n); // input n value
    for(int i = 0; i < n; i++){ // loop until n
        box new; // declare container new
        scanf("%s %s %s %d", new.name, new.leaf, new.root, &new.priority); // input container new
        addPriority(new.priority-1, new, &Q); // call addPriority procedure to add container new to the queue with priority concept
    }
    int m; // declare m to save the number of element that should be process
    scanf("%d", &m); // input m value
    
    queue Q2; // declare queue Q2
    createEmpty(&Q2); // call createEmpty procedure to create empty queue
    while(m--) moveTo(&Q, &Q2); // loop while m is not 0
    
    printf("Harus Diproses:\n"); // print harus diproses
    printQueue(Q2); // call procedure printQueue to print the elemets of queue 2
    printf("\nWaiting List:\n"); // print waiting list
    printQueue(Q); // call procedure printQueue to print the elemets of queue 1
}