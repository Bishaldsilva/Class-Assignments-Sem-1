#include<stdio.h>

void insert_edge(int arr1[],int arr2[]){
    for(int i=0;i<3;i++){
        arr1[i] = arr2[i];
    }
}

void right_shift(int edges[][3],int start,int end){
    int i;
    for(i=start;i > end; i--){
        insert_edge(edges[i],edges[i-1]);
    }
}

int getParent(int parent[], int node){
    if(parent[node] == node)
        return node;
    parent[node] = getParent(parent,parent[node]);
    return parent[node];
}

void union_node(int parent[],int rank[],int node1,int node2){
    int parent_node1 = getParent(parent,node1);
    int parent_node2 = getParent(parent,node2);

    if(rank[parent_node1] > rank[parent_node2])
        parent[parent_node2] = parent_node1;
    else if(rank[parent_node2] > rank[parent_node1])
        parent[parent_node1] = parent_node2;
    else {
        parent[parent_node2] = parent_node1;
        rank[parent_node1]++;
    }
}

int mst(int n, int graph[][n], int parent[], int rank[]){
    int i,j,k,edges[n*n][3],last_index = 0;
    for(i=0;i<n;i++){
        for(j=i + 1;j<n;j++){
            if(graph[i][j] != 0){
                int arr[3] = {i,j,graph[i][j]};
                if(last_index == 0){
                    insert_edge(edges[last_index],arr);
                    last_index++;
                } else {
                    if(edges[last_index-1][2] < graph[i][j]){
                        insert_edge(edges[last_index],arr);
                        last_index++;
                    } else {
                        for(k=0;k<last_index;k++){
                            if(graph[i][j] < edges[k][2]){
                                right_shift(edges,last_index,k);
                                last_index++;
                                insert_edge(edges[k],arr);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int weight = 0;
    for(i = 0; i < last_index; i++){
        int parent1 = getParent(parent,edges[i][0]);
        int parent2 = getParent(parent,edges[i][1]);

        if(parent1 != parent2){
            union_node(parent, rank, edges[i][0], edges[i][1]);
            weight += edges[i][2];
        }
    }
    
    return weight;
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

    int parent[n],rank[n];
    for(i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_weight = mst(n,graph, parent, rank);
    printf("The weight of the minimum spanning tree of this graph is: %d",mst_weight);


    return 0;
}