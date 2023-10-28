#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[],int n){
    int flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    printf("Array Sorted\n");
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int val = arr[i];
        int hole = i;
        while(hole > 0 && arr[hole-1] > val){
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = val;
    }
    printf("Array sorted...\n");
}

void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min= j;
            }
        }
        swap(&a[i],&a[min]);
    }
    printf("Array sorted...\n");
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int op,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("1 for bubble sort\n2 for insertion sort\n3 for selection sort\n4 for display\n");
    while (1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                bubble_sort(arr,n);
                break;
            case 2:
                insertion_sort(arr,n);
                break;
            case 3:
                selection_sort(arr,n);
                break;
            case 4:
                printf("Elments of the array are...\n");
                display(arr,n);
                break;
            default:
                exit(0);
        }
    }
}