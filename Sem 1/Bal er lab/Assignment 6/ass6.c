#include<stdio.h>

void dfs_stack(int n, int graph[][n], int dfs[]){
    int node, dfs_ind = 0, i, top = 0, stack[2*n], visited[n];
    for(i = 0; i < n; i++){
        visited[i] = 0;
    }
    stack[0] = 0;

    while(top >= 0){
        node = stack[top];
        top--;

        dfs[dfs_ind] = node;
        dfs_ind++;

        for(i = 0; i < n; i++){
            if(visited[i] == 0 && graph[node][i] == 1)
                stack[++top] = i;
        }

        visited[node] = 1;
    }

}

int main(){
    int n, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int val, graph[n][n], dfs[n];
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            printf("Enter the edge for %d<-->%d: ",i,j);
            scanf("%d",&val);
            graph[i][j] = val;
            graph[j][i] = val;
        }
    }

    dfs_stack(n,graph,dfs);

    printf("dfs of the graph is: \n");
    for(i = 0; i < n; i++)
        printf("%d ",dfs[i]);

}