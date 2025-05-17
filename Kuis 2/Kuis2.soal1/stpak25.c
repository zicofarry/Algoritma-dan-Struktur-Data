/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 1 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "stpak25.h" // include my header "stpak25.h"

// procedure to create empty stack
void createEmpty(stack *S){
    (*S).top = NULL;
}

// function to check if its an empty stack
int isEmpty(stack S){
    int result = 0;
    if(S.top == NULL) result = 1;
    return result;
}

// function to count element of the stack
int countElement(stack S){
    int result = 0;
    if(S.top != NULL){
        /* if stack is not empty */
        element* point;
        
        /* initialization */
        point = S.top;
        while(point != NULL){
            /* process */
            result = result + 1;
            
            /* iteration */
            point = point->next;
        }
    }
    return result;
}

// procedure to push element to the stack
void push(box tmp, stack *S){
    element* new;
    new = (element *) malloc (sizeof (element));

    new->container = tmp;
    if((*S).top == NULL){
        // if stack is empty
        new->next = NULL;
    }else{
        // if stack is not empty
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

// procedure to move element to the another stack (breakdown concept)
void moveTo(stack* S, stack* S2){
    if((*S).top != NULL){
        element* x = (*S).top;
        // update top with the second element
        (*S).top = (*S).top->next;
        
        // x next update with first element
        x->next = (*S2).top;
        
        // first update with x
        (*S2).top = x;
        x = NULL;
    }else{
        printf("empty stack\n");
    }
}

// procedure to print the element
void printElement(element* point){
    printf("%s %d %d %d\n", point->container.resi, point->container.date, point->container.month, point->container.year);
}

// procedure to print the stack
void printStack(stack S){
    if(S.top != NULL){
        element* point = S.top;
        while(point != NULL){
            printElement(point);
            
            /* iteration */
            point = point->next;
        }
    }else{
        /* process if the stack is empty */
        printf("kosong\n");
    }
}

// procedure to solve the problem
void solve(){
    stack S1; // declare stack S1 for "Stack Utama"
    stack S2; // declare stack S2 for "Stack Temp 1"
    stack S3; // declare stack S3 for "Stack Temp 2"
    createEmpty(&S1); // call createEmpty procedure to create empty stack 1
    createEmpty(&S2); // call createEmpty procedure to create empty stack 2
    createEmpty(&S3); // call createEmpty procedure to create empty stack 3
    int n; // declare n for the number element of the queue
    scanf("%d", &n); // input n value
    for(int i = 0; i < n; i++){ // loop until n
        box new; // declare container new
        scanf("%s %d %d %d", new.resi, &new.date, &new.month, &new.year); // input container new
        push(new, &S1); // push container new to the queue
    }
    printf("Stack Utama:\n"); // print stack utama
    printStack(S1); // call printStack pricedure
    while(S1.top != NULL){ // loop while S1.top is not NULL
        if(S2.top != NULL){ // if S2.top is not NULL
            if(S1.top->container.year < S2.top->container.year || (S1.top->container.year <= S2.top->container.year &&
                S1.top->container.month < S2.top->container.month) || (S1.top->container.year <= S2.top->container.year &&
                S1.top->container.month <= S2.top->container.month && S1.top->container.date <= S2.top->container.date)){
                // if date is bigger
                moveTo(&S1, &S2); // move to stack temp 1
            }else{ // if its not
                moveTo(&S1, &S3); // move to stack temp 2
            }
        }else{ // if its NULL
            moveTo(&S1, &S2); // just move to stack temp 1
        }
    }
    printf("\nStack Temp1\n"); // print stack temp 1
    printStack(S2); // call printStack procedure
    printf("\nStack Temp2\n"); // print stack temp 2
    printStack(S3); // call printStack procedure
}