typedef struct{
    // contents of the container

}value;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    value container;
    alamatelmt next;
} element;

typedef struct{
    element* first;
}list;

void createList(list *L){
    (*L).first = NULL;    
}

int countelementt(list L){
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

void delFirst(list *L){
    // if list is not empty
    if((*L).first != NULL){   
        element* delete = (*L).first;
        // if element is only 1
        if(countelementt(*L) == 1){
            (*L).first = NULL;
        }
        // if element is more than 1
        else{
            (*L).first = (*L).first->next;
            delete->next = NULL;
        }
        // delete, call free
        free(delete);
    }  
}

void delAfter(element* prev, list *L){
    // if prev is not NULL
    if(prev != NULL){
        // declare delete pointer and fill in prev next
        element* delete = prev->next;
        // if element at the end of list
        if(delete->next == NULL){
            prev->next = NULL;
        // if element is not at the end
        }else{
            prev->next = delete->next;
            delete->next = NULL;
        }
        // delete, call free
        free(delete);
    }
}

void delLast(list *L){
    // if list is not empty
    if((*L).first != NULL){
        // if element is only 1, call delFirst
        if(countelementt(*L) == 1){
            delFirst(L);
        }
        // if element is more than 1
        else{
            // declare last and prev pointer
    
            element* last = (*L).first;
    
            element* prev;
            // loop to find the last and prev positions
            while(last->next != NULL){
                // iterasi
                prev = last;
                last = last->next;
            }
        delAfter(prev, L);
        }
    }
}


void printelementt(list L){
    if(L.first != NULL){
        /*if list is not empty*/
        /*initialization*/
        element* point = L.first;
        int i = 1;
        while(point != NULL){
            /*process*/    
            // printf("%s %d %d %d\n", point->container.photo, point->container.date, point->container.month, point->container.year);
            // printf("\n"point->container.);

            /*iteration*/
            point = point->next;
            i++;
        }
    }else{
        /*process is list if empty*/
        printf("empty list\n");
    }
}

void delAll(list *L){
    if(countelementt(*L) != 0){
        int i;    
        for(i = countelementt(*L); i >= 1; i--){
            /*process of deleting list elements*/
            delLast(L);
        }
    }
}

