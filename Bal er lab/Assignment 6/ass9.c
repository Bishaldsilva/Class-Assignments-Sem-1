#include<stdio.h>

void topological_sort(int n,int graph[][n],int visited[],int stack[],int node,int *top){
    visited[node] = 1;
    for(int i=0;i < n;i++){
        if(graph[node][i] == 1 && visited[i] == 0)
            topological_sort(n,graph,visited,stack,i,top);
    }
    stack[*top] = node;
    *top = *top + 1;
}

int main(){
    int n,i,j,val;
    printf("Enter the number of node: ");
    scanf("%d",&n);

    int graph[n][n],stack[n],visited[n],top=0;
    for(i = 0;i < n;i++){
        for(j = 0;j< n;j++){
            printf("enter the edge for %d and %d: ",i,j);
            scanf("%d",&val);
            graph[i][j] = val;
            // graph[j][i] = val;
        }
    }

    for(i = 0;i < n;i++){
        visited[i] = 0;
    }

    topological_sort(n,graph,visited,stack,0,&top);

    printf("Topological Sort of the graph is: ");
    for(i=n-1;i>=0;i--){
        printf("%d ",stack[i]);
    }
}