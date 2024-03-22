#include<stdio.h>

int heap[30] = {-1};
int heapSize = 0;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = -1;
    if(l <= heapSize && heap[l] > heap[i]){
        largest = l;
    } else {
        largest = i;
    }

    if(r <= heapSize && heap[r] > heap[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&heap[largest],&heap[i]);
        heapify(largest);
    }
}

void insert(int val){
    heapSize++;
    int i = heapSize;
    heap[i] = val;
    while (i > 1 && heap[i /2] < heap[i]){
        swap(&heap[i/2],&heap[i]);
        i = i/2;
    }
}

int delete(){
    int x = heap[1];
    swap(&heap[1],&heap[heapSize]);
    heapSize--;
    heapify(1);
    return x;
}

void buildHeap(){
    for(int i=heapSize / 2; i > 0;i--){
        heapify(i);
    }
}

void heapSort(){
    int n = heapSize;
    while(heapSize){
        swap(&heap[1],&heap[heapSize]);
        heapSize--;
        heapify(1);
    }
    heapSize = n;
}

void display(){
    for(int i=1;i<=heapSize;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int main(){
    int val;
    for(int i=1;i<=5;i++){
        scanf("%d",&val);
        heap[i] = val;
        heapSize++;
    }
    buildHeap();
    display();
    heapSort();
    display();
    return 0;
}