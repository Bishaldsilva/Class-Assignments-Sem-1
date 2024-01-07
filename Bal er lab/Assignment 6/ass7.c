#include<stdio.h>
#define INT_MAX 1000009

void dijkstras_algo(int n, int graph[][n], int visited[], int distance[]){

    int loop;
    for(loop = 0; loop < n; loop++){
        int i,ind = -1, min_val = INT_MAX;
        for(i = 0; i < n; i++){
            if(visited[i] == 0 && distance[i] < min_val){
                min_val = distance[i];
                ind = i;
            }
        }

        visited[ind] = 1;

        for(i = 0; i < n; i++){
            if(visited[i] == 0 && graph[ind][i] > 0){
                if(distance[ind] + graph[ind][i] < distance[i])
                    distance[i] = distance[ind] + graph[ind][i];
            }
        }
    }
}

int main(){

    int n,i,j;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int graph[n][n], visited[n],distance[n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Enter the weight of the edge %d --> %d: ",i,j);
            scanf("%d",&graph[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        visited[i] = 0;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    dijkstras_algo(n, graph, visited, distance);

    printf("The shortest distance to each node is(starting from 0): ");
    for(i = 0; i < n; i++){
        printf("%d ",distance[i]);
    }



    return 0;
}