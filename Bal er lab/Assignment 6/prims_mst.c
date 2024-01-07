#include<stdio.h>
#define INT_MAX 1000009

int prims_mst(int n, int graph[][n], int key[], int mst[], int parent[]){
    int j, sum = 0;
    for(j = 0; j < n; j++){
        int i, u = -1, min_val = INT_MAX;

        for(i = 0; i < n; i++){
            if(mst[i] == 0 && key[i] < min_val){
                min_val = key[i];
                u = i;
            }
        }

        mst[u] = 1;

        for(i = 0; i < n; i++){
            if(mst[i] == 0 && graph[u][i] != 0 && key[i] > graph[u][i]){
                key[i] = graph[u][i];
                parent[i] = u;
            }
        }
    }
    for(j = 0; j < n; j++)
        sum += key[j];

    return sum;
}

int main(){
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);

    int i,j,graph[n][n],val;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            printf("Enter the weight for the edge %d<-->%d: ",i,j);
            scanf("%d",&val);
            graph[i][j] = val;
            graph[j][i] = val;
        }
    }

    int key[n],mst[n],parent[n];
    for(i = 0; i < n; i++){
        key[i] = INT_MAX;
        mst[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;

    int min_weight = prims_mst(n,graph,key,mst,parent);
    printf("The weight of the minimum spanning tree of this graph is: %d",min_weight);

    return 0;
}