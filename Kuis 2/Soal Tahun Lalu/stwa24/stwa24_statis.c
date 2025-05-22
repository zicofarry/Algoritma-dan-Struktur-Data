#include <stdio.h>
#include <string.h>

typedef struct{
    char color[51];
    int level;
}box;

typedef struct{
    int top;
    box data[51];
}stack;

void createEmpty(stack *S){
    (*S).top = -1;
}

int isEmpty(stack S){
    int result = 0;
    if(S.top == -1){
        result = 1;
    }
    return result;
}
    
int isFull(stack S){
    int result = 0;
    if(S.top == 50){
        result = 1;
    }
    return result;
}

void push(box tmp, stack *S ){
    
    if(isFull(*S) == 1){
        /*jika stack penuh*/
        printf("stack penuh\n");
    }else{
        if(isEmpty(*S) == 1){
            /* jika stack kosong */
            (*S).top = 0;
            (*S).data[0] = tmp;
        }else{
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top] = tmp;
        }
    }
}

void pop(stack *S){
    if((*S).top == 0){
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }else{
        if((*S).top != -1){
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

// procedure to move element to the another stack
void moveTo(stack *S, stack *S2){
    if((*S).top != -1){
        // update stack2 top place
        (*S2).top = (*S2).top + 1;

        // fill stack2 top with stack1 top
        (*S2).data[(*S2).top] = (*S).data[(*S).top];

        // update stack1 with the elements below it
        (*S).top = (*S).top - 1;
    }else{
        printf("empty stack\n");
    }
}

void printStack(stack S){
    if(S.top != -1){
        for(int i = S.top; i >= 0; i--){
            printf("%s %d\n", S.data[i].color, S.data[i].level);
        }
    }
    else{
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

    while(S1.top != -1){
        if(S2.top != -1){
            if(S1.data[S1.top].level > S2.data[S2.top].level){
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