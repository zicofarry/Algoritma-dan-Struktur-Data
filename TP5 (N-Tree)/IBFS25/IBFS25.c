/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 5 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "IBFS25.h" // include header "IBFS25.h"

// re-declare global variable
int space[15];          // to save space value per level
int idx;                // index of the last character in the word
int wlen;               // word length
char cc;                // current character
char cw[50];            // current word
char tape[501];         // input tape
tree T;                 // n-er tree

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

// procedure to add element to the queue
void add(boxQue tmp, queue *Q ){
    element* new;
    new = (element *) malloc (sizeof (element));
    new->container = tmp;
    new->next = NULL;
    if((*Q).first == NULL){ // if its an empty queue
        (*Q).first = new;
    }else{ // if its not
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

// procedure to delete an element from the queue
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

// procedure to crate tree
void createTree(box tmp, tree* T){
    node *new; // declare node new
    new = (node *) malloc (sizeof (node)); // malloc node new
    new->container = tmp; // fill new container with tmp
    new->child = NULL; // new point (child) to NULL
    new->sibling = NULL; // new point (sibling) to NULL
    new->parent = NULL; // new point (parent) to NULL
    (*T).root = new; // update root with node new
    new = NULL; // set new with NULL
}

// procedure to add new child node
void addChild(box tmp, node* root){
    if(root != NULL){ // condition to check if the root existed
        node* new; // declare node new
        new = (node*)malloc(sizeof(node)); // malloc node new
        new->container = tmp; // fill new container to tmp
        new->child = NULL; // new point (child) to NULL
        new->parent = root; // new point (parent) to root

        // Condition if the parent node doesn't have a child
        if (root->child == NULL) {
            new->sibling = NULL; // new point (sibling) to NULL
            root->child = new; // root point (child) to new
        }
        // Otherwise, we'll have to append it to the end of the child list
        else { // Condition where there's only 1 child
            if (root->child->sibling == NULL) {
                new->sibling = root->child; // new point (sibling) to root child
                root->child->sibling = new; // root child point (sibling) to NULL
            } else {
                // Loop through to find the last child of the list
                node* last = root->child; // declare node last, set with root child
                while (last->sibling != root->child) { // loop while sibling is not root child
                    last = last->sibling; // update last with the next sibling
                }
                new->sibling = root->child; // new point (sibling) to root child
                last->sibling = new; // last point (sibling) to new
            }
        }
    }
}

// procedure to delete all from node root
void delAll(node* root){
    // Condition to check if root existed
    if (root != NULL) {
        // Condition to check if the parent has a child
        if (root->child != NULL) {
            // Condition where there's only 1 child
            if (root->child->sibling == NULL) {
                delAll(root->child); // Recursively delete the child
            }
            // Condition where there are multiple children
            else {
                node* current;
                node* target;

                // Loop through to delete the children sequentially
                current = root->child;
                while (current->sibling != root->child) {
                    target = current;
                    current = current->sibling;
                    delAll(target); // Delete node recursively
                }
                // Delete the last child node
                if (current != NULL)
                    delAll(current);
            }
        }
        // Finally delete the root node itself
        free(root);
    }
}

// procedure to delete child from parent
void delChild(box tmp, node* root){
    // Condition where the root exist
    if (root != NULL) {
        node* current = root->child;
        if (current != NULL) {
            // Condition where there's only 1 child
            if (current->sibling == NULL) {
                // Found condition
                if (strcmp(root->child->container.name, tmp.name) == 0) {
                    delAll(root->child);
                    root->child = NULL; // Set child to NULL
                    root->parent = NULL; // Set parent to NULL
                } else {
                   // printf("[!] node %c has only one child (%c) and it's not the target\n", root->container.name, root->child->container.name);
                }
            }
            // Condition where there are multiple children
            else {
                node* prev = NULL;
                int found = 0;

                // Loop until every child is checked
                while (current->sibling != root->child && found == 0) {
                    // Found condition
                    if (strcmp(current->container.name, tmp.name) == 0)
                        found = 1;
                    else {
                        prev = current;
                        current = current->sibling;
                    }
                }

                // Check the last remaining child, if it's the target
                if (strcmp(current->container.name, tmp.name) == 0 && found == 0)
                    found = 1;
                if (found == 1) {
                    node* last = root->child;

                    // Loop through to the last child
                    while (last->sibling != root->child) {
                        last = last->sibling;
                    }

                    // Prev is not initialized since the target is root->child in the initial loop
                    if (prev == NULL) {
                        // Condition where there is only 2 children
                        if (current->sibling == last && last->sibling == root->child) {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        // Condition where the children count is above 2
                        else {
                            root->child = current->sibling;
                            last->sibling = root->child;
                        }
                    }
                    // Normal last child condition
                    else {
                        // Find the second child to check number of children
                        node* second_child = root->child->sibling;
                        // Condition where target is last, but there's only 2 children
                        if (prev == root->child && second_child->sibling == root->child) {
                            root->child->sibling = NULL;
                        }
                        // Normal condition where target is last and there is more than 2 children
                        else {
                            prev->sibling = current->sibling;
                            current->sibling = NULL;
                        }
                    }
                    // Delete the target node
                    delAll(current);
                } else {
                    // printf("[!] node with the name %c is not found\n", target->container.name);
                }
            }
        }
    }
}

// function to find node with BFS method
node* findNodeBFS(box find, node* root){
    node *result = NULL; // declare node result, set with NULL
    if(root != NULL){ // if root is not NULL
        queue Q; // declare queue Q
        createEmpty(&Q); // call procedure createEmpty to create an empty queue
        boxQue tmp; // declare boxQue tmp
        tmp.element = root; // update tmp.element with node root
        add(tmp, &Q); // add tmp to queue Q

        while(!isEmpty(Q) && result == NULL){ // loop while queue is not empty and result is still NULL
            boxQue front = Q.first->container; // declare boxQue front, set with first container
            node *current = front.element; // declare node current, set with front element
            
            if(strcmp(current->container.name, find.name) == 0){ // if its the same
                result = current; // update result with current node
            }else{ // if its not
                node *child = current->child; // declare node child, set with current child
                if(child != NULL){ // if child is not NULL
                    if(child->sibling == NULL){ // if child doesnt have sibling
                        boxQue new; // declare boxQue new
                        new.element = child; // update new element with node child
                        add(new, &Q); // add node new to queue
                    }else{ // if its more than 1 child
                        node *start = child; // declare node start, set with node child
                        do{ // do while child its not start
                            boxQue new; // declare boxQue new 
                            new.element = child; // update new element with node child
                            add(new, &Q); // add node new to queue
                            child = child->sibling; // update child with the next sibling
                        }while(child != start);
                    }
                }
            }
            del(&Q); // delete the first element from queue
        }
    }
    return result; // return the result
}

// procedure to print the node from root
void printNode(node *root){
    if(!root->container.level){ // case if its level 0
        printf("[%c] %s (%dkB)\n",root->container.type, root->container.name, root->container.size);
    }else{ // if its not
        for(int i = 0; i < space[root->container.level]; i++){
            printf(" "); // print space according to the level
        }
        if(root->sibling != NULL){ // if sibling is not NULL
            node *parent = root->parent; // declare parent, set with root parent
            if(root->sibling != parent->child){ // if root sibling its not parent child
                printf("├──[%c] %s (%dkB)\n",root->container.type, root->container.name, root->container.size);
            }else{  // if its the last sibling
                printf("└──[%c] %s (%dkB)\n",root->container.type, root->container.name, root->container.size);
            }
        }else{ // case if child doesnt have sibling
            printf("└──[%c] %s (%dkB)\n",root->container.type, root->container.name, root->container.size);
        }
        
    }
}

// procedure to print the tree by pre order
void printPreOrder(node* root){
    // Condition where root exist
    if (root != NULL) {
        printNode(root); // call printNode procedure to print node according to format
        node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                printPreOrder(current);
            }
            // Condition where there are multiple children
            else {
                // Print preorder for each sibling
                while (current->sibling != root->child) {
                    printPreOrder(current);
                    current = current->sibling;
                }
                // Print the last sibling
                printPreOrder(current);
            }
        }
    }
}

// procedure to count size kB and space level
void countSizeAndSpace(int down, node *root){ 
    // Condition where root exist
    if (root != NULL) {
        int total = 0; // declare total, set with 0
        root->container.level -= down; // decrement root level with down
        
        node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                countSizeAndSpace(down, current); // call recursive this procedure
                total += current->container.size; // increment total with current size
            }
            // Condition where there are multiple children
            else {
                // Print preorder for each sibling
                while (current->sibling != root->child) {
                    countSizeAndSpace(down, current); // call recursive this procedure
                    total += current->container.size; // increment total with current size
                    current = current->sibling;
                }
                // Print the last sibling
                countSizeAndSpace(down, current); // call recursive this procedure
                total += current->container.size; // increment total with current size
            }
        }

        if(root->container.type == 'd'){ // if type is directory
            if(root->child == NULL){ // if root doesnt have child
                root->container.size = 0; // update size with 0
            }else{ // if root have a chilf
                root->container.size = total; // update size with total
            }
        }
    }
}

