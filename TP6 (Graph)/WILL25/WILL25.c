/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Praktikum 6 dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "WILL25.h" // include header "WILL25.h"

// procedure to create empty graph
void createEmpty(graph *G){
    (*G).first = NULL;
}

// procedure to add new node
void addNode(box tmp, graph *G){
    node *new; // declare new node
    new = (node *) malloc (sizeof(node)); // malloc new node
    new->container = tmp; // fill container new with box tmp
    new->next = NULL; // new point (next) to NULL
    new->arc = NULL; // new point (arc) to NULL
    if((*G).first == NULL){ // if the first is NULL
        (*G).first = new; // update first with node new
    }else{ // if its not NULL
        /* add new node at the end of graph */
        node *last = (*G).first; // declare node last
        while(last->next != NULL){ // loop while last next is not NULL
            last = last->next; // update last with last next
        }
        last->next = new; // last node point (next) to new node
    }
}

// procedure to add new edge
void addEdge(node *begin, node *dest, int weight){
    edge *new; // declare new edge
    new = (edge *) malloc (sizeof (edge)); // malloc new edge
    new->container_edg = weight; // fill container edge with the weight
    new->next_edg = NULL; // new point (next_edg) to NULL
    new->dest = dest; // new point (dest) to dest
    if(begin->arc == NULL){ // if list edge is NULL
        begin->arc = new; // begin point (arc) to new
    }else{ // if its not NULL
        /* add new edge at the end of edge list */
        edge *last = begin->arc; // declare edge last
        while(last->next_edg != NULL){ // loop while last next_edg is not NULL
            last = last->next_edg; // update last with last next_edg
        }
        last->next_edg = new; // last edge point (next) to new edge
    }
}

// function to find the node
node* findNode(box tmp, graph G){
    node *result = NULL; // declare node result, initialized with NULL
    node *point = G.first; // declare node point, start from first
    int found = 0; // declare found
    // loop while point is not NULL and found is 0
    while((point != NULL) && (!found)){
        if(strcmp(point->container.str, tmp.str) == 0){ // if its same
            result = point; // update node result with point
            found = 1; // update found with 1
        }else{ // if its not
            point = point->next; // update point with point next
        }
    }
    return result; // return node result
}

// procedure dfs to perform a search on a graph, (can save the shortest path)
void dfs(node *now, node *dest,
        char path[][51], int depth, int pathWeight,
        char result[][51], int *resDepth, int *resWeight,
        int vstIdx, node *visited[]){

    visited[vstIdx] = now; // update node visited with index vtsIdx with node now
    
    // recursive base
    if(now == dest){ // if now is same with dest
        for(int i = 0; i <= depth; i++){ // loop for to print the path
            printf("%s", path[i]); // print the node
            if(i != depth) printf(" -> "); // print after node (first and middle)
            else printf(" . %d%%\n", pathWeight); // print after node (last)
        }
        if(pathWeight < *resWeight){ // if pathWeigth less than resWeight
            *resWeight = pathWeight; // update resWeight with pathWeight
            *resDepth = depth + 1; // update resDepth with depth + 1
            for(int i = 0; i <= depth; i++){ // loop untuk depth index
                strcpy(result[i], path[i]); // save the shortest path to the result
            }
        }
        return;
    }

    // update edge point with the first edge of the new node
    edge *point = now->arc;
    while(point != NULL){ // loop while point its not NULL
        int found = 0; // declare int found, set with 0
        int i = 0; // declare int i, start with 0
        // loop while i less equal than vstIdx and found is 0
        while(i <= vstIdx && !found){
            if(visited[i] == point->dest){ // if its same
                found = 1; // update found with 1
            }else{ // if its not
                i++; // do an increment for i
            }
        }

        if(!found){ // if its not found
            strcpy(path[depth + 1], point->dest->container.str); // copy the new node to path
            // recurive call procedure dfs
            dfs(point->dest, dest,
                path, depth + 1, pathWeight + point->container_edg,
                result, resDepth, resWeight,
                vstIdx + 1, visited);
        }
        point = point->next_edg; // update point with the next edge
    }
}

void solve(){
    graph G; // declare graph G
    createEmpty(&G); // call procedure createEmpty to create an empty graph
    int n; // declare n
    scanf("%d", &n); // input n value
    box from, to; // declare box from and to
    node *begin, *end; // declare node begin and end
    int weight; // declare int weight
    for(int i = 0; i < n; i++){ // loop until n
        scanf("%s %s %d", from.str, to.str, &weight); // scan from, to, and weight
        begin = findNode(from, G); // find node from
        if(begin == NULL){ // if its NULL
            addNode(from, &G); // add new node from
            begin = findNode(from, G); // update node begin with from
        }
        end = findNode(to, G); // find node to
        if(end == NULL){ // if its NULL
            addNode(to, &G); // add new node to
            end = findNode(to, G); // update node end with to
        }
        if((begin != NULL) && (end != NULL)){ // to make sure, check if begin and end its not nULL
            addEdge(begin, end, weight); // if its true, add new edge with some weight
        }
    }
    /* no need to declare new box or new node
    because all the boxes and the nodes is save
    in graph G, so we can use the box and node 
    that have been used before, cuz its more efficient */
    scanf("%s %s", from.str, to.str); // input from and to, to find some path
    scanf("%d", &weight); // input battery now value
    begin = findNode(from, G); // update node begin with from
    end = findNode(to, G); // update node end with to

    // declare some array and node to save the path
    char path[100][51]; // declare path to save the path from begin to end
    char result[100][51]; /* declare result (honestly in this case the result
                            is not used, but cuz the dfs procedure that i created
                            it can be reusable cuz can save the shortest path, 
                            in case its needed to save) */
    int resWeight = 999999; // declare resWeight to save the minimum weight
    int resDepth = 0; // declare resDepth to save the depth of the result
    node *visited[100]; // declare node visited, to save some nodes that are visited

    // call procedure dfs, fill path index 0 with node begin
    strcpy(path[0], begin->container.str);
    dfs(begin, end, path, 0, 0, result, &resDepth, &resWeight, 0, visited);
    printf("---\n");
    if(weight-resWeight < 0){
        printf("Cahaya terakhir padam di tengah perjalanan.\n");
        printf("Sisa baterai: 0%%.\n");
    }else{
        printf("Berhasil mencapai tujuan sebelum kehabisan cahaya.\n");
        printf("Sisa baterai: %d%%.\n", weight-resWeight);
    }
}