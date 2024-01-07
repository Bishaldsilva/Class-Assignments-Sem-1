#include<stdio.h>

void dfs(int n,int graph[][n],int visited[],int dfs_arr[],int node,int ind){
    visited[node] = 1;
    dfs_arr[ind] = node;
    for(int i=0;i < n;i++){
        if(graph[node][i] == 1 && visited[i] == 0)
            dfs(n,graph,visited,dfs_arr,i,ind + 1);
    }
}

int main(){
    int n,i,j,val;
    printf("Enter the number of node: ");
    scanf("%d",&n);

    int graph[n][n],dfs_arr[n],visited[n];
    for(i = 0;i < n;i++){
        for(j = i;j< n;j++){
            printf("enter the edge for %d and %d: ",i,j);
            scanf("%d",&val);
            graph[i][j] = val;
            graph[j][i] = val;
        }
    }

    for(i = 0;i < n;i++){
        visited[i] = 0;
    }

    dfs(n,graph,visited,dfs_arr,0,0);

    for(i=0;i<n;i++){
        printf("%d ",dfs_arr[i]);
    }
}