// function to check eop
int eop(char pita[]){
    return (pita[idx] == ';'); // if its true, return 1
}

// memulai mesin
void start(char pita[]){
    // set index dan panjang kata menjadi 0
    idx = 0;
    wlen = 0;

    if(pita[idx] == '"'){ // kondisi jika nama mengandung spasi, maka harus diapit dengan tanda petik 2
        idx++;
        while(((pita[idx] != '"') && (eop(pita) == 0)) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
            if(pita[idx] == '\\' ){
                idx++;
            }
            
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0';
        idx++;
    }else{
        // masukkan kata baru
        while ((pita[idx] != ' ') && (eop(pita) == 0)){
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0'; // akhiri lagi
    }
}

// pindah next kata
void inc(char pita[]){
    wlen = 0; // set panjang kata jadi 0 (memastikan)


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }
    
    if(pita[idx] == '"'){ // kondisi jika nama mengandung spasi, maka harus diapit dengan tanda petik 2
        idx++;
        while(((pita[idx] != '"') && (eop(pita) == 0)) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
            if(pita[idx] == '\\' ){
                idx++;
            }
            
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0';
        idx++;
    }else{ // kondisi kata biasa
        // masukkan kata baru
        while ((pita[idx] != ' ') && (eop(pita) == 0)){
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0'; // akhiri lagi
    }

}

// mengembalikan current word
char* getcw(){
    return cw;
}

// function to convert string to integer
int str_to_int(char str[]){
    int n = 0; // declare n, set with 0
    for(int i = 0; i < str[i] != '\0'; i++){ // loop for per digit string
        n = n * 10 + (str[i] - '0'); // update value integer perdigit
    }
    return n; // return integer value
}

void solve(){
    box new; // declare box new
    strcpy(new.name, "root"); // update new name with root
    new.size = 0; // update new size with 0
    new.type = 'd'; // update new type with d
    new.level = 0; // update new level with 0
    space[0] = 0; // set space index 0 with 0

    createTree(new, &T); // call createTree procedure to create an empty tree
    node *dirNow = T.root; // declare dirNow to get current directory
    char str[201]; // declare string str to save input string value
    int stop = 0; // declare int stop, set with 0
    while(!stop){ // loop while stop is 0
        scanf(" %200[^\n]%*c", &str); // input str value
        start(str); // start str tape
        if(strcmp(getcw(), "tambah") == 0){ // case to add child
            inc(str); // inc str to get file type
            if(strcmp(getcw(), "directory") == 0 ) new.type = 'd'; // if its directory
            else if(strcmp(getcw(), "file") == 0) new.type = 'f'; // if its file
            inc(str); // inc str to get file name
            strcpy(new.name, getcw());
            inc(str); // inc str to get file size
            new.size = str_to_int(getcw());
            new.level = dirNow->container.level + 1; // get new level from dirNow level + 1
            addChild(new, dirNow); // call addChild procedure to add child to dirNow
            // update space size
            if(new.level - 1 == 0) space[new.level] = 1;
            else space[new.level] = space[new.level-1] + 4;
        }else if(strcmp(getcw(), "hapus") == 0){ // case to delete child
            inc(str); // inc str to get file name
            strcpy(new.name, getcw());
            node *nodeNew = findNodeBFS(new, T.root); // call function findNodeBFS to get node from new
            node *parent = nodeNew->parent; // declare parent, set with nodeNew parent
            if(parent != NULL){ // if parent its not NULL
                delChild(new, parent); // call procedure delChild to delete node new from node parent
            }
        }else if(strcmp(getcw(), "list") == 0){ // case to show the list of file
            countSizeAndSpace(dirNow->container.level, T.root); // call this procedure to count size kB and space level
            printf("----- list file di %s -----\n", dirNow->container.name); // print dirNow
            printPreOrder(dirNow); // call printPreOrder procedure to print the tree
            printf("\n");
        }else if(strcmp(getcw(), "pindah_ke") == 0){ // case to change directory now
            inc(str); // inc str to get file name
            strcpy(new.name, getcw());
            node *find = findNodeBFS(new, T.root); // call function findNodeBFS to get node from new
            if(find != NULL){ // if find its not NULL
                if(find->container.type == 'd'){ // if find container type is directory
                    dirNow = find; // update dirNow with find
                }else{ // if its not directory
                    printf("gagal pindah: %s bukan direktori\n\n", find->container.name);
                }
            }else{ // if its NULL
                printf("gagal pindah: direktori %s tidak ditemukan\n\n", new.name);
            }
        }else if(strcmp(getcw(), "cari") == 0){ // case to find the file from current directory
            inc(str); // inc str to get file name
            strcpy(new.name, getcw());
            node *find =  findNodeBFS(new, dirNow); // call function findNodeBFS to get node from new
            if(find != NULL) printf("hasil pencarian: file %s (%dkB) ditemukan! :3\n\n", find->container.name, find->container.size);
            else printf("hasil pencarian: file/direktori %s tidak ditemukan :(\n\n", new.name);
        }else if(strcmp(getcw(), "reset") == 0){ // case to reset all the file and directory except te root
            dirNow = T.root; // update dirNow with T.root
            if(T.root->child != NULL){
                node *target = T.root->child;
                if(target->sibling == NULL){
                    delChild(target->container, T.root);
                }else{
                    node *start = target; // declare node start, set with target
                    do{ // do while target its not start
                        delChild(target->container, T.root); // call delChild procedure to delete child from root
                        target = target->sibling; // update target with the next sibling
                    }while(target != start);
                }
            }
        }else if(strcmp(getcw(), "exit") == 0){ // case to exit the file system
            printf("meoww, bye! ~bubu\n");
            stop = 1; // update stop with 1
        }
    }
}