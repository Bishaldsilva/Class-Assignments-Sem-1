#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front, rear;
    int *list;
};

void bfs_algo(int n, int graph[][n], int bfs[], struct queue queue){
    int i, ind = 0, node = 0, visited[n];
    queue.list[queue.rear] = node;
    queue.rear++;

    for(i = 0; i < n; i++){
        visited[i] = 0;
    }

    while(queue.front < queue.rear){
        node = queue.list[queue.front];
        queue.front++;
        visited[node] = 1;
        bfs[ind] = node;
        ind++;

        for(i = 0; i < n; i++){
            if(visited[i] == 0 && graph[node][i] == 1){
                queue.list[queue.rear] = i;
                queue.rear++;
            }
        }
    }
}

int main(){
    int n, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int val, graph[n][n], bfs[n];
    struct queue queue;
    queue.list = (int *)malloc(sizeof(int) * n * n);
    queue.front = 0;
    queue.rear = 0;

    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            printf("Enter the edge for %d<-->%d: ",i,j);
            scanf("%d",&val);
            graph[i][j] = val;
            graph[j][i] = val;
        }
    }

    bfs_algo(n, graph, bfs, queue);

    printf("bfs of the graph is: \n");
    for(i = 0; i < n; i++){
        printf("%d ",bfs[i]);
    }

    return 0;
}