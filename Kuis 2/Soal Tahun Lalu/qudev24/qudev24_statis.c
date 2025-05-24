#include <stdio.h>
#include <string.h>

typedef struct{
    char name[51];
    int porto;
    int skill;
}box;

typedef struct{
    int first;
    int last;
    box data[51];
}queue;

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int result = 0;
    if(Q.first == -1){
        result = 1;
    }
    return result;
}

int isFull(queue Q){
    int result = 0;
    if(Q.last == 51){
        result = 1;
    }
    return result;
}

// void add(box tmp, queue *Q ){
//     if(isEmpty(*Q) == 1){
//         /* if queue is empty */
//         (*Q).first = 0;
//         (*Q).last = 0;
//         (*Q).data[0] = tmp;
//     }else{
//         /* if queue is not empty */
//         if(isFull(*Q) != 1){
//             (*Q).last = (*Q).last + 1;
//             (*Q).data[(*Q).last] = tmp;
//         }
//         else{
//             printf("queue full\n");
//         }
//     }
// }

void add(box tmp, queue *Q ){
    /* if queue is not full */
    if(!isFull(*Q)){
        if(isEmpty(*Q)){
            (*Q).first = 0;
        }
        (*Q).last = (*Q).last + 1;
        (*Q).data[(*Q).last] = tmp;
    }else{
        printf("queue full\n");
    }
}

void addPriority(int priority, box tmp, queue *Q){
    if(isEmpty(*Q) == 1){
        /* if queue is empty */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = tmp;
    }else{
        /* if queue is not empty */
        if(isFull(*Q) != 1){
            if(priority == 0){
                for(int i = (*Q).last ; i >= (*Q).first;i--){
                    (*Q).data[i+1] = (*Q).data[i];
                }
                (*Q).data[0] = tmp;
                (*Q).last = (*Q).last + 1;
            }else if(priority > (*Q).last){
                (*Q).last = (*Q).last + 1;
                (*Q).data[(*Q).last] = tmp;
            }else{
                for(int i = (*Q).last ; i >= priority;i--){
                    (*Q).data[i+1] = (*Q).data[i];
                }
                (*Q).data[priority] = tmp;
                (*Q).last = (*Q).last + 1;
            }
        }else{
            printf("queue full\n");
        }
    }
}

void del(queue *Q){
    if((*Q).last == 0){
        (*Q).first = -1;
        (*Q).last = -1;
    }else{
        /*shift elements to the front*/
        for(int i = ((*Q).first + 1); i <= (*Q).last; i++){
            (*Q).data[i-1] = (*Q).data[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

void moveTo(queue *Q, queue *Q2){
    if((*Q).first != -1){
        /*if queue is not empty queue*/
        int move = (*Q).first;
        if((*Q2).first == -1){
            (*Q2).first = 0;
        }

        if(isFull(*Q2) != 1){
            (*Q2).last = (*Q2).last + 1;
        }else{
            printf("queue full\n");
        }

        (*Q2).data[(*Q2).last] = (*Q).data[move];

        if((*Q).last == 0){
            (*Q).first = -1;
            (*Q).last = -1;
        }else{
            /*shift elements to the front*/
            for(int i = ((*Q).first + 1); i <= (*Q).last; i++){
                (*Q).data[i-1] = (*Q).data[i];
            }
            (*Q).last = (*Q).last - 1;
        }
    }
}

void printQueue(queue Q){
    if(Q.first != -1){
        for(int i = Q.first; i <= Q.last; i++){
            printf("%s %d %d\n", Q.data[i].name, Q.data[i].porto, Q.data[i].skill);
        }
    }
    else{
        /* process if queue is empty */
        printf("kosong\n");
    }
}

int main(){
    queue Q;
    createEmpty(&Q);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        box new;
        int priority;
        scanf("%s %d %d %d", new.name, &new.porto, &new.skill, &priority);
        addPriority(priority-1, new, &Q);
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
    
    return 0;
}