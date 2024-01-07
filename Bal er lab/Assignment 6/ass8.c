#include<stdio.h>
#define INT_MAX 1000009

void floyd_algo(int n, int srt_paths[][n]){
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){

                if(j == k || j == i || k == i)
                    continue;
                
                if(srt_paths[j][k] > srt_paths[j][i] + srt_paths[i][k])
                    srt_paths[j][k] = srt_paths[j][i] + srt_paths[i][k];
            }
        }
    }
}

int main(){
    int n, i, j;
    printf("Enter the numebr of nodes: ");
    scanf("%d",&n);

    int val, graph[n][n], srt_paths[n][n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Enter the edge for %d --> %d(-1 if edge doesn't exist) : ",i,j);
            scanf("%d",&val);
            if(val == -1){
                graph[i][j] = INT_MAX;
                srt_paths[i][j] = INT_MAX;
            }
            else{
                graph[i][j] = val;
                srt_paths[i][j] = val;
            }
        }
    }

    floyd_algo(n, srt_paths);

    printf("The paths are: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",srt_paths[i][j]);
        }
        printf("\n");
    }
}