#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char color[51];
    int level;
}box;

typedef struct elmt *alamatelmt;
typedef struct elmt{
    box container;
    alamatelmt next;
}element;

typedef struct {
    element* top;
}stack;

void createEmpty(stack *S){
    (*S).top = NULL;
}
    
int isEmpty(stack S){
    int result = 0;
    if(S.top == NULL){
        result = 1;
    }
    return result;
}

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

void pop(stack *S){
    if((*S).top != NULL){
        /*if stack is not empty stack*/
        element *delete = (*S).top;
        if(countElement(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        delete->next = NULL;
        free(delete);
    }else{
        printf("empty stack\n");
    }
}

// procedure to move element to the another stack (breakdown concept)
void moveTo(stack* S, stack* S2){
    if((*S).top != NULL){
        element* x = (*S).top;
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

void printStack(stack S){
    if(S.top != NULL){
        element* point = S.top;
        while(point != NULL){
            printf("%s %d\n", point->container.color, point->container.level);
            
            /* iterasi */
            point = point->next;
        }
    }else{
        /* proses jika stack kosong */
        printf("kosong\n");
    }
}

int main(){
    stack S1;
    stack S2;
    stack S3;
    createEmpty(&S1);
    createEmpty(&S2);
    createEmpty(&S3);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        box new;
        scanf("%s %d", new.color, &new.level);
        push(new, &S1);
    }

    while(S1.top != NULL){
        if(S2.top != NULL){
            if(S1.top->container.level > S2.top->container.level){
                moveTo(&S1, &S2);
            }else{
                moveTo(&S2, &S3);
                moveTo(&S1, &S2);
            }
        }else{
            moveTo(&S1, &S2);
        }
    }
    printf("Stack Warna Gelap:\n");
    printStack(S3);
    printf("\nStack Warna Terang:\n");
    printStack(S2);

    return 0;
}
