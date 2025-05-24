#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define slv solve();

typedef struct{
    char name[51];
    int porto;
    int skill;
}box;

typedef struct elm *alamatelmt;
typedef struct elm{
    box container;
    alamatelmt next;
}element;

typedef struct{
    element *first;
    element *last;
}queue;

void createEmpty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}
    
int isEmpty(queue Q){
    int result = 0;
    if(Q.first == NULL){
        result = 1;
    }
    return result;
}

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

void addPriority(element* priority, box tmp, queue *Q ){
    element* new;
    new = (element *) malloc (sizeof (element));
    new->container = tmp;
    new->next = NULL;

    if((*Q).first == NULL){
        (*Q).first = new;
        (*Q).last = new;
    }else{
        element* before = NULL;
        element* point = (*Q).first;
        while(point != NULL && before != priority){
            before = point;
            point = point->next;
        }

        if(point == (*Q).first){
            new->next = (*Q).first;
            (*Q).first = new;
        }else if(before == (*Q).last){
            (*Q).last->next = new;
            (*Q).last = new;
        }else{
            new->next = point;
            before->next = new;
        }
    }
    new = NULL;
}

void add(box tmp, queue *Q ){
    element* new;
    new = (element *) malloc (sizeof (element));
    new->container = tmp;
    new->next = NULL;
    if((*Q).first == NULL){
        (*Q).first = new;
    }
    else{
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

void del(queue *Q){
    if((*Q).first != NULL){
        /*if queue is not empty queue*/
        element *delete = (*Q).first;
        if(countElement(*Q) == 1){
            (*Q).first = NULL;
            (*Q).last = NULL;
        }else{
            (*Q).first = (*Q).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void moveTo(queue *Q, queue *Q2){
    if((*Q).first != NULL){
        /*if queue is not empty queue*/
        element *move = (*Q).first;
        if(countElement(*Q) == 1){
            (*Q).first = NULL;
            (*Q).last = NULL;
        }else{
            (*Q).first = (*Q).first->next;
            move->next = NULL;
        }

        if((*Q2).first == NULL){
            (*Q2).first = move;
        }
        else{
            (*Q2).last->next = move;
        }
        (*Q2).last = move;
        move = NULL;
    }
}

void printQueue(queue Q){
    if(Q.first != NULL){
        element* point = Q.first;
        while(point != NULL){
            printf("%s %d %d\n", point->container.name, point->container.porto, point->container.skill);
            /* iteration */
            point = point->next;
        }
    }
    else{
        /*process id queue is empty*/
        printf("kosong\n");
    }
}

void solve(){
    queue Q;
    createEmpty(&Q);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        box new;
        int priority;
        scanf("%s %d %d %d", new.name, &new.porto, &new.skill, &priority);
        element* before = NULL;
        element* point = Q.first;
        int j = 1;
        while(j < priority && point != NULL){
            before = point;
            point = point->next;
            j++;
        }
        addPriority(before, new, &Q);
        before = NULL;
        point = NULL;
    }
    int p;
    scanf("%d", &p);
    queue Q2;
    createEmpty(&Q2);
    for(int i = 0; i < p; i++){
        moveTo(&Q, &Q2);
    }

    printf("Developer yang Diterima:\n");
    printQueue(Q2);
    printf("\nCalon Developer:\n");
    printQueue(Q);

}

int main(){slv return 0;} // call macro slv and solve the program