#include<stdio.h>

void addVertex(int nodeNumber, int n, int graph[][n]){
    if(nodeNumber == 0){
        graph[0][0] = 0;
    }
    else {
        int i;
        for(i = 0; i < nodeNumber; i++){
            graph[i][nodeNumber] = 0;
        }
        for(i = 0; i <= nodeNumber; i++){
            graph[nodeNumber][i] = 0;
        }
    }
}

void addEdge(int n, int graph[][n], int u, int v){
    if(u < n && v < n){
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void delEdge(int n, int graph[][n], int u, int v){
    if(u < n && v < n){
        graph[u][v] = 0;
        graph[v][u] = 0;
    }
}

void delVertex(int n, int graph[][n], int v, int *n_ptr){
    if(v < n){
        int i;
        for(i = 0; i < n; i++){
            graph[v][i] = 0;
            graph[i][v] = 0; 
        }
        *n_ptr = *n_ptr - 1; 
    }
}

int main(){
    int n, i, j;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);

    int graph[100][100];
    for(i = 0; i < n; i++){
        addVertex(i, n, graph);
    }

    addEdge(n, graph, 0, 1);
    printf("Edge betwen %dth verted and %dth vertex has been added...\n",0,1);

    delEdge(n, graph, 0, 1);
    printf("Edge betwen %dth verted and %dth vertex has been deleted...\n",0,1);

    delVertex(n, graph, n - 1, &n);
    printf("vertex %d has been deleted...\n",n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }


    return 0;
}